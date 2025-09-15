
work * hash_pop(_Bool blocking)

{
  _Bool _Var1;
  int iVar2;
  UT_hash_bucket *pUVar3;
  uint uVar4;
  UT_hash_table *pUVar5;
  _Bool blocking_local;
  char tmp42 [2048];
  timeval now;
  timespec then;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  int hc;
  int rc;
  work *tmp;
  work *work;
  
  work = (work *)0x0;
  _mutex_lock(stgd_lock,"cgminer.c","hash_pop",0x1fd1);
  if ((staged_work == (work *)0x0) || (((staged_work->hh).tbl)->num_items == 0)) {
    work_emptied = true;
    if (!blocking) goto LAB_00056f2a;
    do {
      cgtime(&now);
      then.tv_sec = now.tv_sec + 10;
      then.tv_nsec = now.tv_usec * 1000;
      pthread_cond_signal((pthread_cond_t *)&gws_cond);
      iVar2 = pthread_cond_timedwait
                        ((pthread_cond_t *)&getq->cond,(pthread_mutex_t *)stgd_lock,
                         (timespec *)&then);
      if (((iVar2 != 0) && (no_work != true)) &&
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
  if (staged_work == (work *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = ((staged_work->hh).tbl)->num_items;
  }
  if (staged_rollable < (int)uVar4) {
    work = staged_work;
    if (staged_work == (work *)0x0) {
      tmp = (work *)0x0;
    }
    else {
      tmp = (work *)(staged_work->hh).next;
    }
    while ((work != (work *)0x0 && (_Var1 = work_rollable(work), _Var1))) {
      work = tmp;
      if (tmp == (work *)0x0) {
        tmp = (work *)0x0;
      }
      else {
        tmp = (work *)(tmp->hh).next;
      }
    }
  }
  else {
    work = staged_work;
  }
  if (((work->hh).prev == (void *)0x0) && ((work->hh).next == (void *)0x0)) {
    free(((staged_work->hh).tbl)->buckets);
    free((staged_work->hh).tbl);
    staged_work = (work *)0x0;
  }
  else {
    if (work == (work *)((int)((staged_work->hh).tbl)->tail - ((staged_work->hh).tbl)->hho)) {
      ((staged_work->hh).tbl)->tail =
           (UT_hash_handle *)((int)(work->hh).prev + ((staged_work->hh).tbl)->hho);
    }
    if ((work->hh).prev == (void *)0x0) {
      staged_work = (work *)(work->hh).next;
    }
    else {
      *(void **)((int)(work->hh).prev + ((staged_work->hh).tbl)->hho + 8) = (work->hh).next;
    }
    if ((work->hh).next != (void *)0x0) {
      *(void **)((int)(work->hh).next + ((staged_work->hh).tbl)->hho + 4) = (work->hh).prev;
    }
    uVar4 = ((staged_work->hh).tbl)->num_buckets - 1 & (work->hh).hashv;
    pUVar3 = ((staged_work->hh).tbl)->buckets;
    pUVar3[uVar4].count = pUVar3[uVar4].count - 1;
    if (&work->hh == ((staged_work->hh).tbl)->buckets[uVar4].hh_head) {
      ((staged_work->hh).tbl)->buckets[uVar4].hh_head = (work->hh).hh_next;
    }
    if ((work->hh).hh_prev != (UT_hash_handle *)0x0) {
      ((work->hh).hh_prev)->hh_next = (work->hh).hh_next;
    }
    if ((work->hh).hh_next != (UT_hash_handle *)0x0) {
      ((work->hh).hh_next)->hh_prev = (work->hh).hh_prev;
    }
    pUVar5 = (staged_work->hh).tbl;
    pUVar5->num_items = pUVar5->num_items - 1;
  }
  _Var1 = work_rollable(work);
  if (_Var1) {
    staged_rollable = staged_rollable + -1;
  }
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  pthread_cond_signal((pthread_cond_t *)&getq->cond);
  last_getwork = time((time_t *)0x0);
LAB_00056f2a:
  _mutex_unlock(stgd_lock,"cgminer.c","hash_pop",0x2019);
  return work;
}

