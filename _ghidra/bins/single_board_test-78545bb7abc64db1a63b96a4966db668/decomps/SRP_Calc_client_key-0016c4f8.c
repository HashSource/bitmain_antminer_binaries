
BIGNUM * SRP_Calc_client_key(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,int param_4,
                            BIGNUM *param_5,BIGNUM *param_6)

{
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *p;
  int iVar1;
  BIGNUM *b;
  BIGNUM *r_02;
  
  if ((((param_2 != (BIGNUM *)0x0 && param_6 != (BIGNUM *)0x0) &&
       (param_3 != (BIGNUM *)0x0 && param_1 != (BIGNUM *)0x0)) &&
      (param_5 != (BIGNUM *)0x0 && param_4 != 0)) && (ctx = BN_CTX_new(), ctx != (BN_CTX *)0x0)) {
    r = BN_new();
    if ((r == (BIGNUM *)0x0) || (r_00 = BN_new(), r_00 == (BIGNUM *)0x0)) {
      p = (BIGNUM *)0x0;
      r_02 = (BIGNUM *)0x0;
      b = (BIGNUM *)0x0;
      r_01 = (BIGNUM *)0x0;
      r_00 = (BIGNUM *)0x0;
    }
    else {
      r_01 = BN_new();
      if (r_01 == (BIGNUM *)0x0) {
        b = (BIGNUM *)0x0;
        r_02 = (BIGNUM *)0x0;
        p = (BIGNUM *)0x0;
      }
      else {
        p = BN_new();
        if (p == (BIGNUM *)0x0) {
          b = (BIGNUM *)0x0;
          r_02 = (BIGNUM *)0x0;
        }
        else {
          BN_with_flags(p,param_4,4);
          BN_set_flags(r,4);
          iVar1 = BN_mod_exp(r,param_3,p,param_1,ctx);
          if (iVar1 == 0) {
            b = (BIGNUM *)0x0;
            r_02 = (BIGNUM *)0x0;
          }
          else {
            r_02 = (BIGNUM *)0x0;
            b = (BIGNUM *)srp_Calc_xy(param_1,param_3,param_1);
            if ((((b != (BIGNUM *)0x0) &&
                 (r_02 = (BIGNUM *)BN_mod_mul(r_00,r,b,param_1,ctx), r_02 != (BIGNUM *)0x0)) &&
                ((r_02 = (BIGNUM *)BN_mod_sub(r,param_2,r_00,param_1,ctx), r_02 != (BIGNUM *)0x0 &&
                 (((r_02 = (BIGNUM *)BN_mul(r_01,param_6,p,ctx), r_02 != (BIGNUM *)0x0 &&
                   (r_02 = (BIGNUM *)BN_add(r_00,param_5,r_01), r_02 != (BIGNUM *)0x0)) &&
                  (r_02 = BN_new(), r_02 != (BIGNUM *)0x0)))))) &&
               (iVar1 = BN_mod_exp(r_02,r,r_00,param_1,ctx), iVar1 == 0)) {
              BN_free(r_02);
              r_02 = (BIGNUM *)0x0;
            }
          }
        }
      }
    }
    BN_CTX_free(ctx);
    BN_free(p);
    BN_clear_free(r);
    BN_clear_free(r_00);
    BN_clear_free(r_01);
    BN_free(b);
    return r_02;
  }
  return (BIGNUM *)0x0;
}

