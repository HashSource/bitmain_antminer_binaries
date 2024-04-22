
int BN_mod_lshift1(BIGNUM *r,BIGNUM *a,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = BN_lshift1(r,a);
  if (iVar1 != 0) {
    iVar1 = BN_div((BIGNUM *)0x0,r,r,m,ctx);
    if ((iVar1 != 0) && (iVar1 = 1, r->neg != 0)) {
      pcVar2 = DAT_000f2048;
      if (m->neg != 0) {
        pcVar2 = DAT_000f204c;
      }
      iVar1 = (*pcVar2)(r,r,m);
    }
  }
  return iVar1;
}

