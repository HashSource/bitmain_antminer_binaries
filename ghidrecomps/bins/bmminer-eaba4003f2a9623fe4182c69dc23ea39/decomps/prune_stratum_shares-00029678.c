
void prune_stratum_shares(pool *pool)

{
  time_t tVar1;
  UT_hash_bucket *pUVar2;
  uint uVar3;
  UT_hash_table *pUVar4;
  bool bVar5;
  pool *pool_local;
  char tmp42 [2048];
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  time_t current_time;
  int cleared;
  stratum_share *tmpshare;
  stratum_share *sshare;
  
  tVar1 = time((time_t *)0x0);
  cleared = 0;
  _mutex_lock(&sshare_lock,"cgminer.c","prune_stratum_shares",0x2748);
  sshare = stratum_shares;
  if (stratum_shares == (stratum_share *)0x0) {
    tmpshare = (stratum_share *)0x0;
  }
  else {
    tmpshare = (stratum_share *)(stratum_shares->hh).next;
  }
  while (sshare != (stratum_share *)0x0) {
    if ((sshare->work->pool == pool) && (sshare->sshare_time + 0x78 < tVar1)) {
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
        uVar3 = ((stratum_shares->hh).tbl)->num_buckets - 1 & (sshare->hh).hashv;
        pUVar2 = ((stratum_shares->hh).tbl)->buckets;
        pUVar2[uVar3].count = pUVar2[uVar3].count - 1;
        if ((stratum_share *)((stratum_shares->hh).tbl)->buckets[uVar3].hh_head == sshare) {
          ((stratum_shares->hh).tbl)->buckets[uVar3].hh_head = (sshare->hh).hh_next;
        }
        if ((sshare->hh).hh_prev != (UT_hash_handle *)0x0) {
          ((sshare->hh).hh_prev)->hh_next = (sshare->hh).hh_next;
        }
        if ((sshare->hh).hh_next != (UT_hash_handle *)0x0) {
          ((sshare->hh).hh_next)->hh_prev = (sshare->hh).hh_prev;
        }
        pUVar4 = (stratum_shares->hh).tbl;
        pUVar4->num_items = pUVar4->num_items - 1;
      }
      _free_work(&sshare->work,"cgminer.c","prune_stratum_shares",0x274f);
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
  _mutex_unlock(&sshare_lock,"cgminer.c","prune_stratum_shares",0x2755);
  if (cleared != 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Lost %d shares due to no stratum share response from pool %d",cleared,
               pool->pool_no);
      _applog(4,tmp42,false);
    }
    pool->stale_shares = pool->stale_shares + cleared;
    bVar5 = CARRY4((uint)total_stale,cleared);
    total_stale._0_4_ = (uint)total_stale + cleared;
    total_stale._4_4_ = total_stale._4_4_ + (cleared >> 0x1f) + (uint)bVar5;
  }
  return;
}

