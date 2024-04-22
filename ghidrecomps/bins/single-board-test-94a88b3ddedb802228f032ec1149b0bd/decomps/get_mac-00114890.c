
void get_mac(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte local_24;
  
  uVar6 = (int)param_2 >> 3;
  param_2 = param_2 & 7;
  local_24 = (byte)param_2;
  if (param_2 != 0) {
    if (param_2 == 1) {
      local_24 = 0xff;
    }
    else {
      local_24 = 0;
    }
  }
  if ((int)uVar6 < 1) {
    uVar6 = 0;
  }
  else {
    uVar7 = uVar6 >> 2;
    uVar3 = uVar6 & 0xfffffffc;
    if (uVar7 == 0 ||
        ((((uint)param_3 | (uint)param_1) & 3) != 0 ||
        (uVar6 < 4 || param_3 < param_1 + 1 && param_1 < param_3 + 1))) {
      uVar3 = 0;
    }
    else {
      if (uVar7 < 9) {
        uVar4 = 0;
        puVar5 = param_3;
        puVar9 = param_1;
      }
      else {
        uVar4 = 0;
        puVar1 = param_1 + 8;
        puVar2 = param_3 + 8;
        do {
          puVar5 = puVar2;
          puVar9 = puVar1;
          uVar8 = uVar4 + 9;
          uVar4 = uVar4 + 8;
          HintPreloadData(puVar9 + 0x15);
          puVar5[-8] = puVar9[-8];
          puVar5[-7] = puVar9[-7];
          puVar5[-6] = puVar9[-6];
          puVar5[-5] = puVar9[-5];
          puVar5[-4] = puVar9[-4];
          puVar5[-3] = puVar9[-3];
          puVar5[-2] = puVar9[-2];
          puVar5[-1] = puVar9[-1];
          puVar1 = puVar9 + 8;
          puVar2 = puVar5 + 8;
        } while (uVar8 < uVar7 - 7);
      }
      puVar9 = puVar9 + -1;
      do {
        puVar9 = puVar9 + 1;
        uVar4 = uVar4 + 1;
        *puVar5 = *puVar9;
        puVar5 = puVar5 + 1;
      } while (uVar4 < uVar7);
      if (uVar6 == uVar3) goto LAB_0011498e;
    }
    do {
      *(undefined *)((int)param_3 + uVar3) = *(undefined *)((int)param_1 + uVar3);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < (int)uVar6);
  }
LAB_0011498e:
  if (param_2 != 0) {
    *(byte *)((int)param_3 + uVar6) = *(byte *)((int)param_1 + uVar6) & local_24;
  }
  return;
}

