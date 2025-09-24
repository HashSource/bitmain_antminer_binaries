
void EVP_PKEY_CTX_set0_keygen_info(EVP_PKEY_CTX *ctx,int *dat,int datlen)

{
  *(int **)(ctx + 0x20) = dat;
  *(int *)(ctx + 0x24) = datlen;
  return;
}

