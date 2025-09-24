
ec_key_st * EVP_PKEY_get1_EC_KEY(EVP_PKEY *pkey)

{
  EC_KEY *key;
  
  key = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
  if (key != (EC_KEY *)0x0) {
    EC_KEY_up_ref(key);
  }
  return key;
}

