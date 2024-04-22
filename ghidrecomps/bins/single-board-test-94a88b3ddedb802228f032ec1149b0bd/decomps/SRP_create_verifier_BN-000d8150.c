
BIGNUM * SRP_create_verifier_BN
                   (int param_1,int param_2,BIGNUM **param_3,BIGNUM **param_4,BIGNUM *param_5,
                   BIGNUM *param_6)

{
  BN_CTX *ctx;
  BIGNUM *p;
  int iVar1;
  BIGNUM *pBVar2;
  uchar auStack_9dc [2500];
  
  ctx = BN_CTX_new();
  if ((((param_1 == 0 || param_2 == 0) || (param_3 == (BIGNUM **)0x0 || param_4 == (BIGNUM **)0x0))
      || (param_5 == (BIGNUM *)0x0 || param_6 == (BIGNUM *)0x0)) || (ctx == (BN_CTX *)0x0)) {
LAB_000d81c0:
    p = (BIGNUM *)0x0;
    pBVar2 = (BIGNUM *)0x0;
  }
  else {
    pBVar2 = *param_3;
    if (pBVar2 == (BIGNUM *)0x0) {
      iVar1 = RAND_pseudo_bytes(auStack_9dc,0x14);
      if (iVar1 < 0) goto LAB_000d81c0;
      pBVar2 = BN_bin2bn(auStack_9dc,0x14,(BIGNUM *)0x0);
      *param_3 = pBVar2;
    }
    p = (BIGNUM *)SRP_Calc_x(pBVar2,param_1,param_2);
    pBVar2 = BN_new();
    *param_4 = pBVar2;
    if (pBVar2 != (BIGNUM *)0x0) {
      iVar1 = BN_mod_exp(pBVar2,param_6,p,param_5,ctx);
      if (iVar1 == 0) {
        BN_clear_free(*param_4);
        pBVar2 = (BIGNUM *)0x0;
      }
      else {
        pBVar2 = (BIGNUM *)0x1;
      }
    }
  }
  BN_clear_free(p);
  BN_CTX_free(ctx);
  return pBVar2;
}

