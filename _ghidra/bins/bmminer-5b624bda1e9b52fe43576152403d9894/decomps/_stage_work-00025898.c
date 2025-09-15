
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void _stage_work(work *work)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  pthread_mutex_t *__mutex;
  int iVar4;
  uint uVar5;
  UT_hash_handle *pUVar6;
  UT_hash_bucket *pUVar7;
  thread_q *ptVar8;
  UT_hash_handle *pUVar9;
  char *func;
  uint uVar10;
  UT_hash_handle *pUVar11;
  char *func_00;
  int line;
  uint uVar12;
  uint uVar13;
  UT_hash_table *pUVar14;
  UT_hash_handle *pUVar15;
  UT_hash_handle *pUVar16;
  void *pvVar17;
  int line_00;
  size_t __size;
  work *pwVar18;
  uint uVar19;
  UT_hash_handle *pUVar20;
  UT_hash_handle *pUVar21;
  UT_hash_handle *pUVar22;
  UT_hash_handle *pUVar23;
  int local_838;
  UT_hash_bucket *local_834;
  char tmp42 [2048];
  
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Pushing work from pool %d to hash queue",work->pool->pool_no);
    _applog(7,tmp42,false);
  }
  work->work_block = work_block;
  test_work_current(work);
  __mutex = stgd_lock;
  work->pool->works = work->pool->works + 1;
  iVar4 = pthread_mutex_lock((pthread_mutex_t *)__mutex);
  if (iVar4 != 0) {
    _mutex_lock((pthread_mutex_t *)"hash_push",(char *)0x1628,func,line);
  }
  if ((work->clone == false) && (work->rolltime != 0)) {
    staged_rollable = staged_rollable + 1;
  }
  ptVar8 = getq;
  if (getq->frozen != false) {
LAB_00025c54:
    pthread_cond_broadcast((pthread_cond_t *)&ptVar8->cond);
    iVar4 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
    if (iVar4 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"hash_push",(char *)0x163a,func_00,line_00);
    }
    (*selective_yield)();
    return;
  }
  uVar5 = work->id;
  bVar1 = *(byte *)((int)&work->id + 3);
  bVar2 = *(byte *)((int)&work->id + 2);
  bVar3 = *(byte *)((int)&work->id + 1);
  (work->hh).keylen = 4;
  pwVar18 = staged_work;
  uVar12 = (byte)uVar5 + 0x112410d + (uint)bVar1 * 0x1000000 + (uint)bVar2 * 0x10000 +
           (uint)bVar3 * 0x100 ^ 0x7f76d;
  uVar10 = 0x9f49bac6 - uVar12 ^ uVar12 << 8;
  (work->hh).key = &work->id;
  uVar5 = (-0x112410d - uVar12) - uVar10 ^ uVar10 >> 0xd;
  uVar12 = (uVar12 - uVar10) - uVar5 ^ uVar5 >> 0xc;
  uVar10 = (uVar10 - uVar5) - uVar12 ^ uVar12 << 0x10;
  uVar13 = (uVar5 - uVar12) - uVar10 ^ uVar10 >> 5;
  uVar5 = (uVar12 - uVar10) - uVar13 ^ uVar13 >> 3;
  uVar12 = (uVar10 - uVar13) - uVar5 ^ uVar5 << 10;
  uVar5 = (uVar13 - uVar5) - uVar12 ^ uVar12 >> 0xf;
  (work->hh).hashv = uVar5;
  if (pwVar18 == (work *)0x0) {
    (work->hh).next = (void *)0x0;
    (work->hh).prev = (void *)0x0;
    staged_work = work;
    pUVar14 = (UT_hash_table *)malloc(0x2c);
    (work->hh).tbl = pUVar14;
    if (pUVar14 == (UT_hash_table *)0x0) goto LAB_00025dc8;
    pUVar14->buckets = (UT_hash_bucket *)0x0;
    pUVar14->num_items = 0;
    pUVar14->tail = (UT_hash_handle *)0x0;
    pUVar14->hho = 0;
    pUVar14->ideal_chain_maxlen = 0;
    pUVar14->nonideal_items = 0;
    pUVar14->ineff_expands = 0;
    pUVar14->noexpand = 0;
    pUVar14->signature = 0;
    pUVar14->tail = &work->hh;
    pUVar14->num_buckets = 0x20;
    pUVar14->log2_num_buckets = 5;
    pUVar14->hho = 0x158;
    pUVar7 = (UT_hash_bucket *)malloc(0x180);
    pUVar14->buckets = pUVar7;
    if (pUVar7 == (UT_hash_bucket *)0x0) goto LAB_00025dc8;
    memset(pUVar7,0,0x180);
    pwVar18 = staged_work;
    pUVar14 = (staged_work->hh).tbl;
    pUVar14->signature = 0xa0111fe1;
  }
  else {
    pUVar14 = (pwVar18->hh).tbl;
    (work->hh).next = (void *)0x0;
    (work->hh).tbl = pUVar14;
    pUVar14 = (pwVar18->hh).tbl;
    pUVar6 = pUVar14->tail;
    iVar4 = pUVar14->hho;
    pUVar6->next = work;
    (work->hh).prev = (void *)((int)pUVar6 - iVar4);
    pUVar14->tail = &work->hh;
  }
  pUVar7 = pUVar14->buckets;
  uVar5 = uVar5 & pUVar14->num_buckets - 1;
  pUVar14->num_items = pUVar14->num_items + 1;
  pUVar6 = pUVar7[uVar5].hh_head;
  uVar12 = pUVar7[uVar5].count + 1;
  pUVar7[uVar5].count = uVar12;
  (work->hh).hh_next = pUVar6;
  (work->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar6 != (UT_hash_handle *)0x0) {
    pUVar6->hh_prev = &work->hh;
  }
  pUVar7[uVar5].hh_head = &work->hh;
  if (((pUVar7[uVar5].expand_mult + 1) * 10 <= uVar12) &&
     (pUVar14 = (work->hh).tbl, pUVar14->noexpand != 1)) {
    __size = pUVar14->num_buckets * 0x18;
    pUVar7 = (UT_hash_bucket *)malloc(__size);
    if (pUVar7 == (UT_hash_bucket *)0x0) {
LAB_00025dc8:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar7,0,__size);
    pUVar14 = (work->hh).tbl;
    uVar12 = pUVar14->num_buckets;
    pUVar14->nonideal_items = 0;
    uVar5 = pUVar14->num_items >> (pUVar14->log2_num_buckets + 1 & 0xff);
    uVar10 = uVar12 * 2 - 1;
    if ((uVar10 & pUVar14->num_items) != 0) {
      uVar5 = uVar5 + 1;
    }
    pUVar14->ideal_chain_maxlen = uVar5;
    if (uVar12 == 0) {
      local_834 = pUVar14->buckets;
    }
    else {
      local_834 = pUVar14->buckets;
      local_838 = 0;
      do {
        pUVar6 = *(UT_hash_handle **)((int)&local_834->hh_head + local_838);
        while (pUVar6 != (UT_hash_handle *)0x0) {
          pUVar22 = pUVar6->hh_next;
          uVar19 = uVar10 & pUVar6->hashv;
          uVar13 = pUVar7[uVar19].count + 1;
          pUVar7[uVar19].count = uVar13;
          if (uVar5 < uVar13) {
            pUVar14->nonideal_items = pUVar14->nonideal_items + 1;
            uVar13 = __aeabi_uidiv(uVar13,uVar5);
            pUVar7[uVar19].expand_mult = uVar13;
          }
          pUVar15 = pUVar7[uVar19].hh_head;
          pUVar6->hh_prev = (UT_hash_handle *)0x0;
          pUVar6->hh_next = pUVar15;
          if (pUVar15 != (UT_hash_handle *)0x0) {
            pUVar15->hh_prev = pUVar6;
          }
          pUVar7[uVar19].hh_head = pUVar6;
          pUVar6 = pUVar22;
        }
        local_838 = local_838 + 0xc;
      } while (local_838 != uVar12 * 0xc);
    }
    free(local_834);
    pUVar14 = (work->hh).tbl;
    pUVar14->buckets = pUVar7;
    pUVar14->log2_num_buckets = pUVar14->log2_num_buckets + 1;
    pUVar14->num_buckets = pUVar14->num_buckets << 1;
    if (pUVar14->num_items >> 1 < pUVar14->nonideal_items) {
      uVar12 = pUVar14->ineff_expands + 1;
      pUVar14->ineff_expands = uVar12;
      pwVar18 = staged_work;
      uVar5 = uVar12;
      if (1 < uVar12) {
        uVar5 = 1;
      }
      if (1 < uVar12) {
        pUVar14->noexpand = uVar5;
      }
    }
    else {
      pUVar14->ineff_expands = 0;
      pwVar18 = staged_work;
    }
    ptVar8 = getq;
    if (pwVar18 == (work *)0x0) goto LAB_00025c54;
  }
  pUVar14 = (pwVar18->hh).tbl;
  pUVar6 = &pwVar18->hh;
  pUVar22 = (UT_hash_handle *)0x1;
