
int EC_GROUP_get_cofactor(EC_GROUP *group,BIGNUM *cofactor,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  
  if (*(BIGNUM **)(group + 0xc) == (BIGNUM *)0x0) {
    return 0;
  }
  pBVar1 = BN_copy(cofactor,*(BIGNUM **)(group + 0xc));
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = BN_is_zero(*(undefined4 *)(group + 0xc));
    return (uint)(iVar2 == 0);
  }
  return 0;
}

