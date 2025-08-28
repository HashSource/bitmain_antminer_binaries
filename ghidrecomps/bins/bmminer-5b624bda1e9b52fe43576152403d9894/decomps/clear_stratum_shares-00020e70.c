
/* WARNING: Unknown calling convention */

void clear_stratum_shares(pool *pool)

{
  stratum_share *psVar1;
  stratum_share *psVar2;
  int iVar3;
  stratum_share *psVar4;
  UT_hash_handle *pUVar5;
  void *pvVar6;
  UT_hash_handle *pUVar7;
  char *func;
  work *pwVar8;
  char *func_00;
  int line;
  int line_00;
  stratum_share *__ptr;
  stratum_share *psVar9;
  uint uVar10;
  stratum_share *psVar11;
  uint uVar12;
  UT_hash_table *pUVar13;
  UT_hash_bucket *pUVar14;
  bool bVar15;
  double dVar16;
  char tmp42 [2048];
  
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)&sshare_lock);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)"clear_stratum_shares",(char *)0x1c55,func,line);
  }
  if (stratum_shares == (stratum_share *)0x0) {
    dVar16 = 0.0;
    uVar10 = 0;
  }
  else {
    pwVar8 = stratum_shares->work;
    uVar10 = 0;
    psVar9 = (stratum_share *)(stratum_shares->hh).next;
    dVar16 = 0.0;
    __ptr = stratum_shares;
    if (pwVar8->pool == pool) goto LAB_00020ebc;
    while (__ptr = psVar9, psVar9 != (stratum_share *)0x0) {
      while( true ) {
        psVar9 = (stratum_share *)(__ptr->hh).next;
        pwVar8 = __ptr->work;
        if (pwVar8->pool != pool) break;
LAB_00020ebc:
        psVar1 = stratum_shares;
        pvVar6 = (__ptr->hh).prev;
        psVar11 = (stratum_share *)(__ptr->hh).next;
        if ((pvVar6 == (void *)0x0) && (psVar11 == (stratum_share *)0x0)) {
          free(((stratum_shares->hh).tbl)->buckets);
          free((psVar1->hh).tbl);
          pwVar8 = __ptr->work;
          stratum_shares = psVar11;
        }
        else {
          pUVar13 = (stratum_shares->hh).tbl;
          iVar3 = pUVar13->hho;
          psVar4 = (stratum_share *)((int)pUVar13->tail - iVar3);
          bVar15 = __ptr == psVar4;
          if (bVar15) {
            psVar4 = (stratum_share *)((int)pvVar6 + iVar3);
          }
          if (bVar15) {
            pUVar13->tail = &psVar4->hh;
          }
          psVar4 = psVar11;
          psVar2 = psVar11;
          if (pvVar6 != (void *)0x0) {
            *(stratum_share **)((int)pvVar6 + iVar3 + 8) = psVar11;
            psVar11 = psVar1;
            psVar4 = (stratum_share *)(__ptr->hh).next;
            psVar2 = stratum_shares;
          }
          stratum_shares = psVar2;
          pUVar13 = (psVar11->hh).tbl;
          if (psVar4 != (stratum_share *)0x0) {
            *(void **)((int)&(psVar4->hh).prev + pUVar13->hho) = pvVar6;
          }
          pUVar14 = pUVar13->buckets;
          uVar12 = pUVar13->num_buckets - 1 & (__ptr->hh).hashv;
          pUVar7 = (__ptr->hh).hh_next;
          pUVar14[uVar12].count = pUVar14[uVar12].count - 1;
          pUVar5 = (__ptr->hh).hh_prev;
          if ((stratum_share *)pUVar14[uVar12].hh_head == __ptr) {
            pUVar14[uVar12].hh_head = pUVar7;
          }
          if (pUVar5 != (UT_hash_handle *)0x0) {
            pUVar5->hh_next = pUVar7;
            pUVar7 = (__ptr->hh).hh_next;
          }
          if (pUVar7 != (UT_hash_handle *)0x0) {
            pUVar7->hh_prev = pUVar5;
          }
          pUVar13->num_items = pUVar13->num_items - 1;
        }
        uVar10 = uVar10 + 1;
        dVar16 = dVar16 + pwVar8->work_difficulty;
        _free_work(&__ptr->work,"cgminer.c","clear_stratum_shares",0x1c5d);
        pool->sshares = pool->sshares + -1;
        free(__ptr);
        __ptr = psVar9;
        if (psVar9 == (stratum_share *)0x0) goto LAB_00020f7a;
      }
    }
  }
LAB_00020f7a:
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&sshare_lock);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"clear_stratum_shares",(char *)0x1c63,func_00,line_00);
  }
  (*selective_yield)();
  if (uVar10 != 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Lost %d shares due to stratum disconnect on pool %d",uVar10,
               pool->pool_no);
      _applog(4,tmp42,false);
    }
    pool->stale_shares = pool->stale_shares + uVar10;
    pool->diff_stale = pool->diff_stale + dVar16;
    total_diff_stale = total_diff_stale + dVar16;
    bVar15 = CARRY4((uint)total_stale,uVar10);
    total_stale._0_4_ = (uint)total_stale + uVar10;
    total_stale._4_4_ = total_stale._4_4_ + ((int)uVar10 >> 0x1f) + (uint)bVar15;
  }
  return;
}

