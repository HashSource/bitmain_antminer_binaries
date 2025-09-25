
int BN_mod_sub_quick(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = BN_sub(r,a,b);
  if ((iVar1 != 0) && (iVar1 = 1, r->neg != 0)) {
    iVar1 = BN_add(r,r,m);
    return iVar1;
  }
  return iVar1;
}

