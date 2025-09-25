
void * EVP_PKEY_CTX_get_app_data(EVP_PKEY_CTX *ctx)

{
  return *(void **)(ctx + 0x18);
}

