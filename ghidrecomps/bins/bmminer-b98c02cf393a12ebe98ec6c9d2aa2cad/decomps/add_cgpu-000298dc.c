
undefined4 add_cgpu(int param_1)

{
  byte *pbVar1;
  size_t sVar2;
  time_t tVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int local_38;
  void *local_34;
  
  uVar15 = 0x9e3779b9;
  pbVar8 = *(byte **)(*(int *)(param_1 + 4) + 8);
  sVar2 = strlen((char *)pbVar8);
  uVar9 = 0xfeedbeef;
  uVar7 = uVar15;
  pbVar1 = pbVar8;
  for (uVar18 = sVar2; 0xb < uVar18; uVar18 = uVar18 - 0xc) {
    iVar16 = uVar7 + (uint)pbVar1[4] + (uint)pbVar1[6] * 0x10000 + (uint)pbVar1[5] * 0x100 +
                     (uint)pbVar1[7] * 0x1000000;
    uVar9 = uVar9 + (uint)pbVar1[8] + (uint)pbVar1[10] * 0x10000 + (uint)pbVar1[9] * 0x100 +
                    (uint)pbVar1[0xb] * 0x1000000;
    uVar7 = ((((uint)*pbVar1 + (uint)pbVar1[2] * 0x10000 + (uint)pbVar1[1] * 0x100 +
              (uint)pbVar1[3] * 0x1000000) - iVar16) - uVar9) + uVar15 ^ uVar9 >> 0xd;
    uVar15 = (iVar16 - uVar9) - uVar7 ^ uVar7 << 8;
    uVar10 = (uVar9 - uVar7) - uVar15 ^ uVar15 >> 0xd;
    uVar9 = (uVar7 - uVar15) - uVar10 ^ uVar10 >> 0xc;
    uVar7 = (uVar15 - uVar10) - uVar9 ^ uVar9 << 0x10;
    uVar10 = (uVar10 - uVar9) - uVar7 ^ uVar7 >> 5;
    uVar15 = (uVar9 - uVar7) - uVar10 ^ uVar10 >> 3;
    uVar7 = (uVar7 - uVar10) - uVar15 ^ uVar15 << 10;
    uVar9 = (uVar10 - uVar15) - uVar7 ^ uVar7 >> 0xf;
    pbVar1 = pbVar1 + 0xc;
  }
  uVar9 = uVar9 + sVar2;
  switch(uVar18) {
  case 0xb:
    uVar9 = uVar9 + (uint)pbVar1[10] * 0x1000000;
  case 10:
    uVar9 = uVar9 + (uint)pbVar1[9] * 0x10000;
  case 9:
    uVar9 = uVar9 + (uint)pbVar1[8] * 0x100;
  case 8:
    uVar7 = uVar7 + (uint)pbVar1[7] * 0x1000000;
  case 7:
    uVar7 = uVar7 + (uint)pbVar1[6] * 0x10000;
  case 6:
    uVar7 = uVar7 + (uint)pbVar1[5] * 0x100;
  case 5:
    uVar7 = uVar7 + pbVar1[4];
  case 4:
    uVar15 = uVar15 + (uint)pbVar1[3] * 0x1000000;
  case 3:
    uVar15 = uVar15 + (uint)pbVar1[2] * 0x10000;
  case 2:
    uVar15 = uVar15 + (uint)pbVar1[1] * 0x100;
  case 1:
    uVar15 = uVar15 + *pbVar1;
  }
  uVar18 = (uVar15 - uVar7) - uVar9 ^ uVar9 >> 0xd;
  uVar15 = (uVar7 - uVar9) - uVar18 ^ uVar18 << 8;
  uVar10 = (uVar9 - uVar18) - uVar15 ^ uVar15 >> 0xd;
  uVar9 = (uVar18 - uVar15) - uVar10 ^ uVar10 >> 0xc;
  uVar7 = (uVar15 - uVar10) - uVar9 ^ uVar9 << 0x10;
  uVar15 = (uVar10 - uVar9) - uVar7 ^ uVar7 >> 5;
  uVar9 = (uVar9 - uVar7) - uVar15 ^ uVar15 >> 3;
  uVar7 = (uVar7 - uVar15) - uVar9 ^ uVar9 << 10;
  uVar15 = (uVar15 - uVar9) - uVar7 ^ uVar7 >> 0xf;
  if (devids_15749 != (byte *)0x0) {
    piVar6 = *(int **)(devids_15749 + 8);
    iVar16 = *(int *)(*piVar6 + (piVar6[1] - 1U & uVar15) * 0xc);
    if (iVar16 != 0) {
      iVar17 = piVar6[5];
      do {
        iVar16 = iVar16 - iVar17;
        if (iVar16 == 0) break;
        if (((uVar15 == *(uint *)(iVar16 + 0x24)) && (sVar2 == *(size_t *)(iVar16 + 0x20))) &&
           (iVar11 = memcmp(*(void **)(iVar16 + 0x1c),pbVar8,sVar2), iVar11 == 0)) {
          iVar17 = *(int *)(iVar16 + 4) + 1;
          *(int *)(iVar16 + 4) = iVar17;
          *(int *)(param_1 + 8) = iVar17;
          goto LAB_00029c70;
        }
        iVar16 = *(int *)(iVar16 + 0x18);
      } while (iVar16 != 0);
    }
  }
  pbVar8 = (byte *)_cgmalloc(0x28,"cgminer.c",__func___15774,0x2ba4);
  _cg_memcpy(pbVar8,*(undefined4 *)(*(int *)(param_1 + 4) + 8),4,"cgminer.c",__func___15774,0x2ba5);
  pbVar8[4] = 0;
  pbVar8[5] = 0;
  pbVar8[6] = 0;
  pbVar8[7] = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  sVar2 = strlen((char *)pbVar8);
  uVar15 = 0xfeedbeef;
  uVar7 = 0x9e3779b9;
  uVar9 = uVar7;
  pbVar1 = pbVar8;
  for (uVar18 = sVar2; 0xb < uVar18; uVar18 = uVar18 - 0xc) {
    iVar16 = (uint)pbVar1[4] + (uint)pbVar1[6] * 0x10000 + (uint)pbVar1[5] * 0x100 +
             (uint)pbVar1[7] * 0x1000000 + uVar9;
    uVar15 = uVar15 + (uint)pbVar1[10] * 0x10000 + (uint)pbVar1[9] * 0x100 + (uint)pbVar1[8] +
                      (uint)pbVar1[0xb] * 0x1000000;
    uVar7 = ((((uint)*pbVar1 + (uint)pbVar1[2] * 0x10000 + (uint)pbVar1[1] * 0x100 +
              (uint)pbVar1[3] * 0x1000000) - iVar16) - uVar15) + uVar7 ^ uVar15 >> 0xd;
    uVar10 = (iVar16 - uVar15) - uVar7 ^ uVar7 << 8;
    uVar9 = (uVar15 - uVar7) - uVar10 ^ uVar10 >> 0xd;
    uVar15 = (uVar7 - uVar10) - uVar9 ^ uVar9 >> 0xc;
    uVar13 = (uVar10 - uVar9) - uVar15 ^ uVar15 << 0x10;
    uVar10 = (uVar9 - uVar15) - uVar13 ^ uVar13 >> 5;
    uVar7 = (uVar15 - uVar13) - uVar10 ^ uVar10 >> 3;
    uVar9 = (uVar13 - uVar10) - uVar7 ^ uVar7 << 10;
    uVar15 = (uVar10 - uVar7) - uVar9 ^ uVar9 >> 0xf;
    pbVar1 = pbVar1 + 0xc;
  }
  uVar15 = uVar15 + sVar2;
  switch(uVar18) {
  case 0xb:
    uVar15 = uVar15 + (uint)pbVar1[10] * 0x1000000;
  case 10:
    uVar15 = uVar15 + (uint)pbVar1[9] * 0x10000;
  case 9:
    uVar15 = uVar15 + (uint)pbVar1[8] * 0x100;
  case 8:
    uVar9 = uVar9 + (uint)pbVar1[7] * 0x1000000;
  case 7:
    uVar9 = uVar9 + (uint)pbVar1[6] * 0x10000;
  case 6:
    uVar9 = uVar9 + (uint)pbVar1[5] * 0x100;
  case 5:
    uVar9 = uVar9 + pbVar1[4];
  case 4:
    uVar7 = uVar7 + (uint)pbVar1[3] * 0x1000000;
  case 3:
    uVar7 = uVar7 + (uint)pbVar1[2] * 0x10000;
  case 2:
    uVar7 = uVar7 + (uint)pbVar1[1] * 0x100;
  case 1:
    uVar7 = uVar7 + *pbVar1;
  }
  uVar18 = (uVar7 - uVar9) - uVar15 ^ uVar15 >> 0xd;
  *(byte **)(pbVar8 + 0x1c) = pbVar8;
  uVar7 = (uVar9 - uVar15) - uVar18 ^ uVar18 << 8;
  uVar10 = (uVar15 - uVar18) - uVar7 ^ uVar7 >> 0xd;
  uVar9 = (uVar18 - uVar7) - uVar10 ^ uVar10 >> 0xc;
  uVar15 = (uVar7 - uVar10) - uVar9 ^ uVar9 << 0x10;
  uVar18 = (uVar10 - uVar9) - uVar15 ^ uVar15 >> 5;
  uVar7 = (uVar9 - uVar15) - uVar18 ^ uVar18 >> 3;
  uVar15 = (uVar15 - uVar18) - uVar7 ^ uVar7 << 10;
  uVar15 = (uVar18 - uVar7) - uVar15 ^ uVar15 >> 0xf;
  *(uint *)(pbVar8 + 0x24) = uVar15;
  sVar2 = strlen((char *)pbVar8);
  pbVar1 = devids_15749;
  *(size_t *)(pbVar8 + 0x20) = sVar2;
  if (pbVar1 == (byte *)0x0) {
    pbVar8[0x10] = 0;
    pbVar8[0x11] = 0;
    pbVar8[0x12] = 0;
    pbVar8[0x13] = 0;
    pbVar8[0xc] = 0;
    pbVar8[0xd] = 0;
    pbVar8[0xe] = 0;
    pbVar8[0xf] = 0;
    devids_15749 = pbVar8;
    pvVar4 = malloc(0x2c);
    *(void **)(pbVar8 + 8) = pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_00029ffc;
    memset(pvVar4,0,0x2c);
    puVar12 = *(undefined4 **)(pbVar8 + 8);
    puVar12[4] = pbVar8 + 8;
    puVar12[1] = 0x20;
    puVar12[2] = 5;
    puVar12[5] = 8;
    pvVar4 = malloc(0x180);
    *puVar12 = pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_00029ffc;
    memset(pvVar4,0,0x180);
    piVar6 = *(int **)(pbVar8 + 8);
    piVar6[10] = -0x5feee01f;
  }
  else {
    *(undefined4 *)(pbVar8 + 8) = *(undefined4 *)(pbVar1 + 8);
    piVar6 = *(int **)(pbVar1 + 8);
    pbVar8[0x10] = 0;
    pbVar8[0x11] = 0;
    pbVar8[0x12] = 0;
    pbVar8[0x13] = 0;
    iVar16 = piVar6[4];
    *(int *)(pbVar8 + 0xc) = iVar16 - piVar6[5];
    *(byte **)(iVar16 + 8) = pbVar8;
    piVar6[4] = (int)(pbVar8 + 8);
  }
  iVar16 = *piVar6;
  piVar6[3] = piVar6[3] + 1;
  iVar11 = (piVar6[1] - 1U & uVar15) * 0xc;
  iVar17 = iVar16 + iVar11;
  iVar14 = *(int *)(iVar16 + iVar11);
  uVar15 = *(int *)(iVar17 + 4) + 1;
  *(uint *)(iVar17 + 4) = uVar15;
  *(int *)(pbVar8 + 0x18) = iVar14;
  pbVar8[0x14] = 0;
  pbVar8[0x15] = 0;
  pbVar8[0x16] = 0;
  pbVar8[0x17] = 0;
  if (iVar14 != 0) {
    *(byte **)(iVar14 + 0xc) = pbVar8 + 8;
  }
  iVar17 = *(int *)(iVar17 + 8);
  *(byte **)(iVar16 + iVar11) = pbVar8 + 8;
  if (((uint)((iVar17 + 1) * 10) <= uVar15) && (*(int *)(*(int *)(pbVar8 + 8) + 0x24) != 1)) {
    pvVar4 = calloc(*(int *)(*(int *)(pbVar8 + 8) + 4) * 0x18,1);
    if (pvVar4 == (void *)0x0) {
LAB_00029ffc:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    piVar6 = *(int **)(pbVar8 + 8);
    iVar16 = piVar6[1];
    piVar6[7] = 0;
    uVar7 = (uint)piVar6[3] >> (piVar6[2] + 1U & 0xff);
    uVar15 = iVar16 * 2 - 1;
    if ((piVar6[3] & uVar15) != 0) {
      uVar7 = uVar7 + 1;
    }
    piVar6[6] = uVar7;
    if (iVar16 == 0) {
      local_34 = (void *)*piVar6;
    }
    else {
      local_34 = (void *)*piVar6;
      local_38 = 0;
      do {
        iVar17 = *(int *)((int)local_34 + local_38);
        while (iVar17 != 0) {
          iVar11 = *(int *)(iVar17 + 0x10);
          uVar18 = uVar15 & *(uint *)(iVar17 + 0x1c);
          uVar9 = *(int *)((int)pvVar4 + uVar18 * 0xc + 4) + 1;
          *(uint *)((int)pvVar4 + uVar18 * 0xc + 4) = uVar9;
          if (uVar7 < uVar9) {
            piVar6[7] = piVar6[7] + 1;
            uVar5 = __udivsi3(uVar9,uVar7);
            *(undefined4 *)((int)pvVar4 + uVar18 * 0xc + 8) = uVar5;
          }
          iVar14 = *(int *)((int)pvVar4 + uVar18 * 0xc);
          *(undefined4 *)(iVar17 + 0xc) = 0;
          *(int *)(iVar17 + 0x10) = iVar14;
          if (iVar14 != 0) {
            *(int *)(iVar14 + 0xc) = iVar17;
          }
          *(int *)((int)pvVar4 + uVar18 * 0xc) = iVar17;
          iVar17 = iVar11;
        }
        local_38 = local_38 + 0xc;
      } while (iVar16 * 0xc != local_38);
    }
    free(local_34);
    puVar12 = *(undefined4 **)(pbVar8 + 8);
    *puVar12 = pvVar4;
    iVar16 = puVar12[2] + 1;
    puVar12[2] = iVar16;
    if ((uint)puVar12[7] <= (uint)puVar12[3] >> 1) {
      iVar16 = 0;
    }
    puVar12[1] = puVar12[1] << 1;
    if ((uint)puVar12[3] >> 1 < (uint)puVar12[7]) {
      uVar7 = puVar12[8] + 1;
      puVar12[8] = uVar7;
      uVar15 = uVar7;
      if (1 < uVar7) {
        uVar15 = 1;
      }
      if (1 < uVar7) {
        puVar12[9] = uVar15;
      }
    }
    else {
      puVar12[8] = iVar16;
    }
  }
LAB_00029c70:
  iVar16 = pthread_rwlock_wrlock((pthread_rwlock_t *)devices_lock);
  if (iVar16 == 0) {
    devices = _cgrealloc(devices,(new_devices + total_devices + 2) * 4,"cgminer.c",__func___15774,
                         0x2bab);
    iVar16 = pthread_rwlock_unlock((pthread_rwlock_t *)devices_lock);
    if (iVar16 == 0) {
      (*selective_yield)();
      iVar16 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
      if (iVar16 != 0) {
                    /* WARNING: Subroutine does not return */
        _mutex_lock_part_47_constprop_75(__func___15774,0x2bae);
      }
      tVar3 = time((time_t *)0x0);
      *(time_t *)(param_1 + 0xe8) = tVar3;
      iVar16 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
      if (iVar16 == 0) {
        (*selective_yield)();
        iVar16 = total_devices;
        if (hotplug_mode == '\0') {
          iVar16 = total_devices + 1;
          iVar17 = total_devices * 4;
          total_devices = iVar16;
          *(int *)(devices + iVar17) = param_1;
        }
        else {
          iVar17 = new_devices + total_devices;
          new_devices = new_devices + 1;
          *(int *)(devices + iVar17 * 4) = param_1;
        }
        if (most_devices < iVar16 - zombie_devs) {
          most_devices = iVar16 - zombie_devs;
        }
        return 1;
      }
                    /* WARNING: Subroutine does not return */
      _mutex_unlock_noyield_part_48_constprop_77(__func___15774,0x2bb0);
    }
  }
  else {
    _wr_lock_part_54_constprop_73(__func___15774,0x2baa);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(__func___15774,0x2bac);
}

