
void __work_completed(cgpu_info *cgpu,work *work)

{
  UT_hash_bucket *pUVar1;
  uint uVar2;
  UT_hash_table *pUVar3;
  work *work_local;
  cgpu_info *cgpu_local;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  
  cgpu->queued_count = cgpu->queued_count - 1;
  if (((work->hh).prev == (void *)0x0) && ((work->hh).next == (void *)0x0)) {
    free(((cgpu->queued_work->hh).tbl)->buckets);
    free((cgpu->queued_work->hh).tbl);
    cgpu->queued_work = (work *)0x0;
  }
  else {
    if ((work *)((int)((cgpu->queued_work->hh).tbl)->tail - ((cgpu->queued_work->hh).tbl)->hho) ==
        work) {
      ((cgpu->queued_work->hh).tbl)->tail =
           (UT_hash_handle *)((int)(work->hh).prev + ((cgpu->queued_work->hh).tbl)->hho);
    }
    if ((work->hh).prev == (void *)0x0) {
      cgpu->queued_work = (work *)(work->hh).next;
    }
    else {
      *(void **)((int)(work->hh).prev + ((cgpu->queued_work->hh).tbl)->hho + 8) = (work->hh).next;
    }
    if ((work->hh).next != (void *)0x0) {
      *(void **)((int)(work->hh).next + ((cgpu->queued_work->hh).tbl)->hho + 4) = (work->hh).prev;
    }
    uVar2 = ((cgpu->queued_work->hh).tbl)->num_buckets - 1 & (work->hh).hashv;
    pUVar1 = ((cgpu->queued_work->hh).tbl)->buckets;
    pUVar1[uVar2].count = pUVar1[uVar2].count - 1;
    if (((cgpu->queued_work->hh).tbl)->buckets[uVar2].hh_head == &work->hh) {
      ((cgpu->queued_work->hh).tbl)->buckets[uVar2].hh_head = (work->hh).hh_next;
    }
    if ((work->hh).hh_prev != (UT_hash_handle *)0x0) {
      ((work->hh).hh_prev)->hh_next = (work->hh).hh_next;
    }
    if ((work->hh).hh_next != (UT_hash_handle *)0x0) {
      ((work->hh).hh_next)->hh_prev = (work->hh).hh_prev;
    }
    pUVar3 = (cgpu->queued_work->hh).tbl;
    pUVar3->num_items = pUVar3->num_items - 1;
  }
  return;
}

