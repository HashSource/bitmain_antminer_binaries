
int EVP_PKEY_set1_RSA(EVP_PKEY *pkey,rsa_st *key)

{
  int iVar1;
  
  iVar1 = EVP_PKEY_assign(pkey,6,key);
  if (iVar1 != 0) {
    RSA_up_ref(key);
  }
  return iVar1;
}

