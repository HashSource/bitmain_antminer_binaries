
EVP_PKEY * EVP_PKEY_CTX_get0_pkey(EVP_PKEY_CTX *ctx)

{
  return *(EVP_PKEY **)(ctx + 8);
}

