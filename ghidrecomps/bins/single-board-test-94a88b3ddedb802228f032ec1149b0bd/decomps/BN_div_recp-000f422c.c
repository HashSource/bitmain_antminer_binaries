
int BN_div_recp(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BN_RECP_CTX *recp,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *a;
  int iVar2;
  int iVar3;
  int iVar4;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  if (dv == (BIGNUM *)0x0) {
    dv = BN_CTX_get(ctx);
  }
  if (rem == (BIGNUM *)0x0) {
    rem = BN_CTX_get(ctx);
  }
  if ((pBVar1 != (BIGNUM *)0x0 && r != (BIGNUM *)0x0) &&
     (dv != (BIGNUM *)0x0 && rem != (BIGNUM *)0x0)) {
    iVar4 = BN_ucmp(m,&recp->N);
    if (iVar4 < 0) {
      BN_set_word(dv,0);
      pBVar1 = BN_copy(rem,m);
      if (pBVar1 == (BIGNUM *)0x0) {
        return 0;
      }
      BN_CTX_end(ctx);
      return 1;
    }
    iVar4 = BN_num_bits(m);
    iVar2 = recp->shift;
    iVar3 = recp->num_bits * 2;
    if (iVar4 + recp->num_bits * -2 < 0 != SBORROW4(iVar4,iVar3)) {
      iVar4 = iVar3;
    }
    if (iVar2 != iVar4) {
      BN_CTX_start(ctx);
      a = BN_CTX_get(ctx);
      if (((a == (BIGNUM *)0x0) || (iVar2 = BN_set_bit(a,iVar4), iVar2 == 0)) ||
         (iVar3 = BN_div(&recp->Nr,(BIGNUM *)0x0,a,&recp->N,ctx), iVar2 = iVar4, iVar3 == 0)) {
        iVar2 = -1;
      }
      BN_CTX_end(ctx);
      recp->shift = iVar2;
    }
    if (((iVar2 != -1) && (iVar2 = BN_rshift(pBVar1,m,recp->num_bits), iVar2 != 0)) &&
       ((iVar2 = BN_mul(r,pBVar1,&recp->Nr,ctx), iVar2 != 0 &&
        (iVar4 = BN_rshift(dv,r,iVar4 - recp->num_bits), iVar4 != 0)))) {
      dv->neg = 0;
      iVar4 = BN_mul(r,&recp->N,dv,ctx);
      if ((iVar4 != 0) && (iVar4 = BN_usub(rem,m,r), iVar4 != 0)) {
        rem->neg = 0;
        iVar4 = 4;
        do {
          iVar2 = BN_ucmp(rem,&recp->N);
          if (iVar2 < 0) {
            iVar4 = rem->top;
            if (iVar4 != 0) {
              iVar4 = m->neg;
            }
            rem->neg = iVar4;
            iVar4 = 1;
            dv->neg = m->neg ^ (recp->N).neg;
            goto LAB_000f427c;
          }
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            ERR_put_error(3,0x82,0x65,DAT_000f43ec,0xcb);
            iVar4 = 0;
            goto LAB_000f427c;
          }
          iVar2 = BN_usub(rem,rem,&recp->N);
        } while ((iVar2 != 0) && (iVar2 = BN_add_word(dv,1), iVar2 != 0));
      }
    }
  }
  iVar4 = 0;
LAB_000f427c:
  BN_CTX_end(ctx);
  return iVar4;
}

