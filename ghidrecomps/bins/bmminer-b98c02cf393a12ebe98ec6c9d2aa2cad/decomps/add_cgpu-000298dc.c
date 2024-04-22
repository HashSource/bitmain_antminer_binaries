
undefined4 add_cgpu(int param_1)

{
  byte *pbVar1;
  size_t sVar2;
  time_t tVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  void *pvVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  void **ppvVar20;
  void *pvVar21;
  int local_38;
  void *local_34;
  
  uVar16 = 0x9e3779b9;
  pbVar9 = *(byte **)(*(int *)(param_1 + 4) + 8);
  sVar2 = strlen((char *)pbVar9);
  uVar10 = 0xfeedbeef;
  uVar8 = uVar16;
  pbVar1 = pbVar9;
  for (uVar19 = sVar2; 0xb < uVar19; uVar19 = uVar19 - 0xc) {
    iVar17 = uVar8 + (uint)pbVar1[4] + (uint)pbVar1[6] * 0x10000 + (uint)pbVar1[5] * 0x100 +
                     (uint)pbVar1[7] * 0x1000000;
    uVar10 = uVar10 + (uint)pbVar1[8] + (uint)pbVar1[10] * 0x10000 + (uint)pbVar1[9] * 0x100 +
                      (uint)pbVar1[0xb] * 0x1000000;
    uVar8 = ((((uint)*pbVar1 + (uint)pbVar1[2] * 0x10000 + (uint)pbVar1[1] * 0x100 +
              (uint)pbVar1[3] * 0x1000000) - iVar17) - uVar10) + uVar16 ^ uVar10 >> 0xd;
    uVar16 = (iVar17 - uVar10) - uVar8 ^ uVar8 << 8;
    uVar11 = (uVar10 - uVar8) - uVar16 ^ uVar16 >> 0xd;
    uVar10 = (uVar8 - uVar16) - uVar11 ^ uVar11 >> 0xc;
    uVar8 = (uVar16 - uVar11) - uVar10 ^ uVar10 << 0x10;
    uVar11 = (uVar11 - uVar10) - uVar8 ^ uVar8 >> 5;
    uVar16 = (uVar10 - uVar8) - uVar11 ^ uVar11 >> 3;
    uVar8 = (uVar8 - uVar11) - uVar16 ^ uVar16 << 10;
    uVar10 = (uVar11 - uVar16) - uVar8 ^ uVar8 >> 0xf;
    pbVar1 = pbVar1 + 0xc;
  }
  uVar10 = uVar10 + sVar2;
  switch(uVar19) {
  case 0xb:
    uVar10 = uVar10 + (uint)pbVar1[10] * 0x1000000;
  case 10:
    uVar10 = uVar10 + (uint)pbVar1[9] * 0x10000;
  case 9:
    uVar10 = uVar10 + (uint)pbVar1[8] * 0x100;
  case 8:
    uVar8 = uVar8 + (uint)pbVar1[7] * 0x1000000;
  case 7:
    uVar8 = uVar8 + (uint)pbVar1[6] * 0x10000;
  case 6:
    uVar8 = uVar8 + (uint)pbVar1[5] * 0x100;
  case 5:
    uVar8 = uVar8 + pbVar1[4];
  case 4:
    uVar16 = uVar16 + (uint)pbVar1[3] * 0x1000000;
  case 3:
    uVar16 = uVar16 + (uint)pbVar1[2] * 0x10000;
  case 2:
    uVar16 = uVar16 + (uint)pbVar1[1] * 0x100;
  case 1:
    uVar16 = uVar16 + *pbVar1;
  }
  uVar19 = (uVar16 - uVar8) - uVar10 ^ uVar10 >> 0xd;
  uVar16 = (uVar8 - uVar10) - uVar19 ^ uVar19 << 8;
  uVar11 = (uVar10 - uVar19) - uVar16 ^ uVar16 >> 0xd;
  uVar10 = (uVar19 - uVar16) - uVar11 ^ uVar11 >> 0xc;
  uVar8 = (uVar16 - uVar11) - uVar10 ^ uVar10 << 0x10;
  uVar16 = (uVar11 - uVar10) - uVar8 ^ uVar8 >> 5;
  uVar10 = (uVar10 - uVar8) - uVar16 ^ uVar16 >> 3;
  uVar8 = (uVar8 - uVar16) - uVar10 ^ uVar10 << 10;
  uVar16 = (uVar16 - uVar10) - uVar8 ^ uVar8 >> 0xf;
  if (devids_15749 != (byte *)0x0) {
    piVar7 = *(int **)(devids_15749 + 8);
    iVar17 = *(int *)(*piVar7 + (piVar7[1] - 1U & uVar16) * 0xc);
    if (iVar17 != 0) {
      iVar18 = piVar7[5];
      do {
        iVar17 = iVar17 - iVar18;
        if (iVar17 == 0) break;
        if (((uVar16 == *(uint *)(iVar17 + 0x24)) && (sVar2 == *(size_t *)(iVar17 + 0x20))) &&
           (iVar12 = memcmp(*(void **)(iVar17 + 0x1c),pbVar9,sVar2), iVar12 == 0)) {
          iVar18 = *(int *)(iVar17 + 4) + 1;
          *(int *)(iVar17 + 4) = iVar18;
          *(int *)(param_1 + 8) = iVar18;
          goto LAB_00029c70;
        }
        iVar17 = *(int *)(iVar17 + 0x18);
      } while (iVar17 != 0);
    }
  }
  uVar6 = DAT_00029d58;
  pbVar9 = (byte *)_cgmalloc(0x28,"cgminer.c",DAT_00029d58,0x2ba4);
  _cg_memcpy(pbVar9,*(undefined4 *)(*(int *)(param_1 + 4) + 8),4,"cgminer.c",uVar6,0x2ba5);
  *(undefined4 *)(pbVar9 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  sVar2 = strlen((char *)pbVar9);
  uVar16 = 0xfeedbeef;
  uVar8 = 0x9e3779b9;
  uVar10 = uVar8;
  pbVar1 = pbVar9;
  for (uVar19 = sVar2; 0xb < uVar19; uVar19 = uVar19 - 0xc) {
    iVar17 = (uint)pbVar1[4] + (uint)pbVar1[6] * 0x10000 + (uint)pbVar1[5] * 0x100 +
             (uint)pbVar1[7] * 0x1000000 + uVar10;
    uVar16 = uVar16 + (uint)pbVar1[10] * 0x10000 + (uint)pbVar1[9] * 0x100 + (uint)pbVar1[8] +
                      (uint)pbVar1[0xb] * 0x1000000;
    uVar8 = ((((uint)*pbVar1 + (uint)pbVar1[2] * 0x10000 + (uint)pbVar1[1] * 0x100 +
              (uint)pbVar1[3] * 0x1000000) - iVar17) - uVar16) + uVar8 ^ uVar16 >> 0xd;
    uVar11 = (iVar17 - uVar16) - uVar8 ^ uVar8 << 8;
    uVar10 = (uVar16 - uVar8) - uVar11 ^ uVar11 >> 0xd;
    uVar16 = (uVar8 - uVar11) - uVar10 ^ uVar10 >> 0xc;
    uVar14 = (uVar11 - uVar10) - uVar16 ^ uVar16 << 0x10;
    uVar11 = (uVar10 - uVar16) - uVar14 ^ uVar14 >> 5;
    uVar8 = (uVar16 - uVar14) - uVar11 ^ uVar11 >> 3;
    uVar10 = (uVar14 - uVar11) - uVar8 ^ uVar8 << 10;
    uVar16 = (uVar11 - uVar8) - uVar10 ^ uVar10 >> 0xf;
    pbVar1 = pbVar1 + 0xc;
  }
  uVar16 = uVar16 + sVar2;
  switch(uVar19) {
  case 0xb:
    uVar16 = uVar16 + (uint)pbVar1[10] * 0x1000000;
  case 10:
    uVar16 = uVar16 + (uint)pbVar1[9] * 0x10000;
  case 9:
    uVar16 = uVar16 + (uint)pbVar1[8] * 0x100;
  case 8:
    uVar10 = uVar10 + (uint)pbVar1[7] * 0x1000000;
  case 7:
    uVar10 = uVar10 + (uint)pbVar1[6] * 0x10000;
  case 6:
    uVar10 = uVar10 + (uint)pbVar1[5] * 0x100;
  case 5:
    uVar10 = uVar10 + pbVar1[4];
  case 4:
    uVar8 = uVar8 + (uint)pbVar1[3] * 0x1000000;
  case 3:
    uVar8 = uVar8 + (uint)pbVar1[2] * 0x10000;
  case 2:
    uVar8 = uVar8 + (uint)pbVar1[1] * 0x100;
  case 1:
    uVar8 = uVar8 + *pbVar1;
  }
  uVar19 = (uVar8 - uVar10) - uVar16 ^ uVar16 >> 0xd;
  *(byte **)(pbVar9 + 0x1c) = pbVar9;
  uVar8 = (uVar10 - uVar16) - uVar19 ^ uVar19 << 8;
  uVar11 = (uVar16 - uVar19) - uVar8 ^ uVar8 >> 0xd;
  uVar10 = (uVar19 - uVar8) - uVar11 ^ uVar11 >> 0xc;
  uVar16 = (uVar8 - uVar11) - uVar10 ^ uVar10 << 0x10;
  uVar19 = (uVar11 - uVar10) - uVar16 ^ uVar16 >> 5;
  uVar8 = (uVar10 - uVar16) - uVar19 ^ uVar19 >> 3;
  uVar16 = (uVar16 - uVar19) - uVar8 ^ uVar8 << 10;
  uVar16 = (uVar19 - uVar8) - uVar16 ^ uVar16 >> 0xf;
  *(uint *)(pbVar9 + 0x24) = uVar16;
  sVar2 = strlen((char *)pbVar9);
  pbVar1 = devids_15749;
  *(size_t *)(pbVar9 + 0x20) = sVar2;
  if (pbVar1 == (byte *)0x0) {
    *(undefined4 *)(pbVar9 + 0x10) = 0;
    *(undefined4 *)(pbVar9 + 0xc) = 0;
    devids_15749 = pbVar9;
    pvVar4 = malloc(0x2c);
    *(void **)(pbVar9 + 8) = pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_00029ffc;
    memset(pvVar4,0,0x2c);
    ppvVar20 = *(void ***)(pbVar9 + 8);
    ppvVar20[4] = pbVar9 + 8;
    ppvVar20[1] = (void *)0x20;
    ppvVar20[2] = (void *)0x5;
    ppvVar20[5] = (void *)0x8;
    pvVar4 = malloc(0x180);
    *ppvVar20 = pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_00029ffc;
    memset(pvVar4,0,0x180);
    piVar7 = *(int **)(pbVar9 + 8);
    piVar7[10] = -0x5feee01f;
  }
  else {
    *(undefined4 *)(pbVar9 + 8) = *(undefined4 *)(pbVar1 + 8);
    piVar7 = *(int **)(pbVar1 + 8);
    *(undefined4 *)(pbVar9 + 0x10) = 0;
    iVar17 = piVar7[4];
    *(int *)(pbVar9 + 0xc) = iVar17 - piVar7[5];
    *(byte **)(iVar17 + 8) = pbVar9;
    piVar7[4] = (int)(pbVar9 + 8);
  }
  iVar17 = *piVar7;
  piVar7[3] = piVar7[3] + 1;
  iVar12 = (piVar7[1] - 1U & uVar16) * 0xc;
  iVar18 = iVar17 + iVar12;
  iVar15 = *(int *)(iVar17 + iVar12);
  uVar16 = *(int *)(iVar18 + 4) + 1;
  *(uint *)(iVar18 + 4) = uVar16;
  *(int *)(pbVar9 + 0x18) = iVar15;
  *(undefined4 *)(pbVar9 + 0x14) = 0;
  if (iVar15 != 0) {
    *(byte **)(iVar15 + 0xc) = pbVar9 + 8;
  }
  iVar18 = *(int *)(iVar18 + 8);
  *(byte **)(iVar17 + iVar12) = pbVar9 + 8;
  if (((uint)((iVar18 + 1) * 10) <= uVar16) && (*(int *)(*(int *)(pbVar9 + 8) + 0x24) != 1)) {
    pvVar4 = calloc(*(int *)(*(int *)(pbVar9 + 8) + 4) * 0x18,1);
    if (pvVar4 == (void *)0x0) {
LAB_00029ffc:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    ppvVar20 = *(void ***)(pbVar9 + 8);
    pvVar13 = ppvVar20[1];
    ppvVar20[7] = (void *)0x0;
    pvVar21 = (void *)((uint)ppvVar20[3] >> ((int)ppvVar20[2] + 1U & 0xff));
    uVar16 = (int)pvVar13 * 2 - 1;
    if (((uint)ppvVar20[3] & uVar16) != 0) {
      pvVar21 = (void *)((int)pvVar21 + 1);
    }
    ppvVar20[6] = pvVar21;
    if (pvVar13 == (void *)0x0) {
      local_34 = *ppvVar20;
    }
    else {
      local_34 = *ppvVar20;
      local_38 = 0;
      do {
        iVar17 = *(int *)((int)local_34 + local_38);
        while (iVar17 != 0) {
          iVar18 = *(int *)(iVar17 + 0x10);
          uVar8 = uVar16 & *(uint *)(iVar17 + 0x1c);
          pvVar5 = (void *)(*(int *)((int)pvVar4 + uVar8 * 0xc + 4) + 1);
          *(void **)((int)pvVar4 + uVar8 * 0xc + 4) = pvVar5;
          if (pvVar21 < pvVar5) {
            ppvVar20[7] = (void *)((int)ppvVar20[7] + 1);
            uVar6 = __udivsi3(pvVar5,pvVar21);
            *(undefined4 *)((int)pvVar4 + uVar8 * 0xc + 8) = uVar6;
          }
          iVar12 = *(int *)((int)pvVar4 + uVar8 * 0xc);
          *(undefined4 *)(iVar17 + 0xc) = 0;
          *(int *)(iVar17 + 0x10) = iVar12;
          if (iVar12 != 0) {
            *(int *)(iVar12 + 0xc) = iVar17;
          }
          *(int *)((int)pvVar4 + uVar8 * 0xc) = iVar17;
          iVar17 = iVar18;
        }
        local_38 = local_38 + 0xc;
      } while ((int)pvVar13 * 0xc != local_38);
    }
    free(local_34);
    ppvVar20 = *(void ***)(pbVar9 + 8);
    *ppvVar20 = pvVar4;
    pvVar4 = (void *)((int)ppvVar20[2] + 1);
    ppvVar20[2] = pvVar4;
    if (ppvVar20[7] <= (void *)((uint)ppvVar20[3] >> 1)) {
      pvVar4 = (void *)0x0;
    }
    ppvVar20[1] = (void *)((int)ppvVar20[1] << 1);
    if ((void *)((uint)ppvVar20[3] >> 1) < ppvVar20[7]) {
      pvVar13 = (void *)((int)ppvVar20[8] + 1);
      ppvVar20[8] = pvVar13;
      pvVar4 = pvVar13;
      if ((void *)0x1 < pvVar13) {
        pvVar4 = (void *)0x1;
      }
      if ((void *)0x1 < pvVar13) {
        ppvVar20[9] = pvVar4;
      }
    }
    else {
      ppvVar20[8] = pvVar4;
    }
  }
LAB_00029c70:
  iVar17 = pthread_rwlock_wrlock((pthread_rwlock_t *)devices_lock);
  if (iVar17 == 0) {
    devices = _cgrealloc(devices,(new_devices + total_devices + 2) * 4,"cgminer.c",DAT_00029d58,
                         0x2bab);
    iVar17 = pthread_rwlock_unlock((pthread_rwlock_t *)devices_lock);
    if (iVar17 == 0) {
      (*selective_yield)();
      iVar17 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
      if (iVar17 != 0) {
                    /* WARNING: Subroutine does not return */
        _mutex_lock_part_47_constprop_75(DAT_0002a004,0x2bae);
      }
      tVar3 = time((time_t *)0x0);
      *(time_t *)(param_1 + 0xe8) = tVar3;
      iVar17 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
      if (iVar17 != 0) {
                    /* WARNING: Subroutine does not return */
        _mutex_unlock_noyield_part_48_constprop_77(DAT_0002a004,0x2bb0);
      }
      (*selective_yield)();
      iVar17 = total_devices;
      if (hotplug_mode == '\0') {
        iVar17 = total_devices + 1;
        iVar18 = total_devices * 4;
        total_devices = iVar17;
        *(int *)(devices + iVar18) = param_1;
      }
      else {
        iVar18 = new_devices + total_devices;
        new_devices = new_devices + 1;
        *(int *)(devices + iVar18 * 4) = param_1;
      }
      if (most_devices < iVar17 - zombie_devs) {
        most_devices = iVar17 - zombie_devs;
      }
      return 1;
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_0002a004,0x2baa);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0002a004,0x2bac);
}

