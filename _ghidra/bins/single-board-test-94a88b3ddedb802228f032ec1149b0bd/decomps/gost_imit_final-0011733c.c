
undefined4 gost_imit_final(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int local_30;
  int local_2c;
  
  iVar8 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar8 + 0x103c) == 0) {
    ERR_GOST_error(0x8c,0x74,"gost_crypt.c",0x239);
    return 0;
  }
  iVar5 = *(int *)(iVar8 + 0x1030);
  if (iVar5 == 0) {
    if (*(int *)(iVar8 + 0x1038) == 0) goto LAB_00117360;
    local_30 = iVar5;
    local_2c = iVar5;
    gost_imit_update(param_1,&local_30);
  }
  uVar6 = *(uint *)(iVar8 + 0x1038);
  if (uVar6 == 0) goto LAB_00117360;
  if ((int)uVar6 < 8) {
    uVar9 = ~uVar6 + 9;
    uVar2 = -(iVar8 + uVar6 + 0x1028) & 3;
    if (uVar9 <= uVar2) {
      uVar2 = uVar9;
    }
    if (uVar9 < 4) {
      uVar2 = uVar9;
    }
    uVar4 = uVar6;
    uVar7 = uVar6;
    if (uVar2 != 0) {
      do {
        uVar7 = uVar4 + 1;
        *(undefined1 *)(iVar8 + uVar4 + 0x1028) = 0;
        uVar4 = uVar7;
      } while (uVar7 - uVar6 < uVar2);
      if (uVar9 == uVar2) goto LAB_0011744a;
    }
    uVar4 = uVar9 - uVar2 >> 2;
    if (uVar4 != 0) {
      puVar10 = (undefined4 *)(uVar6 + 0x1028 + uVar2 + iVar8);
      if (uVar4 < 9) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0;
        puVar1 = puVar10;
        do {
          puVar10 = puVar1 + 8;
          uVar3 = uVar6 + 9;
          uVar6 = uVar6 + 8;
          HintPreloadData(puVar1 + 0x28);
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0;
          puVar1[4] = 0;
          puVar1[5] = 0;
          puVar1[6] = 0;
          puVar1[7] = 0;
          puVar1 = puVar10;
        } while (uVar3 < uVar4 - 7);
      }
      do {
        uVar6 = uVar6 + 1;
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      } while (uVar6 < uVar4);
      uVar7 = uVar7 + uVar4 * 4;
      if (uVar9 - uVar2 == uVar4 * 4) goto LAB_0011744a;
    }
    do {
      iVar5 = iVar8 + uVar7;
      uVar7 = uVar7 + 1;
      *(undefined1 *)(iVar5 + 0x1028) = 0;
    } while ((int)uVar7 < 8);
  }
LAB_0011744a:
  if ((*(int *)(iVar8 + 0x1034) != 0) && (*(int *)(iVar8 + 0x1030) == 0x400)) {
    cryptopro_key_meshing(iVar8,&local_30);
  }
  mac_block(iVar8,iVar8 + 0x1020,iVar8 + 0x1028);
  *(uint *)(iVar8 + 0x1030) = (*(uint *)(iVar8 + 0x1030) & 0x3ff) + 8;
LAB_00117360:
  get_mac(iVar8 + 0x1020,0x20,param_2);
  return 1;
}

