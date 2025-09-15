
BIGNUM * EC_KEY_get0_private_key(EC_KEY *key)

{
  return *(BIGNUM **)(key + 0xc);
}

