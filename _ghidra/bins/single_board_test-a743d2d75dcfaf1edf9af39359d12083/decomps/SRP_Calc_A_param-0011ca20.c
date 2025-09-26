
undefined4 SRP_Calc_A_param(int param_1)

{
  int iVar1;
  BIGNUM *pBVar2;
  uchar auStack_38 [48];
  
  iVar1 = RAND_bytes(auStack_38,0x30);
  if (0 < iVar1) {
    pBVar2 = BN_bin2bn(auStack_38,0x30,*(BIGNUM **)(param_1 + 0x1bc));
    *(BIGNUM **)(param_1 + 0x1bc) = pBVar2;
    OPENSSL_cleanse(auStack_38,0x30);
    iVar1 = SRP_Calc_A(*(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(param_1 + 0x1a8),
                       *(undefined4 *)(param_1 + 0x1ac));
    *(int *)(param_1 + 0x1b8) = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

