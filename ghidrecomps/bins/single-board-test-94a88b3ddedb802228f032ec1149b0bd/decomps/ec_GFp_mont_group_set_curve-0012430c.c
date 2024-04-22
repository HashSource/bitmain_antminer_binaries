
int ec_GFp_mont_group_set_curve
              (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,BN_CTX *param_5)

{
  BN_MONT_CTX *mont;
  int iVar1;
  BIGNUM *r;
  BIGNUM *a;
  BN_CTX *c;
  
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(BIGNUM **)(param_1 + 0xa4) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  mont = BN_MONT_CTX_new();
  if (mont == (BN_MONT_CTX *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = BN_MONT_CTX_set(mont,param_2,param_5);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0xbd,3,DAT_001243f4,0xde);
      iVar1 = 0;
    }
    else {
      r = BN_new();
      if (r == (BIGNUM *)0x0) {
        iVar1 = 0;
      }
      else {
        a = BN_value_one();
        iVar1 = BN_mod_mul_montgomery(r,a,&mont->RR,mont,param_5);
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          *(BN_MONT_CTX **)(param_1 + 0xa0) = mont;
          *(BIGNUM **)(param_1 + 0xa4) = r;
          mont = (BN_MONT_CTX *)0x0;
          iVar1 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
          if (iVar1 == 0) {
            BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
            *(undefined4 *)(param_1 + 0xa0) = 0;
            BN_free(*(BIGNUM **)(param_1 + 0xa4));
            *(undefined4 *)(param_1 + 0xa4) = 0;
            mont = (BN_MONT_CTX *)0x0;
          }
        }
      }
    }
  }
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
  }
  return iVar1;
}

