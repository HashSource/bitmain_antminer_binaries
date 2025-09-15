
int EVP_PKEY_set1_RSA(EVP_PKEY *pkey,rsa_st *key)

{
  rsa_st *prVar1;
  
  prVar1 = (rsa_st *)pkey_set_type(pkey,6,0,0xffffffff);
  if ((prVar1 != (rsa_st *)0x0) && ((pkey->pkey).rsa = key, prVar1 = key, key != (rsa_st *)0x0)) {
    RSA_up_ref(key);
    return 1;
  }
  return (int)prVar1;
}

