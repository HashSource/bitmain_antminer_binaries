
/* WARNING: Unknown calling convention */

_Bool add_cgpu(cgpu_info *cgpu)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  int *piVar8;
  byte bVar9;
  char *pcVar10;
  char *pcVar11;
  int *piVar12;
  int *piVar13;
  char *pcVar14;
  UT_hash_handle *pUVar15;
  char *pcVar16;
  int *piVar17;
  UT_hash_table *__n;
  _cgpu_devid_counter *__s;
  size_t sVar18;
  time_t tVar19;
  int iVar20;
  UT_hash_bucket *pUVar21;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  byte *pbVar22;
  _cgpu_devid_counter *p_Var23;
  int line;
  int line_00;
  int line_01;
  int line_02;
  UT_hash_handle *pUVar24;
  uint uVar25;
  uint uVar26;
  UT_hash_handle *pUVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  void *pvVar32;
  UT_hash_table *pUVar33;
  uint uVar34;
  byte *__s_00;
  UT_hash_handle *pUVar35;
  int local_34;
  UT_hash_bucket *local_30;
  
  uVar30 = 0x9e3779b9;
  __s_00 = (byte *)cgpu->drv->name;
  uVar34 = 0xfeedbeef;
  __n = (UT_hash_table *)strlen((char *)__s_00);
  uVar25 = uVar30;
  pbVar22 = __s_00;
  for (pUVar33 = __n; (UT_hash_table *)0xb < pUVar33;
      pUVar33 = (UT_hash_table *)&pUVar33[-1].ineff_expands) {
    pbVar6 = pbVar22 + 2;
    pbVar7 = pbVar22 + 6;
    pbVar1 = pbVar22 + 1;
    pbVar2 = pbVar22 + 5;
    bVar9 = *pbVar22;
    pbVar3 = pbVar22 + 3;
    pbVar4 = pbVar22 + 4;
    pbVar5 = pbVar22 + 7;
    uVar34 = (uint)pbVar22[10] * 0x10000 + (uint)pbVar22[9] * 0x100 + (uint)pbVar22[8] +
             (uint)pbVar22[0xb] * 0x1000000 + uVar34;
    pbVar22 = pbVar22 + 0xc;
    iVar31 = uVar25 + (uint)*pbVar7 * 0x10000 + (uint)*pbVar2 * 0x100 + (uint)*pbVar4 +
                      (uint)*pbVar5 * 0x1000000;
    uVar25 = uVar30 + ((((uint)*pbVar6 * 0x10000 + (uint)*pbVar1 * 0x100 + (uint)bVar9 +
                        (uint)*pbVar3 * 0x1000000) - uVar34) - iVar31) ^ uVar34 >> 0xd;
    uVar30 = (iVar31 - uVar34) - uVar25 ^ uVar25 << 8;
    uVar34 = (uVar34 - uVar25) - uVar30 ^ uVar30 >> 0xd;
    uVar26 = (uVar25 - uVar30) - uVar34 ^ uVar34 >> 0xc;
    uVar25 = (uVar30 - uVar34) - uVar26 ^ uVar26 << 0x10;
    uVar34 = (uVar34 - uVar26) - uVar25 ^ uVar25 >> 5;
    uVar30 = (uVar26 - uVar25) - uVar34 ^ uVar34 >> 3;
    uVar25 = (uVar25 - uVar34) - uVar30 ^ uVar30 << 10;
    uVar34 = (uVar34 - uVar30) - uVar25 ^ uVar25 >> 0xf;
  }
  uVar34 = (int)&__n->buckets + uVar34;
  switch(pUVar33) {
  case (UT_hash_table *)0xb:
    uVar34 = uVar34 + (uint)pbVar22[10] * 0x1000000;
  case (UT_hash_table *)0xa:
    uVar34 = uVar34 + (uint)pbVar22[9] * 0x10000;
  case (UT_hash_table *)0x9:
    uVar34 = uVar34 + (uint)pbVar22[8] * 0x100;
  case (UT_hash_table *)0x8:
    uVar25 = uVar25 + (uint)pbVar22[7] * 0x1000000;
  case (UT_hash_table *)0x7:
    uVar25 = uVar25 + (uint)pbVar22[6] * 0x10000;
  case (UT_hash_table *)0x6:
    uVar25 = uVar25 + (uint)pbVar22[5] * 0x100;
  case (UT_hash_table *)0x5:
    uVar25 = uVar25 + pbVar22[4];
  case (UT_hash_table *)0x4:
    uVar30 = uVar30 + (uint)pbVar22[3] * 0x1000000;
  case (UT_hash_table *)0x3:
    uVar30 = uVar30 + (uint)pbVar22[2] * 0x10000;
  case (UT_hash_table *)0x2:
    uVar30 = uVar30 + (uint)pbVar22[1] * 0x100;
  case (UT_hash_table *)0x1:
    uVar30 = uVar30 + *pbVar22;
  }
  uVar30 = (uVar30 - uVar25) - uVar34 ^ uVar34 >> 0xd;
  uVar25 = (uVar25 - uVar34) - uVar30 ^ uVar30 << 8;
  uVar34 = (uVar34 - uVar30) - uVar25 ^ uVar25 >> 0xd;
  uVar30 = (uVar30 - uVar25) - uVar34 ^ uVar34 >> 0xc;
  uVar25 = (uVar25 - uVar34) - uVar30 ^ uVar30 << 0x10;
  uVar34 = (uVar34 - uVar30) - uVar25 ^ uVar25 >> 5;
  uVar30 = (uVar30 - uVar25) - uVar34 ^ uVar34 >> 3;
  uVar25 = (uVar25 - uVar34) - uVar30 ^ uVar30 << 10;
  pvVar32 = (void *)((uVar34 - uVar30) - uVar25 ^ uVar25 >> 0xf);
  if (add_cgpu::devids != (_cgpu_devid_counter *)0x0) {
    pUVar33 = (add_cgpu::devids->hh).tbl;
    pUVar27 = pUVar33->buckets[pUVar33->num_buckets - 1 & (uint)pvVar32].hh_head;
    if (pUVar27 != (UT_hash_handle *)0x0) {
      pUVar27 = (UT_hash_handle *)((int)pUVar27 - pUVar33->hho);
    }
    for (; pUVar27 != (UT_hash_handle *)0x0;
        pUVar27 = (UT_hash_handle *)(pUVar27->keylen - pUVar33->hho)) {
      if (((pUVar27[1].prev == pvVar32) && (__n == pUVar27[1].tbl)) &&
         (iVar31 = memcmp((void *)pUVar27->hashv,__s_00,(size_t)__n), iVar31 == 0)) {
        pvVar32 = (void *)((int)pUVar27->prev + 1);
        pUVar27->prev = pvVar32;
        cgpu->device_id = (int)pvVar32;
        goto LAB_00029fa6;
      }
      if (pUVar27->keylen == 0) break;
    }
  }
  __s = (_cgpu_devid_counter *)_cgmalloc(0x28,"cgminer.c","add_cgpu",0x2b80);
  _cg_memcpy(__s,cgpu->drv->name,4,"cgminer.c","add_cgpu",0x2b81);
  uVar30 = 0xfeedbeef;
  __s->lastid = 0;
  cgpu->device_id = 0;
  sVar18 = strlen((char *)__s);
  uVar25 = 0x9e3779b9;
  uVar34 = uVar25;
  p_Var23 = __s;
  for (uVar26 = sVar18; 0xb < uVar26; uVar26 = uVar26 - 0xc) {
    pUVar35 = &p_Var23->hh;
    pcVar10 = p_Var23->name;
    pUVar24 = &p_Var23->hh;
    pcVar11 = p_Var23->name;
    piVar12 = &p_Var23->lastid;
    piVar13 = &p_Var23->lastid;
    pUVar27 = &p_Var23->hh;
    pcVar14 = p_Var23->name;
    pUVar15 = &p_Var23->hh;
    pcVar16 = p_Var23->name;
    piVar8 = &p_Var23->lastid;
    piVar17 = &p_Var23->lastid;
    p_Var23 = (_cgpu_devid_counter *)&(p_Var23->hh).prev;
    uVar30 = (uint)*(byte *)&pUVar27->tbl +
             (uint)*(byte *)((int)&pUVar35->tbl + 2) * 0x10000 +
             (uint)*(byte *)((int)&pUVar24->tbl + 1) * 0x100 +
             (uint)*(byte *)((int)&pUVar15->tbl + 3) * 0x1000000 + uVar30;
    iVar31 = uVar34 + (uint)(byte)*piVar8 +
                      (uint)*(byte *)((int)piVar12 + 2) * 0x10000 +
                      (uint)*(byte *)((int)piVar13 + 1) * 0x100 +
                      (uint)*(byte *)((int)piVar17 + 3) * 0x1000000;
    uVar25 = uVar25 + ((((uint)(byte)pcVar10[2] * 0x10000 + (uint)(byte)pcVar11[1] * 0x100 +
                         (uint)(byte)*pcVar14 + (uint)(byte)pcVar16[3] * 0x1000000) - uVar30) -
                      iVar31) ^ uVar30 >> 0xd;
    uVar28 = (iVar31 - uVar30) - uVar25 ^ uVar25 << 8;
    uVar34 = (uVar30 - uVar25) - uVar28 ^ uVar28 >> 0xd;
    uVar30 = (uVar25 - uVar28) - uVar34 ^ uVar34 >> 0xc;
    uVar29 = (uVar28 - uVar34) - uVar30 ^ uVar30 << 0x10;
    uVar28 = (uVar34 - uVar30) - uVar29 ^ uVar29 >> 5;
    uVar25 = (uVar30 - uVar29) - uVar28 ^ uVar28 >> 3;
    uVar34 = (uVar29 - uVar28) - uVar25 ^ uVar25 << 10;
    uVar30 = (uVar28 - uVar25) - uVar34 ^ uVar34 >> 0xf;
  }
  uVar30 = uVar30 + sVar18;
  switch(uVar26) {
  case 0xb:
    uVar30 = uVar30 + (uint)*(byte *)((int)&(p_Var23->hh).tbl + 2) * 0x1000000;
  case 10:
    uVar30 = uVar30 + (uint)*(byte *)((int)&(p_Var23->hh).tbl + 1) * 0x10000;
  case 9:
    uVar30 = uVar30 + (uint)*(byte *)&(p_Var23->hh).tbl * 0x100;
  case 8:
    uVar34 = uVar34 + (uint)*(byte *)((int)&p_Var23->lastid + 3) * 0x1000000;
  case 7:
    uVar34 = uVar34 + (uint)*(byte *)((int)&p_Var23->lastid + 2) * 0x10000;
  case 6:
    uVar34 = uVar34 + (uint)*(byte *)((int)&p_Var23->lastid + 1) * 0x100;
  case 5:
    uVar34 = uVar34 + (byte)p_Var23->lastid;
  case 4:
    uVar25 = uVar25 + (uint)(byte)p_Var23->name[3] * 0x1000000;
  case 3:
    uVar25 = uVar25 + (uint)(byte)p_Var23->name[2] * 0x10000;
  case 2:
    uVar25 = uVar25 + (uint)(byte)p_Var23->name[1] * 0x100;
  case 1:
    uVar25 = uVar25 + (byte)p_Var23->name[0];
  }
  uVar25 = (uVar25 - uVar34) - uVar30 ^ uVar30 >> 0xd;
  uVar34 = (uVar34 - uVar30) - uVar25 ^ uVar25 << 8;
  (__s->hh).key = __s;
  uVar26 = (uVar30 - uVar25) - uVar34 ^ uVar34 >> 0xd;
  uVar30 = (uVar25 - uVar34) - uVar26 ^ uVar26 >> 0xc;
  uVar25 = (uVar34 - uVar26) - uVar30 ^ uVar30 << 0x10;
  uVar34 = (uVar26 - uVar30) - uVar25 ^ uVar25 >> 5;
  uVar30 = (uVar30 - uVar25) - uVar34 ^ uVar34 >> 3;
  uVar25 = (uVar25 - uVar34) - uVar30 ^ uVar30 << 10;
  uVar30 = (uVar34 - uVar30) - uVar25 ^ uVar25 >> 0xf;
  (__s->hh).hashv = uVar30;
  sVar18 = strlen((char *)__s);
  p_Var23 = add_cgpu::devids;
  (__s->hh).keylen = sVar18;
  if (p_Var23 == (_cgpu_devid_counter *)0x0) {
    (__s->hh).next = (void *)0x0;
    (__s->hh).prev = (void *)0x0;
    add_cgpu::devids = __s;
    pUVar33 = (UT_hash_table *)malloc(0x2c);
    (__s->hh).tbl = pUVar33;
    if (pUVar33 == (UT_hash_table *)0x0) goto LAB_0002a320;
    pUVar33->buckets = (UT_hash_bucket *)0x0;
    pUVar33->num_buckets = 0;
    pUVar33->log2_num_buckets = 0;
    pUVar33->num_items = 0;
    pUVar33->tail = (UT_hash_handle *)0x0;
    pUVar33->hho = 0;
    pUVar33->ideal_chain_maxlen = 0;
    pUVar33->nonideal_items = 0;
    pUVar33->ineff_expands = 0;
    pUVar33->noexpand = 0;
    pUVar33->signature = 0;
    pUVar33 = (__s->hh).tbl;
    pUVar33->tail = &__s->hh;
    pUVar33->num_buckets = 0x20;
    pUVar33->log2_num_buckets = 5;
    pUVar33->hho = 8;
    pUVar21 = (UT_hash_bucket *)malloc(0x180);
    pUVar33->buckets = pUVar21;
    if (pUVar21 == (UT_hash_bucket *)0x0) goto LAB_0002a320;
    memset(pUVar21,0,0x180);
    pUVar33 = (__s->hh).tbl;
    pUVar33->signature = 0xa0111fe1;
  }
  else {
    (__s->hh).tbl = (p_Var23->hh).tbl;
    (__s->hh).next = (void *)0x0;
    pUVar33 = (p_Var23->hh).tbl;
    pUVar27 = pUVar33->tail;
    iVar31 = pUVar33->hho;
    pUVar27->next = __s;
    (__s->hh).prev = (void *)((int)pUVar27 - iVar31);
    pUVar33->tail = &__s->hh;
  }
  pUVar21 = pUVar33->buckets;
  uVar30 = uVar30 & pUVar33->num_buckets - 1;
  pUVar33->num_items = pUVar33->num_items + 1;
  pUVar27 = pUVar21[uVar30].hh_head;
  uVar25 = pUVar21[uVar30].count + 1;
  pUVar21[uVar30].count = uVar25;
  (__s->hh).hh_next = pUVar27;
  (__s->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar27 != (UT_hash_handle *)0x0) {
    pUVar27->hh_prev = &__s->hh;
  }
  pUVar21[uVar30].hh_head = &__s->hh;
  if (((pUVar21[uVar30].expand_mult + 1) * 10 <= uVar25) &&
     (pUVar33 = (__s->hh).tbl, pUVar33->noexpand != 1)) {
    sVar18 = pUVar33->num_buckets * 0x18;
    pUVar21 = (UT_hash_bucket *)malloc(sVar18);
    if (pUVar21 == (UT_hash_bucket *)0x0) {
LAB_0002a320:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar21,0,sVar18);
    pUVar33 = (__s->hh).tbl;
    uVar25 = pUVar33->num_buckets;
    pUVar33->nonideal_items = 0;
    uVar34 = pUVar33->num_items >> (pUVar33->log2_num_buckets + 1 & 0xff);
    uVar30 = uVar25 * 2 - 1;
    if ((pUVar33->num_items & uVar30) != 0) {
      uVar34 = uVar34 + 1;
    }
    pUVar33->ideal_chain_maxlen = uVar34;
    if (uVar25 == 0) {
      local_30 = pUVar33->buckets;
    }
    else {
      local_30 = pUVar33->buckets;
      local_34 = 0;
      do {
        pUVar27 = *(UT_hash_handle **)((int)&local_30->hh_head + local_34);
        while (pUVar27 != (UT_hash_handle *)0x0) {
          pUVar35 = pUVar27->hh_next;
          uVar28 = pUVar27->hashv & uVar30;
          uVar26 = pUVar21[uVar28].count + 1;
          pUVar21[uVar28].count = uVar26;
          if (uVar34 < uVar26) {
            pUVar33->nonideal_items = pUVar33->nonideal_items + 1;
            uVar26 = __aeabi_uidiv(uVar26,uVar34);
            pUVar21[uVar28].expand_mult = uVar26;
          }
          pUVar24 = pUVar21[uVar28].hh_head;
          pUVar27->hh_prev = (UT_hash_handle *)0x0;
          pUVar27->hh_next = pUVar24;
          if (pUVar24 != (UT_hash_handle *)0x0) {
            pUVar24->hh_prev = pUVar27;
          }
          pUVar21[uVar28].hh_head = pUVar27;
          pUVar27 = pUVar35;
        }
        local_34 = local_34 + 0xc;
      } while (local_34 != uVar25 * 0xc);
    }
    free(local_30);
    pUVar33 = (__s->hh).tbl;
    uVar34 = pUVar33->nonideal_items;
    pUVar33->buckets = pUVar21;
    uVar30 = pUVar33->num_items >> 1;
    uVar25 = uVar34;
    if (uVar34 <= uVar30) {
      uVar25 = 0;
    }
    pUVar33->log2_num_buckets = pUVar33->log2_num_buckets + 1;
    pUVar33->num_buckets = pUVar33->num_buckets << 1;
    if (uVar30 < uVar34) {
      uVar25 = pUVar33->ineff_expands + 1;
      pUVar33->ineff_expands = uVar25;
      uVar30 = uVar25;
      if (1 < uVar25) {
        uVar30 = 1;
      }
      if (1 < uVar25) {
        pUVar33->noexpand = uVar30;
      }
    }
    else {
      pUVar33->ineff_expands = uVar25;
    }
  }
