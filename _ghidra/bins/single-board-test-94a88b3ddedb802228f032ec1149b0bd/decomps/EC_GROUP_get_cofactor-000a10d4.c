
int EC_GROUP_get_cofactor(EC_GROUP *group,BIGNUM *cofactor,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_copy(cofactor,(BIGNUM *)(group + 0x1c));
  if ((pBVar1 != (BIGNUM *)0x0) && (pBVar1 = *(BIGNUM **)(group + 0x20), pBVar1 != (BIGNUM *)0x0)) {
    pBVar1 = (BIGNUM *)0x1;
  }
  return (int)pBVar1;
}

