
void * EVP_PKEY_get0(EVP_PKEY *pkey)

{
  return (pkey->pkey).ptr;
}

