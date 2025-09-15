
undefined4
SSL_set_srp_server_param_pw(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  
  iVar1 = SRP_get_default_gN(param_4);
  if (iVar1 != 0) {
    pBVar2 = BN_dup(*(BIGNUM **)(iVar1 + 8));
    *(BIGNUM **)(param_1 + 0x1a8) = pBVar2;
    pBVar2 = BN_dup(*(BIGNUM **)(iVar1 + 4));
    *(BIGNUM **)(param_1 + 0x1ac) = pBVar2;
    if (*(BIGNUM **)(param_1 + 0x1c4) != (BIGNUM *)0x0) {
      BN_clear_free(*(BIGNUM **)(param_1 + 0x1c4));
      *(undefined4 *)(param_1 + 0x1c4) = 0;
    }
    if (*(BIGNUM **)(param_1 + 0x1b0) != (BIGNUM *)0x0) {
      BN_clear_free(*(BIGNUM **)(param_1 + 0x1b0));
      *(undefined4 *)(param_1 + 0x1b0) = 0;
    }
    iVar1 = SRP_create_verifier_BN
                      (param_2,param_3,param_1 + 0x1b0,param_1 + 0x1c4,*(undefined4 *)(iVar1 + 8),
                       *(undefined4 *)(iVar1 + 4));
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

