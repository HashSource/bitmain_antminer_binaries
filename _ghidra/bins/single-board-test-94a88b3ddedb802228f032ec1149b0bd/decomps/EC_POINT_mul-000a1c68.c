
int EC_POINT_mul(EC_GROUP *group,EC_POINT *r,BIGNUM *n,EC_POINT *q,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x78) == (code *)0x0) {
    iVar1 = ec_wNAF_mul();
  }
  else {
    iVar1 = (**(code **)(*(int *)group + 0x78))();
  }
  return iVar1;
}

