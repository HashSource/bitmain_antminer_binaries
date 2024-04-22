
undefined4 inflateReset2(int param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 unaff_r8;
  bool bVar7;
  
  if ((param_1 != 0) && (puVar5 = *(undefined4 **)(param_1 + 0x1c), puVar5 != (undefined4 *)0x0)) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar6 = 0;
    }
    else {
      iVar6 = (int)param_2 >> 4;
      if ((int)param_2 < 0x30) {
        param_2 = param_2 & 0xf;
      }
      iVar6 = iVar6 + 1;
    }
    bVar7 = param_2 == 0;
    bVar2 = param_2 - 8 != 7;
    bVar1 = 6 < param_2 - 8;
    if (!bVar7 && !bVar1 || (bVar7 || !bVar2)) {
      unaff_r8 = 0;
    }
    if ((bVar7 || bVar1) && (!bVar7 && bVar2)) {
      unaff_r8 = 1;
    }
    if (!bVar7 && !bVar1 || (bVar7 || !bVar2)) {
      if ((puVar5[0xd] == 0) || (param_2 == puVar5[9])) {
        puVar5[2] = iVar6;
        puVar5[9] = param_2;
      }
      else {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
        puVar4 = *(undefined4 **)(param_1 + 0x1c);
        puVar5[0xd] = unaff_r8;
        puVar5[2] = iVar6;
        puVar5[9] = param_2;
        puVar5 = puVar4;
        if (puVar4 == (undefined4 *)0x0) {
          return 0xfffffffe;
        }
      }
      uVar3 = puVar5[2];
      puVar5[10] = 0;
      puVar5[0xb] = 0;
      puVar5[0xc] = 0;
      puVar5[7] = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (uVar3 != 0) {
        *(uint *)(param_1 + 0x30) = uVar3 & 1;
      }
      puVar4 = puVar5 + 0x14c;
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[3] = 0;
      puVar5[8] = 0;
      puVar5[0xe] = 0;
      puVar5[0xf] = 0;
      puVar5[5] = 0x8000;
      puVar5[0x1b] = puVar4;
      puVar5[0x14] = puVar4;
      puVar5[0x13] = puVar4;
      puVar5[0x6f0] = 1;
      puVar5[0x6f1] = 0xffffffff;
      return 0;
    }
  }
  return 0xfffffffe;
}

