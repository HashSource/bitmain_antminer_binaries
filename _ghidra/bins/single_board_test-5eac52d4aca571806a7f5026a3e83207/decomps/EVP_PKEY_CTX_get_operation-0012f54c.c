
int EVP_PKEY_CTX_get_operation(EVP_PKEY_CTX *ctx)

{
  return *(int *)(ctx + 0x10);
}

