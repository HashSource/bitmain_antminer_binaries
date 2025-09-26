
int EVP_DigestInit(EVP_MD_CTX *ctx,EVP_MD *type)

{
  int iVar1;
  
  memset(ctx,0,0x18);
  iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
  return iVar1;
}

