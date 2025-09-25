
EVP_PKEY * ssl_dh_to_pkey(dh_st *param_1)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  if (param_1 == (dh_st *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  pkey = EVP_PKEY_new();
  iVar1 = EVP_PKEY_set1_DH(pkey,param_1);
  if (0 < iVar1) {
    return pkey;
  }
  EVP_PKEY_free(pkey);
  return (EVP_PKEY *)0x0;
}

