
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *pkey,ec_key_st *key)

{
  int iVar1;
  
  iVar1 = EVP_PKEY_assign(pkey,0x198,key);
  if (iVar1 != 0) {
    EC_KEY_up_ref(key);
  }
  return iVar1;
}

