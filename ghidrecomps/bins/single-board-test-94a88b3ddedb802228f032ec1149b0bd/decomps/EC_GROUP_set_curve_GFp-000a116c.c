
int EC_GROUP_set_curve_GFp(EC_GROUP *group,BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x18) == (code *)0x0) {
    ERR_put_error(0x10,0x6d,0x42,DAT_000a1198,0x1a8);
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*(int *)group + 0x18))();
  }
  return iVar1;
}

