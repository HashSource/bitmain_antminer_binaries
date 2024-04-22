
int BN_nnmod(BIGNUM *r,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = BN_div((BIGNUM *)0x0,r,m,d,ctx);
  if ((iVar1 != 0) && (iVar1 = 1, r->neg != 0)) {
    pcVar2 = DAT_000f1e6c;
    if (d->neg != 0) {
      pcVar2 = DAT_000f1e70;
    }
    iVar1 = (*pcVar2)(r,r,d);
  }
  return iVar1;
}

