
int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = BN_is_zero(d);
  if (iVar1 != 0) {
    ERR_put_error(3,0x6b,0x67,"crypto/bn/bn_div.c",0xd7);
    return 0;
  }
  if (d->d[d->top + 0x3fffffff] != 0) {
    iVar2 = bn_div_fixed_top(dv,rem,m,d,ctx);
    iVar1 = 0;
    if (iVar2 != 0) {
      if (dv != (BIGNUM *)0x0) {
        bn_correct_top(dv);
      }
      iVar1 = iVar2;
      if (rem != (BIGNUM *)0x0) {
        bn_correct_top(rem);
      }
    }
    return iVar1;
  }
  ERR_put_error(3,0x6b,0x6b,"crypto/bn/bn_div.c",0xe1);
  return 0;
}

