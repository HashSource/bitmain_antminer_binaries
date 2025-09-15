
void __add_queued(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  int local_38;
  void *local_30;
  
  *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
  *(int *)(param_2 + 0x16c) = param_2 + 0x154;
  *(undefined4 *)(param_2 + 0x170) = 4;
  iVar1 = *(int *)(param_1 + 0x160);
  uVar4 = *(byte *)(param_2 + 0x154) + 0x112410d + (uint)*(byte *)(param_2 + 0x157) * 0x1000000 +
          (uint)*(byte *)(param_2 + 0x156) * 0x10000 + (uint)*(byte *)(param_2 + 0x155) * 0x100 ^
          0x7f76d;
  uVar8 = 0x9f49bac6 - uVar4 ^ uVar4 << 8;
  uVar6 = (-0x112410d - uVar4) - uVar8 ^ uVar8 >> 0xd;
  uVar4 = (uVar4 - uVar8) - uVar6 ^ uVar6 >> 0xc;
  uVar8 = (uVar8 - uVar6) - uVar4 ^ uVar4 << 0x10;
  uVar6 = (uVar6 - uVar4) - uVar8 ^ uVar8 >> 5;
  uVar4 = (uVar4 - uVar8) - uVar6 ^ uVar6 >> 3;
  uVar8 = (uVar8 - uVar6) - uVar4 ^ uVar4 << 10;
  uVar4 = (uVar6 - uVar4) - uVar8 ^ uVar8 >> 0xf;
  *(uint *)(param_2 + 0x174) = uVar4;
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 0x160) = 0;
    *(undefined4 *)(param_2 + 0x15c) = 0;
    *(int *)(param_1 + 0x160) = param_2;
    puVar10 = (undefined4 *)calloc(0x2c,1);
    *(undefined4 **)(param_2 + 0x158) = puVar10;
    if (puVar10 == (undefined4 *)0x0) goto LAB_0001dc84;
    puVar10[1] = 0x20;
    puVar10[4] = param_2 + 0x158;
    puVar10[2] = 5;
    puVar10[5] = 0x158;
    pvVar2 = calloc(0x180,1);
    *puVar10 = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_0001dc84;
    iVar1 = *(int *)(param_1 + 0x160);
    puVar10[10] = 0xa0111fe1;
  }
  else {
    *(undefined4 *)(param_2 + 0x158) = *(undefined4 *)(iVar1 + 0x158);
    iVar9 = *(int *)(iVar1 + 0x158);
    *(undefined4 *)(param_2 + 0x160) = 0;
    iVar5 = *(int *)(iVar9 + 0x10);
    *(int *)(param_2 + 0x15c) = iVar5 - *(int *)(iVar9 + 0x14);
    *(int *)(iVar5 + 8) = param_2;
    *(int *)(iVar9 + 0x10) = param_2 + 0x158;
  }
  piVar7 = *(int **)(iVar1 + 0x158);
  iVar1 = *piVar7;
  piVar7[3] = piVar7[3] + 1;
  iVar9 = (piVar7[1] - 1U & uVar4) * 0xc;
  iVar5 = iVar1 + iVar9;
  iVar12 = *(int *)(iVar1 + iVar9);
  uVar4 = *(int *)(iVar5 + 4) + 1;
  *(uint *)(iVar5 + 4) = uVar4;
  *(int *)(param_2 + 0x168) = iVar12;
  *(undefined4 *)(param_2 + 0x164) = 0;
  if (iVar12 != 0) {
    *(int *)(iVar12 + 0xc) = param_2 + 0x158;
  }
  iVar5 = *(int *)(iVar5 + 8);
  *(int *)(iVar1 + iVar9) = param_2 + 0x158;
  if (((uint)((iVar5 + 1) * 10) <= uVar4) && (piVar7 = *(int **)(param_2 + 0x158), piVar7[9] != 1))
  {
    pvVar2 = calloc(piVar7[1] * 0x18,1);
    if (pvVar2 == (void *)0x0) {
LAB_0001dc84:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    iVar1 = piVar7[1];
    piVar7[7] = 0;
    uVar4 = (uint)piVar7[3] >> (piVar7[2] + 1U & 0xff);
    uVar6 = iVar1 * 2 - 1;
    if ((piVar7[3] & uVar6) != 0) {
      uVar4 = uVar4 + 1;
    }
    piVar7[6] = uVar4;
    if (iVar1 == 0) {
      local_30 = (void *)*piVar7;
    }
    else {
      local_30 = (void *)*piVar7;
      local_38 = 0;
      do {
        iVar5 = *(int *)((int)local_30 + local_38);
        while (iVar5 != 0) {
          iVar9 = *(int *)(iVar5 + 0x10);
          uVar11 = uVar6 & *(uint *)(iVar5 + 0x1c);
          uVar8 = *(int *)((int)pvVar2 + uVar11 * 0xc + 4) + 1;
          *(uint *)((int)pvVar2 + uVar11 * 0xc + 4) = uVar8;
          if (uVar4 < uVar8) {
            piVar7[7] = piVar7[7] + 1;
            uVar3 = __udivsi3(uVar8,uVar4);
            *(undefined4 *)((int)pvVar2 + uVar11 * 0xc + 8) = uVar3;
          }
          iVar12 = *(int *)((int)pvVar2 + uVar11 * 0xc);
          *(undefined4 *)(iVar5 + 0xc) = 0;
          *(int *)(iVar5 + 0x10) = iVar12;
          if (iVar12 != 0) {
            *(int *)(iVar12 + 0xc) = iVar5;
          }
          *(int *)((int)pvVar2 + uVar11 * 0xc) = iVar5;
          iVar5 = iVar9;
        }
        local_38 = local_38 + 0xc;
      } while (iVar1 * 0xc != local_38);
    }
    free(local_30);
    puVar10 = *(undefined4 **)(param_2 + 0x158);
    *puVar10 = pvVar2;
    iVar1 = puVar10[2] + 1;
    puVar10[2] = iVar1;
    if ((uint)puVar10[7] <= (uint)puVar10[3] >> 1) {
      iVar1 = 0;
    }
    puVar10[1] = puVar10[1] << 1;
    if ((uint)puVar10[3] >> 1 < (uint)puVar10[7]) {
      uVar6 = puVar10[8] + 1;
      puVar10[8] = uVar6;
      uVar4 = uVar6;
      if (1 < uVar6) {
        uVar4 = 1;
      }
      if (1 < uVar6) {
        puVar10[9] = uVar4;
      }
    }
    else {
      puVar10[8] = iVar1;
    }
  }
  return;
}

