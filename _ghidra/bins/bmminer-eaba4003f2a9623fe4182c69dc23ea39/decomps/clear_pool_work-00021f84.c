
void clear_pool_work(pool *pool)

{
  UT_hash_bucket *pUVar1;
  UT_hash_table *pUVar2;
  pool *pool_local;
  char tmp42 [2048];
  work *work;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  int cleared;
  work *tmp;
  
  cleared = 0;
  _mutex_lock(stgd_lock,"cgminer.c","clear_pool_work",0x1c7b);
  work = staged_work;
  if (staged_work == (work *)0x0) {
    tmp = (work *)0x0;
  }
  else {
    tmp = (work *)(staged_work->hh).next;
  }
  while (work != (work *)0x0) {
    if (work->pool == pool) {
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
        pUVar1 = ((staged_work->hh).tbl)->buckets;
        pUVar1[_hd_bkt].count = pUVar1[_hd_bkt].count - 1;
        if (((staged_work->hh).tbl)->buckets[_hd_bkt].hh_head == _hd_hh_del) {
          ((staged_work->hh).tbl)->buckets[_hd_bkt].hh_head = (work->hh).hh_next;
        }
        if ((work->hh).hh_prev != (UT_hash_handle *)0x0) {
          ((work->hh).hh_prev)->hh_next = (work->hh).hh_next;
        }
        if ((work->hh).hh_next != (UT_hash_handle *)0x0) {
          ((work->hh).hh_next)->hh_prev = (work->hh).hh_prev;
        }
        pUVar2 = (staged_work->hh).tbl;
        pUVar2->num_items = pUVar2->num_items - 1;
      }
      _free_work(&work,"cgminer.c","clear_pool_work",0x1c81);
      cleared = cleared + 1;
    }
    work = tmp;
    if (tmp == (work *)0x0) {
      tmp = (work *)0x0;
    }
    else {
      tmp = (work *)(tmp->hh).next;
    }
  }
  _mutex_unlock(stgd_lock,"cgminer.c","clear_pool_work",0x1c85);
  if ((cleared != 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Cleared %d work items due to stratum disconnect on pool %d",cleared,
             pool->pool_no);
    _applog(6,tmp42,false);
  }
  return;
}

