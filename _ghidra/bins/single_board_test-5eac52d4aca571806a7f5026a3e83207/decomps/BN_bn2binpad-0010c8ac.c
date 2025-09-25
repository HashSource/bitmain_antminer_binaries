
size_t BN_bn2binpad(BIGNUM *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  BIGNUM local_34;
  
  if ((int)param_3 < 0) {
    return 0xffffffff;
  }
  iVar2 = BN_num_bits(param_1);
  iVar5 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar5 = iVar2 + 0xe;
  }
  if ((int)param_3 < iVar5 >> 3) {
    local_34.d = param_1->d;
    local_34.top = param_1->top;
    local_34.dmax = param_1->dmax;
    local_34.neg = param_1->neg;
    local_34.flags = param_1->flags;
    bn_correct_top(&local_34);
    iVar2 = BN_num_bits(&local_34);
    iVar5 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar5 = iVar2 + 0xe;
    }
    if ((int)param_3 < iVar5 >> 3) {
      return 0xffffffff;
    }
    iVar5 = param_1->dmax;
  }
  else {
    iVar5 = param_1->dmax;
  }
  if (iVar5 * 8 != 0) {
    iVar4 = param_1->top;
    pbVar3 = (byte *)((int)param_2 + param_3);
    uVar7 = 0;
    iVar2 = iVar4 * -8;
    if (param_3 != 0) {
      do {
        uVar8 = uVar7 >> 3;
        uVar6 = uVar7 & 7;
        uVar7 = uVar7 - ((int)(uVar7 - (iVar5 * 8 + -1)) >> 0x1f);
        iVar1 = iVar2 >> 0x1f;
        iVar2 = iVar2 + 1;
        pbVar3 = pbVar3 + -1;
        *pbVar3 = (byte)(param_1->d[uVar8] >> (uVar6 << 3)) & (byte)iVar1;
      } while (param_3 + iVar4 * -8 != iVar2);
    }
    return param_3;
  }
  OPENSSL_cleanse(param_2,param_3);
  return param_3;
}

