
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
  int *piVar23;
  double *pdVar24;
  timeval *ptVar25;
  block *pbVar26;
  int iVar27;
  block *pbVar28;
  uint _hj_k;
  block *pbVar29;
  UT_hash_handle *pUVar30;
  UT_hash_handle *_hs_e;
  UT_hash_handle *_hd_hh_del;
  size_t sVar31;
  uint _hj_k_1;
  UT_hash_bucket *_he_new_buckets;
  int powdiff;
  pool *ppVar32;
  tm *ptVar33;
  tm *tm;
  uint uVar34;
  UT_hash_handle *pUVar35;
  char *pcVar36;
  uint uVar37;
  UT_hash_handle *pUVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  _func_int *p_Var42;
  byte *pbVar43;
  UT_hash_handle *pUVar44;
  void *pvVar45;
  block *pbVar46;
  int line;
  pool *ppVar47;
  pool *pool;
  uchar *puVar48;
  UT_hash_handle *pUVar49;
  UT_hash_handle *_hs_q;
  block *pbVar50;
  block *oldblock;
  UT_hash_handle *_he_thh;
  pool *ppVar51;
  char cVar52;
  pthread_rwlock_t *ppVar53;
  UT_hash_table *pUVar54;
  UT_hash_handle *pUVar55;
  UT_hash_bucket *pUVar56;
  uint uVar57;
  UT_hash_table *pUVar58;
  UT_hash_bucket *_he_newbkt;
  UT_hash_handle *_he_hh_nxt;
  uint _hs_qsize;
  int ms;
  char *pcVar59;
  UT_hash_handle *pUVar60;
  UT_hash_handle *_hs_p;
  UT_hash_handle *pUVar61;
  bool bVar62;
  double dVar63;
  undefined8 uVar64;
  uint in_stack_fffff734;
  int local_8bc;
  uchar *_hj_key;
  block *local_8b0;
  UT_hash_bucket *local_8ac;
  uint height;
  time_t tmp_time;
  uchar bedata [32];
  char hexstr [68];
  char tmp42 [2048];
  
  ppVar47 = work->pool;
  puVar48 = ppVar47->coinbase;
  height = 0;
  pcVar59 = (char *)(uint)puVar48[0x2a];
  if (work->mandatory != false) {
    return true;
  }
  bedata._0_4_ = *(undefined4 *)(work->data + 0x20);
  bedata._4_4_ = *(undefined4 *)(work->data + 0x1c);
  pcVar36 = (char *)0x20;
  bedata._12_4_ = *(undefined4 *)(work->data + 0x14);
  bedata._20_4_ = *(undefined4 *)(work->data + 0xc);
  bedata._8_4_ = *(undefined4 *)(work->data + 0x18);
  bedata._16_4_ = *(undefined4 *)(work->data + 0x10);
  uVar41 = *(uint *)(work->data + 4);
  bedata._24_4_ = *(undefined4 *)(work->data + 8);
  bedata._28_4_ = uVar41;
  __bin2hex(hexstr,bedata,0x20);
  if (pcVar59 < (char *)0x5) {
    in_stack_fffff734 = 0x15a9;
    _cg_memcpy(&height,puVar48 + 0x2b,(uint)pcVar59,DAT_00025310,DAT_0002530c,0x15a9);
    uVar41 = height - 1;
    pcVar36 = pcVar59;
    height = uVar41;
  }
  iVar27 = pthread_mutex_lock((pthread_mutex_t *)&ppVar47->data_lock);
  if (iVar27 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00025888,(char *)0x15ae,pcVar36,uVar41);
  }
  ppVar53 = &(ppVar47->data_lock).rwlock;
  iVar27 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar53);
  if (iVar27 != 0) {
    _wr_lock(DAT_00025888,(char *)0x15ae,pcVar36,uVar41);
  }
  uVar41 = (uint)(ppVar47->swork).clean;
  if (uVar41 != 0) {
    pcVar36 = (char *)0x0;
    uVar41 = 1;
    (ppVar47->swork).clean = false;
    work->longpoll = true;
  }
  iVar27 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar53);
  if (iVar27 != 0) {
    _rw_unlock(DAT_00025888,(char *)0x15b6,pcVar36,uVar41);
  }
  iVar27 = pthread_mutex_unlock((pthread_mutex_t *)&ppVar47->data_lock);
  if (iVar27 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00025888,(char *)0x15b6,pcVar36,uVar41);
  }
  p_Var42 = selective_yield;
  (*selective_yield)();
  iVar27 = pthread_rwlock_wrlock(DAT_00024c14);
  if (iVar27 != 0) {
    _wr_lock(DAT_00025890,(char *)0x155f,pcVar36,(int)p_Var42);
  }
  pbVar28 = (block *)strlen(hexstr);
  uVar41 = 0x9e3779b9;
  uVar57 = 0xfeedbeef;
  pbVar43 = (byte *)hexstr;
  uVar34 = uVar41;
  for (pbVar29 = pbVar28; (block *)0xb < pbVar29; pbVar29 = (block *)&pbVar29[-1].hh.keylen) {
    pbVar1 = pbVar43 + 6;
    pbVar10 = pbVar43 + 10;
    pbVar11 = pbVar43 + 2;
    pbVar2 = pbVar43 + 5;
    pbVar3 = pbVar43 + 9;
    pbVar4 = pbVar43 + 1;
    pbVar5 = pbVar43 + 7;
    pbVar6 = pbVar43 + 4;
    bVar12 = *pbVar43;
    pbVar7 = pbVar43 + 8;
    pbVar8 = pbVar43 + 3;
    pbVar9 = pbVar43 + 0xb;
    pbVar43 = pbVar43 + 0xc;
    iVar27 = uVar34 + (uint)*pbVar1 * 0x10000 + (uint)*pbVar2 * 0x100 + (uint)*pbVar6 +
                      (uint)*pbVar5 * 0x1000000;
    uVar57 = (uint)*pbVar10 * 0x10000 + (uint)*pbVar3 * 0x100 + (uint)*pbVar7 +
             (uint)*pbVar9 * 0x1000000 + uVar57;
    uVar34 = uVar41 + ((((uint)*pbVar11 * 0x10000 + (uint)*pbVar4 * 0x100 + (uint)bVar12 +
                        (uint)*pbVar8 * 0x1000000) - iVar27) - uVar57) ^ uVar57 >> 0xd;
    uVar41 = (iVar27 - uVar57) - uVar34 ^ uVar34 << 8;
    uVar37 = (uVar57 - uVar34) - uVar41 ^ uVar41 >> 0xd;
    uVar57 = (uVar34 - uVar41) - uVar37 ^ uVar37 >> 0xc;
    uVar34 = (uVar41 - uVar37) - uVar57 ^ uVar57 << 0x10;
    uVar37 = (uVar37 - uVar57) - uVar34 ^ uVar34 >> 5;
    uVar41 = (uVar57 - uVar34) - uVar37 ^ uVar37 >> 3;
    uVar34 = (uVar34 - uVar37) - uVar41 ^ uVar41 << 10;
    uVar57 = (uVar37 - uVar41) - uVar34 ^ uVar34 >> 0xf;
  }
  pcVar59 = pbVar28->hash + uVar57;
  switch(pbVar29) {
  case (block *)0xb:
    pcVar59 = pcVar59 + (uint)pbVar43[10] * 0x1000000;
  case (block *)0xa:
    pcVar59 = pcVar59 + (uint)pbVar43[9] * 0x10000;
  case (block *)0x9:
    pcVar59 = pcVar59 + (uint)pbVar43[8] * 0x100;
  case (block *)0x8:
    uVar34 = uVar34 + (uint)pbVar43[7] * 0x1000000;
  case (block *)0x7:
    uVar34 = uVar34 + (uint)pbVar43[6] * 0x10000;
  case (block *)0x6:
    uVar34 = uVar34 + (uint)pbVar43[5] * 0x100;
  case (block *)0x5:
    uVar34 = uVar34 + pbVar43[4];
  case (block *)0x4:
    uVar41 = uVar41 + (uint)pbVar43[3] * 0x1000000;
  case (block *)0x3:
    uVar41 = uVar41 + (uint)pbVar43[2] * 0x10000;
  case (block *)0x2:
    uVar41 = uVar41 + (uint)pbVar43[1] * 0x100;
  case (block *)0x1:
    uVar41 = uVar41 + *pbVar43;
  }
  uVar41 = (uVar41 - uVar34) - (int)pcVar59 ^ (uint)pcVar59 >> 0xd;
  uVar34 = (uVar34 - (int)pcVar59) - uVar41 ^ uVar41 << 8;
  uVar57 = (uint)(pcVar59 + (-uVar34 - uVar41)) ^ uVar34 >> 0xd;
  uVar41 = (uVar41 - uVar34) - uVar57 ^ uVar57 >> 0xc;
  uVar34 = (uVar34 - uVar57) - uVar41 ^ uVar41 << 0x10;
  uVar57 = (uVar57 - uVar41) - uVar34 ^ uVar34 >> 5;
  uVar41 = (uVar41 - uVar34) - uVar57 ^ uVar57 >> 3;
  uVar34 = (uVar34 - uVar57) - uVar41 ^ uVar41 << 10;
  pUVar54 = (UT_hash_table *)((uVar57 - uVar41) - uVar34 ^ uVar34 >> 0xf);
  if (blocks != (block *)0x0) {
    pUVar58 = (blocks->hh).tbl;
    pUVar49 = pUVar58->buckets[pUVar58->num_buckets - 1 & (uint)pUVar54].hh_head;
    if (pUVar49 != (UT_hash_handle *)0x0) {
      pUVar49 = (UT_hash_handle *)((int)pUVar49 - pUVar58->hho);
    }
    for (; pUVar49 != (UT_hash_handle *)0x0;
        pUVar49 = (UT_hash_handle *)((int)pUVar49[2].key - pUVar58->hho)) {
      if (((pUVar54 == pUVar49[3].tbl) && (pbVar29 = (block *)pUVar49[2].hashv, pbVar28 == pbVar29))
         && (pbVar50 = pbVar28, iVar27 = memcmp((void *)pUVar49[2].keylen,hexstr,(size_t)pbVar28),
            iVar27 == 0)) {
        cVar52 = '\x01';
        local_8b0 = (block *)0x0;
        goto LAB_00025122;
      }
      if (pUVar49[2].key == (void *)0x0) break;
    }
  }
  pbVar29 = (block *)_cgcalloc(0x68,1,DAT_00024c18,DAT_00024c1c,0x1563);
  if (pbVar29 == (block *)0x0) {
    tmp42._0_4_ = *DAT_0002588c;
    tmp42._4_4_ = DAT_0002588c[1];
    tmp42._8_4_ = DAT_0002588c[2];
    tmp42._12_4_ = DAT_0002588c[3];
    tmp42[16] = (char)DAT_0002588c[4];
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcpy((char *)pbVar29,hexstr);
  pbVar28 = blocks;
  piVar23 = DAT_00024c20;
  local_8b0 = blocks;
  iVar27 = *DAT_00024c20;
  pbVar29->block_no = iVar27;
  *piVar23 = iVar27 + 1;
  if (pbVar28 != (block *)0x0) {
    pUVar54 = (pbVar28->hh).tbl;
    if (3 < pUVar54->num_items) {
      pUVar49 = &pbVar28->hh;
      pUVar38 = (UT_hash_handle *)0x1;
LAB_00024bf2:
      pUVar55 = (UT_hash_handle *)0x0;
      uVar41 = 0;
      pUVar61 = pUVar49;
      pUVar49 = (UT_hash_handle *)0x0;
LAB_00024bfa:
      uVar41 = uVar41 + 1;
      _hs_qsize = (uint)pUVar38;
      if (pUVar38 == (UT_hash_handle *)0x0) {
        pUVar35 = (UT_hash_handle *)0x0;
        pUVar44 = pUVar61;
      }
      else {
        pUVar44 = (UT_hash_handle *)pUVar61->next;
        pUVar35 = (UT_hash_handle *)0x1;
        if (pUVar44 != (UT_hash_handle *)0x0) {
          pUVar35 = (UT_hash_handle *)0x1;
          pUVar44 = (UT_hash_handle *)((int)&pUVar44->tbl + pUVar54->hho);
          if (pUVar44 != (UT_hash_handle *)0x0) {
            while (pUVar35 != pUVar38) {
              pUVar44 = (UT_hash_handle *)pUVar44->next;
              pUVar35 = (UT_hash_handle *)((int)&pUVar35->tbl + 1);
              if ((pUVar44 == (UT_hash_handle *)0x0) ||
                 (pUVar44 = (UT_hash_handle *)((int)&pUVar44->tbl + pUVar54->hho),
                 pUVar44 == (UT_hash_handle *)0x0)) break;
            }
          }
        }
      }
LAB_00024c3a:
      do {
        pUVar30 = pUVar61;
        if (pUVar35 == (UT_hash_handle *)0x0) goto LAB_00024c84;
LAB_00024c3c:
        pUVar61 = pUVar30;
        if (_hs_qsize == 0 || pUVar44 == (UT_hash_handle *)0x0) {
          if ((pUVar30 != (UT_hash_handle *)0x0) &&
             (pUVar61 = (UT_hash_handle *)pUVar30->next, pUVar61 != (UT_hash_handle *)0x0)) {
            pUVar61 = (UT_hash_handle *)((int)&pUVar61->tbl + pUVar54->hho);
          }
        }
        else {
          iVar27 = pUVar54->hho;
          if (0 < *(int *)((int)pUVar30 + -iVar27 + 100) - *(int *)((int)pUVar44 + -iVar27 + 100)) {
            pUVar60 = (UT_hash_handle *)pUVar44->next;
            pUVar30 = pUVar44;
            if (pUVar60 == (UT_hash_handle *)0x0) goto joined_r0x000252b6;
            pUVar60 = (UT_hash_handle *)((int)&pUVar60->tbl + iVar27);
            goto joined_r0x000252b6;
          }
          if ((pUVar30 != (UT_hash_handle *)0x0) &&
             (pUVar61 = (UT_hash_handle *)pUVar30->next, pUVar61 != (UT_hash_handle *)0x0)) {
            pUVar61 = (UT_hash_handle *)((int)&pUVar61->tbl + iVar27);
          }
        }
        pUVar35 = (UT_hash_handle *)((int)&pUVar35[-1].hashv + 3);
        if (pUVar55 == (UT_hash_handle *)0x0) {
          pUVar55 = pUVar30;
          pUVar49 = pUVar30;
          if (pUVar30 != (UT_hash_handle *)0x0) {
            pvVar45 = (void *)0x0;
            goto LAB_00024c7e;
          }
          goto LAB_00024c3a;
        }
        while (pUVar30 != (UT_hash_handle *)0x0) {
          pvVar45 = (void *)((int)pUVar55 - pUVar54->hho);
          pUVar55->next = (void *)((int)pUVar30 - pUVar54->hho);
          pUVar55 = pUVar30;
LAB_00024c7e:
          while( true ) {
            pUVar55->prev = pvVar45;
            pUVar30 = pUVar61;
            if (pUVar35 != (UT_hash_handle *)0x0) goto LAB_00024c3c;
LAB_00024c84:
            if (pUVar44 == (UT_hash_handle *)0x0 || _hs_qsize == 0) {
              pUVar61 = pUVar44;
              if (pUVar44 != (UT_hash_handle *)0x0) goto LAB_00024bfa;
              if (pUVar55 != (UT_hash_handle *)0x0) {
                pUVar55->next = (void *)0x0;
              }
              if ((1 < uVar41) &&
                 (pUVar38 = (UT_hash_handle *)((int)pUVar38 << 1), pUVar55 = pUVar49,
                 pUVar49 != (UT_hash_handle *)0x0)) goto LAB_00024bf2;
              pUVar54->tail = pUVar55;
              pbVar50 = (block *)((int)pUVar49 - pUVar54->hho);
              local_8b0 = (block *)pbVar50->block_no;
              pvVar45 = (pbVar50->hh).prev;
              pbVar28 = (block *)(pbVar50->hh).next;
              blocks = pbVar50;
              if ((pvVar45 == (void *)0x0) && (pbVar28 == (block *)0x0)) {
                free(((pbVar50->hh).tbl)->buckets);
                free((pbVar50->hh).tbl);
                blocks = pbVar28;
              }
              else {
                pUVar54 = (pbVar50->hh).tbl;
                iVar27 = pUVar54->hho;
                pbVar46 = (block *)((int)pUVar54->tail - iVar27);
                bVar62 = pbVar50 == pbVar46;
                if (bVar62) {
                  pbVar46 = (block *)((int)pvVar45 + iVar27);
                }
                if (bVar62) {
                  pUVar54->tail = (UT_hash_handle *)pbVar46;
                }
                pbVar46 = pbVar28;
                pbVar26 = pbVar28;
                if (pvVar45 != (void *)0x0) {
                  *(block **)((int)pvVar45 + iVar27 + 8) = pbVar28;
                  pbVar28 = (block *)(pbVar50->hh).next;
                  pbVar46 = pbVar50;
                  pbVar26 = blocks;
                }
                blocks = pbVar26;
                pUVar54 = (pbVar46->hh).tbl;
                if (pbVar28 != (block *)0x0) {
                  *(void **)(pbVar28->hash + pUVar54->hho + 4) = pvVar45;
                }
                pUVar56 = pUVar54->buckets;
                uVar41 = (pbVar50->hh).hashv & pUVar54->num_buckets - 1;
                pUVar38 = (pbVar50->hh).hh_next;
                pUVar56[uVar41].count = pUVar56[uVar41].count - 1;
                pUVar49 = (pbVar50->hh).hh_prev;
                if (&pbVar50->hh == pUVar56[uVar41].hh_head) {
                  pUVar56[uVar41].hh_head = pUVar38;
                }
                if (pUVar49 != (UT_hash_handle *)0x0) {
                  pUVar49->hh_next = pUVar38;
                  pUVar38 = (pbVar50->hh).hh_next;
                }
                if (pUVar38 != (UT_hash_handle *)0x0) {
                  pUVar38->hh_prev = pUVar49;
                }
                pUVar54->num_items = pUVar54->num_items - 1;
                pbVar28 = pbVar46;
              }
              free(pbVar50);
              goto LAB_00024d40;
            }
            pUVar60 = pUVar35;
            pUVar30 = pUVar44;
            if (pUVar44->next != (void *)0x0) {
              pUVar60 = (UT_hash_handle *)((int)pUVar44->next + pUVar54->hho);
            }
joined_r0x000252b6:
            pUVar44 = pUVar60;
            _hs_qsize = _hs_qsize - 1;
            if (pUVar55 != (UT_hash_handle *)0x0) break;
            pvVar45 = (void *)0x0;
            pUVar55 = pUVar30;
            pUVar49 = pUVar30;
          }
        }
        pUVar55->next = (void *)0x0;
        pUVar55 = pUVar30;
      } while( true );
    }
    local_8b0 = (block *)0x0;
  }
LAB_00024d40:
  sVar31 = strlen((char *)pbVar29);
  uVar41 = 0xfeedbeef;
  uVar34 = 0x9e3779b9;
  uVar57 = uVar34;
  pbVar50 = pbVar29;
  for (uVar37 = sVar31; 0xb < uVar37; uVar37 = uVar37 - 0xc) {
    pcVar59 = pbVar50->hash;
    pcVar36 = pbVar50->hash;
    pcVar13 = pbVar50->hash;
    pcVar14 = pbVar50->hash;
    pcVar15 = pbVar50->hash;
    pcVar16 = pbVar50->hash;
    pcVar17 = pbVar50->hash;
    pcVar18 = pbVar50->hash;
    pcVar19 = pbVar50->hash;
    pcVar20 = pbVar50->hash;
    pcVar21 = pbVar50->hash;
    pcVar22 = pbVar50->hash;
    pbVar50 = (block *)(pbVar50->hash + 0xc);
    iVar27 = uVar57 + (uint)(byte)pcVar17[4] +
                      (uint)(byte)pcVar59[6] * 0x10000 + (uint)(byte)pcVar13[5] * 0x100 +
                      (uint)(byte)pcVar19[7] * 0x1000000;
    uVar41 = (uint)(byte)pcVar21[8] +
             (uint)(byte)pcVar15[10] * 0x10000 + (uint)(byte)pcVar16[9] * 0x100 +
             (uint)(byte)pcVar22[0xb] * 0x1000000 + uVar41;
    uVar39 = uVar34 + ((((uint)(byte)*pcVar18 +
                         (uint)(byte)pcVar36[2] * 0x10000 + (uint)(byte)pcVar14[1] * 0x100 +
                        (uint)(byte)pcVar20[3] * 0x1000000) - iVar27) - uVar41) ^ uVar41 >> 0xd;
    uVar34 = (iVar27 - uVar41) - uVar39 ^ uVar39 << 8;
    uVar57 = (uVar41 - uVar39) - uVar34 ^ uVar34 >> 0xd;
    uVar40 = (uVar39 - uVar34) - uVar57 ^ uVar57 >> 0xc;
    uVar41 = (uVar34 - uVar57) - uVar40 ^ uVar40 << 0x10;
    uVar39 = (uVar57 - uVar40) - uVar41 ^ uVar41 >> 5;
    uVar34 = (uVar40 - uVar41) - uVar39 ^ uVar39 >> 3;
    uVar57 = (uVar41 - uVar39) - uVar34 ^ uVar34 << 10;
    uVar41 = (uVar39 - uVar34) - uVar57 ^ uVar57 >> 0xf;
  }
  uVar41 = uVar41 + sVar31;
  switch(uVar37) {
  case 0xb:
    uVar41 = uVar41 + (uint)(byte)pbVar50->hash[10] * 0x1000000;
  case 10:
    uVar41 = uVar41 + (uint)(byte)pbVar50->hash[9] * 0x10000;
  case 9:
    uVar41 = uVar41 + (uint)(byte)pbVar50->hash[8] * 0x100;
  case 8:
    uVar57 = uVar57 + (uint)(byte)pbVar50->hash[7] * 0x1000000;
  case 7:
    uVar57 = uVar57 + (uint)(byte)pbVar50->hash[6] * 0x10000;
  case 6:
    uVar57 = uVar57 + (uint)(byte)pbVar50->hash[5] * 0x100;
  case 5:
    uVar57 = uVar57 + (byte)pbVar50->hash[4];
  case 4:
    uVar34 = uVar34 + (uint)(byte)pbVar50->hash[3] * 0x1000000;
  case 3:
    uVar34 = uVar34 + (uint)(byte)pbVar50->hash[2] * 0x10000;
  case 2:
    uVar34 = uVar34 + (uint)(byte)pbVar50->hash[1] * 0x100;
  case 1:
    uVar34 = uVar34 + (byte)pbVar50->hash[0];
  }
  uVar34 = (uVar34 - uVar57) - uVar41 ^ uVar41 >> 0xd;
  uVar57 = (uVar57 - uVar41) - uVar34 ^ uVar34 << 8;
  (pbVar29->hh).key = pbVar29;
  uVar37 = (uVar41 - uVar34) - uVar57 ^ uVar57 >> 0xd;
  uVar41 = (uVar34 - uVar57) - uVar37 ^ uVar37 >> 0xc;
  uVar34 = (uVar57 - uVar37) - uVar41 ^ uVar41 << 0x10;
  uVar57 = (uVar37 - uVar41) - uVar34 ^ uVar34 >> 5;
  uVar41 = (uVar41 - uVar34) - uVar57 ^ uVar57 >> 3;
  uVar34 = (uVar34 - uVar57) - uVar41 ^ uVar41 << 10;
  uVar41 = (uVar57 - uVar41) - uVar34 ^ uVar34 >> 0xf;
  (pbVar29->hh).hashv = uVar41;
  sVar31 = strlen((char *)pbVar29);
  (pbVar29->hh).keylen = sVar31;
  if (pbVar28 == (block *)0x0) {
    (pbVar29->hh).next = (void *)0x0;
    (pbVar29->hh).prev = (void *)0x0;
    blocks = pbVar29;
    pUVar54 = (UT_hash_table *)malloc(0x2c);
    (pbVar29->hh).tbl = pUVar54;
    if (pUVar54 == (UT_hash_table *)0x0) goto LAB_00025764;
    pUVar54->buckets = (UT_hash_bucket *)0x0;
    pUVar54->num_buckets = 0;
    pUVar54->log2_num_buckets = 0;
    pUVar54->num_items = 0;
    pUVar54->tail = (UT_hash_handle *)0x0;
    pUVar54->hho = 0;
    pUVar54->ideal_chain_maxlen = 0;
    pUVar54->nonideal_items = 0;
    pUVar54->ineff_expands = 0;
    pUVar54->noexpand = 0;
    pUVar54->signature = 0;
    pUVar54 = (pbVar29->hh).tbl;
    pUVar54->tail = &pbVar29->hh;
    pUVar54->num_buckets = 0x20;
    pUVar54->log2_num_buckets = 5;
    pUVar54->hho = 0x44;
    pUVar56 = (UT_hash_bucket *)malloc(0x180);
    pUVar54->buckets = pUVar56;
    if (pUVar56 == (UT_hash_bucket *)0x0) goto LAB_00025764;
    memset(pUVar56,0,0x180);
    pUVar54 = (pbVar29->hh).tbl;
    pUVar54->signature = 0xa0111fe1;
  }
  else {
    pUVar54 = (pbVar28->hh).tbl;
    (pbVar29->hh).next = (void *)0x0;
    (pbVar29->hh).tbl = pUVar54;
    pUVar54 = (pbVar28->hh).tbl;
    pUVar49 = pUVar54->tail;
    iVar27 = pUVar54->hho;
    pUVar49->next = pbVar29;
    (pbVar29->hh).prev = (void *)((int)pUVar49 - iVar27);
    pUVar54->tail = &pbVar29->hh;
  }
  pUVar56 = pUVar54->buckets;
  uVar41 = uVar41 & pUVar54->num_buckets - 1;
  pUVar54->num_items = pUVar54->num_items + 1;
  pUVar49 = pUVar56[uVar41].hh_head;
  uVar34 = pUVar56[uVar41].count + 1;
  pUVar56[uVar41].count = uVar34;
  (pbVar29->hh).hh_next = pUVar49;
  (pbVar29->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar49 != (UT_hash_handle *)0x0) {
    pUVar49->hh_prev = &pbVar29->hh;
  }
  pUVar56[uVar41].hh_head = &pbVar29->hh;
  iVar27 = pUVar56[uVar41].expand_mult + 1;
  pbVar50 = (block *)(iVar27 * 5);
  if ((uint)(iVar27 * 10) <= uVar34) {
    pUVar54 = (pbVar29->hh).tbl;
    pbVar50 = (block *)pUVar54->noexpand;
    if (pbVar50 != (block *)0x1) {
      sVar31 = pUVar54->num_buckets * 0x18;
      pUVar56 = (UT_hash_bucket *)malloc(sVar31);
      if (pUVar56 == (UT_hash_bucket *)0x0) {
LAB_00025764:
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar56,0,sVar31);
      pUVar54 = (pbVar29->hh).tbl;
      uVar34 = pUVar54->num_buckets;
      pUVar54->nonideal_items = 0;
      uVar41 = pUVar54->num_items >> (pUVar54->log2_num_buckets + 1 & 0xff);
      uVar57 = uVar34 * 2 - 1;
      if ((uVar57 & pUVar54->num_items) != 0) {
        uVar41 = uVar41 + 1;
      }
      pUVar54->ideal_chain_maxlen = uVar41;
      if (uVar34 == 0) {
        local_8ac = pUVar54->buckets;
      }
      else {
        local_8ac = pUVar54->buckets;
        local_8bc = 0;
        do {
          pUVar49 = *(UT_hash_handle **)((int)&local_8ac->hh_head + local_8bc);
          while (pUVar49 != (UT_hash_handle *)0x0) {
            pUVar38 = pUVar49->hh_next;
            uVar39 = uVar57 & pUVar49->hashv;
            uVar37 = pUVar56[uVar39].count + 1;
            pUVar56[uVar39].count = uVar37;
            if (uVar41 < uVar37) {
              pUVar54->nonideal_items = pUVar54->nonideal_items + 1;
              uVar37 = __aeabi_uidiv(uVar37,uVar41);
              pUVar56[uVar39].expand_mult = uVar37;
            }
            pUVar61 = pUVar56[uVar39].hh_head;
            pUVar49->hh_prev = (UT_hash_handle *)0x0;
            pUVar49->hh_next = pUVar61;
            if (pUVar61 != (UT_hash_handle *)0x0) {
              pUVar61->hh_prev = pUVar49;
            }
            pUVar56[uVar39].hh_head = pUVar49;
            pUVar49 = pUVar38;
          }
          local_8bc = local_8bc + 0xc;
        } while (local_8bc != uVar34 * 0xc);
      }
      free(local_8ac);
      pUVar54 = (pbVar29->hh).tbl;
      uVar34 = pUVar54->nonideal_items;
      pbVar50 = (block *)pUVar54->num_items;
      pUVar54->buckets = pUVar56;
      pUVar54->log2_num_buckets = pUVar54->log2_num_buckets + 1;
      uVar41 = uVar34;
      if (uVar34 <= (uint)pbVar50 >> 1) {
        uVar41 = 0;
      }
      pUVar54->num_buckets = pUVar54->num_buckets << 1;
      if ((uint)pbVar50 >> 1 < uVar34) {
        uVar34 = pUVar54->ineff_expands + 1;
        pUVar54->ineff_expands = uVar34;
        uVar41 = uVar34;
        if (1 < uVar34) {
          uVar41 = 1;
        }
        if (1 < uVar34) {
          pUVar54->noexpand = uVar41;
        }
      }
      else {
        pUVar54->ineff_expands = uVar41;
      }
    }
  }
  iVar27 = 0x1d - (uint)work->data[0x48];
  uVar41 = iVar27 * 8;
  dVar63 = DAT_000252e0;
  if (7 < (int)uVar41) {
    pbVar50 = (block *)0xffff;
    dVar63 = (double)__aeabi_ul2d(0xffff << (uVar41 & 0xff),
                                  0xffff << (uVar41 - 0x20 & 0xff) |
                                  0xffffU >> (iVar27 * -8 + 0x20U & 0xff));
  }
  pdVar24 = DAT_000252e8;
  uVar41 = *(uint *)(work->data + 0x48);
  pbVar29 = (block *)((uVar41 >> 8 & 0xff) << 0x10 | (uVar41 >> 0x10 & 0xff) << 8 | uVar41 >> 0x18);
  dVar63 = dVar63 / (double)(longlong)(int)pbVar29;
  if (dVar63 != *DAT_000252e8) {
    uVar64 = __fixunsdfdi(SUB84(dVar63,0),(int)((ulonglong)dVar63 >> 0x20));
    pbVar50 = DAT_00025880;
    suffix_string((ulonglong)in_stack_fffff734 << 0x20,(char *)uVar64,
                  (size_t)((ulonglong)uVar64 >> 0x20),(int)DAT_00025880);
    pcVar59 = DAT_00025860;
    *pdVar24 = dVar63;
    if (((*pcVar59 != '\0') || (*DAT_00025864 != '\0')) ||
       (pbVar29 = *DAT_00025868, 4 < (int)pbVar29)) {
      pbVar29 = DAT_00025880;
      snprintf(tmp42,0x800,DAT_00025884);
      pbVar50 = (block *)0x0;
      _applog(5,tmp42,false);
    }
  }
  if (local_8b0 == (block *)0x0) {
    cVar52 = '\0';
  }
  else {
    cVar52 = DAT_000252ec->hash[0];
    pbVar29 = DAT_000252ec;
    if (cVar52 != '\0') {
      if ((*DAT_000252f0 == '\0') && (*DAT_000252f4 == '\0')) {
        pbVar29 = *DAT_000252f8;
        cVar52 = '\0';
        if ((int)pbVar29 < 7) goto LAB_00025122;
      }
      cVar52 = '\0';
      pbVar29 = local_8b0;
      snprintf(tmp42,0x800,DAT_000252fc);
      pbVar50 = (block *)0x0;
      _applog(7,tmp42,false);
    }
  }
LAB_00025122:
  iVar27 = pthread_rwlock_unlock(DAT_00025300);
  if (iVar27 != 0) {
    _rw_unlock(DAT_00025890,(char *)0x1585,pbVar50->hash,(int)pbVar29);
  }
  p_Var42 = selective_yield;
  (*selective_yield)();
  if (cVar52 == '\0') {
    iVar27 = pthread_mutex_lock(DAT_000255a0);
    if (iVar27 != 0) {
      _mutex_lock((pthread_mutex_t *)DAT_00025894,(char *)0x1528,pbVar50->hash,(int)p_Var42);
    }
    iVar27 = pthread_rwlock_wrlock(DAT_000255a4);
    if (iVar27 != 0) {
      _wr_lock(DAT_00025894,(char *)0x1528,pbVar50->hash,(int)p_Var42);
    }
    ppVar53 = DAT_000255ac;
    ptVar25 = DAT_000255a8;
    cgtime(DAT_000255a8);
    strcpy(DAT_000255b0,hexstr);
    _cg_memcpy(DAT_000255b4,bedata,0x20,DAT_00025588,ppVar53->__size,0x152b);
    iVar27 = ptVar25->tv_usec;
    tmp_time = ptVar25->tv_sec;
    ptVar33 = localtime(&tmp_time);
    line = ptVar33->tm_hour;
    pcVar59 = DAT_000255bc;
    snprintf(DAT_000255b8,0x20,DAT_000255bc,line,ptVar33->tm_min,ptVar33->tm_sec,iVar27 / 1000);
    iVar27 = pthread_rwlock_unlock(DAT_000255a4);
    if (iVar27 != 0) {
      _rw_unlock(ppVar53,(char *)0x152d,pcVar59,line);
    }
    iVar27 = pthread_mutex_unlock(DAT_000255a0);
    if (iVar27 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)DAT_00025894,(char *)0x152d,pcVar59,line);
    }
    (*selective_yield)();
    iVar27 = 0;
    do {
      if (DAT_000255b0[iVar27] != '0') break;
      iVar27 = iVar27 + 1;
    } while (iVar27 != 0x39);
    strncpy(DAT_000255c0,DAT_000255b0 + iVar27,8);
    prev_block[8] = '\0';
    if (((*DAT_00025590 != '\0') || (*DAT_00025594 != '\0')) || (5 < *DAT_00025598)) {
      snprintf(tmp42,0x800,DAT_000255c8,DAT_000255b0,DAT_000255c4);
      _applog(6,tmp42,false);
    }
  }
  if (((local_8b0 != (block *)0x0) && (DAT_000252ec->hash[0] != '\0')) &&
     ((*DAT_000252f0 != '\0' || ((*DAT_000252f4 != '\0' || (6 < (int)*DAT_000252f8)))))) {
    snprintf(tmp42,0x800,DAT_000252fc,local_8b0);
    _applog(7,tmp42,false);
  }
  if (cVar52 != '\0') {
    cVar52 = '\x01';
    iVar27 = memcmp(ppVar47->prev_block,bedata,0x20);
    if (iVar27 != 0) {
      iVar27 = memcmp(bedata,DAT_00025304,0x20);
      if (iVar27 == 0) {
        if (((*DAT_00025590 != '\0') || (*DAT_00025594 != '\0')) || (5 < *DAT_00025598)) {
          snprintf(tmp42,0x800,DAT_000255d0,ppVar47->pool_no,height);
          _applog(6,tmp42,false);
        }
        cVar52 = '\x01';
        _cg_memcpy(ppVar47->prev_block,bedata,0x20,DAT_00025588,DAT_00025584,0x15f0);
      }
      else {
        cVar52 = DAT_000252ec->hash[0];
        if ((cVar52 != '\0') &&
           (((*DAT_000252f0 != '\0' || (*DAT_000252f4 != '\0')) ||
            (cVar52 = '\0', 6 < (int)*DAT_000252f8)))) {
          cVar52 = '\0';
          snprintf(tmp42,0x800,DAT_00025308,ppVar47->pool_no,height);
          _applog(7,tmp42,false);
        }
      }
    }
    if (work->longpoll != false) {
      uVar41 = pool_strategy + ~POOL_ROTATE;
      work_block = work_block + 1;
      work->work_block = work_block;
      if ((uVar41 < 2) || (ppVar51 = work->pool, ppVar32 = current_pool(), ppVar51 == ppVar32)) {
        if (work->stratum == false) {
          if (((*DAT_00025860 != '\0') || (*DAT_00025864 != '\0')) || (4 < (int)*DAT_00025868)) {
            iVar27 = DAT_00025870;
            if (work->gbt != false) {
              iVar27 = DAT_0002586c;
            }
            snprintf(tmp42,0x800,DAT_00025874,iVar27,work->pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else if (((*DAT_00025590 != '\0') || (*DAT_00025594 != '\0')) || (4 < *DAT_00025598)) {
          snprintf(tmp42,0x800,DAT_000255cc,ppVar47->pool_no);
          _applog(5,tmp42,false);
        }
        restart_threads();
      }
    }
    goto out;
  }
  _cg_memcpy(ppVar47->prev_block,bedata,0x20,DAT_00025588,DAT_00025584,0x15be);
  cVar52 = '\0';
  if (*DAT_0002558c == 1) goto out;
  work_block = work_block + 1;
  work->work_block = work_block;
  if (work->longpoll == false) {
    if (*DAT_000255d4 == '\0') {
      if ((ppVar47->gbt_solo == false) &&
         (((*DAT_00025860 != '\0' || (*DAT_00025864 != '\0')) || (4 < (int)*DAT_00025868)))) {
        tmp42._0_4_ = *DAT_0002587c;
        tmp42._4_4_ = DAT_0002587c[1];
        tmp42._8_4_ = DAT_0002587c[2];
        tmp42._12_4_ = DAT_0002587c[3];
        tmp42._16_4_ = DAT_0002587c[4];
        tmp42._20_4_ = DAT_0002587c[5];
        tmp42._24_4_ = DAT_0002587c[6];
        tmp42[28] = (char)(short)DAT_0002587c[7];
        tmp42[29] = (char)((ushort)(short)DAT_0002587c[7] >> 8);
        _applog(5,tmp42,false);
      }
    }
    else if ((ppVar47->gbt_solo == false) &&
            (((*DAT_00025590 != '\0' || (*DAT_00025594 != '\0')) || (4 < *DAT_00025598)))) {
      tmp42._0_4_ = *DAT_000255d8;
      tmp42._4_4_ = DAT_000255d8[1];
      tmp42._8_4_ = DAT_000255d8[2];
      tmp42._12_4_ = DAT_000255d8[3];
      tmp42._16_4_ = DAT_000255d8[4];
      tmp42._20_4_ = DAT_000255d8[5];
      tmp42._24_4_ = DAT_000255d8[6];
      tmp42._28_4_ = DAT_000255d8[7];
      tmp42._32_4_ = DAT_000255d8[8];
      tmp42._36_4_ = DAT_000255d8[9];
      tmp42._40_4_ = DAT_000255d8[10];
      tmp42._44_4_ = DAT_000255d8[0xb];
      tmp42._48_4_ = DAT_000255d8[0xc];
      tmp42._52_2_ = (undefined2)DAT_000255d8[0xd];
      tmp42[54] = (char)((uint)DAT_000255d8[0xd] >> 0x10);
      _applog(5,tmp42,false);
    }
  }
  else if (work->stratum == false) {
    if (((*DAT_00025860 != '\0') || (*DAT_00025864 != '\0')) || (4 < (int)*DAT_00025868)) {
      uVar41 = work->pool->pool_no;
      pcVar59 = DAT_00025878;
      iVar27 = DAT_00025870;
      if (work->gbt != false) {
        iVar27 = DAT_0002586c;
      }
      goto LAB_00025386;
    }
  }
  else if (((*DAT_00025590 != '\0') || (*DAT_00025594 != '\0')) || (4 < *DAT_00025598)) {
    pcVar59 = DAT_0002559c;
    iVar27 = ppVar47->pool_no;
    uVar41 = height;
LAB_00025386:
    snprintf(tmp42,0x800,pcVar59,iVar27,uVar41);
    _applog(5,tmp42,false);
  }
  restart_threads();
  cVar52 = '\x01';
out:
  work->longpoll = false;
  return (_Bool)cVar52;
}

