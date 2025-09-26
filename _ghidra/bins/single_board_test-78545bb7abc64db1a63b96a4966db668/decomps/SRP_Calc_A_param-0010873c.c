
int SRP_Calc_A_param(int param_1)

{
  int iVar1;
  BIGNUM *pBVar2;
  uchar auStack_40 [52];
  
  iVar1 = RAND_priv_bytes(auStack_40,0x30);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    pBVar2 = BN_bin2bn(auStack_40,0x30,*(BIGNUM **)(param_1 + 0x634));
    *(BIGNUM **)(param_1 + 0x634) = pBVar2;
    OPENSSL_cleanse(auStack_40,0x30);
    iVar1 = SRP_Calc_A(*(undefined4 *)(param_1 + 0x634),*(undefined4 *)(param_1 + 0x620),
                       *(undefined4 *)(param_1 + 0x624));
    *(int *)(param_1 + 0x630) = iVar1;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

