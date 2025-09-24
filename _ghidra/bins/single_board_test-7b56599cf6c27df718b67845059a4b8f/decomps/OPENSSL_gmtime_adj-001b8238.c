
undefined4 OPENSSL_gmtime_adj(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  param_2 = param_2 + param_3 / 0x15180;
  pcVar2 = (char *)(param_3 % 0x15180 + *param_1 + param_1[2] * 0xe10 + param_1[1] * 0x3c);
  if ((int)pcVar2 < 0x15180) {
    if ((int)pcVar2 < 0) {
      param_2 = param_2 + -1;
      pcVar2 = "d2i_X509_REQ" + (int)(pcVar2 + 2);
    }
  }
  else {
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + -0x15180;
  }
  iVar5 = param_1[4] + -0xd;
  iVar6 = iVar5 >> 0x1f;
  iVar5 = iVar5 / 0xc + iVar6;
  iVar7 = iVar5 - iVar6;
  uVar8 = (iVar7 + param_1[5] + 0x1a2c) * 0x5b5;
  uVar4 = ((param_1[5] + 0x1a90 + iVar7) / 100) * 3;
  uVar9 = uVar8 & ~((int)uVar8 >> 0x20);
  if ((int)uVar8 < 0) {
    uVar9 = uVar8 + 3;
  }
  uVar8 = uVar4 & ~((int)uVar4 >> 0x20);
  if ((int)uVar4 < 0) {
    uVar8 = uVar4 + 3;
  }
  param_2 = param_1[3] +
            ((((param_1[4] + -1 + (iVar6 - iVar5) * 0xc) * 0x16f) / 0xc + ((int)uVar9 >> 2)) -
            ((int)uVar8 >> 2)) + -0x7d4b + param_2;
  if (-1 < param_2) {
    param_2 = param_2 + 0x10bd9;
    iVar5 = (param_2 * 4) / 0x23ab1;
    iVar7 = iVar5 * 0x23ab1;
    iVar6 = iVar7 + 3;
    if (iVar6 < 0) {
      iVar6 = iVar7 + 6;
    }
    param_2 = param_2 - (iVar6 >> 2);
    iVar6 = (param_2 * 4000 + 4000) / 0x164b09;
    uVar9 = iVar6 * 0x5b5;
    uVar4 = uVar9 & ~((int)uVar9 >> 0x20);
    if ((int)uVar9 < 0) {
      uVar4 = uVar9 + 3;
    }
    iVar1 = (param_2 - ((int)uVar4 >> 2)) + 0x1f;
    iVar3 = iVar1 * 0x50;
    iVar7 = iVar3 / 0x6925;
    uVar4 = ((iVar5 + -0x31) * 100 + iVar6 + iVar7) - 0x76c;
    if (uVar4 < 0x1fa4) {
      param_1[5] = uVar4;
      iVar3 = iVar3 / 0x98f;
      param_1[4] = iVar3 + iVar7 * -0xc + 1;
      *param_1 = (int)pcVar2 % 0x3c;
      param_1[1] = ((int)pcVar2 / 0x3c) % 0x3c;
      param_1[2] = (int)pcVar2 / 0xe10;
      param_1[3] = iVar1 - (iVar3 * 0x98f) / 0x50;
      return 1;
    }
  }
  return 0;
}

