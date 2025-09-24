
undefined4 OPENSSL_gmtime_diff(uint *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_2c;
  
  pcVar3 = (char *)(*param_3 + param_3[2] * 0xe10 + param_3[1] * 0x3c);
  if ((int)pcVar3 < 0x15180) {
    if ((int)pcVar3 < 0) {
      iVar9 = -1;
      pcVar3 = "d2i_X509_REQ" + (int)(pcVar3 + 2);
    }
    else {
      iVar9 = 0;
    }
  }
  else {
    iVar9 = 1;
    pcVar3 = pcVar3 + -0x15180;
  }
  iVar8 = param_3[4] + -0xd;
  iVar1 = iVar8 >> 0x1f;
  iVar8 = iVar8 / 0xc + iVar1;
  iVar5 = iVar8 - iVar1;
  uVar6 = (iVar5 + param_3[5] + 0x1a2c) * 0x5b5;
  uVar2 = uVar6 & ~((int)uVar6 >> 0x20);
  if ((int)uVar6 < 0) {
    uVar2 = uVar6 + 3;
  }
  uVar6 = ((param_3[5] + 0x1a90 + iVar5) / 100) * 3;
  uVar7 = uVar6 & ~((int)uVar6 >> 0x20);
  if ((int)uVar6 < 0) {
    uVar7 = uVar6 + 3;
  }
  iVar9 = param_3[3] +
          ((((param_3[4] + -1 + (iVar1 - iVar8) * 0xc) * 0x16f) / 0xc + ((int)uVar2 >> 2)) -
          ((int)uVar7 >> 2)) + -0x7d4b + iVar9;
  if (-1 < iVar9) {
    pcVar4 = (char *)(*param_4 + param_4[2] * 0xe10 + param_4[1] * 0x3c);
    if ((int)pcVar4 < 0x15180) {
      if ((int)pcVar4 < 0) {
        pcVar4 = "d2i_X509_REQ" + (int)(pcVar4 + 2);
        local_2c = -1;
      }
      else {
        local_2c = 0;
      }
    }
    else {
      local_2c = 1;
      pcVar4 = pcVar4 + -0x15180;
    }
    iVar8 = param_4[4] + -0xd;
    iVar1 = iVar8 >> 0x1f;
    iVar8 = iVar8 / 0xc + iVar1;
    iVar5 = iVar8 - iVar1;
    uVar7 = (iVar5 + param_4[5] + 0x1a2c) * 0x5b5;
    uVar2 = ((param_4[5] + 0x1a90 + iVar5) / 100) * 3;
    uVar6 = uVar7 & ~((int)uVar7 >> 0x20);
    if ((int)uVar7 < 0) {
      uVar6 = uVar7 + 3;
    }
    uVar7 = uVar2 & ~((int)uVar2 >> 0x20);
    if ((int)uVar2 < 0) {
      uVar7 = uVar2 + 3;
    }
    local_2c = param_4[3] +
               ((((param_4[4] + -1 + (iVar1 - iVar8) * 0xc) * 0x16f) / 0xc + ((int)uVar6 >> 2)) -
               ((int)uVar7 >> 2)) + -0x7d4b + local_2c;
    if (-1 < local_2c) {
      pcVar4 = pcVar4 + -(int)pcVar3;
      uVar6 = local_2c - iVar9;
      uVar2 = (uint)pcVar4 >> 0x1f;
      if ((int)uVar6 < 1) {
        uVar2 = 0;
      }
      if (uVar2 == 0) {
        if (((uint)(0 < (int)pcVar4) & uVar6 >> 0x1f) != 0) {
          uVar6 = uVar6 + 1;
          pcVar4 = pcVar4 + -0x15180;
        }
      }
      else {
        uVar6 = uVar6 - 1;
        pcVar4 = "d2i_X509_REQ" + (int)(pcVar4 + 2);
      }
      if (param_1 != (uint *)0x0) {
        *param_1 = uVar6;
      }
      if (param_2 == (undefined4 *)0x0) {
        return 1;
      }
      *param_2 = pcVar4;
      return 1;
    }
  }
  return 0;
}

