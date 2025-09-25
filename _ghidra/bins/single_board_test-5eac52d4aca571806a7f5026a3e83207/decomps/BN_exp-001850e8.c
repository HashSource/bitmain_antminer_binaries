
int BN_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  
  iVar1 = BN_get_flags(p,4);
  if ((iVar1 != 0) || (iVar1 = BN_get_flags(a,4), iVar1 != 0)) {
    ERR_put_error(3,0x7b,0x42,"crypto/bn/bn_exp.c",0x31);
    return 0;
  }
  BN_CTX_start(ctx);
  pBVar5 = r;
  if (p == r || a == r) {
    pBVar5 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if ((a_00 != (BIGNUM *)0x0 && pBVar5 != (BIGNUM *)0x0) &&
     (pBVar2 = BN_copy(a_00,a), pBVar2 != (BIGNUM *)0x0)) {
    iVar1 = BN_num_bits(p);
    iVar3 = BN_is_odd(p);
    if (iVar3 == 0) {
      pBVar2 = (BIGNUM *)BN_set_word(pBVar5,1);
    }
    else {
      pBVar2 = BN_copy(pBVar5,a);
    }
    if (pBVar2 != (BIGNUM *)0x0) {
      if (1 < iVar1) {
        iVar3 = 1;
        do {
          iVar4 = BN_sqr(a_00,a_00,ctx);
          if (iVar4 == 0) goto LAB_00185148;
          iVar4 = iVar3 + 1;
          iVar3 = BN_is_bit_set(p,iVar3);
          if ((iVar3 != 0) && (iVar3 = BN_mul(pBVar5,pBVar5,a_00,ctx), iVar3 == 0))
          goto LAB_00185148;
          iVar3 = iVar4;
        } while (iVar1 != iVar4);
      }
      if (pBVar5 == r) {
        pBVar5 = (BIGNUM *)0x1;
      }
      else {
        pBVar5 = BN_copy(r,pBVar5);
        if (pBVar5 != (BIGNUM *)0x0) {
          pBVar5 = (BIGNUM *)0x1;
        }
      }
      goto LAB_0018514a;
    }
  }
LAB_00185148:
  pBVar5 = (BIGNUM *)0x0;
LAB_0018514a:
  BN_CTX_end(ctx);
  return (int)pBVar5;
}

