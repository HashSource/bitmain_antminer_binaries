
BN_BLINDING * RSA_setup_blinding(RSA *rsa,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BN_BLINDING *pBVar3;
  BN_CTX *ctx_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *b;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *a;
  
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    return (BN_BLINDING *)0x0;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = BN_CTX_get(ctx_00);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(4,0x88,0x41,"crypto/rsa/rsa_crpt.c",0x7e);
    pBVar1 = (BIGNUM *)0x0;
    pBVar3 = (BN_BLINDING *)0x0;
    goto LAB_0014fde6;
  }
  pBVar1 = rsa->e;
  pBVar5 = pBVar1;
  if (pBVar1 != (BIGNUM *)0x0) {
LAB_0014fda6:
    pBVar2 = BN_new();
    pBVar1 = pBVar5;
    if (pBVar2 == (BIGNUM *)0x0) {
      ERR_put_error(4,0x88,0x41,"crypto/rsa/rsa_crpt.c",0x90);
      pBVar3 = (BN_BLINDING *)0x0;
    }
    else {
      BN_with_flags(pBVar2,rsa->n,4);
      pBVar3 = BN_BLINDING_create_param
                         ((BN_BLINDING *)0x0,pBVar5,pBVar2,ctx_00,
                          (bn_mod_exp *)rsa->meth->bn_mod_exp,rsa->_method_mod_p);
      BN_free(pBVar2);
      if (pBVar3 == (BN_BLINDING *)0x0) {
        ERR_put_error(4,0x88,3,"crypto/rsa/rsa_crpt.c",0x9b);
      }
      else {
        BN_BLINDING_set_current_thread(pBVar3);
      }
    }
    goto LAB_0014fde6;
  }
  a = rsa->d;
  pBVar5 = rsa->p;
  pBVar2 = rsa->q;
  if (pBVar2 != (BIGNUM *)0x0 && (pBVar5 != (BIGNUM *)0x0 && a != (BIGNUM *)0x0)) {
    BN_CTX_start(ctx_00);
    r = BN_CTX_get(ctx_00);
    r_00 = BN_CTX_get(ctx_00);
    r_01 = BN_CTX_get(ctx_00);
    if (r_01 != (BIGNUM *)0x0) {
      b = BN_value_one();
      iVar4 = BN_sub(r_00,pBVar5,b);
      if (iVar4 != 0) {
        pBVar5 = BN_value_one();
        iVar4 = BN_sub(r_01,pBVar2,pBVar5);
        if ((iVar4 != 0) && (iVar4 = BN_mul(r,r_00,r_01,ctx_00), iVar4 != 0)) {
          pBVar5 = BN_mod_inverse((BIGNUM *)0x0,a,r,ctx_00);
          BN_CTX_end(ctx_00);
          if (pBVar5 != (BIGNUM *)0x0) goto LAB_0014fda6;
          goto LAB_0014fe7a;
        }
      }
    }
    BN_CTX_end(ctx_00);
  }
LAB_0014fe7a:
  pBVar3 = (BN_BLINDING *)0x0;
  ERR_put_error(4,0x88,0x8c,"crypto/rsa/rsa_crpt.c",0x85);
LAB_0014fde6:
  BN_CTX_end(ctx_00);
  if (ctx_00 != ctx) {
    BN_CTX_free(ctx_00);
  }
  if (pBVar1 != rsa->e) {
    BN_free(pBVar1);
  }
  return pBVar3;
}

