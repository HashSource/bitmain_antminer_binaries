
int EC_POINT_mul(EC_GROUP *group,EC_POINT *r,BIGNUM *n,EC_POINT *q,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  EC_POINT *local_18;
  BIGNUM *local_14;
  
  local_14 = m;
  local_18 = q;
  iVar1 = EC_POINTs_mul(group,r,n,(uint)(q != (EC_POINT *)0x0 && m != (BIGNUM *)0x0),&local_18,
                        &local_14,ctx);
  return iVar1;
}

