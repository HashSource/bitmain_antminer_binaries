
void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = ctx->num;
  if (iVar1 != 0) {
    iVar1 = evp_encodeblock_int(ctx,out,ctx->enc_data);
    iVar2 = ctx->expect_nl << 0x1f;
    bVar3 = -1 < iVar2;
    if (bVar3) {
      iVar2 = 10;
    }
    if (bVar3) {
      out[iVar1] = (uchar)iVar2;
      iVar1 = iVar1 + 1;
    }
    out[iVar1] = '\0';
    ctx->num = 0;
  }
  *outl = iVar1;
  return;
}