LAB_00029fa6:
  iVar31 = pthread_rwlock_wrlock((pthread_rwlock_t *)&devices_lock);
  if (iVar31 != 0) {
    _wr_lock((pthread_rwlock_t *)"add_cgpu",(char *)0x2b86,func,line);
  }
  devices = (cgpu_info **)
            _cgrealloc(devices,(total_devices + new_devices + 2) * 4,"cgminer.c","add_cgpu",0x2b87);
  iVar31 = pthread_rwlock_unlock((pthread_rwlock_t *)&devices_lock);
  if (iVar31 != 0) {
    _rw_unlock((pthread_rwlock_t *)"add_cgpu",(char *)0x2b88,func_00,line_00);
  }
  (*selective_yield)();
  iVar31 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
  if (iVar31 != 0) {
    _mutex_lock((pthread_mutex_t *)"add_cgpu",(char *)0x2b8a,func_01,line_01);
  }
  tVar19 = time((time_t *)0x0);
  cgpu->last_device_valid_work = tVar19;
  iVar31 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
  if (iVar31 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"add_cgpu",(char *)0x2b8c,func_02,line_02);
  }
  (*selective_yield)();
  iVar31 = total_devices;
  if (hotplug_mode == false) {
    iVar31 = total_devices + 1;
    devices[total_devices] = cgpu;
    total_devices = iVar31;
  }
  else {
    iVar20 = new_devices + total_devices;
    new_devices = new_devices + 1;
    devices[iVar20] = cgpu;
  }
  if (most_devices < iVar31 - zombie_devs) {
    most_devices = iVar31 - zombie_devs;
  }
  return true;
}

