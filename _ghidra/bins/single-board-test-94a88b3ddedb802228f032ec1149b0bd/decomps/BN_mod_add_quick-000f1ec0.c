
int BN_mod_add_quick(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = BN_uadd(r,a,b);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = BN_ucmp(r,m);
  if (-1 < iVar1) {
    iVar1 = BN_usub(r,r,m);
    return iVar1;
  }
  return 1;
}

