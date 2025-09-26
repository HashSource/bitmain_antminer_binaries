
int EC_KEY_precompute_mult(EC_KEY *key,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(EC_GROUP **)(key + 4) != (EC_GROUP *)0x0) {
    iVar1 = EC_GROUP_precompute_mult(*(EC_GROUP **)(key + 4),ctx);
    return iVar1;
  }
  return 0;
}

