
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void _stage_work(work *work)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  pthread_mutex_t *__mutex;
  int iVar5;
  uint uVar6;
  UT_hash_handle *pUVar7;
  UT_hash_bucket *pUVar8;
  UT_hash_bucket *_he_new_buckets;
  thread_q *ptVar9;
  UT_hash_handle *pUVar10;
  UT_hash_handle *_hs_e;
  JE **func;
  uint uVar11;
  JE **ppJVar12;
  UT_hash_handle *pUVar13;
  pool *line;
  uint uVar14;
  uint uVar15;
  UT_hash_table *pUVar16;
  UT_hash_handle *pUVar17;
  UT_hash_handle *pUVar18;
  void *pvVar19;
  size_t __size;
  UT_hash_handle *_he_thh;
  UT_hash_handle *_hs_q;
  work *pwVar20;
  uint uVar21;
  UT_hash_handle *pUVar22;
  UT_hash_bucket *_he_newbkt;
  uint _hs_qsize;
  UT_hash_handle *pUVar23;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_handle *pUVar24;
  UT_hash_handle *_hs_p;
  int local_838;
  UT_hash_bucket *local_834;
  char tmp42 [2048];
  
  if ((*DAT_00025b7c != '\0') &&
     (((*DAT_00025b80 != '\0' || (*DAT_00025b84 != '\0')) || (6 < *DAT_00025b88)))) {
    snprintf(tmp42,0x800,DAT_00025b8c,work->pool->pool_no);
    _applog(7,tmp42,false);
  }
  work->work_block = work_block;
  test_work_current(work);
  __mutex = stgd_lock;
  line = work->pool;
  func = (JE **)(line->works + 1);
  line->works = (int)func;
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)__mutex);
  if (iVar5 != 0) {
    _mutex_lock(DAT_00025df4,(char *)0x1628,(char *)func,(int)line);
  }
  iVar5 = DAT_00025b90;
  if ((work->clone == false) && (work->rolltime != 0)) {
    staged_rollable = staged_rollable + 1;
  }
  ptVar9 = getq;
  if (getq->frozen != false) {
LAB_00025c54:
    pthread_cond_broadcast((pthread_cond_t *)&ptVar9->cond);
    ppJVar12 = &jedata;
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
    if (iVar5 != 0) {
      _mutex_unlock_noyield(DAT_00025df4,(char *)0x163a,(char *)func,(int)ppJVar12);
    }
    (**DAT_00025df0)();
    return;
  }
  bVar1 = *(byte *)&work->id;
  bVar2 = *(byte *)((int)&work->id + 3);
  bVar3 = *(byte *)((int)&work->id + 2);
  bVar4 = *(byte *)((int)&work->id + 1);
  (work->hh).keylen = 4;
  pwVar20 = staged_work;
  uVar14 = bVar1 + 0x112410d + (uint)bVar2 * 0x1000000 + (uint)bVar3 * 0x10000 + (uint)bVar4 * 0x100
           ^ 0x7f76d;
  uVar11 = 0x9f49bac6 - uVar14 ^ uVar14 << 8;
  (work->hh).key = &work->id;
  uVar6 = (-0x112410d - uVar14) - uVar11 ^ uVar11 >> 0xd;
  uVar14 = (uVar14 - uVar11) - uVar6 ^ uVar6 >> 0xc;
  uVar11 = (uVar11 - uVar6) - uVar14 ^ uVar14 << 0x10;
  uVar15 = (uVar6 - uVar14) - uVar11 ^ uVar11 >> 5;
  uVar6 = (uVar14 - uVar11) - uVar15 ^ uVar15 >> 3;
  uVar14 = (uVar11 - uVar15) - uVar6 ^ uVar6 << 10;
  uVar6 = (uVar15 - uVar6) - uVar14 ^ uVar14 >> 0xf;
  (work->hh).hashv = uVar6;
  if (pwVar20 == (work *)0x0) {
    (work->hh).next = (void *)0x0;
    (work->hh).prev = (void *)0x0;
    *(work **)(iVar5 + 0x458) = work;
    pUVar16 = (UT_hash_table *)malloc(0x2c);
    (work->hh).tbl = pUVar16;
    if (pUVar16 == (UT_hash_table *)0x0) goto LAB_00025dc8;
    pUVar16->buckets = (UT_hash_bucket *)0x0;
    pUVar16->num_items = 0;
    pUVar16->tail = (UT_hash_handle *)0x0;
    pUVar16->hho = 0;
    pUVar16->ideal_chain_maxlen = 0;
    pUVar16->nonideal_items = 0;
    pUVar16->ineff_expands = 0;
    pUVar16->noexpand = 0;
    pUVar16->signature = 0;
    pUVar16->tail = &work->hh;
    pUVar16->num_buckets = 0x20;
    pUVar16->log2_num_buckets = 5;
    pUVar16->hho = 0x158;
    pUVar8 = (UT_hash_bucket *)malloc(0x180);
    pUVar16->buckets = pUVar8;
    if (pUVar8 == (UT_hash_bucket *)0x0) goto LAB_00025dc8;
    memset(pUVar8,0,0x180);
    pwVar20 = *(work **)(iVar5 + 0x458);
    pUVar16 = (pwVar20->hh).tbl;
    pUVar16->signature = 0xa0111fe1;
  }
  else {
    pUVar16 = (pwVar20->hh).tbl;
    (work->hh).next = (void *)0x0;
    (work->hh).tbl = pUVar16;
    pUVar16 = (pwVar20->hh).tbl;
    pUVar7 = pUVar16->tail;
    iVar5 = pUVar16->hho;
    pUVar7->next = work;
    (work->hh).prev = (void *)((int)pUVar7 - iVar5);
    pUVar16->tail = &work->hh;
  }
  pUVar8 = pUVar16->buckets;
  uVar6 = uVar6 & pUVar16->num_buckets - 1;
  pUVar16->num_items = pUVar16->num_items + 1;
  pUVar7 = pUVar8[uVar6].hh_head;
  uVar14 = pUVar8[uVar6].count + 1;
  pUVar8[uVar6].count = uVar14;
  (work->hh).hh_next = pUVar7;
  (work->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar7 != (UT_hash_handle *)0x0) {
    pUVar7->hh_prev = &work->hh;
  }
  pUVar8[uVar6].hh_head = &work->hh;
  if (((pUVar8[uVar6].expand_mult + 1) * 10 <= uVar14) &&
     (pUVar16 = (work->hh).tbl, pUVar16->noexpand != 1)) {
    __size = pUVar16->num_buckets * 0x18;
    pUVar8 = (UT_hash_bucket *)malloc(__size);
    if (pUVar8 == (UT_hash_bucket *)0x0) {
LAB_00025dc8:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar8,0,__size);
    pUVar16 = (work->hh).tbl;
    uVar14 = pUVar16->num_buckets;
    pUVar16->nonideal_items = 0;
    uVar6 = pUVar16->num_items >> (pUVar16->log2_num_buckets + 1 & 0xff);
    uVar11 = uVar14 * 2 - 1;
    if ((uVar11 & pUVar16->num_items) != 0) {
      uVar6 = uVar6 + 1;
    }
    pUVar16->ideal_chain_maxlen = uVar6;
    if (uVar14 == 0) {
      local_834 = pUVar16->buckets;
    }
    else {
      local_834 = pUVar16->buckets;
      local_838 = 0;
      do {
        pUVar7 = *(UT_hash_handle **)((int)&local_834->hh_head + local_838);
        while (pUVar7 != (UT_hash_handle *)0x0) {
          pUVar23 = pUVar7->hh_next;
          uVar21 = uVar11 & pUVar7->hashv;
          uVar15 = pUVar8[uVar21].count + 1;
          pUVar8[uVar21].count = uVar15;
          if (uVar6 < uVar15) {
            pUVar16->nonideal_items = pUVar16->nonideal_items + 1;
            uVar15 = __aeabi_uidiv(uVar15,uVar6);
            pUVar8[uVar21].expand_mult = uVar15;
          }
          pUVar17 = pUVar8[uVar21].hh_head;
          pUVar7->hh_prev = (UT_hash_handle *)0x0;
          pUVar7->hh_next = pUVar17;
          if (pUVar17 != (UT_hash_handle *)0x0) {
            pUVar17->hh_prev = pUVar7;
          }
          pUVar8[uVar21].hh_head = pUVar7;
          pUVar7 = pUVar23;
        }
        local_838 = local_838 + 0xc;
      } while (local_838 != uVar14 * 0xc);
    }
    free(local_834);
    pUVar16 = (work->hh).tbl;
    pUVar16->buckets = pUVar8;
    pUVar16->log2_num_buckets = pUVar16->log2_num_buckets + 1;
    pUVar16->num_buckets = pUVar16->num_buckets << 1;
    if (pUVar16->num_items >> 1 < pUVar16->nonideal_items) {
      ppJVar12 = (JE **)(pUVar16->ineff_expands + 1);
      pUVar16->ineff_expands = (uint)ppJVar12;
      pwVar20 = staged_work;
      func = ppJVar12;
      if ((JE **)0x1 < ppJVar12) {
        func = (JE **)0x1;
      }
      if ((JE **)0x1 < ppJVar12) {
        pUVar16->noexpand = (uint)func;
      }
    }
    else {
      func = (JE **)0x0;
      pUVar16->ineff_expands = 0;
      pwVar20 = staged_work;
    }
    ptVar9 = getq;
    if (pwVar20 == (work *)0x0) goto LAB_00025c54;
  }
  pUVar16 = (pwVar20->hh).tbl;
  pUVar7 = &pwVar20->hh;
  pUVar23 = (UT_hash_handle *)0x1;
