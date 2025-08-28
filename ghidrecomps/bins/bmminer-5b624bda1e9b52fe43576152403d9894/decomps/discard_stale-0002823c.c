
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void discard_stale(void)

{
  work *pwVar1;
  work *pwVar2;
  _Bool _Var3;
  int iVar4;
  void *pvVar5;
  UT_hash_handle *pUVar6;
  work *pwVar7;
  char *func;
  char *func_00;
  int line;
  UT_hash_bucket *pUVar8;
  UT_hash_handle *pUVar9;
  int line_00;
  work *pwVar10;
  UT_hash_table *pUVar11;
  work *pwVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  work *local_81c;
  char tmp42 [2048];
  
  iVar4 = pthread_mutex_lock((pthread_mutex_t *)stgd_lock);
  if (iVar4 != 0) {
    _mutex_lock((pthread_mutex_t *)"discard_stale",(char *)0x149e,func,line);
  }
  local_81c = staged_work;
  pwVar10 = staged_work;
  if (staged_work != (work *)0x0) {
    pwVar10 = (work *)(staged_work->hh).next;
  }
  iVar4 = 0;
  if (staged_work != (work *)0x0) {
    while( true ) {
      _Var3 = stale_work(local_81c,false);
      pwVar1 = staged_work;
      if (_Var3) {
        pvVar5 = (local_81c->hh).prev;
        pwVar12 = (work *)(local_81c->hh).next;
        if ((pvVar5 == (void *)0x0) && (pwVar12 == (work *)0x0)) {
          free(((staged_work->hh).tbl)->buckets);
          free((staged_work->hh).tbl);
          staged_work = pwVar12;
        }
        else {
          pUVar11 = (staged_work->hh).tbl;
          iVar13 = pUVar11->hho;
          pwVar7 = (work *)((int)pUVar11->tail - iVar13);
          bVar15 = local_81c == pwVar7;
          if (bVar15) {
            pwVar7 = (work *)((int)pvVar5 + iVar13);
          }
          if (bVar15) {
            pUVar11->tail = (UT_hash_handle *)pwVar7;
          }
          pwVar7 = pwVar12;
          pwVar2 = pwVar12;
          if (pvVar5 != (void *)0x0) {
            *(work **)((int)pvVar5 + iVar13 + 8) = pwVar12;
            pwVar12 = pwVar1;
            pwVar7 = (work *)(local_81c->hh).next;
            pwVar2 = staged_work;
          }
          staged_work = pwVar2;
          pUVar11 = (pwVar12->hh).tbl;
          if (pwVar7 != (work *)0x0) {
            *(void **)(pwVar7->data + pUVar11->hho + 4) = pvVar5;
          }
          pUVar8 = pUVar11->buckets;
          uVar14 = pUVar11->num_buckets - 1 & (local_81c->hh).hashv;
          pUVar6 = (local_81c->hh).hh_next;
          if (pUVar8[uVar14].hh_head == &local_81c->hh) {
            pUVar8[uVar14].hh_head = pUVar6;
          }
          pUVar9 = (local_81c->hh).hh_prev;
          pUVar8[uVar14].count = pUVar8[uVar14].count - 1;
          if (pUVar9 != (UT_hash_handle *)0x0) {
            pUVar9->hh_next = pUVar6;
            pUVar6 = (local_81c->hh).hh_next;
          }
          if (pUVar6 != (UT_hash_handle *)0x0) {
            pUVar6->hh_prev = pUVar9;
          }
          pUVar11->num_items = pUVar11->num_items - 1;
        }
        iVar4 = iVar4 + 1;
        _discard_work(&local_81c,"cgminer.c","discard_stale",0x14a5);
      }
      local_81c = pwVar10;
      if (pwVar10 == (work *)0x0) break;
      pwVar10 = (work *)(pwVar10->hh).next;
    }
  }
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  iVar13 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
  if (iVar13 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"discard_stale",(char *)0x14ab,func_00,line_00);
  }
  (*selective_yield)();
  if (((iVar4 != 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"Discarded %d stales that didn\'t match current hash",iVar4);
    _applog(7,tmp42,false);
  }
  return;
}

