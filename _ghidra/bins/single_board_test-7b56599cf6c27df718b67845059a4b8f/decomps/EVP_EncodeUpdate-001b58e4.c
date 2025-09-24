
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  int iVar2;
  size_t __n;
  bool bVar3;
  
  *outl = 0;
  if (inl < 1) {
    return;
  }
  iVar1 = ctx->length;
  if (0x50 < iVar1) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: ctx->length <= (int)sizeof(ctx->enc_data)","crypto/evp/encode.c",
                0xab,iVar1,in);
  }
  iVar2 = ctx->num;
  __n = iVar1 - iVar2;
  if (inl < (int)__n) {
    memcpy(ctx->enc_data + iVar2,in,inl);
    ctx->num = inl + ctx->num;
    return;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
    if (inl < iVar1) {
      iVar2 = 0;
LAB_001b59dc:
      memcpy(ctx->enc_data,in,inl);
      ctx->num = inl;
      *outl = iVar2;
      return;
    }
  }
  else {
    memcpy(ctx->enc_data + iVar2,in,__n);
    iVar2 = evp_encodeblock_int(ctx,out,ctx->enc_data,ctx->length);
    out = out + iVar2;
    ctx->num = 0;
    inl = inl - __n;
    in = in + __n;
    if (-1 < ctx->expect_nl << 0x1f) {
      iVar2 = iVar2 + 1;
      *out = '\n';
      out = out + 1;
    }
    *out = '\0';
    if (inl < ctx->length) {
LAB_001b5954:
      if (-1 < iVar2) {
        if (inl == 0) {
          ctx->num = 0;
          *outl = iVar2;
          return;
        }
        goto LAB_001b59dc;
      }
      goto LAB_001b59b0;
    }
    if (iVar2 < 0) goto LAB_001b59b0;
  }
  do {
    iVar1 = evp_encodeblock_int(ctx,out,in);
    out = out + iVar1;
    iVar2 = iVar2 + iVar1;
    inl = inl - ctx->length;
    in = in + ctx->length;
    bVar3 = -1 < ctx->expect_nl << 0x1f;
    if (bVar3) {
      *out = '\n';
      out = out + 1;
    }
    *out = '\0';
    if (bVar3) {
      iVar2 = iVar2 + 1;
    }
    if (inl < ctx->length) goto LAB_001b5954;
  } while (-1 < iVar2);
LAB_001b59b0:
  *outl = 0;
  return;
}

