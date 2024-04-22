
int ec_GFp_nist_field_sqr(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  BN_CTX *c;
  
  if ((param_1 == 0 || param_2 == (BIGNUM *)0x0) || (param_3 == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xc9,0x86,DAT_0012467c,0xcb);
  }
  else {
    c = (BN_CTX *)0x0;
    if ((param_4 != (BN_CTX *)0x0) ||
       (param_4 = BN_CTX_new(), c = param_4, param_4 != (BN_CTX *)0x0)) {
      iVar1 = BN_sqr(param_2,param_3,param_4);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,param_4);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
      }
      if (c == (BN_CTX *)0x0) {
        return iVar1;
      }
      BN_CTX_free(c);
      return iVar1;
    }
  }
  return 0;
}

