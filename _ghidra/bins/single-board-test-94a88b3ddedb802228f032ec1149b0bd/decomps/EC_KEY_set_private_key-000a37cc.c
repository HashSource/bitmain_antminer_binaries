
int EC_KEY_set_private_key(EC_KEY *key,BIGNUM *prv)

{
  BIGNUM *pBVar1;
  
  if (*(BIGNUM **)(key + 0xc) != (BIGNUM *)0x0) {
    BN_clear_free(*(BIGNUM **)(key + 0xc));
  }
  pBVar1 = BN_dup(prv);
  *(BIGNUM **)(key + 0xc) = pBVar1;
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x1;
  }
  return (int)pBVar1;
}

