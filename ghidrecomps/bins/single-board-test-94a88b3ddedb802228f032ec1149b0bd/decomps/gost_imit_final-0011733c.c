
undefined4 gost_imit_final(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int local_30;
  int local_2c;
  
  iVar7 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar7 + 0x103c) == 0) {
    ERR_GOST_error(0x8c,0x74,DAT_0011749c,0x239);
    return 0;
  }
  iVar4 = *(int *)(iVar7 + 0x1030);
  if (iVar4 == 0) {
    if (*(int *)(iVar7 + 0x1038) == 0) goto LAB_00117360;
    local_30 = iVar4;
    local_2c = iVar4;
    gost_imit_update(param_1,&local_30);
  }
  uVar5 = *(uint *)(iVar7 + 0x1038);
  if (uVar5 == 0) goto LAB_00117360;
  if ((int)uVar5 < 8) {
    uVar8 = ~uVar5 + 9;
    uVar2 = -(iVar7 + uVar5 + 0x1028) & 3;
    if (uVar8 <= uVar2) {
      uVar2 = uVar8;
    }
    if (uVar8 < 4) {
      uVar2 = uVar8;
    }
    uVar3 = uVar5;
    uVar6 = uVar5;
    if (uVar2 != 0) {
      do {
        uVar6 = uVar3 + 1;
        *(undefined *)(iVar7 + uVar3 + 0x1028) = 0;
        uVar3 = uVar6;
      } while (uVar6 - uVar5 < uVar2);
      if (uVar8 == uVar2) goto LAB_0011744a;
    }
    uVar8 = uVar8 - uVar2;
    uVar3 = uVar8 >> 2;
    if (uVar3 != 0) {
      puVar9 = (undefined4 *)(uVar5 + 0x1028 + uVar2 + iVar7);
      if (uVar3 < 9) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0;
        puVar1 = puVar9;
        do {
          puVar9 = puVar1 + 8;
          uVar2 = uVar5 + 9;
          uVar5 = uVar5 + 8;
          HintPreloadData(puVar1 + 0x28);
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0;
          puVar1[4] = 0;
          puVar1[5] = 0;
          puVar1[6] = 0;
          puVar1[7] = 0;
          puVar1 = puVar9;
        } while (uVar2 < uVar3 - 7);
      }
      do {
        uVar5 = uVar5 + 1;
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      } while (uVar5 < uVar3);
      uVar6 = uVar6 + (uVar8 & 0xfffffffc);
      if (uVar8 == (uVar8 & 0xfffffffc)) goto LAB_0011744a;
    }
    do {
      iVar4 = iVar7 + uVar6;
      uVar6 = uVar6 + 1;
      *(undefined *)(iVar4 + 0x1028) = 0;
    } while ((int)uVar6 < 8);
  }
LAB_0011744a:
  if ((*(int *)(iVar7 + 0x1034) != 0) && (*(int *)(iVar7 + 0x1030) == 0x400)) {
    cryptopro_key_meshing(iVar7,&local_30);
  }
  mac_block(iVar7,iVar7 + 0x1020,iVar7 + 0x1028);
  *(uint *)(iVar7 + 0x1030) = (*(uint *)(iVar7 + 0x1030) & 0x3ff) + 8;
LAB_00117360:
  get_mac(iVar7 + 0x1020,0x20,param_2);
  return 1;
}

