
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
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte bVar12;
  code **ppcVar13;
  int iVar14;
  char *pcVar15;
  uint _hj_k;
  uchar *_hj_key_1;
  uint _hj_k_1;
  time_t tVar16;
  size_t sVar17;
  void *pvVar18;
  UT_hash_bucket *_he_new_buckets;
  void *pvVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  byte *pbVar22;
  code *line;
  int iVar23;
  void **ppvVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uchar *puVar28;
  int iVar29;
  int iVar30;
  void *pvVar31;
  UT_hash_handle *_he_thh;
  uint uVar32;
  int iVar33;
  uchar *puVar34;
  void *pvVar35;
  char *pcVar36;
  int *piVar37;
  UT_hash_bucket *_he_newbkt;
  uint uVar38;
  char *pcVar39;
  byte *pbVar40;
  uchar *_hj_key;
  UT_hash_handle *_he_hh_nxt;
  int local_34;
  void *local_30;
  
  uVar32 = 0x9e3779b9;
  pbVar40 = (byte *)cgpu->drv->name;
  uVar38 = 0xfeedbeef;
  pcVar15 = (char *)strlen((char *)pbVar40);
  iVar14 = DAT_0002a074;
  uVar25 = uVar32;
  pbVar22 = pbVar40;
  for (pcVar36 = pcVar15; (char *)0xb < pcVar36; pcVar36 = pcVar36 + -0xc) {
    pbVar6 = pbVar22 + 2;
    pbVar7 = pbVar22 + 6;
    pbVar1 = pbVar22 + 1;
    pbVar2 = pbVar22 + 5;
    bVar12 = *pbVar22;
    pbVar3 = pbVar22 + 3;
    pbVar4 = pbVar22 + 4;
    pbVar5 = pbVar22 + 7;
    uVar38 = (uint)pbVar22[10] * 0x10000 + (uint)pbVar22[9] * 0x100 + (uint)pbVar22[8] +
             (uint)pbVar22[0xb] * 0x1000000 + uVar38;
    pbVar22 = pbVar22 + 0xc;
    iVar33 = uVar25 + (uint)*pbVar7 * 0x10000 + (uint)*pbVar2 * 0x100 + (uint)*pbVar4 +
                      (uint)*pbVar5 * 0x1000000;
    uVar25 = uVar32 + ((((uint)*pbVar6 * 0x10000 + (uint)*pbVar1 * 0x100 + (uint)bVar12 +
                        (uint)*pbVar3 * 0x1000000) - uVar38) - iVar33) ^ uVar38 >> 0xd;
    uVar32 = (iVar33 - uVar38) - uVar25 ^ uVar25 << 8;
    uVar38 = (uVar38 - uVar25) - uVar32 ^ uVar32 >> 0xd;
    uVar26 = (uVar25 - uVar32) - uVar38 ^ uVar38 >> 0xc;
    uVar25 = (uVar32 - uVar38) - uVar26 ^ uVar26 << 0x10;
    uVar38 = (uVar38 - uVar26) - uVar25 ^ uVar25 >> 5;
    uVar32 = (uVar26 - uVar25) - uVar38 ^ uVar38 >> 3;
    uVar25 = (uVar25 - uVar38) - uVar32 ^ uVar32 << 10;
    uVar38 = (uVar38 - uVar32) - uVar25 ^ uVar25 >> 0xf;
  }
  pcVar39 = pcVar15 + uVar38;
  switch(pcVar36) {
  case (char *)0xb:
    pcVar39 = pcVar39 + (uint)pbVar22[10] * 0x1000000;
  case (char *)0xa:
    pcVar39 = pcVar39 + (uint)pbVar22[9] * 0x10000;
  case (char *)0x9:
    pcVar39 = pcVar39 + (uint)pbVar22[8] * 0x100;
  case (char *)0x8:
    uVar25 = uVar25 + (uint)pbVar22[7] * 0x1000000;
  case (char *)0x7:
    uVar25 = uVar25 + (uint)pbVar22[6] * 0x10000;
  case (char *)0x6:
    uVar25 = uVar25 + (uint)pbVar22[5] * 0x100;
  case (char *)0x5:
    uVar25 = uVar25 + pbVar22[4];
  case (char *)0x4:
    uVar32 = uVar32 + (uint)pbVar22[3] * 0x1000000;
  case (char *)0x3:
    uVar32 = uVar32 + (uint)pbVar22[2] * 0x10000;
  case (char *)0x2:
    uVar32 = uVar32 + (uint)pbVar22[1] * 0x100;
  case (char *)0x1:
    uVar32 = uVar32 + *pbVar22;
  }
  uVar32 = (uVar32 - uVar25) - (int)pcVar39 ^ (uint)pcVar39 >> 0xd;
  uVar25 = (uVar25 - (int)pcVar39) - uVar32 ^ uVar32 << 8;
  uVar38 = (uint)(pcVar39 + (-uVar25 - uVar32)) ^ uVar25 >> 0xd;
  uVar32 = (uVar32 - uVar25) - uVar38 ^ uVar38 >> 0xc;
  uVar25 = (uVar25 - uVar38) - uVar32 ^ uVar32 << 0x10;
  uVar38 = (uVar38 - uVar32) - uVar25 ^ uVar25 >> 5;
  uVar32 = (uVar32 - uVar25) - uVar38 ^ uVar38 >> 3;
  uVar25 = (uVar25 - uVar38) - uVar32 ^ uVar32 << 10;
  uVar32 = (uVar38 - uVar32) - uVar25 ^ uVar25 >> 0xf;
  if (*(int *)(DAT_0002a074 + 0xa6c) != 0) {
    piVar37 = *(int **)(*(int *)(DAT_0002a074 + 0xa6c) + 8);
    iVar33 = *(int *)(*piVar37 + (piVar37[1] - 1U & uVar32) * 0xc);
    if (iVar33 != 0) {
      iVar33 = iVar33 - piVar37[5];
    }
    for (; iVar33 != 0; iVar33 = *(int *)(iVar33 + 0x18) - piVar37[5]) {
      if (((*(uint *)(iVar33 + 0x24) == uVar32) && (pcVar15 == *(char **)(iVar33 + 0x20))) &&
         (pcVar36 = pcVar15, iVar29 = memcmp(*(void **)(iVar33 + 0x1c),pbVar40,(size_t)pcVar15),
         iVar29 == 0)) {
        ppvVar24 = (void **)(*(int *)(iVar33 + 4) + 1);
        *(void ***)(iVar33 + 4) = ppvVar24;
        cgpu->device_id = (int)ppvVar24;
        goto LAB_00029fa6;
      }
      if (*(int *)(iVar33 + 0x18) == 0) break;
    }
  }
  pcVar36 = DAT_0002a050;
  pbVar40 = (byte *)_cgmalloc(0x28,DAT_0002a054,DAT_0002a050,0x2b80);
  _cg_memcpy(pbVar40,cgpu->drv->name,4,DAT_0002a054,pcVar36,0x2b81);
  uVar32 = 0xfeedbeef;
  *(undefined4 *)(pbVar40 + 4) = 0;
  cgpu->device_id = 0;
  _hj_key_1 = (uchar *)strlen((char *)pbVar40);
  uVar25 = 0x9e3779b9;
  uVar38 = uVar25;
  pbVar22 = pbVar40;
  for (puVar34 = _hj_key_1; (uchar *)0xb < puVar34; puVar34 = puVar34 + -0xc) {
    pbVar8 = pbVar22 + 10;
    pbVar1 = pbVar22 + 2;
    pbVar2 = pbVar22 + 9;
    pbVar3 = pbVar22 + 1;
    pbVar9 = pbVar22 + 6;
    pbVar4 = pbVar22 + 5;
    pbVar10 = pbVar22 + 8;
    bVar12 = *pbVar22;
    pbVar5 = pbVar22 + 0xb;
    pbVar6 = pbVar22 + 3;
    pbVar11 = pbVar22 + 4;
    pbVar7 = pbVar22 + 7;
    pbVar22 = pbVar22 + 0xc;
    uVar32 = (uint)*pbVar10 + (uint)*pbVar8 * 0x10000 + (uint)*pbVar2 * 0x100 +
             (uint)*pbVar5 * 0x1000000 + uVar32;
    iVar33 = uVar38 + (uint)*pbVar11 + (uint)*pbVar9 * 0x10000 + (uint)*pbVar4 * 0x100 +
                      (uint)*pbVar7 * 0x1000000;
    uVar25 = uVar25 + ((((uint)*pbVar1 * 0x10000 + (uint)*pbVar3 * 0x100 + (uint)bVar12 +
                        (uint)*pbVar6 * 0x1000000) - uVar32) - iVar33) ^ uVar32 >> 0xd;
    uVar26 = (iVar33 - uVar32) - uVar25 ^ uVar25 << 8;
    uVar38 = (uVar32 - uVar25) - uVar26 ^ uVar26 >> 0xd;
    uVar32 = (uVar25 - uVar26) - uVar38 ^ uVar38 >> 0xc;
    uVar27 = (uVar26 - uVar38) - uVar32 ^ uVar32 << 0x10;
    uVar26 = (uVar38 - uVar32) - uVar27 ^ uVar27 >> 5;
    uVar25 = (uVar32 - uVar27) - uVar26 ^ uVar26 >> 3;
    uVar38 = (uVar27 - uVar26) - uVar25 ^ uVar25 << 10;
    uVar32 = (uVar26 - uVar25) - uVar38 ^ uVar38 >> 0xf;
  }
  puVar28 = _hj_key_1 + uVar32;
  switch(puVar34) {
  case (uchar *)0xb:
    puVar28 = puVar28 + (uint)pbVar22[10] * 0x1000000;
  case (uchar *)0xa:
    puVar28 = puVar28 + (uint)pbVar22[9] * 0x10000;
  case (uchar *)0x9:
    puVar28 = puVar28 + (uint)pbVar22[8] * 0x100;
  case (uchar *)0x8:
    uVar38 = uVar38 + (uint)pbVar22[7] * 0x1000000;
  case (uchar *)0x7:
    uVar38 = uVar38 + (uint)pbVar22[6] * 0x10000;
  case (uchar *)0x6:
    uVar38 = uVar38 + (uint)pbVar22[5] * 0x100;
  case (uchar *)0x5:
    uVar38 = uVar38 + pbVar22[4];
  case (uchar *)0x4:
    uVar25 = uVar25 + (uint)pbVar22[3] * 0x1000000;
  case (uchar *)0x3:
    uVar25 = uVar25 + (uint)pbVar22[2] * 0x10000;
  case (uchar *)0x2:
    uVar25 = uVar25 + (uint)pbVar22[1] * 0x100;
  case (uchar *)0x1:
    uVar25 = uVar25 + *pbVar22;
  }
  uVar32 = (uVar25 - uVar38) - (int)puVar28 ^ (uint)puVar28 >> 0xd;
  uVar25 = (uVar38 - (int)puVar28) - uVar32 ^ uVar32 << 8;
  *(byte **)(pbVar40 + 0x1c) = pbVar40;
  uVar38 = (uint)(puVar28 + (-uVar25 - uVar32)) ^ uVar25 >> 0xd;
  uVar32 = (uVar32 - uVar25) - uVar38 ^ uVar38 >> 0xc;
  uVar25 = (uVar25 - uVar38) - uVar32 ^ uVar32 << 0x10;
  uVar38 = (uVar38 - uVar32) - uVar25 ^ uVar25 >> 5;
  uVar32 = (uVar32 - uVar25) - uVar38 ^ uVar38 >> 3;
  uVar25 = (uVar25 - uVar38) - uVar32 ^ uVar32 << 10;
  uVar32 = (uVar38 - uVar32) - uVar25 ^ uVar25 >> 0xf;
  *(uint *)(pbVar40 + 0x24) = uVar32;
  sVar17 = strlen((char *)pbVar40);
  iVar33 = DAT_0002a358;
  iVar29 = *(int *)(iVar14 + 0xa6c);
  *(size_t *)(pbVar40 + 0x20) = sVar17;
  if (iVar29 == 0) {
    *(undefined4 *)(pbVar40 + 0x10) = 0;
    *(undefined4 *)(pbVar40 + 0xc) = 0;
    *(byte **)(iVar33 + 0xa6c) = pbVar40;
    puVar21 = (undefined4 *)malloc(0x2c);
    *(undefined4 **)(pbVar40 + 8) = puVar21;
    if (puVar21 == (undefined4 *)0x0) goto LAB_0002a320;
    *puVar21 = 0;
    puVar21[1] = 0;
    puVar21[2] = 0;
    puVar21[3] = 0;
    puVar21[4] = 0;
    puVar21[5] = 0;
    puVar21[6] = 0;
    puVar21[7] = 0;
    puVar21[8] = 0;
    puVar21[9] = 0;
    puVar21[10] = 0;
    ppvVar24 = *(void ***)(pbVar40 + 8);
    ppvVar24[4] = pbVar40 + 8;
    ppvVar24[1] = (void *)0x20;
    ppvVar24[2] = (void *)0x5;
    ppvVar24[5] = (void *)0x8;
    pvVar18 = malloc(0x180);
    *ppvVar24 = pvVar18;
    if (pvVar18 == (void *)0x0) goto LAB_0002a320;
    memset(pvVar18,0,0x180);
    piVar37 = *(int **)(pbVar40 + 8);
    piVar37[10] = -0x5feee01f;
  }
  else {
    *(undefined4 *)(pbVar40 + 8) = *(undefined4 *)(iVar29 + 8);
    *(undefined4 *)(pbVar40 + 0x10) = 0;
    piVar37 = *(int **)(iVar29 + 8);
    iVar33 = piVar37[4];
    iVar29 = piVar37[5];
    *(byte **)(iVar33 + 8) = pbVar40;
    *(int *)(pbVar40 + 0xc) = iVar33 - iVar29;
    piVar37[4] = (int)(pbVar40 + 8);
  }
  iVar33 = *piVar37;
  piVar37[3] = piVar37[3] + 1;
  iVar23 = (uVar32 & piVar37[1] - 1U) * 0xc;
  iVar29 = iVar33 + iVar23;
  iVar30 = *(int *)(iVar33 + iVar23);
  uVar32 = *(int *)(iVar29 + 4) + 1;
  *(uint *)(iVar29 + 4) = uVar32;
  *(int *)(pbVar40 + 0x18) = iVar30;
  *(undefined4 *)(pbVar40 + 0x14) = 0;
  if (iVar30 != 0) {
    *(byte **)(iVar30 + 0xc) = pbVar40 + 8;
  }
  pcVar36 = *(char **)(iVar29 + 8);
  *(byte **)(iVar33 + iVar23) = pbVar40 + 8;
  ppvVar24 = (void **)((int)(pcVar36 + 1) * 5);
  if ((uint)((int)(pcVar36 + 1) * 10) <= uVar32) {
    ppvVar24 = *(void ***)(pbVar40 + 8);
    pcVar36 = (char *)ppvVar24[9];
    if (pcVar36 != (char *)0x1) {
      pvVar31 = ppvVar24[1];
      pvVar18 = malloc((int)pvVar31 * 0x18);
      if (pvVar18 == (void *)0x0) {
LAB_0002a320:
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pvVar18,0,(int)pvVar31 * 0x18);
      ppvVar24 = *(void ***)(pbVar40 + 8);
      pvVar31 = ppvVar24[1];
      ppvVar24[7] = (void *)0x0;
      pvVar35 = (void *)((uint)ppvVar24[3] >> ((int)ppvVar24[2] + 1U & 0xff));
      uVar32 = (int)pvVar31 * 2 - 1;
      if (((uint)ppvVar24[3] & uVar32) != 0) {
        pvVar35 = (void *)((int)pvVar35 + 1);
      }
      ppvVar24[6] = pvVar35;
      if (pvVar31 == (void *)0x0) {
        local_30 = *ppvVar24;
      }
      else {
        local_30 = *ppvVar24;
        local_34 = 0;
        do {
          iVar33 = *(int *)((int)local_30 + local_34);
          while (iVar33 != 0) {
            iVar29 = *(int *)(iVar33 + 0x10);
            uVar25 = *(uint *)(iVar33 + 0x1c) & uVar32;
            pvVar19 = (void *)(*(int *)((int)pvVar18 + uVar25 * 0xc + 4) + 1);
            *(void **)((int)pvVar18 + uVar25 * 0xc + 4) = pvVar19;
            if (pvVar35 < pvVar19) {
              ppvVar24[7] = (void *)((int)ppvVar24[7] + 1);
              uVar20 = __aeabi_uidiv(pvVar19,pvVar35);
              *(undefined4 *)((int)pvVar18 + uVar25 * 0xc + 8) = uVar20;
            }
            iVar23 = *(int *)((int)pvVar18 + uVar25 * 0xc);
            *(undefined4 *)(iVar33 + 0xc) = 0;
            *(int *)(iVar33 + 0x10) = iVar23;
            if (iVar23 != 0) {
              *(int *)(iVar23 + 0xc) = iVar33;
            }
            *(int *)((int)pvVar18 + uVar25 * 0xc) = iVar33;
            iVar33 = iVar29;
          }
          local_34 = local_34 + 0xc;
        } while (local_34 != (int)pvVar31 * 0xc);
      }
      free(local_30);
      ppvVar24 = *(void ***)(pbVar40 + 8);
      pcVar15 = (char *)ppvVar24[7];
      *ppvVar24 = pvVar18;
      pcVar36 = pcVar15;
      if (pcVar15 <= (char *)((uint)ppvVar24[3] >> 1)) {
        pcVar36 = (char *)0x0;
      }
      ppvVar24[2] = (void *)((int)ppvVar24[2] + 1);
      ppvVar24[1] = (void *)((int)ppvVar24[1] << 1);
      if ((char *)((uint)ppvVar24[3] >> 1) < pcVar15) {
        pcVar15 = (char *)((int)ppvVar24[8] + 1);
        ppvVar24[8] = pcVar15;
        pcVar36 = pcVar15;
        if ((char *)0x1 < pcVar15) {
          pcVar36 = (char *)0x1;
        }
        if ((char *)0x1 < pcVar15) {
          ppvVar24[9] = pcVar36;
        }
      }
      else {
        ppvVar24[8] = pcVar36;
      }
    }
  }