LAB_00025b9e:
  pUVar20 = (UT_hash_handle *)0x0;
  uVar5 = 0;
  pUVar15 = pUVar6;
  pUVar6 = (UT_hash_handle *)0x0;
LAB_00025ba8:
  uVar5 = uVar5 + 1;
  pUVar21 = pUVar22;
  if (pUVar22 == (UT_hash_handle *)0x0) {
    pUVar11 = (UT_hash_handle *)0x0;
    pUVar16 = pUVar15;
  }
  else {
    pUVar16 = (UT_hash_handle *)pUVar15->next;
    pUVar11 = (UT_hash_handle *)0x1;
    if (pUVar16 != (UT_hash_handle *)0x0) {
      pUVar11 = (UT_hash_handle *)0x1;
      pUVar16 = (UT_hash_handle *)((int)&pUVar16->tbl + pUVar14->hho);
      if (pUVar16 != (UT_hash_handle *)0x0) {
        while (pUVar11 != pUVar22) {
          pUVar16 = (UT_hash_handle *)pUVar16->next;
          pUVar11 = (UT_hash_handle *)((int)&pUVar11->tbl + 1);
          if ((pUVar16 == (UT_hash_handle *)0x0) ||
             (pUVar16 = (UT_hash_handle *)((int)&pUVar16->tbl + pUVar14->hho),
             pUVar16 == (UT_hash_handle *)0x0)) break;
        }
      }
    }
  }
