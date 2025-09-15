
int EVP_DecodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  
  *outl = 0;
  if (ctx->num == 0) {
    return 1;
  }
  iVar1 = EVP_DecodeBlock(out,ctx->enc_data,ctx->num);
  if (-1 < iVar1) {
    ctx->num = 0;
    *outl = iVar1;
    return 1;
  }
  return -1;
}

