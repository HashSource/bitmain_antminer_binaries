
void * EVP_PKEY_get0(EVP_PKEY *pkey)

{
  return (void *)pkey->save_parameters;
}

