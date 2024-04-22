
undefined4 gost_imit_update(int param_1,undefined *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined auStack_30 [12];
  
  iVar7 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar7 + 0x103c) == 0) {
    ERR_GOST_error(0x73,0x74,DAT_00117338,0x21b);
    uVar3 = 0;
  }
  else {
    uVar5 = *(uint *)(iVar7 + 0x1038);
    if (uVar5 != 0) {
      uVar1 = param_3;
      if (param_3 != 0) {
        uVar1 = 1;
      }
      if (7 < uVar5) {
        uVar1 = 0;
      }
      puVar4 = param_2;
      if (uVar1 != 0) {
        do {
          param_3 = param_3 - 1;
          param_2 = puVar4 + 1;
          iVar2 = iVar7 + uVar5;
          uVar5 = uVar5 + 1;
          *(undefined *)(iVar2 + 0x1028) = *puVar4;
          puVar4 = param_2;
        } while (uVar5 < 8 && param_3 != 0);
      }
      if (uVar5 != 8) {
        *(uint *)(iVar7 + 0x1038) = uVar5;
        return 1;
      }
      if ((*(int *)(iVar7 + 0x1034) != 0) && (*(int *)(iVar7 + 0x1030) == 0x400)) {
        cryptopro_key_meshing(iVar7,auStack_30);
      }
      mac_block(iVar7,iVar7 + 0x1020,iVar7 + 0x1028);
      *(uint *)(iVar7 + 0x1030) = (*(uint *)(iVar7 + 0x1030) & 0x3ff) + 8;
    }
    if (8 < param_3) {
      puVar6 = (uint *)(iVar7 + 0x1030);
      puVar4 = param_2;
      uVar5 = param_3;
      do {
        uVar5 = uVar5 - 8;
        if ((*(int *)(iVar7 + 0x1034) != 0) && (*puVar6 == 0x400)) {
          cryptopro_key_meshing(iVar7,auStack_30);
        }
        mac_block(iVar7,iVar7 + 0x1020,puVar4);
        *puVar6 = (*puVar6 & 0x3ff) + 8;
        puVar4 = puVar4 + 8;
      } while (8 < uVar5);
      uVar5 = param_3 - 9;
      param_3 = (param_3 - 8) - (uVar5 & 0xfffffff8);
      param_2 = param_2 + ((uVar5 >> 3) + 1) * 8;
    }
    if (param_3 != 0) {
      memcpy((void *)(iVar7 + 0x1028),param_2,param_3);
    }
    uVar3 = 1;
    *(uint *)(iVar7 + 0x1038) = param_3;
  }
  return uVar3;
}

