
int ec_GFp_nist_field_sqr(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  BN_CTX *c;
  
  if (param_1 == 0 || (param_3 == (BIGNUM *)0x0 || param_2 == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xc9,0x86,"crypto/ec/ecp_nist.c",0x98);
    BN_CTX_free((BN_CTX *)0x0);
    return 0;
  }
  c = (BN_CTX *)0x0;
  if (((param_4 != (BN_CTX *)0x0) || (c = BN_CTX_new(), param_4 = c, c != (BN_CTX *)0x0)) &&
     (iVar1 = BN_sqr(param_2,param_3,param_4), iVar1 != 0)) {
    iVar1 = (**(code **)(param_1 + 0x58))(param_2,param_2,*(undefined4 *)(param_1 + 0x28),param_4);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    BN_CTX_free(c);
    return iVar1;
  }
  BN_CTX_free(c);
  return 0;
}

