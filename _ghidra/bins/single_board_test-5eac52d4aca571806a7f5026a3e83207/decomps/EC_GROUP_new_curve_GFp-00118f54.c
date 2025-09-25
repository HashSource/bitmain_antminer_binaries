
EC_GROUP * EC_GROUP_new_curve_GFp(BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  EC_METHOD *meth;
  EC_GROUP *group;
  
  iVar1 = BN_nist_mod_func();
  if (iVar1 == 0) {
    meth = EC_GFp_mont_method();
  }
  else {
    meth = EC_GFp_nist_method();
  }
  group = EC_GROUP_new(meth);
  if ((group != (EC_GROUP *)0x0) && (iVar1 = EC_GROUP_set_curve(group,p,a,b,ctx), iVar1 == 0)) {
    EC_GROUP_clear_free(group);
    group = (EC_GROUP *)0x0;
  }
  return group;
}

