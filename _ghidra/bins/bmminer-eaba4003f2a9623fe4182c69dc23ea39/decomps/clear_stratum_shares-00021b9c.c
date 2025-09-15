
void clear_stratum_shares(pool *pool)

{
  UT_hash_bucket *pUVar1;
  uint uVar2;
  UT_hash_table *pUVar3;
  bool bVar4;
  pool *pool_local;
  char tmp42 [2048];
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  int cleared;
  double diff_cleared;
  stratum_share *tmpshare;
  stratum_share *sshare;
  
  diff_cleared = 0.0;
  cleared = 0;
  _mutex_lock(&sshare_lock,"cgminer.c","clear_stratum_shares",0x1c5c);
  sshare = stratum_shares;
  if (stratum_shares == (stratum_share *)0x0) {
    tmpshare = (stratum_share *)0x0;
  }
  else {
    tmpshare = (stratum_share *)(stratum_shares->hh).next;
  }
  while (sshare != (stratum_share *)0x0) {
    if (sshare->work->pool == pool) {
      if (((sshare->hh).prev == (void *)0x0) && ((sshare->hh).next == (void *)0x0)) {
        free(((stratum_shares->hh).tbl)->buckets);
        free((stratum_shares->hh).tbl);
        stratum_shares = (stratum_share *)0x0;
      }
      else {
        if ((stratum_share *)
            ((int)((stratum_shares->hh).tbl)->tail - ((stratum_shares->hh).tbl)->hho) == sshare) {
          ((stratum_shares->hh).tbl)->tail =
               (UT_hash_handle *)((int)(sshare->hh).prev + ((stratum_shares->hh).tbl)->hho);
        }
        if ((sshare->hh).prev == (void *)0x0) {
          stratum_shares = (stratum_share *)(sshare->hh).next;
        }
        else {
          *(void **)((int)(sshare->hh).prev + ((stratum_shares->hh).tbl)->hho + 8) =
               (sshare->hh).next;
        }
        if ((sshare->hh).next != (void *)0x0) {
          *(void **)((int)(sshare->hh).next + ((stratum_shares->hh).tbl)->hho + 4) =
               (sshare->hh).prev;
        }
        uVar2 = ((stratum_shares->hh).tbl)->num_buckets - 1 & (sshare->hh).hashv;
        pUVar1 = ((stratum_shares->hh).tbl)->buckets;
        pUVar1[uVar2].count = pUVar1[uVar2].count - 1;
        if ((stratum_share *)((stratum_shares->hh).tbl)->buckets[uVar2].hh_head == sshare) {
          ((stratum_shares->hh).tbl)->buckets[uVar2].hh_head = (sshare->hh).hh_next;
        }
        if ((sshare->hh).hh_prev != (UT_hash_handle *)0x0) {
          ((sshare->hh).hh_prev)->hh_next = (sshare->hh).hh_next;
        }
        if ((sshare->hh).hh_next != (UT_hash_handle *)0x0) {
          ((sshare->hh).hh_next)->hh_prev = (sshare->hh).hh_prev;
        }
        pUVar3 = (stratum_shares->hh).tbl;
        pUVar3->num_items = pUVar3->num_items - 1;
      }
      diff_cleared = diff_cleared + sshare->work->work_difficulty;
      _free_work(&sshare->work,"cgminer.c","clear_stratum_shares",0x1c64);
      pool->sshares = pool->sshares + -1;
      free(sshare);
      cleared = cleared + 1;
    }
    sshare = tmpshare;
    if (tmpshare == (stratum_share *)0x0) {
      tmpshare = (stratum_share *)0x0;
    }
    else {
      tmpshare = (stratum_share *)(tmpshare->hh).next;
    }
  }
  _mutex_unlock(&sshare_lock,"cgminer.c","clear_stratum_shares",0x1c6a);
  if (cleared != 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Lost %d shares due to stratum disconnect on pool %d",cleared,
               pool->pool_no);
      _applog(4,tmp42,false);
    }
    pool->stale_shares = pool->stale_shares + cleared;
    bVar4 = CARRY4((uint)total_stale,cleared);
    total_stale._0_4_ = (uint)total_stale + cleared;
    total_stale._4_4_ = total_stale._4_4_ + (cleared >> 0x1f) + (uint)bVar4;
    pool->diff_stale = pool->diff_stale + diff_cleared;
    total_diff_stale = total_diff_stale + diff_cleared;
  }
  return;
}

