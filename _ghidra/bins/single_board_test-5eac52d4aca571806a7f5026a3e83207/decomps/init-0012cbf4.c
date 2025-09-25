
int init(EVP_PKEY_CTX *ctx)

{
  MD5_CTX *c;
  int iVar1;
  
  c = (MD5_CTX *)EVP_MD_CTX_md_data(ctx);
  iVar1 = MD5_Init(c);
  return iVar1;
}

