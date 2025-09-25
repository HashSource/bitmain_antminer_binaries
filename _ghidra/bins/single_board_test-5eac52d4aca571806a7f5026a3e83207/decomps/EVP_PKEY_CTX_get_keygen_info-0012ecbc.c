
int EVP_PKEY_CTX_get_keygen_info(EVP_PKEY_CTX *ctx,int idx)

{
  if (idx == -1) {
    return *(int *)(ctx + 0x24);
  }
  if ((-1 < idx) && (idx <= *(int *)(ctx + 0x24))) {
    return *(int *)(*(int *)(ctx + 0x20) + idx * 4);
  }
  return 0;
}

