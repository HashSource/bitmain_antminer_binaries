
int init(EVP_PKEY_CTX *ctx)

{
  SHA_CTX *c;
  int iVar1;
  
  c = (SHA_CTX *)EVP_MD_CTX_md_data(ctx);
  iVar1 = SHA1_Init(c);
  return iVar1;
}

