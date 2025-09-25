
int SSL_srp_server_param_with_username(int param_1,undefined4 *param_2)

{
  int iVar1;
  BIGNUM *pBVar2;
  code *pcVar3;
  uchar auStack_40 [52];
  
  pcVar3 = *(code **)(param_1 + 0x610);
  *param_2 = 0x73;
  if ((pcVar3 != (code *)0x0) &&
     (iVar1 = (*pcVar3)(param_1,param_2,*(undefined4 *)(param_1 + 0x60c)), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = *(int *)(param_1 + 0x620);
  *param_2 = 0x50;
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x624) != 0)) && (*(int *)(param_1 + 0x628) != 0)) &&
     ((*(int *)(param_1 + 0x63c) != 0 && (iVar1 = RAND_priv_bytes(auStack_40,0x30), 0 < iVar1)))) {
    pBVar2 = BN_bin2bn(auStack_40,0x30,(BIGNUM *)0x0);
    *(BIGNUM **)(param_1 + 0x638) = pBVar2;
    OPENSSL_cleanse(auStack_40,0x30);
    iVar1 = SRP_Calc_B(*(undefined4 *)(param_1 + 0x638),*(undefined4 *)(param_1 + 0x620),
                       *(undefined4 *)(param_1 + 0x624),*(undefined4 *)(param_1 + 0x63c));
    *(int *)(param_1 + 0x62c) = iVar1;
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 2;
}

