
int EVP_Digest(void *data,size_t count,uchar *md,uint *size,EVP_MD *type,ENGINE *impl)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    return 0;
  }
  EVP_MD_CTX_set_flags(ctx,1);
  iVar1 = EVP_DigestInit_ex(ctx,type,impl);
  if ((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(ctx,data,count), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(ctx,md,size);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

