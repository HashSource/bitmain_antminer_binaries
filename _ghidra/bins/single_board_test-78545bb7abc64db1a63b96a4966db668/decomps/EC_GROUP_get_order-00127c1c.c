
int EC_GROUP_get_order(EC_GROUP *group,BIGNUM *order,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  
  if (*(BIGNUM **)(group + 8) == (BIGNUM *)0x0) {
    return 0;
  }
  pBVar1 = BN_copy(order,*(BIGNUM **)(group + 8));
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = BN_is_zero(order);
    return (uint)(iVar2 == 0);
  }
  return 0;
}

