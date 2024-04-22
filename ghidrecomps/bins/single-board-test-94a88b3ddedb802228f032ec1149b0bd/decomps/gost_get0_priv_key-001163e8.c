
BIGNUM * gost_get0_priv_key(EVP_PKEY *param_1)

{
  int iVar1;
  BIGNUM *pBVar2;
  EC_KEY *key;
  
  iVar1 = EVP_PKEY_base_id(param_1);
  if (iVar1 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_1);
    if (key == (EC_KEY *)0x0) {
      return (BIGNUM *)0x0;
    }
    pBVar2 = EC_KEY_get0_private_key(key);
    return pBVar2;
  }
  if (iVar1 == 0x32c) {
    pBVar2 = (BIGNUM *)EVP_PKEY_get0(param_1);
    if (pBVar2 != (BIGNUM *)0x0) {
      return (BIGNUM *)pBVar2[1].dmax;
    }
  }
  else {
    pBVar2 = (BIGNUM *)0x0;
  }
  return pBVar2;
}

