
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *pkey,ec_key_st *key)

{
  ec_key_st *peVar1;
  
  peVar1 = (ec_key_st *)pkey_set_type(pkey,0x198,0,0xffffffff);
  if ((peVar1 != (ec_key_st *)0x0) && ((pkey->pkey).ec = key, peVar1 = key, key != (ec_key_st *)0x0)
     ) {
    EC_KEY_up_ref(key);
    return 1;
  }
  return (int)peVar1;
}

