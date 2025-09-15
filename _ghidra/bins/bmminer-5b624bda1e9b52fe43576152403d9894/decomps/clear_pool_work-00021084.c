
/* WARNING: Unknown calling convention */

void clear_pool_work(pool *pool)

{
  work *pwVar1;
  work *pwVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  UT_hash_handle *pUVar6;
  char *func;
  char *func_00;
  int line;
  int line_00;
  work *pwVar7;
  UT_hash_handle *pUVar8;
  work *pwVar9;
  work *pwVar10;
  uint uVar11;
  UT_hash_table *pUVar12;
  UT_hash_bucket *pUVar13;
  bool bVar14;
  work *local_824;
  char tmp42 [2048];
  
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)stgd_lock);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)"clear_pool_work",(char *)0x1c74,func,line);
  }
  local_824 = staged_work;
  pwVar9 = staged_work;
  if (staged_work != (work *)0x0) {
    pwVar9 = (work *)(staged_work->hh).next;
  }
  iVar3 = 0;
  if (staged_work != (work *)0x0) {
    while( true ) {
      pwVar1 = staged_work;
      if (local_824->pool == pool) {
        pvVar5 = (local_824->hh).prev;
        pwVar10 = (work *)(local_824->hh).next;
        if ((pvVar5 == (void *)0x0) && (pwVar10 == (work *)0x0)) {
          free(((staged_work->hh).tbl)->buckets);
          free((staged_work->hh).tbl);
          staged_work = pwVar10;
        }
        else {
          pUVar12 = (staged_work->hh).tbl;
          pwVar7 = (work *)((int)pUVar12->tail - pUVar12->hho);
          bVar14 = local_824 == pwVar7;
          if (bVar14) {
            pwVar7 = (work *)((int)pvVar5 + pUVar12->hho);
          }
          if (bVar14) {
            pUVar12->tail = (UT_hash_handle *)pwVar7;
          }
          pwVar7 = pwVar10;
          pwVar2 = pwVar10;
          if (pvVar5 != (void *)0x0) {
            *(work **)((int)pvVar5 + ((staged_work->hh).tbl)->hho + 8) = pwVar10;
            pwVar10 = pwVar1;
            pwVar7 = (work *)(local_824->hh).next;
            pwVar2 = staged_work;
          }
          staged_work = pwVar2;
          pUVar12 = (pwVar10->hh).tbl;
          if (pwVar7 != (work *)0x0) {
            *(void **)(pwVar7->data + pUVar12->hho + 4) = pvVar5;
          }
          pUVar13 = pUVar12->buckets;
          uVar11 = pUVar12->num_buckets - 1 & (local_824->hh).hashv;
          pUVar8 = (local_824->hh).hh_next;
          pUVar13[uVar11].count = pUVar13[uVar11].count - 1;
          pUVar6 = (local_824->hh).hh_prev;
          if (pUVar13[uVar11].hh_head == &local_824->hh) {
            pUVar13[uVar11].hh_head = pUVar8;
          }
          if (pUVar6 != (UT_hash_handle *)0x0) {
            pUVar6->hh_next = pUVar8;
            pUVar8 = (local_824->hh).hh_next;
          }
          if (pUVar8 != (UT_hash_handle *)0x0) {
            pUVar8->hh_prev = pUVar6;
          }
          pUVar12->num_items = pUVar12->num_items - 1;
        }
        iVar3 = iVar3 + 1;
        _free_work(&local_824,"cgminer.c","clear_pool_work",0x1c7a);
      }
      local_824 = pwVar9;
      if (pwVar9 == (work *)0x0) break;
      pwVar9 = (work *)(pwVar9->hh).next;
    }
  }
  iVar4 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
  if (iVar4 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"clear_pool_work",(char *)0x1c7e,func_00,line_00);
  }
  (*selective_yield)();
  if ((iVar3 != 0) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level))))
  {
    snprintf(tmp42,0x800,"Cleared %d work items due to stratum disconnect on pool %d",iVar3,
             pool->pool_no);
    _applog(6,tmp42,false);
  }
  return;
}

