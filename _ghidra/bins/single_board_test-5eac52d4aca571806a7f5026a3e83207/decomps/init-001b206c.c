
int init(EVP_PKEY_CTX *ctx)

{
  RIPEMD160_CTX *c;
  int iVar1;
  
  c = (RIPEMD160_CTX *)EVP_MD_CTX_md_data(ctx);
  iVar1 = RIPEMD160_Init(c);
  return iVar1;
}

