
int init(EVP_PKEY_CTX *ctx)

{
  WHIRLPOOL_CTX *c;
  int iVar1;
  
  c = (WHIRLPOOL_CTX *)EVP_MD_CTX_md_data(ctx);
  iVar1 = WHIRLPOOL_Init(c);
  return iVar1;
}

