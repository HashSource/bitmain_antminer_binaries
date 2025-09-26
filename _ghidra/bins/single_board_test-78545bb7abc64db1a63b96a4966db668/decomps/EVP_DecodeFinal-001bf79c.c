
int EVP_DecodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  
  *outl = 0;
  if (ctx->num == 0) {
    return 1;
  }
  iVar1 = evp_decodeblock_int(ctx,out,ctx->enc_data);
  if (-1 < iVar1) {
    ctx->num = 0;
    *outl = iVar1;
    return 1;
  }
  return -1;
}

