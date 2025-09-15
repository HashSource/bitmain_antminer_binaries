
int EVP_PKEY_id(EVP_PKEY *pkey)

{
  return pkey->type;
}

