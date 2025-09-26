
undefined4 OPENSSL_gmtime_adj(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  param_2 = param_2 + param_3 / 0x15180;
  iVar6 = param_3 % 0x15180 + param_1[2] * 0xe10 + param_1[1] * 0x3c + *param_1;
  if (iVar6 < 0x15180) {
    if (iVar6 < 0) {
      param_2 = param_2 + -1;
      iVar6 = iVar6 + 0x15180;
    }
  }
  else {
    param_2 = param_2 + 1;
    iVar6 = iVar6 + -0x15180;
  }
  iVar8 = param_1[4] + -0xd;
  iVar1 = iVar8 >> 0x1f;
  iVar8 = iVar8 / 0xc + iVar1;
  iVar2 = iVar8 - iVar1;
  uVar3 = (param_1[5] + 0x1a2c + iVar2) * 0x5b5;
  uVar5 = ((param_1[5] + 0x1a90 + iVar2) / 100) * 3;
  uVar4 = uVar5 & ~((int)uVar5 >> 0x20);
  if ((int)uVar5 < 0) {
    uVar4 = uVar5 + 3;
  }
  uVar5 = uVar3 & ~((int)uVar3 >> 0x20);
  if ((int)uVar3 < 0) {
    uVar5 = uVar3 + 3;
  }
  param_2 = param_2 + ((((iVar1 - iVar8) * 0x1134 + param_1[4] * 0x16f + -0x16f) / 0xc +
                       ((int)uVar5 >> 2)) - ((int)uVar4 >> 2)) + param_1[3] + -0x7d4b;
  if (-1 < param_2) {
    param_2 = param_2 + 0x10bd9;
    iVar1 = (param_2 * 4) / 0x23ab1;
    iVar2 = iVar1 * 0x23ab1;
    iVar8 = iVar2 + 3;
    if (iVar8 < 0) {
      iVar8 = iVar2 + 6;
    }
    param_2 = param_2 - (iVar8 >> 2);
    iVar8 = (param_2 * 4000 + 4000) / 0x164b09;
    uVar4 = iVar8 * 0x5b5;
    uVar5 = uVar4 & ~((int)uVar4 >> 0x20);
    if ((int)uVar4 < 0) {
      uVar5 = uVar4 + 3;
    }
    iVar7 = (param_2 - ((int)uVar5 >> 2)) + 0x1f;
    iVar2 = (iVar7 * 0x50) / 0x98f;
    uVar5 = (iVar1 * 100 + iVar8 + iVar2 / 0xb) - 0x1a90;
    if (uVar5 < 0x1fa4) {
      param_1[5] = uVar5;
      param_1[4] = iVar2 + (iVar2 / 0xb) * -0xc + 1;
      param_1[2] = iVar6 / 0xe10;
      *param_1 = iVar6 % 0x3c;
      param_1[3] = iVar7 - (iVar2 * 0x98f) / 0x50;
      param_1[1] = (iVar6 / 0x3c) % 0x3c;
      return 1;
    }
  }
  return 0;
}

