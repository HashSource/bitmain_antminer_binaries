
int BN_mod_lshift(BIGNUM *r,BIGNUM *a,int n,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a_00;
  
  iVar1 = BN_nnmod(r,a,m,ctx);
  if (iVar1 == 0) {
    return 0;
  }
  if (m->neg == 0) {
    a_00 = (BIGNUM *)0x0;
  }
  else {
    m = BN_dup(m);
    if (m == (BIGNUM *)0x0) {
      return 0;
    }
    m->neg = 0;
    a_00 = m;
  }
  iVar1 = BN_mod_lshift_quick(r,r,n,m);
  BN_free(a_00);
  return iVar1;
}

