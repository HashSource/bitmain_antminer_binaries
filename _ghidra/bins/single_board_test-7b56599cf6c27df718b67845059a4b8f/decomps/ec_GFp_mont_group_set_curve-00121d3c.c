
int ec_GFp_mont_group_set_curve
              (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,BN_CTX *param_5)

{
  BN_MONT_CTX *mont;
  int iVar1;
  BIGNUM *a;
  BIGNUM *pBVar2;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = 0;
  BN_free(*(BIGNUM **)(param_1 + 0x54));
  *(undefined4 *)(param_1 + 0x54) = 0;
  if ((param_5 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_5 = c, c == (BN_CTX *)0x0)) {
    iVar1 = 0;
  }
  else {
    mont = BN_MONT_CTX_new();
    if (mont == (BN_MONT_CTX *)0x0) {
      iVar1 = 0;
      a = (BIGNUM *)0x0;
    }
    else {
      iVar1 = BN_MONT_CTX_set(mont,param_2,param_5);
      if (iVar1 == 0) {
        ERR_put_error(0x10,0xbd,3,"crypto/ec/ecp_mont.c",0x9e);
        iVar1 = 0;
        a = (BIGNUM *)0x0;
      }
      else {
        a = BN_new();
        if (a == (BIGNUM *)0x0) {
          iVar1 = 0;
        }
        else {
          pBVar2 = BN_value_one();
          iVar1 = BN_to_montgomery(a,pBVar2,mont,param_5);
          if (iVar1 == 0) {
            iVar1 = 0;
          }
          else {
            *(BN_MONT_CTX **)(param_1 + 0x50) = mont;
            *(BIGNUM **)(param_1 + 0x54) = a;
            a = (BIGNUM *)0x0;
            iVar1 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
            mont = (BN_MONT_CTX *)0x0;
            if (iVar1 == 0) {
              BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x50));
              *(undefined4 *)(param_1 + 0x50) = 0;
              BN_free(*(BIGNUM **)(param_1 + 0x54));
              *(undefined4 *)(param_1 + 0x54) = 0;
              mont = (BN_MONT_CTX *)0x0;
              a = (BIGNUM *)0x0;
            }
          }
        }
      }
    }
    BN_free(a);
    BN_CTX_free(c);
    BN_MONT_CTX_free(mont);
  }
  return iVar1;
}