LAB_00025bd8:
  do {
    pUVar9 = pUVar15;
    if (pUVar11 == (UT_hash_handle *)0x0) goto LAB_00025c16;
LAB_00025bda:
    pUVar15 = pUVar9;
    if (pUVar21 == (UT_hash_handle *)0x0 || pUVar16 == (UT_hash_handle *)0x0) {
      if ((pUVar9 != (UT_hash_handle *)0x0) &&
         (pUVar15 = (UT_hash_handle *)pUVar9->next, pUVar15 != (UT_hash_handle *)0x0)) {
        pUVar15 = (UT_hash_handle *)((int)&pUVar15->tbl + pUVar14->hho);
      }
    }
    else {
      iVar4 = pUVar14->hho;
      if (0 < *(int *)((int)pUVar9 + -iVar4 + 0x108) - *(int *)((int)pUVar16 + -iVar4 + 0x108)) {
        pUVar23 = (UT_hash_handle *)pUVar16->next;
        pUVar9 = pUVar16;
        if (pUVar23 == (UT_hash_handle *)0x0) goto joined_r0x00025cd2;
        pUVar23 = (UT_hash_handle *)((int)&pUVar23->tbl + iVar4);
        goto joined_r0x00025cd2;
      }
      if ((pUVar9 != (UT_hash_handle *)0x0) &&
         (pUVar15 = (UT_hash_handle *)pUVar9->next, pUVar15 != (UT_hash_handle *)0x0)) {
        pUVar15 = (UT_hash_handle *)((int)&pUVar15->tbl + iVar4);
      }
    }
    if (pUVar20 == (UT_hash_handle *)0x0) {
      pUVar11 = (UT_hash_handle *)((int)&pUVar11[-1].hashv + 3);
      pUVar20 = pUVar9;
      pUVar6 = pUVar9;
      if (pUVar9 != (UT_hash_handle *)0x0) {
        pvVar17 = (void *)0x0;
        goto LAB_00025c10;
      }
      goto LAB_00025bd8;
    }
    pUVar11 = (UT_hash_handle *)((int)&pUVar11[-1].hashv + 3);
    while (pUVar9 != (UT_hash_handle *)0x0) {
      pvVar17 = (void *)((int)pUVar20 - pUVar14->hho);
      pUVar20->next = (void *)((int)pUVar9 - pUVar14->hho);
      pUVar20 = pUVar9;
LAB_00025c10:
      while( true ) {
        pUVar20->prev = pvVar17;
        pUVar9 = pUVar15;
        if (pUVar11 != (UT_hash_handle *)0x0) goto LAB_00025bda;
LAB_00025c16:
        if (pUVar16 == (UT_hash_handle *)0x0 || pUVar21 == (UT_hash_handle *)0x0) {
          pUVar15 = pUVar16;
          if (pUVar16 != (UT_hash_handle *)0x0) goto LAB_00025ba8;
          if (pUVar20 != (UT_hash_handle *)0x0) {
            pUVar20->next = (void *)0x0;
          }
          ptVar8 = getq;
          if ((1 < uVar5) &&
             (pUVar22 = (UT_hash_handle *)((int)pUVar22 << 1), pUVar20 = pUVar6,
             pUVar6 != (UT_hash_handle *)0x0)) goto LAB_00025b9e;
          staged_work = (work *)((int)pUVar6 - pUVar14->hho);
          pUVar14->tail = pUVar20;
          goto LAB_00025c54;
        }
        pUVar23 = pUVar11;
        pUVar9 = pUVar16;
        if (pUVar16->next != (void *)0x0) {
          pUVar23 = (UT_hash_handle *)((int)pUVar16->next + pUVar14->hho);
        }
joined_r0x00025cd2:
        pUVar16 = pUVar23;
        pUVar21 = (UT_hash_handle *)((int)&pUVar21[-1].hashv + 3);
        if (pUVar20 != (UT_hash_handle *)0x0) break;
        pvVar17 = (void *)0x0;
        pUVar20 = pUVar9;
        pUVar6 = pUVar9;
      }
    }
    pUVar20->next = (void *)0x0;
    pUVar20 = pUVar9;
  } while( true );
}

