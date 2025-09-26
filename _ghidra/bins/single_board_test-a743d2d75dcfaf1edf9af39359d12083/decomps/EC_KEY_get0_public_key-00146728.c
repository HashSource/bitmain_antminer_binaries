
EC_POINT * EC_KEY_get0_public_key(EC_KEY *key)

{
  return *(EC_POINT **)(key + 8);
}

