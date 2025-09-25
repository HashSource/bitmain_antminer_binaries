
uchar * HMAC(EVP_MD *evp_md,void *key,int key_len,uchar *d,size_t n,uchar *md,uint *md_len)

{
  HMAC_CTX *ctx;
  int iVar1;
  
  if (md == (uchar *)0x0) {
    md = &m_12761;
  }
  ctx = (HMAC_CTX *)HMAC_CTX_new();
  if (ctx != (HMAC_CTX *)0x0) {
    if (key == (void *)0x0 && key_len == 0) {
      key = &dummy_key_12762;
    }
    iVar1 = HMAC_Init_ex(ctx,key,key_len,evp_md,(ENGINE *)0x0);
    if (((iVar1 != 0) && (iVar1 = HMAC_Update(ctx,d,n), iVar1 != 0)) &&
       (iVar1 = HMAC_Final(ctx,md,md_len), iVar1 != 0)) {
      HMAC_CTX_free(ctx);
      return md;
    }
  }
  HMAC_CTX_free(ctx);
  return (uchar *)0x0;
}

