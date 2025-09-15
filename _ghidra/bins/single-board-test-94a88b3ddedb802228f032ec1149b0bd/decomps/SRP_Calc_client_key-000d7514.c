
BIGNUM * SRP_Calc_client_key(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                            BIGNUM *param_5,BIGNUM *param_6)

{
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar1;
  BIGNUM *b;
  BIGNUM *local_2c;
  
  if ((((param_2 == (BIGNUM *)0x0 || param_6 == (BIGNUM *)0x0) ||
       (param_1 == (BIGNUM *)0x0 || param_3 == (BIGNUM *)0x0)) ||
      (param_4 == (BIGNUM *)0x0 || param_5 == (BIGNUM *)0x0)) ||
     (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    r_01 = (BIGNUM *)0x0;
  }
  else {
    r = BN_new();
    if ((r == (BIGNUM *)0x0) || (r_00 = BN_new(), r_00 == (BIGNUM *)0x0)) {
      r_01 = (BIGNUM *)0x0;
      b = (BIGNUM *)0x0;
      r_00 = (BIGNUM *)0x0;
      local_2c = (BIGNUM *)0x0;
    }
    else {
      local_2c = BN_new();
      if (local_2c == (BIGNUM *)0x0) {
        b = (BIGNUM *)0x0;
        r_01 = (BIGNUM *)0x0;
      }
      else {
        r_01 = BN_new();
        if (r_01 == (BIGNUM *)0x0) {
          b = (BIGNUM *)0x0;
        }
        else {
          iVar1 = BN_mod_exp(r,param_3,param_4,param_1,ctx);
          if (iVar1 == 0) {
            b = (BIGNUM *)0x0;
          }
          else {
            b = (BIGNUM *)srp_Calc_k(param_1,param_3);
            if (((b != (BIGNUM *)0x0) && (iVar1 = BN_mod_mul(r_00,r,b,param_1,ctx), iVar1 != 0)) &&
               ((iVar1 = BN_mod_sub(r,param_2,r_00,param_1,ctx), iVar1 != 0 &&
                ((iVar1 = BN_mod_mul(local_2c,param_6,param_4,param_1,ctx), iVar1 != 0 &&
                 (iVar1 = BN_mod_add(r_00,param_5,local_2c,param_1,ctx), iVar1 != 0)))))) {
              BN_mod_exp(r_01,r,r_00,param_1,ctx);
            }
          }
        }
      }
    }
    BN_CTX_free(ctx);
    BN_clear_free(r);
    BN_clear_free(r_00);
    BN_clear_free(local_2c);
    BN_free(b);
  }
  return r_01;
}

