
int SSL_srp_server_param_with_username(int param_1,undefined4 *param_2)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  code *pcVar4;
  uchar auStack_40 [52];
  
  pcVar4 = *(code **)(param_1 + 0x198);
  *param_2 = 0x73;
  if ((pcVar4 == (code *)0x0) ||
     (iVar1 = (*pcVar4)(param_1,param_2,*(undefined4 *)(param_1 + 0x194)), iVar1 == 0)) {
    iVar1 = *(int *)(param_1 + 0x1a8);
    *param_2 = 0x50;
    if (((iVar1 == 0) ||
        (((*(int *)(param_1 + 0x1ac) == 0 || (*(int *)(param_1 + 0x1b0) == 0)) ||
         (*(int *)(param_1 + 0x1c4) == 0)))) || (iVar1 = RAND_bytes(auStack_40,0x30), iVar1 < 1)) {
      iVar1 = 2;
    }
    else {
      pBVar2 = BN_bin2bn(auStack_40,0x30,(BIGNUM *)0x0);
      *(BIGNUM **)(param_1 + 0x1c0) = pBVar2;
      OPENSSL_cleanse(auStack_40,0x30);
      iVar3 = SRP_Calc_B(*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1a8),
                         *(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1c4));
      if (iVar3 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = 0;
      }
      *(int *)(param_1 + 0x1b4) = iVar3;
    }
  }
  return iVar1;
}

