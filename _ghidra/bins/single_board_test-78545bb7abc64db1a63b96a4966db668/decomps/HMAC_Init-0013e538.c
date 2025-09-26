
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  int iVar1;
  
  if (key != (void *)0x0 && md != (EVP_MD *)0x0) {
    HMAC_CTX_reset();
  }
  iVar1 = HMAC_Init_ex(ctx,key,len,md,(ENGINE *)0x0);
  return iVar1;
}

