
void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  int n;
  
  n = ctx->num;
  if (n != 0) {
    iVar1 = EVP_EncodeBlock(out,ctx->enc_data,n);
    n = iVar1 + 1;
    out[iVar1] = '\n';
    out[n] = '\0';
    ctx->num = 0;
  }
  *outl = n;
  return;
}

