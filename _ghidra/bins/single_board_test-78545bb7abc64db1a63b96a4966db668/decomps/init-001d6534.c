
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  EVP_MD_CTX_md_data(ctx);
  iVar1 = BLAKE2b_Init();
  return iVar1;
}

