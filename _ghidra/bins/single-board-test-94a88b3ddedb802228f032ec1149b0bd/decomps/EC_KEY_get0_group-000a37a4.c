
EC_GROUP * EC_KEY_get0_group(EC_KEY *key)

{
  return *(EC_GROUP **)(key + 4);
}

