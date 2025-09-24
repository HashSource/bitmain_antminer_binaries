
EVP_PKEY * EVP_PKEY_new_mac_key(int type,ENGINE *e,uchar *key,int keylen)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  EVP_PKEY *local_14;
  
  local_14 = (EVP_PKEY *)0x0;
  ctx = EVP_PKEY_CTX_new_id(type,e);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    local_14 = (EVP_PKEY *)0x0;
  }
  else {
    iVar1 = EVP_PKEY_keygen_init(ctx);
    if (0 < iVar1) {
      iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,4,6,keylen,key);
      if (0 < iVar1) {
        EVP_PKEY_keygen(ctx,&local_14);
      }
    }
    EVP_PKEY_CTX_free(ctx);
  }
  return local_14;
}

