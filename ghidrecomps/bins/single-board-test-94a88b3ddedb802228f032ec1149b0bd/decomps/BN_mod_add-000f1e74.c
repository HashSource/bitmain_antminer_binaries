
int BN_mod_add(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = BN_add(r,a,b);
  if (iVar1 != 0) {
    iVar1 = BN_div((BIGNUM *)0x0,r,r,m,ctx);
    if ((iVar1 != 0) && (iVar1 = 1, r->neg != 0)) {
      pcVar2 = DAT_000f1eb8;
      if (m->neg != 0) {
        pcVar2 = DAT_000f1ebc;
      }
      iVar1 = (*pcVar2)(r,r,m);
    }
  }
  return iVar1;
}

