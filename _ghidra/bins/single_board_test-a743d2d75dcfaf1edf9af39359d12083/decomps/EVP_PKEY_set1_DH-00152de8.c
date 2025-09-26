
int EVP_PKEY_set1_DH(EVP_PKEY *pkey,dh_st *key)

{
  dh_st *pdVar1;
  
  pdVar1 = (dh_st *)pkey_set_type(pkey,0x1c,0,0xffffffff);
  if ((pdVar1 != (dh_st *)0x0) && ((pkey->pkey).dh = key, pdVar1 = key, key != (dh_st *)0x0)) {
    DH_up_ref(key);
    return 1;
  }
  return (int)pdVar1;
}

