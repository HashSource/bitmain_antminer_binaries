
/* WARNING: Unknown calling convention */

_Bool test_work_current(work *work)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte bVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  char *pcVar22;
  char *pcVar23;
  undefined4 uVar24;
  block *pbVar25;
  int iVar26;
  size_t sVar27;
  block *__dest;
  UT_hash_handle *pUVar28;
  pool *ppVar29;
  tm *ptVar30;
  uint uVar31;
  UT_hash_handle *pUVar32;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  uint uVar33;
  UT_hash_handle *pUVar34;
  uint uVar35;
  char *func_04;
  char *pcVar36;
  char *func_05;
  char *func_06;
  char *func_07;
  char *func_08;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  byte *pbVar37;
  UT_hash_handle *pUVar38;
  void *pvVar39;
  block *pbVar40;
  int line_04;
  int line_05;
  int line_06;
  int line_07;
  int line_08;
  undefined1 *puVar41;
  pool *ppVar42;
  uchar *puVar43;
  UT_hash_handle *pUVar44;
  block *pbVar45;
  pool *ppVar46;
  char cVar47;
  undefined1 uVar48;
  pthread_rwlock_t *__rwlock;
  uint uVar49;
  UT_hash_table *pUVar50;
  UT_hash_handle *pUVar51;
  block *pbVar52;
  UT_hash_bucket *pUVar53;
  uint uVar54;
  UT_hash_table *pUVar55;
  UT_hash_handle *pUVar56;
  uint uVar57;
  UT_hash_handle *pUVar58;
  UT_hash_handle *pUVar59;
  bool bVar60;
  double dVar61;
  uint64_t val;
  int local_8bc;
  block *local_8b0;
  UT_hash_bucket *local_8ac;
  uint height;
  __time_t local_898;
  uchar bedata [32];
  char hexstr [68];
  char tmp42 [2048];
  
  ppVar42 = work->pool;
  puVar43 = ppVar42->coinbase;
  height = 0;
  uVar57 = (uint)puVar43[0x2a];
  if (work->mandatory != false) {
    return true;
  }
  bedata._0_4_ = *(undefined4 *)(work->data + 0x20);
  bedata._4_4_ = *(undefined4 *)(work->data + 0x1c);
  bedata._12_4_ = *(undefined4 *)(work->data + 0x14);
  bedata._20_4_ = *(undefined4 *)(work->data + 0xc);
  bedata._8_4_ = *(undefined4 *)(work->data + 0x18);
  bedata._16_4_ = *(undefined4 *)(work->data + 0x10);
  bedata._28_4_ = *(undefined4 *)(work->data + 4);
  bedata._24_4_ = *(undefined4 *)(work->data + 8);
  __bin2hex(hexstr,bedata,0x20);
  if (uVar57 < 5) {
    _cg_memcpy(&height,puVar43 + 0x2b,uVar57,"cgminer.c","test_work_current",0x15a9);
    height = height - 1;
  }
  iVar26 = pthread_mutex_lock((pthread_mutex_t *)&ppVar42->data_lock);
  if (iVar26 != 0) {
    _mutex_lock((pthread_mutex_t *)"test_work_current",(char *)0x15ae,func,line);
  }
  __rwlock = &(ppVar42->data_lock).rwlock;
  iVar26 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
  if (iVar26 != 0) {
    _wr_lock((pthread_rwlock_t *)"test_work_current",(char *)0x15ae,func_00,line_00);
  }
  if ((ppVar42->swork).clean != false) {
    (ppVar42->swork).clean = false;
    work->longpoll = true;
  }
  iVar26 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar26 != 0) {
    _rw_unlock((pthread_rwlock_t *)"test_work_current",(char *)0x15b6,func_01,line_01);
  }
  iVar26 = pthread_mutex_unlock((pthread_mutex_t *)&ppVar42->data_lock);
  if (iVar26 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"test_work_current",(char *)0x15b6,func_02,line_02);
  }
  (*selective_yield)();
  iVar26 = pthread_rwlock_wrlock((pthread_rwlock_t *)&blk_lock);
  if (iVar26 != 0) {
    _wr_lock((pthread_rwlock_t *)"block_exists",(char *)0x155f,func_03,line_03);
  }
  sVar27 = strlen(hexstr);
  uVar57 = 0x9e3779b9;
  uVar54 = 0xfeedbeef;
  pbVar37 = (byte *)hexstr;
  uVar31 = uVar57;
  for (uVar49 = sVar27; 0xb < uVar49; uVar49 = uVar49 - 0xc) {
    pbVar1 = pbVar37 + 6;
    pbVar10 = pbVar37 + 10;
    pbVar11 = pbVar37 + 2;
    pbVar2 = pbVar37 + 5;
    pbVar3 = pbVar37 + 9;
    pbVar4 = pbVar37 + 1;
    pbVar5 = pbVar37 + 7;
    pbVar6 = pbVar37 + 4;
    bVar12 = *pbVar37;
    pbVar7 = pbVar37 + 8;
    pbVar8 = pbVar37 + 3;
    pbVar9 = pbVar37 + 0xb;
    pbVar37 = pbVar37 + 0xc;
    iVar26 = uVar31 + (uint)*pbVar1 * 0x10000 + (uint)*pbVar2 * 0x100 + (uint)*pbVar6 +
                      (uint)*pbVar5 * 0x1000000;
    uVar54 = (uint)*pbVar10 * 0x10000 + (uint)*pbVar3 * 0x100 + (uint)*pbVar7 +
             (uint)*pbVar9 * 0x1000000 + uVar54;
    uVar31 = uVar57 + ((((uint)*pbVar11 * 0x10000 + (uint)*pbVar4 * 0x100 + (uint)bVar12 +
                        (uint)*pbVar8 * 0x1000000) - iVar26) - uVar54) ^ uVar54 >> 0xd;
    uVar57 = (iVar26 - uVar54) - uVar31 ^ uVar31 << 8;
    uVar33 = (uVar54 - uVar31) - uVar57 ^ uVar57 >> 0xd;
    uVar54 = (uVar31 - uVar57) - uVar33 ^ uVar33 >> 0xc;
    uVar31 = (uVar57 - uVar33) - uVar54 ^ uVar54 << 0x10;
    uVar33 = (uVar33 - uVar54) - uVar31 ^ uVar31 >> 5;
    uVar57 = (uVar54 - uVar31) - uVar33 ^ uVar33 >> 3;
    uVar31 = (uVar31 - uVar33) - uVar57 ^ uVar57 << 10;
    uVar54 = (uVar33 - uVar57) - uVar31 ^ uVar31 >> 0xf;
  }
  uVar54 = uVar54 + sVar27;
  switch(uVar49) {
  case 0xb:
    uVar54 = uVar54 + (uint)pbVar37[10] * 0x1000000;
  case 10:
    uVar54 = uVar54 + (uint)pbVar37[9] * 0x10000;
  case 9:
    uVar54 = uVar54 + (uint)pbVar37[8] * 0x100;
  case 8:
    uVar31 = uVar31 + (uint)pbVar37[7] * 0x1000000;
  case 7:
    uVar31 = uVar31 + (uint)pbVar37[6] * 0x10000;
  case 6:
    uVar31 = uVar31 + (uint)pbVar37[5] * 0x100;
  case 5:
    uVar31 = uVar31 + pbVar37[4];
  case 4:
    uVar57 = uVar57 + (uint)pbVar37[3] * 0x1000000;
  case 3:
    uVar57 = uVar57 + (uint)pbVar37[2] * 0x10000;
  case 2:
    uVar57 = uVar57 + (uint)pbVar37[1] * 0x100;
  case 1:
    uVar57 = uVar57 + *pbVar37;
  }
  uVar57 = (uVar57 - uVar31) - uVar54 ^ uVar54 >> 0xd;
  uVar31 = (uVar31 - uVar54) - uVar57 ^ uVar57 << 8;
  uVar54 = (uVar54 - uVar57) - uVar31 ^ uVar31 >> 0xd;
  uVar57 = (uVar57 - uVar31) - uVar54 ^ uVar54 >> 0xc;
  uVar31 = (uVar31 - uVar54) - uVar57 ^ uVar57 << 0x10;
  uVar54 = (uVar54 - uVar57) - uVar31 ^ uVar31 >> 5;
  uVar57 = (uVar57 - uVar31) - uVar54 ^ uVar54 >> 3;
  uVar31 = (uVar31 - uVar54) - uVar57 ^ uVar57 << 10;
  pUVar50 = (UT_hash_table *)((uVar54 - uVar57) - uVar31 ^ uVar31 >> 0xf);
  if (blocks != (block *)0x0) {
    pUVar55 = (blocks->hh).tbl;
    pUVar44 = pUVar55->buckets[pUVar55->num_buckets - 1 & (uint)pUVar50].hh_head;
    if (pUVar44 != (UT_hash_handle *)0x0) {
      pUVar44 = (UT_hash_handle *)((int)pUVar44 - pUVar55->hho);
    }
    for (; pUVar44 != (UT_hash_handle *)0x0;
        pUVar44 = (UT_hash_handle *)((int)pUVar44[2].key - pUVar55->hho)) {
      if (((pUVar50 == pUVar44[3].tbl) && (sVar27 == pUVar44[2].hashv)) &&
         (iVar26 = memcmp((void *)pUVar44[2].keylen,hexstr,sVar27), iVar26 == 0)) {
        cVar47 = '\x01';
        local_8b0 = (block *)0x0;
        goto LAB_00025122;
      }
      if (pUVar44[2].key == (void *)0x0) break;
    }
  }
  __dest = (block *)_cgcalloc(0x68,1,"cgminer.c","block_exists",0x1563);
  if (__dest == (block *)0x0) {
    builtin_strncpy(tmp42,"block_exists OOM",0x10);
    tmp42._16_4_ = tmp42._16_4_ & 0xffffff00;
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcpy((char *)__dest,hexstr);
  pbVar52 = blocks;
  local_8b0 = blocks;
  uVar57 = new_blocks + 1;
  __dest->block_no = new_blocks;
  new_blocks = uVar57;
  if (pbVar52 != (block *)0x0) {
    pUVar50 = (pbVar52->hh).tbl;
    if (3 < pUVar50->num_items) {
      pUVar44 = &pbVar52->hh;
      pUVar34 = (UT_hash_handle *)0x1;
LAB_00024bf2:
      pUVar51 = (UT_hash_handle *)0x0;
      uVar57 = 0;
      pUVar59 = pUVar44;
      pUVar44 = (UT_hash_handle *)0x0;
LAB_00024bfa:
      uVar57 = uVar57 + 1;
      pUVar56 = pUVar34;
      if (pUVar34 == (UT_hash_handle *)0x0) {
        pUVar32 = (UT_hash_handle *)0x0;
        pUVar38 = pUVar59;
      }
      else {
        pUVar38 = (UT_hash_handle *)pUVar59->next;
        pUVar32 = (UT_hash_handle *)0x1;
        if (pUVar38 != (UT_hash_handle *)0x0) {
          pUVar32 = (UT_hash_handle *)0x1;
          pUVar38 = (UT_hash_handle *)((int)&pUVar38->tbl + pUVar50->hho);
          if (pUVar38 != (UT_hash_handle *)0x0) {
            while (pUVar32 != pUVar34) {
              pUVar38 = (UT_hash_handle *)pUVar38->next;
              pUVar32 = (UT_hash_handle *)((int)&pUVar32->tbl + 1);
              if ((pUVar38 == (UT_hash_handle *)0x0) ||
                 (pUVar38 = (UT_hash_handle *)((int)&pUVar38->tbl + pUVar50->hho),
                 pUVar38 == (UT_hash_handle *)0x0)) break;
            }
          }
        }
      }
LAB_00024c3a:
      do {
        pUVar28 = pUVar59;
        if (pUVar32 == (UT_hash_handle *)0x0) goto LAB_00024c84;
LAB_00024c3c:
        pUVar59 = pUVar28;
        if (pUVar56 == (UT_hash_handle *)0x0 || pUVar38 == (UT_hash_handle *)0x0) {
          if ((pUVar28 != (UT_hash_handle *)0x0) &&
             (pUVar59 = (UT_hash_handle *)pUVar28->next, pUVar59 != (UT_hash_handle *)0x0)) {
            pUVar59 = (UT_hash_handle *)((int)&pUVar59->tbl + pUVar50->hho);
          }
        }
        else {
          iVar26 = pUVar50->hho;
          if (0 < *(int *)((int)pUVar28 + -iVar26 + 100) - *(int *)((int)pUVar38 + -iVar26 + 100)) {
            pUVar58 = (UT_hash_handle *)pUVar38->next;
            pUVar28 = pUVar38;
            if (pUVar58 == (UT_hash_handle *)0x0) goto joined_r0x000252b6;
            pUVar58 = (UT_hash_handle *)((int)&pUVar58->tbl + iVar26);
            goto joined_r0x000252b6;
          }
          if ((pUVar28 != (UT_hash_handle *)0x0) &&
             (pUVar59 = (UT_hash_handle *)pUVar28->next, pUVar59 != (UT_hash_handle *)0x0)) {
            pUVar59 = (UT_hash_handle *)((int)&pUVar59->tbl + iVar26);
          }
        }
        pUVar32 = (UT_hash_handle *)((int)&pUVar32[-1].hashv + 3);
        if (pUVar51 == (UT_hash_handle *)0x0) {
          pUVar51 = pUVar28;
          pUVar44 = pUVar28;
          if (pUVar28 != (UT_hash_handle *)0x0) {
            pvVar39 = (void *)0x0;
            goto LAB_00024c7e;
          }
          goto LAB_00024c3a;
        }
        while (pUVar28 != (UT_hash_handle *)0x0) {
          pvVar39 = (void *)((int)pUVar51 - pUVar50->hho);
          pUVar51->next = (void *)((int)pUVar28 - pUVar50->hho);
          pUVar51 = pUVar28;
LAB_00024c7e:
          while( true ) {
            pUVar51->prev = pvVar39;
            pUVar28 = pUVar59;
            if (pUVar32 != (UT_hash_handle *)0x0) goto LAB_00024c3c;
LAB_00024c84:
            if (pUVar38 == (UT_hash_handle *)0x0 || pUVar56 == (UT_hash_handle *)0x0) {
              pUVar59 = pUVar38;
              if (pUVar38 != (UT_hash_handle *)0x0) goto LAB_00024bfa;
              if (pUVar51 != (UT_hash_handle *)0x0) {
                pUVar51->next = (void *)0x0;
              }
              if ((1 < uVar57) &&
                 (pUVar34 = (UT_hash_handle *)((int)pUVar34 << 1), pUVar51 = pUVar44,
                 pUVar44 != (UT_hash_handle *)0x0)) goto LAB_00024bf2;
              pUVar50->tail = pUVar51;
              pbVar45 = (block *)((int)pUVar44 - pUVar50->hho);
              local_8b0 = (block *)pbVar45->block_no;
              pvVar39 = (pbVar45->hh).prev;
              pbVar52 = (block *)(pbVar45->hh).next;
              blocks = pbVar45;
              if ((pvVar39 == (void *)0x0) && (pbVar52 == (block *)0x0)) {
                free(((pbVar45->hh).tbl)->buckets);
                free((pbVar45->hh).tbl);
                blocks = pbVar52;
              }
              else {
                pUVar50 = (pbVar45->hh).tbl;
                iVar26 = pUVar50->hho;
                pbVar40 = (block *)((int)pUVar50->tail - iVar26);
                bVar60 = pbVar45 == pbVar40;
                if (bVar60) {
                  pbVar40 = (block *)((int)pvVar39 + iVar26);
                }
                if (bVar60) {
                  pUVar50->tail = (UT_hash_handle *)pbVar40;
                }
                pbVar40 = pbVar52;
                pbVar25 = pbVar52;
                if (pvVar39 != (void *)0x0) {
                  *(block **)((int)pvVar39 + iVar26 + 8) = pbVar52;
                  pbVar52 = (block *)(pbVar45->hh).next;
                  pbVar40 = pbVar45;
                  pbVar25 = blocks;
                }
                blocks = pbVar25;
                pUVar50 = (pbVar40->hh).tbl;
                if (pbVar52 != (block *)0x0) {
                  *(void **)(pbVar52->hash + pUVar50->hho + 4) = pvVar39;
                }
                pUVar53 = pUVar50->buckets;
                uVar57 = (pbVar45->hh).hashv & pUVar50->num_buckets - 1;
                pUVar34 = (pbVar45->hh).hh_next;
                pUVar53[uVar57].count = pUVar53[uVar57].count - 1;
                pUVar44 = (pbVar45->hh).hh_prev;
                if (&pbVar45->hh == pUVar53[uVar57].hh_head) {
                  pUVar53[uVar57].hh_head = pUVar34;
                }
                if (pUVar44 != (UT_hash_handle *)0x0) {
                  pUVar44->hh_next = pUVar34;
                  pUVar34 = (pbVar45->hh).hh_next;
                }
                if (pUVar34 != (UT_hash_handle *)0x0) {
                  pUVar34->hh_prev = pUVar44;
                }
                pUVar50->num_items = pUVar50->num_items - 1;
                pbVar52 = pbVar40;
              }
              free(pbVar45);
              goto LAB_00024d40;
            }
            pUVar58 = pUVar32;
            pUVar28 = pUVar38;
            if (pUVar38->next != (void *)0x0) {
              pUVar58 = (UT_hash_handle *)((int)pUVar38->next + pUVar50->hho);
            }
joined_r0x000252b6:
            pUVar38 = pUVar58;
            pUVar56 = (UT_hash_handle *)((int)&pUVar56[-1].hashv + 3);
            if (pUVar51 != (UT_hash_handle *)0x0) break;
            pvVar39 = (void *)0x0;
            pUVar51 = pUVar28;
            pUVar44 = pUVar28;
          }
        }
        pUVar51->next = (void *)0x0;
        pUVar51 = pUVar28;
      } while( true );
    }
    local_8b0 = (block *)0x0;
  }
LAB_00024d40:
  sVar27 = strlen((char *)__dest);
  uVar57 = 0xfeedbeef;
  uVar31 = 0x9e3779b9;
  uVar54 = uVar31;
  pbVar45 = __dest;
  for (uVar49 = sVar27; 0xb < uVar49; uVar49 = uVar49 - 0xc) {
    pcVar36 = pbVar45->hash;
    pcVar13 = pbVar45->hash;
    pcVar14 = pbVar45->hash;
    pcVar15 = pbVar45->hash;
    pcVar16 = pbVar45->hash;
    pcVar17 = pbVar45->hash;
    pcVar18 = pbVar45->hash;
    pcVar19 = pbVar45->hash;
    pcVar20 = pbVar45->hash;
    pcVar21 = pbVar45->hash;
    pcVar22 = pbVar45->hash;
    pcVar23 = pbVar45->hash;
    pbVar45 = (block *)(pbVar45->hash + 0xc);
    iVar26 = uVar54 + (uint)(byte)pcVar18[4] +
                      (uint)(byte)pcVar36[6] * 0x10000 + (uint)(byte)pcVar14[5] * 0x100 +
                      (uint)(byte)pcVar20[7] * 0x1000000;
    uVar57 = (uint)(byte)pcVar22[8] +
             (uint)(byte)pcVar16[10] * 0x10000 + (uint)(byte)pcVar17[9] * 0x100 +
             (uint)(byte)pcVar23[0xb] * 0x1000000 + uVar57;
    uVar33 = uVar31 + ((((uint)(byte)*pcVar19 +
                         (uint)(byte)pcVar13[2] * 0x10000 + (uint)(byte)pcVar15[1] * 0x100 +
                        (uint)(byte)pcVar21[3] * 0x1000000) - iVar26) - uVar57) ^ uVar57 >> 0xd;
    uVar31 = (iVar26 - uVar57) - uVar33 ^ uVar33 << 8;
    uVar54 = (uVar57 - uVar33) - uVar31 ^ uVar31 >> 0xd;
    uVar35 = (uVar33 - uVar31) - uVar54 ^ uVar54 >> 0xc;
    uVar57 = (uVar31 - uVar54) - uVar35 ^ uVar35 << 0x10;
    uVar33 = (uVar54 - uVar35) - uVar57 ^ uVar57 >> 5;
    uVar31 = (uVar35 - uVar57) - uVar33 ^ uVar33 >> 3;
    uVar54 = (uVar57 - uVar33) - uVar31 ^ uVar31 << 10;
    uVar57 = (uVar33 - uVar31) - uVar54 ^ uVar54 >> 0xf;
  }
  uVar57 = uVar57 + sVar27;
  switch(uVar49) {
  case 0xb:
    uVar57 = uVar57 + (uint)(byte)pbVar45->hash[10] * 0x1000000;
  case 10:
    uVar57 = uVar57 + (uint)(byte)pbVar45->hash[9] * 0x10000;
  case 9:
    uVar57 = uVar57 + (uint)(byte)pbVar45->hash[8] * 0x100;
  case 8:
    uVar54 = uVar54 + (uint)(byte)pbVar45->hash[7] * 0x1000000;
  case 7:
    uVar54 = uVar54 + (uint)(byte)pbVar45->hash[6] * 0x10000;
  case 6:
    uVar54 = uVar54 + (uint)(byte)pbVar45->hash[5] * 0x100;
  case 5:
    uVar54 = uVar54 + (byte)pbVar45->hash[4];
  case 4:
    uVar31 = uVar31 + (uint)(byte)pbVar45->hash[3] * 0x1000000;
  case 3:
    uVar31 = uVar31 + (uint)(byte)pbVar45->hash[2] * 0x10000;
  case 2:
    uVar31 = uVar31 + (uint)(byte)pbVar45->hash[1] * 0x100;
  case 1:
    uVar31 = uVar31 + (byte)pbVar45->hash[0];
  }
  uVar31 = (uVar31 - uVar54) - uVar57 ^ uVar57 >> 0xd;
  uVar54 = (uVar54 - uVar57) - uVar31 ^ uVar31 << 8;
  (__dest->hh).key = __dest;
  uVar49 = (uVar57 - uVar31) - uVar54 ^ uVar54 >> 0xd;
  uVar57 = (uVar31 - uVar54) - uVar49 ^ uVar49 >> 0xc;
  uVar31 = (uVar54 - uVar49) - uVar57 ^ uVar57 << 0x10;
  uVar54 = (uVar49 - uVar57) - uVar31 ^ uVar31 >> 5;
  uVar57 = (uVar57 - uVar31) - uVar54 ^ uVar54 >> 3;
  uVar31 = (uVar31 - uVar54) - uVar57 ^ uVar57 << 10;
  uVar57 = (uVar54 - uVar57) - uVar31 ^ uVar31 >> 0xf;
  (__dest->hh).hashv = uVar57;
  sVar27 = strlen((char *)__dest);
  (__dest->hh).keylen = sVar27;
  if (pbVar52 == (block *)0x0) {
    (__dest->hh).next = (void *)0x0;
    (__dest->hh).prev = (void *)0x0;
    blocks = __dest;
    pUVar50 = (UT_hash_table *)malloc(0x2c);
    (__dest->hh).tbl = pUVar50;
    if (pUVar50 == (UT_hash_table *)0x0) goto LAB_00025764;
    pUVar50->buckets = (UT_hash_bucket *)0x0;
    pUVar50->num_buckets = 0;
    pUVar50->log2_num_buckets = 0;
    pUVar50->num_items = 0;
    pUVar50->tail = (UT_hash_handle *)0x0;
    pUVar50->hho = 0;
    pUVar50->ideal_chain_maxlen = 0;
    pUVar50->nonideal_items = 0;
    pUVar50->ineff_expands = 0;
    pUVar50->noexpand = 0;
    pUVar50->signature = 0;
    pUVar50 = (__dest->hh).tbl;
    pUVar50->tail = &__dest->hh;
    pUVar50->num_buckets = 0x20;
    pUVar50->log2_num_buckets = 5;
    pUVar50->hho = 0x44;
    pUVar53 = (UT_hash_bucket *)malloc(0x180);
    pUVar50->buckets = pUVar53;
    if (pUVar53 == (UT_hash_bucket *)0x0) goto LAB_00025764;
    memset(pUVar53,0,0x180);
    pUVar50 = (__dest->hh).tbl;
    pUVar50->signature = 0xa0111fe1;
  }
  else {
    pUVar50 = (pbVar52->hh).tbl;
    (__dest->hh).next = (void *)0x0;
    (__dest->hh).tbl = pUVar50;
    pUVar50 = (pbVar52->hh).tbl;
    pUVar44 = pUVar50->tail;
    iVar26 = pUVar50->hho;
    pUVar44->next = __dest;
    (__dest->hh).prev = (void *)((int)pUVar44 - iVar26);
    pUVar50->tail = &__dest->hh;
  }
  pUVar53 = pUVar50->buckets;
  uVar57 = uVar57 & pUVar50->num_buckets - 1;
  pUVar50->num_items = pUVar50->num_items + 1;
  pUVar44 = pUVar53[uVar57].hh_head;
  uVar31 = pUVar53[uVar57].count + 1;
  pUVar53[uVar57].count = uVar31;
  (__dest->hh).hh_next = pUVar44;
  (__dest->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar44 != (UT_hash_handle *)0x0) {
    pUVar44->hh_prev = &__dest->hh;
  }
  pUVar53[uVar57].hh_head = &__dest->hh;
  if (((pUVar53[uVar57].expand_mult + 1) * 10 <= uVar31) &&
     (pUVar50 = (__dest->hh).tbl, pUVar50->noexpand != 1)) {
    sVar27 = pUVar50->num_buckets * 0x18;
    pUVar53 = (UT_hash_bucket *)malloc(sVar27);
    if (pUVar53 == (UT_hash_bucket *)0x0) {
LAB_00025764:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar53,0,sVar27);
    pUVar50 = (__dest->hh).tbl;
    uVar31 = pUVar50->num_buckets;
    pUVar50->nonideal_items = 0;
    uVar57 = pUVar50->num_items >> (pUVar50->log2_num_buckets + 1 & 0xff);
    uVar54 = uVar31 * 2 - 1;
    if ((uVar54 & pUVar50->num_items) != 0) {
      uVar57 = uVar57 + 1;
    }
    pUVar50->ideal_chain_maxlen = uVar57;
    if (uVar31 == 0) {
      local_8ac = pUVar50->buckets;
    }
    else {
      local_8ac = pUVar50->buckets;
      local_8bc = 0;
      do {
        pUVar44 = *(UT_hash_handle **)((int)&local_8ac->hh_head + local_8bc);
        while (pUVar44 != (UT_hash_handle *)0x0) {
          pUVar34 = pUVar44->hh_next;
          uVar33 = uVar54 & pUVar44->hashv;
          uVar49 = pUVar53[uVar33].count + 1;
          pUVar53[uVar33].count = uVar49;
          if (uVar57 < uVar49) {
            pUVar50->nonideal_items = pUVar50->nonideal_items + 1;
            uVar49 = __aeabi_uidiv(uVar49,uVar57);
            pUVar53[uVar33].expand_mult = uVar49;
          }
          pUVar59 = pUVar53[uVar33].hh_head;
          pUVar44->hh_prev = (UT_hash_handle *)0x0;
          pUVar44->hh_next = pUVar59;
          if (pUVar59 != (UT_hash_handle *)0x0) {
            pUVar59->hh_prev = pUVar44;
          }
          pUVar53[uVar33].hh_head = pUVar44;
          pUVar44 = pUVar34;
        }
        local_8bc = local_8bc + 0xc;
      } while (local_8bc != uVar31 * 0xc);
    }
    free(local_8ac);
    pUVar50 = (__dest->hh).tbl;
    uVar54 = pUVar50->nonideal_items;
    pUVar50->buckets = pUVar53;
    uVar57 = pUVar50->num_items >> 1;
    pUVar50->log2_num_buckets = pUVar50->log2_num_buckets + 1;
    uVar31 = uVar54;
    if (uVar54 <= uVar57) {
      uVar31 = 0;
    }
    pUVar50->num_buckets = pUVar50->num_buckets << 1;
    if (uVar57 < uVar54) {
      uVar31 = pUVar50->ineff_expands + 1;
      pUVar50->ineff_expands = uVar31;
      uVar57 = uVar31;
      if (1 < uVar31) {
        uVar57 = 1;
      }
      if (1 < uVar31) {
        pUVar50->noexpand = uVar57;
      }
    }
    else {
      pUVar50->ineff_expands = uVar31;
    }
  }
  iVar26 = 0x1d - (uint)work->data[0x48];
  uVar57 = iVar26 * 8;
  if ((int)uVar57 < 8) {
    dVar61 = 16776960.0;
  }
  else {
    dVar61 = (double)__aeabi_ul2d(0xffff << (uVar57 & 0xff),
                                  0xffff << (uVar57 - 0x20 & 0xff) |
                                  0xffffU >> (iVar26 * -8 + 0x20U & 0xff));
  }
  uVar57 = *(uint *)(work->data + 0x48);
  dVar61 = dVar61 / (double)(longlong)
                            (int)((uVar57 >> 8 & 0xff) << 0x10 | (uVar57 >> 0x10 & 0xff) << 8 |
                                 uVar57 >> 0x18);
  if (dVar61 != current_diff) {
    val = __fixunsdfdi(SUB84(dVar61,0),(int)((ulonglong)dVar61 >> 0x20));
    suffix_string(val,block_diff,8,0);
    current_diff = dVar61;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Network diff set to %s",block_diff);
      _applog(5,tmp42,false);
    }
  }
  if (local_8b0 == (block *)0x0) {
    cVar47 = '\0';
  }
  else {
    cVar47 = opt_debug;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (cVar47 = '\0', 6 < opt_log_level))))
    {
      cVar47 = '\0';
      snprintf(tmp42,0x800,"Deleted block %d from database",local_8b0);
      _applog(7,tmp42,false);
    }
  }
