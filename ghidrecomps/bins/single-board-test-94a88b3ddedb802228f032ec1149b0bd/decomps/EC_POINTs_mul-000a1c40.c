
int EC_POINTs_mul(EC_GROUP *group,EC_POINT *r,BIGNUM *n,size_t num,EC_POINT **p,BIGNUM **m,
                 BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x78) != (code *)0x0) {
    iVar1 = (**(code **)(*(int *)group + 0x78))();
    return iVar1;
  }
  iVar1 = ec_wNAF_mul();
  return iVar1;
}

