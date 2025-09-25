
int BN_div_recp(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BN_RECP_CTX *recp,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  int iVar2;
  int iVar3;
  int iVar4;
  
  BN_CTX_start(ctx);
  if (dv == (BIGNUM *)0x0) {
    dv = BN_CTX_get(ctx);
  }
  if (rem == (BIGNUM *)0x0) {
    rem = BN_CTX_get(ctx);
  }
  pBVar1 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  if (r != (BIGNUM *)0x0) {
    iVar2 = BN_ucmp(m,&recp->N);
    if (iVar2 < 0) {
      BN_set_word(dv,0);
      pBVar1 = BN_copy(rem,m);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_CTX_end(ctx);
        return 0;
      }
      BN_CTX_end(ctx);
      return 1;
    }
    iVar3 = BN_num_bits(m);
    iVar4 = recp->shift;
    iVar2 = recp->num_bits * 2;
    if (iVar2 < iVar3) {
      iVar2 = iVar3;
    }
    if (iVar4 != iVar2) {
      iVar4 = BN_reciprocal(&recp->Nr,&recp->N,iVar2,ctx);
      recp->shift = iVar4;
    }
    if ((((iVar4 != -1) && (iVar3 = BN_rshift(pBVar1,m,recp->num_bits), iVar3 != 0)) &&
        (iVar3 = BN_mul(r,pBVar1,&recp->Nr,ctx), iVar3 != 0)) &&
       (iVar2 = BN_rshift(dv,r,iVar2 - recp->num_bits), iVar2 != 0)) {
      dv->neg = 0;
      iVar2 = BN_mul(r,&recp->N,dv,ctx);
      if ((iVar2 != 0) && (iVar2 = BN_usub(rem,m,r), iVar2 != 0)) {
        rem->neg = 0;
        iVar2 = 4;
        do {
          iVar3 = BN_ucmp(rem,&recp->N);
          if (iVar3 < 0) {
            iVar2 = BN_is_zero();
            if (iVar2 == 0) {
              iVar2 = m->neg;
            }
            else {
              iVar2 = 0;
            }
            rem->neg = iVar2;
            iVar2 = 1;
            dv->neg = (recp->N).neg ^ m->neg;
            goto LAB_0018a4b6;
          }
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            ERR_put_error(3,0x82,0x65,"crypto/bn/bn_recp.c",0x95);
            iVar2 = 0;
            goto LAB_0018a4b6;
          }
          iVar3 = BN_usub(rem,rem,&recp->N);
        } while ((iVar3 != 0) && (iVar3 = BN_add_word(dv,1), iVar3 != 0));
      }
    }
  }
  iVar2 = 0;
LAB_0018a4b6:
  BN_CTX_end(ctx);
  return iVar2;
}

