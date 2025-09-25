
undefined4 ec_GFp_mont_field_inv(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  int iVar1;
  undefined4 uVar2;
  BN_CTX *c;
  
  if ((*(int *)(param_1 + 0x50) == 0) ||
     ((c = (BN_CTX *)0x0, param_4 == (BN_CTX *)0x0 &&
      (param_4 = (BN_CTX *)BN_CTX_secure_new(), c = param_4, param_4 == (BN_CTX *)0x0)))) {
    return 0;
  }
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if ((((a != (BIGNUM *)0x0) && (iVar1 = BN_set_word(a,2), iVar1 != 0)) &&
      (iVar1 = BN_sub(a,*(BIGNUM **)(param_1 + 0x28),a), iVar1 != 0)) &&
     (iVar1 = BN_mod_exp_mont(param_2,param_3,a,*(BIGNUM **)(param_1 + 0x28),param_4,
                              *(BN_MONT_CTX **)(param_1 + 0x50)), iVar1 != 0)) {
    uVar2 = 1;
    iVar1 = BN_is_zero(param_2);
    if (iVar1 == 0) goto LAB_0011dbfc;
    ERR_put_error(0x10,0x129,0xa5,"crypto/ec/ecp_mont.c",0xf6);
  }
  uVar2 = 0;
LAB_0011dbfc:
  BN_CTX_end(param_4);
  BN_CTX_free(c);
  return uVar2;
}

