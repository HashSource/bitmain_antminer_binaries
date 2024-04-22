
int BN_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (p->flags << 0x1d < 0) {
    ERR_put_error(3,0x7b,0x42,DAT_000ef77c,0x9b);
    return -1;
  }
  BN_CTX_start(ctx);
  a_01 = r;
  if (r == a || r == p) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if ((a_01 != (BIGNUM *)0x0 && a_00 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(a_00,a), pBVar1 != (BIGNUM *)0x0)) {
    iVar2 = BN_num_bits(p);
    if ((p->top < 1) || (-1 < (int)(*p->d << 0x1f))) {
      pBVar1 = (BIGNUM *)BN_set_word(a_01,1);
    }
    else {
      pBVar1 = BN_copy(a_01,a);
    }
    if (pBVar1 != (BIGNUM *)0x0) {
      if (1 < iVar2) {
        iVar4 = 1;
        do {
          iVar3 = BN_sqr(a_00,a_00,ctx);
          iVar5 = iVar4 + 1;
          if ((iVar3 == 0) ||
             ((iVar4 = BN_is_bit_set(p,iVar4), iVar4 != 0 &&
              (iVar4 = BN_mul(a_01,a_01,a_00,ctx), iVar4 == 0)))) goto LAB_000ef6c0;
          iVar4 = iVar5;
        } while (iVar5 != iVar2);
      }
      iVar2 = 1;
      if (r != a_01) {
        BN_copy(r,a_01);
        iVar2 = 1;
      }
      goto LAB_000ef6c2;
    }
  }
LAB_000ef6c0:
  iVar2 = 0;
LAB_000ef6c2:
  BN_CTX_end(ctx);
  return iVar2;
}

