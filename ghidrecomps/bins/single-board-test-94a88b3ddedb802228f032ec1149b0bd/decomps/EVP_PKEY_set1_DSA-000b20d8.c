
int EVP_PKEY_set1_DSA(EVP_PKEY *pkey,dsa_st *key)

{
  dsa_st *pdVar1;
  
  pdVar1 = (dsa_st *)pkey_set_type(pkey,0x74,0,0xffffffff);
  if ((pdVar1 != (dsa_st *)0x0) && ((pkey->pkey).dsa = key, pdVar1 = key, key != (dsa_st *)0x0)) {
    DSA_up_ref(key);
    return 1;
  }
  return (int)pdVar1;
}