LAB_00025122:
  iVar26 = pthread_rwlock_unlock((pthread_rwlock_t *)&blk_lock);
  if (iVar26 != 0) {
    _rw_unlock((pthread_rwlock_t *)"block_exists",(char *)0x1585,func_04,line_04);
  }
  (*selective_yield)();
  if (cVar47 == '\0') {
    iVar26 = pthread_mutex_lock((pthread_mutex_t *)&ch_lock);
    if (iVar26 != 0) {
      _mutex_lock((pthread_mutex_t *)"set_curblock",(char *)0x1528,func_05,line_05);
    }
    iVar26 = pthread_rwlock_wrlock((pthread_rwlock_t *)&ch_lock.rwlock);
    if (iVar26 != 0) {
      _wr_lock((pthread_rwlock_t *)"set_curblock",(char *)0x1528,func_06,line_06);
    }
    cgtime(&block_timeval);
    strcpy(current_hash,hexstr);
    _cg_memcpy(current_block,bedata,0x20,"cgminer.c","set_curblock",0x152b);
    local_898 = block_timeval.tv_sec;
    iVar26 = block_timeval.tv_usec / 1000;
    ptVar30 = localtime(&local_898);
    snprintf(blocktime,0x20,"[%02d:%02d:%02d.%03d]",ptVar30->tm_hour,ptVar30->tm_min,ptVar30->tm_sec
             ,iVar26);
    iVar26 = pthread_rwlock_unlock((pthread_rwlock_t *)&ch_lock.rwlock);
    if (iVar26 != 0) {
      _rw_unlock((pthread_rwlock_t *)"set_curblock",(char *)0x152d,func_07,line_07);
    }
    iVar26 = pthread_mutex_unlock((pthread_mutex_t *)&ch_lock);
    if (iVar26 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"set_curblock",(char *)0x152d,func_08,line_08);
    }
    (*selective_yield)();
    iVar26 = 0;
    do {
      if (current_hash[iVar26] != '0') break;
      iVar26 = iVar26 + 1;
    } while (iVar26 != 0x39);
    strncpy(prev_block,current_hash + iVar26,8);
    prev_block[8] = '\0';
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"New block: %s... diff %s",current_hash,block_diff);
      _applog(6,tmp42,false);
    }
  }
  if (((local_8b0 != (block *)0x0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"Deleted block %d from database",local_8b0);
    _applog(7,tmp42,false);
  }
  if (cVar47 != '\0') {
    iVar26 = memcmp(ppVar42->prev_block,bedata,0x20);
    uVar48 = 1;
    if (iVar26 != 0) {
      iVar26 = memcmp(bedata,current_block,0x20);
      if (iVar26 == 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d now up to date at height %d",ppVar42->pool_no,height);
          _applog(6,tmp42,false);
        }
        uVar48 = 1;
        _cg_memcpy(ppVar42->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x15f0);
      }
      else {
        uVar48 = opt_debug;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (uVar48 = 0, 6 < opt_log_level)))
           ) {
          uVar48 = 0;
          snprintf(tmp42,0x800,"Stale data from pool %d at height %d",ppVar42->pool_no,height);
          _applog(7,tmp42,false);
        }
      }
    }
    if (work->longpoll != false) {
      uVar57 = pool_strategy - POOL_LOADBALANCE;
      work_block = work_block + 1;
      work->work_block = work_block;
      if ((uVar57 < 2) || (ppVar46 = work->pool, ppVar29 = current_pool(), ppVar46 == ppVar29)) {
        if (work->stratum == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            puVar41 = &DAT_00046bb8;
            if (work->gbt != false) {
              puVar41 = &DAT_0004d014;
            }
            snprintf(tmp42,0x800,"%sLONGPOLL from pool %d requested work restart",puVar41,
                     work->pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Stratum from pool %d requested work restart",ppVar42->pool_no);
          _applog(5,tmp42,false);
        }
        restart_threads();
      }
    }
    goto LAB_00025212;
  }
  _cg_memcpy(ppVar42->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x15be);
  uVar24 = tmp42._28_4_;
  uVar48 = 0;
  if (new_blocks == 1) goto LAB_00025212;
  work_block = work_block + 1;
  work->work_block = work_block;
  if (work->longpoll == false) {
    if (have_longpoll == false) {
      if ((ppVar42->gbt_solo == false) &&
         (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
        builtin_strncpy(tmp42,"New block detected on network",0x1e);
        tmp42._30_2_ = SUB42(uVar24,2);
        _applog(5,tmp42,false);
      }
    }
    else if ((ppVar42->gbt_solo == false) &&
            (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
      builtin_strncpy(tmp42,"New block detected on network before pool notificati",0x34);
      tmp42[0x34] = 'o';
      tmp42[0x35] = 'n';
      tmp42[0x36] = '\0';
      _applog(5,tmp42,false);
    }
  }
  else if (work->stratum == false) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      puVar41 = &DAT_00046bb8;
      uVar57 = work->pool->pool_no;
      pcVar36 = "%sLONGPOLL from pool %d detected new block";
      if (work->gbt != false) {
        puVar41 = &DAT_0004d014;
      }
      goto LAB_00025386;
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    pcVar36 = "Stratum from pool %d detected new block at height %d";
    puVar41 = (undefined1 *)ppVar42->pool_no;
    uVar57 = height;
LAB_00025386:
    snprintf(tmp42,0x800,pcVar36,puVar41,uVar57);
    _applog(5,tmp42,false);
  }
  restart_threads();
  uVar48 = 1;
LAB_00025212:
  work->longpoll = false;
  return (_Bool)uVar48;
}

