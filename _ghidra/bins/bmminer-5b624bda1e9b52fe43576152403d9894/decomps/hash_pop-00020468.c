
/* WARNING: Unknown calling convention */

work * hash_pop(_Bool blocking)

{
  work *pwVar1;
  work *pwVar2;
  work *pwVar3;
  int iVar4;
  UT_hash_bucket *pUVar5;
  void *pvVar6;
  uint uVar7;
  UT_hash_handle *pUVar8;
  char *func;
  UT_hash_handle *pUVar9;
  char *func_00;
  int line;
  work *pwVar10;
  int line_00;
  UT_hash_table *pUVar11;
  work *pwVar12;
  bool bVar13;
  timespec then;
  timeval now;
  char tmp42 [2048];
  
  pwVar3 = (work *)(uint)blocking;
  iVar4 = pthread_mutex_lock((pthread_mutex_t *)stgd_lock);
  if (iVar4 != 0) {
    _mutex_lock((pthread_mutex_t *)"hash_pop",(char *)0x1f78,func,line);
  }
  if ((staged_work == (work *)0x0) || (((staged_work->hh).tbl)->num_items == 0)) {
    work_emptied = true;
    if (pwVar3 == (work *)0x0) goto LAB_00020618;
    do {
      cgtime(&now);
      then.tv_nsec = now.tv_usec * 1000;
      then.tv_sec = now.tv_sec + 10;
      pthread_cond_signal((pthread_cond_t *)&gws_cond);
      iVar4 = pthread_cond_timedwait
                        ((pthread_cond_t *)&getq->cond,(pthread_mutex_t *)stgd_lock,
                         (timespec *)&then);
      if (((iVar4 != 0) && (no_work == false)) &&
         ((no_work = true, use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))
          ))) {
        builtin_strncpy(tmp42,"Waiting for work to be available from pools.",0x2c);
        tmp42[0x2c] = '\0';
        _applog(4,tmp42,false);
      }
    } while ((staged_work == (work *)0x0) || (((staged_work->hh).tbl)->num_items == 0));
  }
  if (no_work != false) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      builtin_strncpy(tmp42,"Work available from pools, resuming.",0x24);
      tmp42._36_4_ = tmp42._36_4_ & 0xffffff00;
      _applog(4,tmp42,false);
    }
    no_work = false;
  }
  pwVar1 = staged_work;
  pUVar11 = pURam00000158;
  if (((staged_work == (work *)0x0) ||
      (pUVar11 = (staged_work->hh).tbl, (int)pUVar11->num_items <= staged_rollable)) ||
     ((staged_work->clone != false ||
      (pwVar12 = (work *)(staged_work->hh).next, staged_work->rolltime == 0)))) {
    pvVar6 = (staged_work->hh).prev;
    pwVar12 = (work *)(staged_work->hh).next;
    pwVar3 = staged_work;
    if (pvVar6 == (void *)0x0) goto LAB_000206b4;
LAB_00020586:
    iVar4 = pUVar11->hho;
    pwVar10 = (work *)((int)pUVar11->tail - iVar4);
    bVar13 = pwVar3 == pwVar10;
    if (bVar13) {
      pwVar10 = (work *)((int)pvVar6 + iVar4);
    }
    if (bVar13) {
      pUVar11->tail = (UT_hash_handle *)pwVar10;
    }
    pwVar10 = pwVar12;
    pwVar2 = pwVar12;
    if (pvVar6 != (void *)0x0) {
      *(work **)((int)pvVar6 + iVar4 + 8) = pwVar12;
      pwVar12 = (work *)(pwVar3->hh).next;
      pwVar10 = pwVar1;
      pwVar2 = staged_work;
    }
    staged_work = pwVar2;
    pUVar11 = (pwVar10->hh).tbl;
    if (pwVar12 != (work *)0x0) {
      *(void **)(pwVar12->data + pUVar11->hho + 4) = pvVar6;
    }
    pUVar5 = pUVar11->buckets;
    uVar7 = pUVar11->num_buckets - 1 & (pwVar3->hh).hashv;
    pUVar9 = (pwVar3->hh).hh_next;
    pUVar5[uVar7].count = pUVar5[uVar7].count - 1;
    if (pUVar5[uVar7].hh_head == &pwVar3->hh) {
      pUVar5[uVar7].hh_head = pUVar9;
    }
    pUVar8 = (pwVar3->hh).hh_prev;
    if (pUVar8 != (UT_hash_handle *)0x0) {
      pUVar8->hh_next = pUVar9;
      pUVar9 = (pwVar3->hh).hh_next;
    }
    if (pUVar9 != (UT_hash_handle *)0x0) {
      pUVar9->hh_prev = pUVar8;
    }
    pUVar11->num_items = pUVar11->num_items - 1;
  }
  else {
    do {
      pwVar3 = pwVar12;
      if ((pwVar3 == (work *)0x0) || (pwVar3->clone != false)) break;
      pwVar12 = (work *)(pwVar3->hh).next;
    } while (pwVar3->rolltime != 0);
    pvVar6 = (pwVar3->hh).prev;
    pwVar12 = (work *)(pwVar3->hh).next;
    if (pvVar6 != (void *)0x0) goto LAB_00020586;
LAB_000206b4:
    if (pwVar12 != (work *)0x0) goto LAB_00020586;
    free(pUVar11->buckets);
    free((staged_work->hh).tbl);
    staged_work = pwVar12;
  }
  if ((pwVar3->clone == false) && (pwVar3->rolltime != 0)) {
    staged_rollable = staged_rollable + -1;
  }
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  pthread_cond_signal((pthread_cond_t *)&getq->cond);
  last_getwork = time((time_t *)0x0);
LAB_00020618:
  iVar4 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
  if (iVar4 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"hash_pop",(char *)0x1fc0,func_00,line_00);
  }
  (*selective_yield)();
  return pwVar3;
}

