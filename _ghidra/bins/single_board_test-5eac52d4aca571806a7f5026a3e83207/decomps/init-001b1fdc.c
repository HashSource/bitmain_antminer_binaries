
int init(EVP_PKEY_CTX *ctx)

{
  MD4_CTX *c;
  int iVar1;
  
  c = (MD4_CTX *)EVP_MD_CTX_md_data(ctx);
  iVar1 = MD4_Init(c);
  return iVar1;
}

