
int EVP_PKEY_get_attr_count(EVP_PKEY *key)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_count(key[1].type);
  return iVar1;
}

