
int EC_GROUP_get_curve_GFp(EC_GROUP *group,BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x1c) == (code *)0x0) {
    ERR_put_error(0x10,0x82,0x42,DAT_000a11c8,0x1b2);
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*(int *)group + 0x1c))();
  }
  return iVar1;
}

