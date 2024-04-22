
BN_BLINDING * RSA_setup_blinding(RSA *rsa,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  BN_BLINDING *pBVar3;
  CRYPTO_THREADID *id;
  BN_CTX *ctx_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *b;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *a;
  undefined4 in_stack_ffffffa8;
  undefined4 in_stack_ffffffac;
  BIGNUM local_3c;
  
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    return (BN_BLINDING *)0x0;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = BN_CTX_get(ctx_00);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(4,0x88,0x41,DAT_000a4728,0xcc);
    pBVar1 = (BIGNUM *)0x0;
    pBVar3 = (BN_BLINDING *)0x0;
    goto LAB_000a45ea;
  }
  pBVar1 = rsa->e;
  pBVar5 = pBVar1;
  if (pBVar1 != (BIGNUM *)0x0) {
LAB_000a45a2:
    iVar2 = RAND_status();
    if (((iVar2 == 0) && (pBVar1 = rsa->d, pBVar1 != (BIGNUM *)0x0)) && (pBVar1->d != (ulong *)0x0))
    {
      RAND_add(pBVar1->d,pBVar1->dmax << 2,(double)CONCAT44(in_stack_ffffffac,in_stack_ffffffa8));
    }
    if (rsa->flags << 0x17 < 0) {
      pBVar1 = rsa->n;
    }
    else {
      pBVar4 = rsa->n;
      pBVar1 = &local_3c;
      local_3c.d = pBVar4->d;
      local_3c.top = pBVar4->top;
      local_3c.dmax = pBVar4->dmax;
      local_3c.neg = pBVar4->neg;
      local_3c.flags = local_3c.flags & 1U | pBVar4->flags & 0xfffffffeU | 6;
    }
    pBVar3 = BN_BLINDING_create_param
                       ((BN_BLINDING *)0x0,pBVar5,pBVar1,ctx_00,(bn_mod_exp *)rsa->meth->bn_mod_exp,
                        rsa->_method_mod_n);
    pBVar1 = pBVar5;
    if (pBVar3 == (BN_BLINDING *)0x0) {
      ERR_put_error(4,0x88,3,DAT_000a4728,0xeb);
    }
    else {
      id = BN_BLINDING_thread_id(pBVar3);
      CRYPTO_THREADID_current(id);
    }
    goto LAB_000a45ea;
  }
  a = rsa->d;
  pBVar5 = rsa->p;
  pBVar4 = rsa->q;
  if ((a != (BIGNUM *)0x0 && pBVar5 != (BIGNUM *)0x0) && (pBVar4 != (BIGNUM *)0x0)) {
    BN_CTX_start(ctx_00);
    r = BN_CTX_get(ctx_00);
    r_00 = BN_CTX_get(ctx_00);
    r_01 = BN_CTX_get(ctx_00);
    if (r_01 != (BIGNUM *)0x0) {
      b = BN_value_one();
      iVar2 = BN_sub(r_00,pBVar5,b);
      if (iVar2 != 0) {
        pBVar5 = BN_value_one();
        iVar2 = BN_sub(r_01,pBVar4,pBVar5);
        if ((iVar2 != 0) && (iVar2 = BN_mul(r,r_00,r_01,ctx_00), iVar2 != 0)) {
          pBVar5 = BN_mod_inverse((BIGNUM *)0x0,a,r,ctx_00);
          BN_CTX_end(ctx_00);
          if (pBVar5 != (BIGNUM *)0x0) goto LAB_000a45a2;
          goto LAB_000a4692;
        }
      }
    }
    BN_CTX_end(ctx_00);
  }
LAB_000a4692:
  ERR_put_error(4,0x88,0x8c,DAT_000a4728,0xd3);
  pBVar3 = (BN_BLINDING *)0x0;
LAB_000a45ea:
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (rsa->e == (BIGNUM *)0x0) {
    BN_free(pBVar1);
  }
  return pBVar3;
}

