
undefined4
gost_mac_iv(undefined4 param_1,uint param_2,undefined4 *param_3,int param_4,uint param_5,
           undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  byte local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_38 = *param_3;
  uStack_34 = param_3[1];
  if (param_5 < 8) {
    uVar7 = 8;
    uVar4 = 0;
  }
  else {
    uVar10 = 0;
    uVar7 = 8;
    do {
      uVar4 = uVar7;
      uVar7 = uVar4 + 8;
      mac_block(param_1,&local_38,uVar10 + param_4);
      uVar10 = uVar4;
    } while (uVar7 <= param_5);
  }
  if (uVar4 < param_5) {
    local_2c = 0;
    local_30 = 0;
    memcpy(&local_30,(void *)(param_4 + uVar4),param_5 - uVar4);
    mac_block(param_1,&local_38,&local_30);
    uVar4 = uVar7;
  }
  if (uVar4 == 8) {
    local_2c = 0;
    local_30 = 0;
    mac_block(param_1,&local_38,&local_30);
  }
  uVar4 = param_2 & 7;
  local_3c = (byte)uVar4;
  param_2 = (int)param_2 >> 3;
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      local_3c = 0xff;
    }
    else {
      local_3c = 0;
    }
  }
  if ((int)param_2 < 1) {
    param_2 = 0;
  }
  else {
    uVar10 = param_2 >> 2;
    uVar7 = param_2 & 0xfffffffc;
    if (uVar10 == 0 || (param_2 < 4 || ((uint)param_6 & 3) != 0)) {
      uVar7 = 0;
    }
    else {
      if (uVar10 < 9) {
        puVar11 = &local_38;
        uVar3 = 0;
        puVar6 = param_6;
      }
      else {
        puVar2 = (undefined4 *)&stack0xffffffe8;
        uVar8 = 0;
        puVar1 = param_6;
        do {
          puVar11 = puVar2;
          uVar3 = uVar8 + 8;
          uVar12 = uVar8 + 9;
          uVar9 = puVar11[-5];
          HintPreloadData(puVar11 + 0x15);
          *puVar1 = puVar11[-8];
          uVar5 = puVar11[-7];
          puVar1[3] = uVar9;
          uVar9 = puVar11[-4];
          puVar1[1] = uVar5;
          uVar5 = puVar11[-6];
          puVar1[4] = uVar9;
          puVar1[2] = uVar5;
          puVar1[7] = puVar11[-1];
          puVar1[5] = puVar11[-3];
          puVar1[6] = puVar11[-2];
          puVar2 = puVar11 + 8;
          puVar6 = puVar1 + 8;
          uVar8 = uVar3;
          puVar1 = puVar1 + 8;
        } while (uVar12 < uVar10 - 7);
      }
      puVar11 = puVar11 + -1;
      do {
        puVar11 = puVar11 + 1;
        uVar3 = uVar3 + 1;
        *puVar6 = *puVar11;
        puVar6 = puVar6 + 1;
      } while (uVar3 < uVar10);
      if (param_2 == uVar7) goto LAB_00114c68;
    }
    do {
      *(undefined *)((int)param_6 + uVar7) = *(undefined *)((int)&local_38 + uVar7);
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)param_2);
  }
LAB_00114c68:
  if (uVar4 != 0) {
    *(byte *)((int)param_6 + param_2) = *(byte *)((int)&local_38 + param_2) & local_3c;
  }
  return 1;
}

