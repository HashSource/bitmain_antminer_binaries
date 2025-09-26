
undefined4 OPENSSL_gmtime_diff(uint *param_1,uint *param_2,int *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar1 = param_3[2] * 0xe10 + param_3[1] * 0x3c + *param_3;
  if (iVar1 < 0x15180) {
    if (iVar1 < 0) {
      iVar4 = -1;
      iVar1 = iVar1 + 0x15180;
    }
    else {
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 1;
    iVar1 = iVar1 + -0x15180;
  }
  iVar7 = param_3[4] + -0xd;
  iVar8 = iVar7 >> 0x1f;
  iVar7 = iVar7 / 0xc + iVar8;
  iVar9 = iVar7 - iVar8;
  uVar5 = (param_3[5] + 0x1a2c + iVar9) * 0x5b5;
  uVar3 = ((iVar9 + param_3[5] + 0x1a90) / 100) * 3;
  uVar2 = uVar3 & ~((int)uVar3 >> 0x20);
  if ((int)uVar3 < 0) {
    uVar2 = uVar3 + 3;
  }
  uVar3 = uVar5 & ~((int)uVar5 >> 0x20);
  if ((int)uVar5 < 0) {
    uVar3 = uVar5 + 3;
  }
  iVar4 = iVar4 + param_3[3] +
                  ((((iVar8 - iVar7) * 0x1134 + param_3[4] * 0x16f + -0x16f) / 0xc +
                   ((int)uVar3 >> 2)) - ((int)uVar2 >> 2)) + -0x7d4b;
  if (-1 < iVar4) {
    iVar7 = param_4[2] * 0xe10 + param_4[1] * 0x3c + *param_4;
    if (iVar7 < 0x15180) {
      if (iVar7 < 0) {
        iVar8 = -1;
        iVar7 = iVar7 + 0x15180;
      }
      else {
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 1;
      iVar7 = iVar7 + -0x15180;
    }
    iVar10 = param_4[4] + -0xd;
    iVar9 = iVar10 >> 0x1f;
    iVar10 = iVar10 / 0xc + iVar9;
    iVar6 = iVar10 - iVar9;
    uVar5 = (param_4[5] + 0x1a2c + iVar6) * 0x5b5;
    uVar3 = ((iVar6 + param_4[5] + 0x1a90) / 100) * 3;
    uVar2 = uVar3 & ~((int)uVar3 >> 0x20);
    if ((int)uVar3 < 0) {
      uVar2 = uVar3 + 3;
    }
    uVar3 = uVar5 & ~((int)uVar5 >> 0x20);
    if ((int)uVar5 < 0) {
      uVar3 = uVar5 + 3;
    }
    iVar8 = iVar8 + param_4[3] +
                    ((((iVar9 - iVar10) * 0x1134 + param_4[4] * 0x16f + -0x16f) / 0xc +
                     ((int)uVar3 >> 2)) - ((int)uVar2 >> 2)) + -0x7d4b;
    if (-1 < iVar8) {
      uVar2 = iVar7 - iVar1;
      uVar5 = iVar8 - iVar4;
      uVar3 = uVar2 >> 0x1f;
      if ((int)uVar5 < 1) {
        uVar3 = 0;
      }
      if (uVar3 != 0) {
        uVar5 = uVar5 - 1;
        uVar2 = uVar2 + 0x15180;
      }
      uVar3 = uVar5 >> 0x1f;
      if ((int)uVar2 < 1) {
        uVar3 = 0;
      }
      if (uVar3 != 0) {
        uVar5 = uVar5 + 1;
        uVar2 = uVar2 - 0x15180;
      }
      if (param_1 != (uint *)0x0) {
        *param_1 = uVar5;
      }
      if (param_2 != (uint *)0x0) {
        *param_2 = uVar2;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

