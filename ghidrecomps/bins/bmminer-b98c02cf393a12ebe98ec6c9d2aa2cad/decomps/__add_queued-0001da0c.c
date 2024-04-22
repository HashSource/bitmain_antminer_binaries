
void __add_queued(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  void *pvVar11;
  int iVar12;
  void *pvVar13;
  void **ppvVar14;
  int local_38;
  void *local_30;
  
  *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
  *(int *)(param_2 + 0x16c) = param_2 + 0x154;
  *(undefined4 *)(param_2 + 0x170) = 4;
  iVar1 = *(int *)(param_1 + 0x160);
  uVar5 = *(byte *)(param_2 + 0x154) + 0x112410d + (uint)*(byte *)(param_2 + 0x157) * 0x1000000 +
          (uint)*(byte *)(param_2 + 0x156) * 0x10000 + (uint)*(byte *)(param_2 + 0x155) * 0x100 ^
          0x7f76d;
  uVar9 = 0x9f49bac6 - uVar5 ^ uVar5 << 8;
  uVar7 = (-0x112410d - uVar5) - uVar9 ^ uVar9 >> 0xd;
  uVar5 = (uVar5 - uVar9) - uVar7 ^ uVar7 >> 0xc;
  uVar9 = (uVar9 - uVar7) - uVar5 ^ uVar5 << 0x10;
  uVar7 = (uVar7 - uVar5) - uVar9 ^ uVar9 >> 5;
  uVar5 = (uVar5 - uVar9) - uVar7 ^ uVar7 >> 3;
  uVar9 = (uVar9 - uVar7) - uVar5 ^ uVar5 << 10;
  uVar5 = (uVar7 - uVar5) - uVar9 ^ uVar9 >> 0xf;
  *(uint *)(param_2 + 0x174) = uVar5;
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 0x160) = 0;
    *(undefined4 *)(param_2 + 0x15c) = 0;
    *(int *)(param_1 + 0x160) = param_2;
    ppvVar14 = (void **)calloc(0x2c,1);
    *(void ***)(param_2 + 0x158) = ppvVar14;
    if (ppvVar14 == (void **)0x0) goto LAB_0001dc84;
    ppvVar14[1] = (void *)0x20;
    ppvVar14[4] = (void *)(param_2 + 0x158);
    ppvVar14[2] = (void *)0x5;
    ppvVar14[5] = (void *)0x158;
    pvVar2 = calloc(0x180,1);
    *ppvVar14 = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_0001dc84;
    iVar1 = *(int *)(param_1 + 0x160);
    ppvVar14[10] = (void *)0xa0111fe1;
  }
  else {
    *(undefined4 *)(param_2 + 0x158) = *(undefined4 *)(iVar1 + 0x158);
    iVar10 = *(int *)(iVar1 + 0x158);
    *(undefined4 *)(param_2 + 0x160) = 0;
    iVar6 = *(int *)(iVar10 + 0x10);
    *(int *)(param_2 + 0x15c) = iVar6 - *(int *)(iVar10 + 0x14);
    *(int *)(iVar6 + 8) = param_2;
    *(int *)(iVar10 + 0x10) = param_2 + 0x158;
  }
  piVar8 = *(int **)(iVar1 + 0x158);
  iVar1 = *piVar8;
  piVar8[3] = piVar8[3] + 1;
  iVar10 = (piVar8[1] - 1U & uVar5) * 0xc;
  iVar6 = iVar1 + iVar10;
  iVar12 = *(int *)(iVar1 + iVar10);
  uVar5 = *(int *)(iVar6 + 4) + 1;
  *(uint *)(iVar6 + 4) = uVar5;
  *(int *)(param_2 + 0x168) = iVar12;
  *(undefined4 *)(param_2 + 0x164) = 0;
  if (iVar12 != 0) {
    *(int *)(iVar12 + 0xc) = param_2 + 0x158;
  }
  iVar6 = *(int *)(iVar6 + 8);
  *(int *)(iVar1 + iVar10) = param_2 + 0x158;
  if (((uint)((iVar6 + 1) * 10) <= uVar5) &&
     (ppvVar14 = *(void ***)(param_2 + 0x158), ppvVar14[9] != (void *)0x1)) {
    pvVar2 = calloc((int)ppvVar14[1] * 0x18,1);
    if (pvVar2 == (void *)0x0) {
LAB_0001dc84:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    pvVar11 = ppvVar14[1];
    ppvVar14[7] = (void *)0x0;
    pvVar13 = (void *)((uint)ppvVar14[3] >> ((int)ppvVar14[2] + 1U & 0xff));
    uVar5 = (int)pvVar11 * 2 - 1;
    if (((uint)ppvVar14[3] & uVar5) != 0) {
      pvVar13 = (void *)((int)pvVar13 + 1);
    }
    ppvVar14[6] = pvVar13;
    if (pvVar11 == (void *)0x0) {
      local_30 = *ppvVar14;
    }
    else {
      local_30 = *ppvVar14;
      local_38 = 0;
      do {
        iVar1 = *(int *)((int)local_30 + local_38);
        while (iVar1 != 0) {
          iVar6 = *(int *)(iVar1 + 0x10);
          uVar7 = uVar5 & *(uint *)(iVar1 + 0x1c);
          pvVar3 = (void *)(*(int *)((int)pvVar2 + uVar7 * 0xc + 4) + 1);
          *(void **)((int)pvVar2 + uVar7 * 0xc + 4) = pvVar3;
          if (pvVar13 < pvVar3) {
            ppvVar14[7] = (void *)((int)ppvVar14[7] + 1);
            uVar4 = __udivsi3(pvVar3,pvVar13);
            *(undefined4 *)((int)pvVar2 + uVar7 * 0xc + 8) = uVar4;
          }
          iVar10 = *(int *)((int)pvVar2 + uVar7 * 0xc);
          *(undefined4 *)(iVar1 + 0xc) = 0;
          *(int *)(iVar1 + 0x10) = iVar10;
          if (iVar10 != 0) {
            *(int *)(iVar10 + 0xc) = iVar1;
          }
          *(int *)((int)pvVar2 + uVar7 * 0xc) = iVar1;
          iVar1 = iVar6;
        }
        local_38 = local_38 + 0xc;
      } while ((int)pvVar11 * 0xc != local_38);
    }
    free(local_30);
    ppvVar14 = *(void ***)(param_2 + 0x158);
    *ppvVar14 = pvVar2;
    pvVar2 = (void *)((int)ppvVar14[2] + 1);
    ppvVar14[2] = pvVar2;
    if (ppvVar14[7] <= (void *)((uint)ppvVar14[3] >> 1)) {
      pvVar2 = (void *)0x0;
    }
    ppvVar14[1] = (void *)((int)ppvVar14[1] << 1);
    if ((void *)((uint)ppvVar14[3] >> 1) < ppvVar14[7]) {
      pvVar11 = (void *)((int)ppvVar14[8] + 1);
      ppvVar14[8] = pvVar11;
      pvVar2 = pvVar11;
      if ((void *)0x1 < pvVar11) {
        pvVar2 = (void *)0x1;
      }
      if ((void *)0x1 < pvVar11) {
        ppvVar14[9] = pvVar2;
      }
    }
    else {
      ppvVar14[8] = pvVar2;
    }
  }
  return;
}