LAB_00025b9e:
  pUVar22 = (UT_hash_handle *)0x0;
  uVar6 = 0;
  pUVar17 = pUVar7;
  pUVar7 = (UT_hash_handle *)0x0;
LAB_00025ba8:
  uVar6 = uVar6 + 1;
  _hs_qsize = (uint)pUVar23;
  if (pUVar23 == (UT_hash_handle *)0x0) {
    pUVar13 = (UT_hash_handle *)0x0;
    pUVar18 = pUVar17;
  }
  else {
    pUVar18 = (UT_hash_handle *)pUVar17->next;
    pUVar13 = (UT_hash_handle *)0x1;
    if (pUVar18 != (UT_hash_handle *)0x0) {
      pUVar13 = (UT_hash_handle *)0x1;
      pUVar18 = (UT_hash_handle *)((int)&pUVar18->tbl + pUVar16->hho);
      if (pUVar18 != (UT_hash_handle *)0x0) {
        while (pUVar13 != pUVar23) {
          pUVar18 = (UT_hash_handle *)pUVar18->next;
          pUVar13 = (UT_hash_handle *)((int)&pUVar13->tbl + 1);
          if ((pUVar18 == (UT_hash_handle *)0x0) ||
             (pUVar18 = (UT_hash_handle *)((int)&pUVar18->tbl + pUVar16->hho),
             pUVar18 == (UT_hash_handle *)0x0)) break;
        }
      }
    }
  }
