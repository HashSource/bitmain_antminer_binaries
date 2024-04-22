
/* WARNING: Unknown calling convention */

void discard_stale(void)

{
  _Bool _Var1;
  UT_hash_bucket *pUVar2;
  UT_hash_table *pUVar3;
  char tmp42 [2048];
  work *work;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  int stale;
  work *tmp;
  
  stale = 0;
  _mutex_lock(stgd_lock,"cgminer.c","discard_stale",0x14ef);
  work = staged_work;
  if (staged_work == (work *)0x0) {
    tmp = (work *)0x0;
  }
  else {
    tmp = (work *)(staged_work->hh).next;
  }
  while (work != (work *)0x0) {
    _Var1 = stale_work(work,false);
    if (_Var1) {
      if (((work->hh).prev == (void *)0x0) && ((work->hh).next == (void *)0x0)) {
        free(((staged_work->hh).tbl)->buckets);
        free((staged_work->hh).tbl);
        staged_work = (work *)0x0;
      }
      else {
        _hd_hh_del = &work->hh;
        if ((work *)((int)((staged_work->hh).tbl)->tail - ((staged_work->hh).tbl)->hho) == work) {
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
        _hd_bkt = ((staged_work->hh).tbl)->num_buckets - 1 & (work->hh).hashv;
        pUVar2 = ((staged_work->hh).tbl)->buckets;
        pUVar2[_hd_bkt].count = pUVar2[_hd_bkt].count - 1;
        if (_hd_hh_del == ((staged_work->hh).tbl)->buckets[_hd_bkt].hh_head) {
          ((staged_work->hh).tbl)->buckets[_hd_bkt].hh_head = (work->hh).hh_next;
        }
        if ((work->hh).hh_prev != (UT_hash_handle *)0x0) {
          ((work->hh).hh_prev)->hh_next = (work->hh).hh_next;
        }
        if ((work->hh).hh_next != (UT_hash_handle *)0x0) {
          ((work->hh).hh_next)->hh_prev = (work->hh).hh_prev;
        }
        pUVar3 = (staged_work->hh).tbl;
        pUVar3->num_items = pUVar3->num_items - 1;
      }
      _discard_work(&work,"cgminer.c","discard_stale",0x14f6);
      stale = stale + 1;
    }
    work = tmp;
    if (tmp == (work *)0x0) {
      tmp = (work *)0x0;
    }
    else {
      tmp = (work *)(tmp->hh).next;
    }
  }
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  _mutex_unlock(stgd_lock,"cgminer.c","discard_stale",0x14fc);
  if (((stale != 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"Discarded %d stales that didn\'t match current hash",stale);
    _applog(7,tmp42,false);
  }
  return;
}

