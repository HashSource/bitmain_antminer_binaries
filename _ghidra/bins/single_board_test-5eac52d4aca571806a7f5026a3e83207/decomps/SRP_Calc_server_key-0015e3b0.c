
BIGNUM * SRP_Calc_server_key(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                            BIGNUM *param_5)

{
  BN_CTX *ctx;
  BIGNUM *r;
  int iVar1;
  BIGNUM *r_00;
  
  if (param_1 != (BIGNUM *)0x0 && param_3 != (BIGNUM *)0x0) {
    r_00 = (BIGNUM *)0x0;
    if (param_5 != (BIGNUM *)0x0 && (param_4 != (BIGNUM *)0x0 && param_2 != (BIGNUM *)0x0)) {
      ctx = BN_CTX_new();
      if ((ctx == (BN_CTX *)0x0) || (r = BN_new(), r == (BIGNUM *)0x0)) {
        r_00 = (BIGNUM *)0x0;
        r = (BIGNUM *)0x0;
      }
      else {
        r_00 = (BIGNUM *)BN_mod_exp(r,param_2,param_3,param_5,ctx);
        if ((((r_00 != (BIGNUM *)0x0) &&
             (r_00 = (BIGNUM *)BN_mod_mul(r,param_1,r,param_5,ctx), r_00 != (BIGNUM *)0x0)) &&
            (r_00 = BN_new(), r_00 != (BIGNUM *)0x0)) &&
           (iVar1 = BN_mod_exp(r_00,r,param_4,param_5,ctx), iVar1 == 0)) {
          BN_free(r_00);
          r_00 = (BIGNUM *)0x0;
        }
      }
      BN_CTX_free(ctx);
      BN_clear_free(r);
    }
    return r_00;
  }
  return (BIGNUM *)0x0;
}

