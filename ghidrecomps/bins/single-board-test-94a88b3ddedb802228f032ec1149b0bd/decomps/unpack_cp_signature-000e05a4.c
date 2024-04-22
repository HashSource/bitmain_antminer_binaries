
DSA_SIG * unpack_cp_signature(uchar *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uchar uVar1;
  DSA_SIG *pDVar2;
  BIGNUM *pBVar3;
  uchar *puVar4;
  uint len;
  
  pDVar2 = DSA_SIG_new();
  if (pDVar2 == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x89,0x76,DAT_000e0640,0x146,param_4);
    return (DSA_SIG *)0x0;
  }
  param_2 = param_2 >> 1;
  len = param_2;
  puVar4 = param_1;
  if (*param_1 == '\0') {
    if (param_2 != 0) {
      puVar4 = param_1 + 1;
      do {
        len = len - 1;
        if (*puVar4 != '\0') goto joined_r0x000e062c;
        puVar4 = puVar4 + 1;
      } while (len != 0);
    }
  }
  else {
joined_r0x000e062c:
    if (len != 0) {
      pBVar3 = BN_bin2bn(puVar4,len,(BIGNUM *)0x0);
      goto LAB_000e05ea;
    }
  }
  pBVar3 = BN_new();
  BN_set_word(pBVar3,0);
LAB_000e05ea:
  pDVar2->s = pBVar3;
  puVar4 = param_1 + param_2;
  uVar1 = param_1[param_2];
  while (uVar1 == '\0') {
    if (param_2 == 0) goto LAB_000e0614;
    puVar4 = puVar4 + 1;
    param_2 = param_2 - 1;
    uVar1 = *puVar4;
  }
  if (param_2 == 0) {
LAB_000e0614:
    pBVar3 = BN_new();
    BN_set_word(pBVar3,0);
  }
  else {
    pBVar3 = BN_bin2bn(puVar4,param_2,(BIGNUM *)0x0);
  }
  pDVar2->r = pBVar3;
  return pDVar2;
}

