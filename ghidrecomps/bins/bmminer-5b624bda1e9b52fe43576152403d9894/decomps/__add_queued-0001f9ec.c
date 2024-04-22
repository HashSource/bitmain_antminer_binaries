
/* WARNING: Unknown calling convention */

void __add_queued(cgpu_info *cgpu,work *work)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  UT_hash_bucket *_he_new_buckets;
  UT_hash_handle *pUVar6;
  uint uVar7;
  UT_hash_bucket *pUVar8;
  uint uVar9;
  UT_hash_table *pUVar10;
  UT_hash_handle *pUVar11;
  uint uVar12;
  size_t __size;
  UT_hash_handle *_he_thh;
  uint uVar13;
  uint uVar14;
  UT_hash_bucket *_he_newbkt;
  work *pwVar15;
  UT_hash_handle *pUVar16;
  UT_hash_handle *_he_hh_nxt;
  int local_34;
  UT_hash_bucket *local_30;
  
  cgpu->queued_count = cgpu->queued_count + 1;
  bVar1 = *(byte *)&work->id;
  bVar2 = *(byte *)((int)&work->id + 3);
  bVar3 = *(byte *)((int)&work->id + 2);
  bVar4 = *(byte *)((int)&work->id + 1);
  pwVar15 = cgpu->queued_work;
  (work->hh).key = &work->id;
  (work->hh).keylen = 4;
  uVar9 = bVar1 + 0x112410d + (uint)bVar2 * 0x1000000 + (uint)bVar3 * 0x10000 + (uint)bVar4 * 0x100
          ^ 0x7f76d;
  uVar7 = 0x9f49bac6 - uVar9 ^ uVar9 << 8;
  uVar13 = (-0x112410d - uVar9) - uVar7 ^ uVar7 >> 0xd;
  uVar12 = (uVar9 - uVar7) - uVar13 ^ uVar13 >> 0xc;
  uVar9 = (uVar7 - uVar13) - uVar12 ^ uVar12 << 0x10;
  uVar13 = (uVar13 - uVar12) - uVar9 ^ uVar9 >> 5;
  uVar7 = (uVar12 - uVar9) - uVar13 ^ uVar13 >> 3;
  uVar9 = (uVar9 - uVar13) - uVar7 ^ uVar7 << 10;
  uVar7 = (uVar13 - uVar7) - uVar9 ^ uVar9 >> 0xf;
  (work->hh).hashv = uVar7;
  if (pwVar15 == (work *)0x0) {
    (work->hh).next = (void *)0x0;
    (work->hh).prev = (void *)0x0;
    cgpu->queued_work = work;
    pUVar10 = (UT_hash_table *)malloc(0x2c);
    (work->hh).tbl = pUVar10;
    if (pUVar10 == (UT_hash_table *)0x0) goto LAB_0001fccc;
    pwVar15 = cgpu->queued_work;
    pUVar10->buckets = (UT_hash_bucket *)0x0;
    pUVar10->num_buckets = 0;
    pUVar10->log2_num_buckets = 0;
    pUVar10->num_items = 0;
    pUVar10->tail = (UT_hash_handle *)0x0;
    pUVar10->hho = 0;
    pUVar10->ideal_chain_maxlen = 0;
    pUVar10->nonideal_items = 0;
    pUVar10->ineff_expands = 0;
    pUVar10->noexpand = 0;
    pUVar10->signature = 0;
    pUVar10 = (pwVar15->hh).tbl;
    pUVar10->tail = &pwVar15->hh;
    pUVar10->num_buckets = 0x20;
    pUVar10->log2_num_buckets = 5;
    pUVar10->hho = 0x158;
    pUVar8 = (UT_hash_bucket *)malloc(0x180);
    pUVar10->buckets = pUVar8;
    if (pUVar8 == (UT_hash_bucket *)0x0) goto LAB_0001fccc;
    memset(pUVar8,0,0x180);
    pUVar10 = (cgpu->queued_work->hh).tbl;
    pUVar10->signature = 0xa0111fe1;
  }
  else {
    pUVar10 = (pwVar15->hh).tbl;
    (work->hh).next = (void *)0x0;
    (work->hh).tbl = pUVar10;
    pUVar10 = (pwVar15->hh).tbl;
    pUVar6 = pUVar10->tail;
    iVar5 = pUVar10->hho;
    pUVar6->next = work;
    (work->hh).prev = (void *)((int)pUVar6 - iVar5);
    pUVar10->tail = &work->hh;
  }
  pUVar8 = pUVar10->buckets;
  uVar7 = uVar7 & pUVar10->num_buckets - 1;
  pUVar10->num_items = pUVar10->num_items + 1;
  pUVar6 = pUVar8[uVar7].hh_head;
  uVar9 = pUVar8[uVar7].count + 1;
  pUVar8[uVar7].count = uVar9;
  (work->hh).hh_next = pUVar6;
  (work->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar6 != (UT_hash_handle *)0x0) {
    pUVar6->hh_prev = &work->hh;
  }
  pUVar8[uVar7].hh_head = &work->hh;
  if (((pUVar8[uVar7].expand_mult + 1) * 10 <= uVar9) &&
     (pUVar10 = (work->hh).tbl, pUVar10->noexpand != 1)) {
    __size = pUVar10->num_buckets * 0x18;
    pUVar8 = (UT_hash_bucket *)malloc(__size);
    if (pUVar8 == (UT_hash_bucket *)0x0) {
LAB_0001fccc:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar8,0,__size);
    pUVar10 = (work->hh).tbl;
    uVar7 = pUVar10->num_buckets;
    pUVar10->nonideal_items = 0;
    uVar9 = pUVar10->num_items >> (pUVar10->log2_num_buckets + 1 & 0xff);
    uVar13 = uVar7 * 2 - 1;
    if ((uVar13 & pUVar10->num_items) != 0) {
      uVar9 = uVar9 + 1;
    }
    pUVar10->ideal_chain_maxlen = uVar9;
    if (uVar7 == 0) {
      local_30 = pUVar10->buckets;
    }
    else {
      local_30 = pUVar10->buckets;
      local_34 = 0;
      do {
        pUVar6 = *(UT_hash_handle **)((int)&local_30->hh_head + local_34);
        while (pUVar6 != (UT_hash_handle *)0x0) {
          pUVar16 = pUVar6->hh_next;
          uVar14 = uVar13 & pUVar6->hashv;
          uVar12 = pUVar8[uVar14].count + 1;
          pUVar8[uVar14].count = uVar12;
          if (uVar9 < uVar12) {
            pUVar10->nonideal_items = pUVar10->nonideal_items + 1;
            uVar12 = __aeabi_uidiv(uVar12,uVar9);
            pUVar8[uVar14].expand_mult = uVar12;
          }
          pUVar11 = pUVar8[uVar14].hh_head;
          pUVar6->hh_prev = (UT_hash_handle *)0x0;
          pUVar6->hh_next = pUVar11;
          if (pUVar11 != (UT_hash_handle *)0x0) {
            pUVar11->hh_prev = pUVar6;
          }
          pUVar8[uVar14].hh_head = pUVar6;
          pUVar6 = pUVar16;
        }
        local_34 = local_34 + 0xc;
      } while (local_34 != uVar7 * 0xc);
    }
    free(local_30);
    pUVar10 = (work->hh).tbl;
    uVar13 = pUVar10->nonideal_items;
    pUVar10->buckets = pUVar8;
    uVar7 = pUVar10->num_items >> 1;
    uVar9 = uVar13;
    if (uVar13 <= uVar7) {
      uVar9 = 0;
    }
    pUVar10->log2_num_buckets = pUVar10->log2_num_buckets + 1;
    pUVar10->num_buckets = pUVar10->num_buckets << 1;
    if (uVar7 < uVar13) {
      uVar9 = pUVar10->ineff_expands + 1;
      pUVar10->ineff_expands = uVar9;
      uVar7 = uVar9;
      if (1 < uVar9) {
        uVar7 = 1;
      }
      if (1 < uVar9) {
        pUVar10->noexpand = uVar7;
      }
    }
    else {
      pUVar10->ineff_expands = uVar9;
    }
  }
  return;
}

