
void EVP_PKEY_CTX_set_data(EVP_PKEY_CTX *ctx,void *data)

{
  *(void **)(ctx + 0x14) = data;
  return;
}

