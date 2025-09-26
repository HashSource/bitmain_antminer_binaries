
BIGNUM * SRP_create_verifier_BN
                   (int param_1,int param_2,int *param_3,undefined4 *param_4,BIGNUM *param_5,
                   BIGNUM *param_6)

{
  BN_CTX *ctx;
  BIGNUM *r;
  int iVar1;
  BIGNUM *a;
  BIGNUM *p;
  BIGNUM *pBVar2;
  uchar auStack_9e4 [2500];
  
  ctx = BN_CTX_new();
  if ((param_2 == 0 || param_1 == 0) || (param_4 == (undefined4 *)0x0 || param_3 == (int *)0x0)) {
    if (param_3 == (int *)0x0) {
      p = (BIGNUM *)0x0;
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_0016d0c0;
    }
LAB_0016d0ae:
    a = (BIGNUM *)0x0;
    p = (BIGNUM *)0x0;
    pBVar2 = (BIGNUM *)0x0;
  }
  else {
    if (ctx == (BN_CTX *)0x0 || (param_6 == (BIGNUM *)0x0 || param_5 == (BIGNUM *)0x0))
    goto LAB_0016d0ae;
    a = (BIGNUM *)*param_3;
    if (a == (BIGNUM *)0x0) {
      iVar1 = RAND_bytes(auStack_9e4,0x14);
      if ((iVar1 < 1) || (a = BN_bin2bn(auStack_9e4,0x14,(BIGNUM *)0x0), a == (BIGNUM *)0x0))
      goto LAB_0016d0ae;
    }
    p = (BIGNUM *)SRP_Calc_x(a,param_1,param_2);
    pBVar2 = p;
    if ((p != (BIGNUM *)0x0) && (r = BN_new(), pBVar2 = r, r != (BIGNUM *)0x0)) {
      iVar1 = BN_mod_exp(r,param_6,p,param_5,ctx);
      if (iVar1 == 0) {
        BN_clear_free(r);
        pBVar2 = (BIGNUM *)0x0;
      }
      else {
        *param_3 = (int)a;
        pBVar2 = (BIGNUM *)0x1;
        *param_4 = r;
      }
    }
  }
  if ((BIGNUM *)*param_3 != a) {
    BN_clear_free(a);
  }
LAB_0016d0c0:
  BN_clear_free(p);
  BN_CTX_free(ctx);
  return pBVar2;
}

