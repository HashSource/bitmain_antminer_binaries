
int DSA_generate_key(DSA *a)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *p;
  _func_1883 *p_Var2;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  BIGNUM local_2c;
  
  p_Var2 = a->meth->dsa_keygen;
  if (p_Var2 != (_func_1883 *)0x0) {
    iVar1 = (*p_Var2)(a);
    return iVar1;
  }
  ctx = BN_CTX_new();
  if ((ctx == (BN_CTX *)0x0) ||
     ((rnd = a->priv_key, rnd == (BIGNUM *)0x0 && (rnd = BN_new(), rnd == (BIGNUM *)0x0)))) {
LAB_001264ea:
    iVar1 = 0;
  }
  else {
    do {
      iVar1 = BN_rand_range(rnd,a->q);
      if (iVar1 == 0) goto LAB_001264c6;
    } while (rnd->top == 0);
    pBVar3 = a->pub_key;
    if ((pBVar3 == (BIGNUM *)0x0) && (pBVar3 = BN_new(), pBVar3 == (BIGNUM *)0x0)) {
LAB_001264c6:
      if (rnd == (BIGNUM *)0x0) goto LAB_001264ea;
      pBVar3 = a->priv_key;
joined_r0x001264dc:
      iVar1 = 0;
    }
    else {
      p = rnd;
      if (-1 < a->flags << 0x1e) {
        BN_init(&local_2c);
        local_2c.d = rnd->d;
        local_2c.top = rnd->top;
        local_2c.dmax = rnd->dmax;
        local_2c.flags = local_2c.flags & 1U | rnd->flags & 0xfffffffeU | 6;
        local_2c.neg = rnd->neg;
        p = &local_2c;
      }
      iVar1 = BN_mod_exp(pBVar3,a->g,p,a->p,ctx);
      if (iVar1 == 0) {
        if (a->pub_key != (BIGNUM *)0x0) {
          pBVar3 = a->priv_key;
          goto joined_r0x001264dc;
        }
        BN_free(pBVar3);
        iVar1 = 0;
        pBVar3 = a->priv_key;
      }
      else {
        a->priv_key = rnd;
        iVar1 = 1;
        a->pub_key = pBVar3;
        pBVar3 = rnd;
      }
    }
    if (pBVar3 == (BIGNUM *)0x0) {
      BN_free(rnd);
    }
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  return iVar1;
}

