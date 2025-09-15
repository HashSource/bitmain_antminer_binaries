
int BN_reciprocal(BIGNUM *r,BIGNUM *m,int len,BN_CTX *ctx)

{
  BIGNUM *a;
  int iVar1;
  
  BN_CTX_start(ctx);
  a = BN_CTX_get(ctx);
  if ((a != (BIGNUM *)0x0) && (iVar1 = BN_set_bit(a,len), iVar1 != 0)) {
    iVar1 = BN_div(r,(BIGNUM *)0x0,a,m,ctx);
    if (iVar1 != 0) goto LAB_000f448a;
  }
  len = -1;
LAB_000f448a:
  BN_CTX_end(ctx);
  return len;
}