LAB_00025bd8:
  do {
    pUVar10 = pUVar17;
    if (pUVar13 == (UT_hash_handle *)0x0) goto LAB_00025c16;
LAB_00025bda:
    pUVar17 = pUVar10;
    if (_hs_qsize == 0 || pUVar18 == (UT_hash_handle *)0x0) {
      if ((pUVar10 != (UT_hash_handle *)0x0) &&
         (pUVar17 = (UT_hash_handle *)pUVar10->next, pUVar17 != (UT_hash_handle *)0x0)) {
        pUVar17 = (UT_hash_handle *)((int)&pUVar17->tbl + pUVar16->hho);
      }
    }
    else {
      iVar5 = pUVar16->hho;
      if (0 < *(int *)((int)pUVar10 + -iVar5 + 0x108) - *(int *)((int)pUVar18 + -iVar5 + 0x108)) {
        pUVar24 = (UT_hash_handle *)pUVar18->next;
        pUVar10 = pUVar18;
        if (pUVar24 == (UT_hash_handle *)0x0) goto joined_r0x00025cd2;
        pUVar24 = (UT_hash_handle *)((int)&pUVar24->tbl + iVar5);
        goto joined_r0x00025cd2;
      }
      if ((pUVar10 != (UT_hash_handle *)0x0) &&
         (pUVar17 = (UT_hash_handle *)pUVar10->next, pUVar17 != (UT_hash_handle *)0x0)) {
        pUVar17 = (UT_hash_handle *)((int)&pUVar17->tbl + iVar5);
      }
    }
    if (pUVar22 == (UT_hash_handle *)0x0) {
      pUVar13 = (UT_hash_handle *)((int)&pUVar13[-1].hashv + 3);
      pUVar22 = pUVar10;
      pUVar7 = pUVar10;
      if (pUVar10 != (UT_hash_handle *)0x0) {
        pvVar19 = (void *)0x0;
        goto LAB_00025c10;
      }
      goto LAB_00025bd8;
    }
    pUVar13 = (UT_hash_handle *)((int)&pUVar13[-1].hashv + 3);
    while (pUVar10 != (UT_hash_handle *)0x0) {
      pvVar19 = (void *)((int)pUVar22 - pUVar16->hho);
      pUVar22->next = (void *)((int)pUVar10 - pUVar16->hho);
      pUVar22 = pUVar10;
LAB_00025c10:
      while( true ) {
        pUVar22->prev = pvVar19;
        pUVar10 = pUVar17;
        if (pUVar13 != (UT_hash_handle *)0x0) goto LAB_00025bda;
LAB_00025c16:
        if (pUVar18 == (UT_hash_handle *)0x0 || _hs_qsize == 0) {
          pUVar17 = pUVar18;
          if (pUVar18 != (UT_hash_handle *)0x0) goto LAB_00025ba8;
          if (pUVar22 != (UT_hash_handle *)0x0) {
            pUVar22->next = (void *)0x0;
          }
          ptVar9 = getq;
          if ((1 < uVar6) &&
             (pUVar23 = (UT_hash_handle *)((int)pUVar23 << 1), pUVar22 = pUVar7,
             pUVar7 != (UT_hash_handle *)0x0)) goto LAB_00025b9e;
          func = &jedata;
          staged_work = (work *)((int)pUVar7 - pUVar16->hho);
          pUVar16->tail = pUVar22;
          goto LAB_00025c54;
        }
        pUVar24 = pUVar13;
        pUVar10 = pUVar18;
        if (pUVar18->next != (void *)0x0) {
          pUVar24 = (UT_hash_handle *)((int)pUVar18->next + pUVar16->hho);
        }
joined_r0x00025cd2:
        pUVar18 = pUVar24;
        _hs_qsize = _hs_qsize - 1;
        if (pUVar22 != (UT_hash_handle *)0x0) break;
        pvVar19 = (void *)0x0;
        pUVar22 = pUVar10;
        pUVar7 = pUVar10;
      }
    }
    pUVar22->next = (void *)0x0;
    pUVar22 = pUVar10;
  } while( true );
}