LAB_00029fa6:
  iVar33 = pthread_rwlock_wrlock(DAT_0002a058);
  if (iVar33 != 0) {
    _wr_lock(DAT_0002a35c,(char *)0x2b86,pcVar36,(int)ppvVar24);
  }
  ppvVar24 = DAT_0002a060;
  piVar37 = DAT_0002a05c;
  pcVar36 = DAT_0002a054;
  pcVar15 = DAT_0002a050;
  pvVar18 = _cgrealloc(*DAT_0002a060,(*DAT_0002a05c + *(int *)(iVar14 + 0xa70) + 2) * 4,DAT_0002a054
                       ,DAT_0002a050,0x2b87);
  *ppvVar24 = pvVar18;
  iVar33 = pthread_rwlock_unlock(DAT_0002a058);
  if (iVar33 != 0) {
    _rw_unlock(DAT_0002a35c,(char *)0x2b88,pcVar36,(int)pcVar15);
  }
  ppcVar13 = DAT_0002a064;
  line = *DAT_0002a064;
  (*line)();
  iVar33 = pthread_mutex_lock(DAT_0002a068);
  if (iVar33 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_0002a35c,(char *)0x2b8a,pcVar36,(int)line);
  }
  tVar16 = time((time_t *)0x0);
  cgpu->last_device_valid_work = tVar16;
  iVar33 = pthread_mutex_unlock(DAT_0002a068);
  if (iVar33 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_0002a35c,(char *)0x2b8c,pcVar36,(int)line);
  }
  (**ppcVar13)();
  if (*DAT_0002a06c == '\0') {
    iVar33 = *piVar37 + 1;
    *(cgpu_info **)((int)*ppvVar24 + *piVar37 * 4) = cgpu;
    *piVar37 = iVar33;
  }
  else {
    iVar29 = *(int *)(iVar14 + 0xa70);
    iVar33 = *piVar37;
    pvVar18 = *ppvVar24;
    *(int *)(iVar14 + 0xa70) = iVar29 + 1;
    *(cgpu_info **)((int)pvVar18 + (iVar29 + iVar33) * 4) = cgpu;
  }
  if (*(int *)(iVar14 + 0xa74) < iVar33 - *DAT_0002a070) {
    *(int *)(DAT_0002a074 + 0xa74) = iVar33 - *DAT_0002a070;
  }
  return true;
}

