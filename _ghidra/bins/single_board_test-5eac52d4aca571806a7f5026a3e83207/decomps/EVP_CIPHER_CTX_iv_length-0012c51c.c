
int EVP_CIPHER_CTX_iv_length(EVP_CIPHER_CTX *ctx)

{
  ulong uVar1;
  int iVar2;
  int local_c;
  
  uVar1 = EVP_CIPHER_flags(ctx->cipher);
  if (-1 < (int)(uVar1 << 0x14)) {
    return ctx->cipher->iv_len;
  }
  iVar2 = EVP_CIPHER_CTX_ctrl(ctx,0x25,0,&local_c);
  if (iVar2 != 1) {
    local_c = -1;
  }
  return local_c;
}

