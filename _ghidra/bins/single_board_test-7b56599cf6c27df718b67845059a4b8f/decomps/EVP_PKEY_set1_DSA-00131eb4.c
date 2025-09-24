
int EVP_PKEY_set1_DSA(EVP_PKEY *pkey,dsa_st *key)

{
  int iVar1;
  
  iVar1 = EVP_PKEY_assign(pkey,0x74,key);
  if (iVar1 != 0) {
    DSA_up_ref(key);
  }
  return iVar1;
}

