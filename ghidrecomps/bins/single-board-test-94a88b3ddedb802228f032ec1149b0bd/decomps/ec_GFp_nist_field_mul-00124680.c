
int ec_GFp_nist_field_mul
              (int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  BN_CTX *c;
  
  if ((param_1 == 0 || param_2 == (BIGNUM *)0x0) ||
     (param_3 == (BIGNUM *)0x0 || param_4 == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,200,0x43,DAT_00124704,0xb1);
  }
  else {
    c = (BN_CTX *)0x0;
    if ((param_5 != (BN_CTX *)0x0) || (c = BN_CTX_new(), param_5 = c, c != (BN_CTX *)0x0)) {
      iVar1 = BN_mul(param_2,param_3,param_4,param_5);
      if ((iVar1 != 0) &&
         (iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,param_5), iVar1 != 0)
         ) {
        iVar1 = 1;
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

