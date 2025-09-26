
int EVP_PKEY_base_id(EVP_PKEY *pkey)

{
  int iVar1;
  
  iVar1 = EVP_PKEY_type(pkey->type);
  return iVar1;
}

