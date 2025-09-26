
int EVP_DigestInit(EVP_MD_CTX *ctx,EVP_MD *type)

{
  int iVar1;
  
  EVP_MD_CTX_reset();
  iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
  return iVar1;
}

