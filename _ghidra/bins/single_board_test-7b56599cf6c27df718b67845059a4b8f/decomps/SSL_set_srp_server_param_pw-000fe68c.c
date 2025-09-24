
undefined4
SSL_set_srp_server_param_pw(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  
  iVar1 = SRP_get_default_gN(param_4);
  if (iVar1 != 0) {
    pBVar2 = BN_dup(*(BIGNUM **)(iVar1 + 8));
    *(BIGNUM **)(param_1 + 0x620) = pBVar2;
    pBVar2 = BN_dup(*(BIGNUM **)(iVar1 + 4));
    *(BIGNUM **)(param_1 + 0x624) = pBVar2;
    BN_clear_free(*(BIGNUM **)(param_1 + 0x63c));
    *(undefined4 *)(param_1 + 0x63c) = 0;
    BN_clear_free(*(BIGNUM **)(param_1 + 0x628));
    uVar3 = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(param_1 + 0x628) = 0;
    iVar1 = SRP_create_verifier_BN
                      (param_2,param_3,param_1 + 0x628,param_1 + 0x63c,*(undefined4 *)(iVar1 + 8),
                       uVar3);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

