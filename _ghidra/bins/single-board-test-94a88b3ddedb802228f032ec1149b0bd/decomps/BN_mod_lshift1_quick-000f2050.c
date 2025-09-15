
int BN_mod_lshift1_quick(BIGNUM *r,BIGNUM *a,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = BN_lshift1(r,a);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = BN_cmp(r,m);
  if (-1 < iVar1) {
    iVar1 = BN_sub(r,r,m);
    return iVar1;
  }
  return 1;
}

