
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx,uchar *key)

{
  int iVar1;
  
  if ((int)(ctx->cipher->flags << 0x16) < 0) {
    iVar1 = EVP_CIPHER_CTX_ctrl(ctx,6,0,key);
    return iVar1;
  }
  iVar1 = RAND_priv_bytes(key,ctx->key_len);
  return (uint)(0 < iVar1);
}

