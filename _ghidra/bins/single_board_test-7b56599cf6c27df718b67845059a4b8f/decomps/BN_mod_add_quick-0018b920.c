
int BN_mod_add_quick(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = bn_mod_add_fixed_top();
  if (iVar1 != 0) {
    bn_correct_top(r);
  }
  return iVar1;
}

