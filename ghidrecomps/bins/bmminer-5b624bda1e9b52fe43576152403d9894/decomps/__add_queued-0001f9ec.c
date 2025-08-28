
/* WARNING: Unknown calling convention */

void __add_queued(cgpu_info *cgpu,work *work)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  UT_hash_handle *pUVar5;
  uint uVar6;
  UT_hash_bucket *pUVar7;
  uint uVar8;
  UT_hash_table *pUVar9;
  UT_hash_handle *pUVar10;
  uint uVar11;
  size_t __size;
  uint uVar12;
  uint uVar13;
  work *pwVar14;
  UT_hash_handle *pUVar15;
  int local_34;
  UT_hash_bucket *local_30;
  
  cgpu->queued_count = cgpu->queued_count + 1;
  uVar6 = work->id;
  bVar1 = *(byte *)((int)&work->id + 3);
  bVar2 = *(byte *)((int)&work->id + 2);
  bVar3 = *(byte *)((int)&work->id + 1);
  pwVar14 = cgpu->queued_work;
  (work->hh).key = &work->id;
  (work->hh).keylen = 4;
  uVar8 = (byte)uVar6 + 0x112410d + (uint)bVar1 * 0x1000000 + (uint)bVar2 * 0x10000 +
          (uint)bVar3 * 0x100 ^ 0x7f76d;
  uVar6 = 0x9f49bac6 - uVar8 ^ uVar8 << 8;
  uVar12 = (-0x112410d - uVar8) - uVar6 ^ uVar6 >> 0xd;
  uVar11 = (uVar8 - uVar6) - uVar12 ^ uVar12 >> 0xc;
  uVar8 = (uVar6 - uVar12) - uVar11 ^ uVar11 << 0x10;
  uVar12 = (uVar12 - uVar11) - uVar8 ^ uVar8 >> 5;
  uVar6 = (uVar11 - uVar8) - uVar12 ^ uVar12 >> 3;
  uVar8 = (uVar8 - uVar12) - uVar6 ^ uVar6 << 10;
  uVar6 = (uVar12 - uVar6) - uVar8 ^ uVar8 >> 0xf;
  (work->hh).hashv = uVar6;
  if (pwVar14 == (work *)0x0) {
    (work->hh).next = (void *)0x0;
    (work->hh).prev = (void *)0x0;
    cgpu->queued_work = work;
    pUVar9 = (UT_hash_table *)malloc(0x2c);
    (work->hh).tbl = pUVar9;
    if (pUVar9 == (UT_hash_table *)0x0) goto LAB_0001fccc;
    pwVar14 = cgpu->queued_work;
    pUVar9->buckets = (UT_hash_bucket *)0x0;
    pUVar9->num_buckets = 0;
    pUVar9->log2_num_buckets = 0;
    pUVar9->num_items = 0;
    pUVar9->tail = (UT_hash_handle *)0x0;
    pUVar9->hho = 0;
    pUVar9->ideal_chain_maxlen = 0;
    pUVar9->nonideal_items = 0;
    pUVar9->ineff_expands = 0;
    pUVar9->noexpand = 0;
    pUVar9->signature = 0;
    pUVar9 = (pwVar14->hh).tbl;
    pUVar9->tail = &pwVar14->hh;
    pUVar9->num_buckets = 0x20;
    pUVar9->log2_num_buckets = 5;
    pUVar9->hho = 0x158;
    pUVar7 = (UT_hash_bucket *)malloc(0x180);
    pUVar9->buckets = pUVar7;
    if (pUVar7 == (UT_hash_bucket *)0x0) goto LAB_0001fccc;
    memset(pUVar7,0,0x180);
    pUVar9 = (cgpu->queued_work->hh).tbl;
    pUVar9->signature = 0xa0111fe1;
  }
  else {
    pUVar9 = (pwVar14->hh).tbl;
    (work->hh).next = (void *)0x0;
    (work->hh).tbl = pUVar9;
    pUVar9 = (pwVar14->hh).tbl;
    pUVar5 = pUVar9->tail;
    iVar4 = pUVar9->hho;
    pUVar5->next = work;
    (work->hh).prev = (void *)((int)pUVar5 - iVar4);
    pUVar9->tail = &work->hh;
  }
  pUVar7 = pUVar9->buckets;
  uVar6 = uVar6 & pUVar9->num_buckets - 1;
  pUVar9->num_items = pUVar9->num_items + 1;
  pUVar5 = pUVar7[uVar6].hh_head;
  uVar8 = pUVar7[uVar6].count + 1;
  pUVar7[uVar6].count = uVar8;
  (work->hh).hh_next = pUVar5;
  (work->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar5 != (UT_hash_handle *)0x0) {
    pUVar5->hh_prev = &work->hh;
  }
  pUVar7[uVar6].hh_head = &work->hh;
  if (((pUVar7[uVar6].expand_mult + 1) * 10 <= uVar8) &&
     (pUVar9 = (work->hh).tbl, pUVar9->noexpand != 1)) {
    __size = pUVar9->num_buckets * 0x18;
    pUVar7 = (UT_hash_bucket *)malloc(__size);
    if (pUVar7 == (UT_hash_bucket *)0x0) {
LAB_0001fccc:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar7,0,__size);
    pUVar9 = (work->hh).tbl;
    uVar6 = pUVar9->num_buckets;
    pUVar9->nonideal_items = 0;
    uVar8 = pUVar9->num_items >> (pUVar9->log2_num_buckets + 1 & 0xff);
    uVar12 = uVar6 * 2 - 1;
    if ((uVar12 & pUVar9->num_items) != 0) {
      uVar8 = uVar8 + 1;
    }
    pUVar9->ideal_chain_maxlen = uVar8;
    if (uVar6 == 0) {
      local_30 = pUVar9->buckets;
    }
    else {
      local_30 = pUVar9->buckets;
      local_34 = 0;
      do {
        pUVar5 = *(UT_hash_handle **)((int)&local_30->hh_head + local_34);
        while (pUVar5 != (UT_hash_handle *)0x0) {
          pUVar15 = pUVar5->hh_next;
          uVar13 = uVar12 & pUVar5->hashv;
          uVar11 = pUVar7[uVar13].count + 1;
          pUVar7[uVar13].count = uVar11;
          if (uVar8 < uVar11) {
            pUVar9->nonideal_items = pUVar9->nonideal_items + 1;
            uVar11 = __aeabi_uidiv(uVar11,uVar8);
            pUVar7[uVar13].expand_mult = uVar11;
          }
          pUVar10 = pUVar7[uVar13].hh_head;
          pUVar5->hh_prev = (UT_hash_handle *)0x0;
          pUVar5->hh_next = pUVar10;
          if (pUVar10 != (UT_hash_handle *)0x0) {
            pUVar10->hh_prev = pUVar5;
          }
          pUVar7[uVar13].hh_head = pUVar5;
          pUVar5 = pUVar15;
        }
        local_34 = local_34 + 0xc;
      } while (local_34 != uVar6 * 0xc);
    }
    free(local_30);
    pUVar9 = (work->hh).tbl;
    uVar12 = pUVar9->nonideal_items;
    pUVar9->buckets = pUVar7;
    uVar6 = pUVar9->num_items >> 1;
    uVar8 = uVar12;
    if (uVar12 <= uVar6) {
      uVar8 = 0;
    }
    pUVar9->log2_num_buckets = pUVar9->log2_num_buckets + 1;
    pUVar9->num_buckets = pUVar9->num_buckets << 1;
    if (uVar6 < uVar12) {
      uVar8 = pUVar9->ineff_expands + 1;
      pUVar9->ineff_expands = uVar8;
      uVar6 = uVar8;
      if (1 < uVar8) {
        uVar6 = 1;
      }
      if (1 < uVar8) {
        pUVar9->noexpand = uVar6;
      }
    }
    else {
      pUVar9->ineff_expands = uVar8;
    }
  }
  return;
}

