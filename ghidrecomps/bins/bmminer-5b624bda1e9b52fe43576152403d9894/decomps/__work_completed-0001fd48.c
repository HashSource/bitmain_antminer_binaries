
/* WARNING: Unknown calling convention */

void __work_completed(cgpu_info *cgpu,work *work)

{
  work *pwVar1;
  void *pvVar2;
  uint uVar3;
  UT_hash_handle *pUVar4;
  void *pvVar5;
  UT_hash_handle *pUVar6;
  UT_hash_table *pUVar7;
  UT_hash_bucket *pUVar8;
  work *pwVar9;
  UT_hash_handle *_hd_hh_del;
  work *pwVar10;
  bool bVar11;
  
  pvVar5 = (work->hh).prev;
  pwVar9 = (work *)(work->hh).next;
  cgpu->queued_count = cgpu->queued_count - 1;
  if ((pvVar5 == (void *)0x0) && (pwVar9 == (work *)0x0)) {
    free(((cgpu->queued_work->hh).tbl)->buckets);
    free((cgpu->queued_work->hh).tbl);
    cgpu->queued_work = (work *)0x0;
    return;
  }
  pwVar1 = cgpu->queued_work;
  pUVar7 = (pwVar1->hh).tbl;
  pwVar10 = (work *)((int)pUVar7->tail - pUVar7->hho);
  bVar11 = work == pwVar10;
  if (bVar11) {
    pwVar10 = (work *)((int)pvVar5 + pUVar7->hho);
  }
  if (bVar11) {
    pUVar7->tail = (UT_hash_handle *)pwVar10;
  }
  if (pvVar5 == (void *)0x0) {
    cgpu->queued_work = pwVar9;
  }
  else {
    *(work **)((int)pvVar5 + pUVar7->hho + 8) = pwVar9;
    pwVar9 = pwVar1;
  }
  pvVar2 = (work->hh).next;
  pUVar7 = (pwVar9->hh).tbl;
  if (pvVar2 != (void *)0x0) {
    *(void **)((int)pvVar2 + pUVar7->hho + 4) = pvVar5;
  }
  pUVar8 = pUVar7->buckets;
  uVar3 = pUVar7->num_buckets - 1 & (work->hh).hashv;
  pUVar8[uVar3].count = pUVar8[uVar3].count - 1;
  pUVar6 = (work->hh).hh_next;
  if (pUVar8[uVar3].hh_head == &work->hh) {
    pUVar8[uVar3].hh_head = pUVar6;
  }
  pUVar4 = (work->hh).hh_prev;
  if (pUVar4 != (UT_hash_handle *)0x0) {
    pUVar4->hh_next = pUVar6;
    pUVar6 = (work->hh).hh_next;
  }
  if (pUVar6 != (UT_hash_handle *)0x0) {
    pUVar6->hh_prev = pUVar4;
  }
  pUVar7->num_items = pUVar7->num_items - 1;
  return;
}

