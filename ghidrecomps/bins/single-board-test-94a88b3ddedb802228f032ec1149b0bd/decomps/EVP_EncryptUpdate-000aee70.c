
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  size_t sVar3;
  uint __n;
  size_t __n_00;
  
  pEVar2 = ctx->cipher;
  if ((pEVar2->flags & 0x100000) != 0) {
    iVar1 = (*pEVar2->do_cipher)(ctx,out,in,inl);
    if (iVar1 < 0) {
      return 0;
    }
    *outl = iVar1;
    return 1;
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  iVar1 = ctx->buf_len;
  if ((iVar1 == 0) && ((inl & ctx->block_mask) == 0)) {
    iVar1 = (*pEVar2->do_cipher)(ctx,out,in,inl);
    if (iVar1 != 0) {
      *outl = inl;
      return 1;
    }
    *outl = 0;
    return 0;
  }
  sVar3 = pEVar2->block_size;
  if (0x20 < (int)sVar3) {
    OpenSSLDie(DAT_000aef90,0x15c,DAT_000aef94);
  }
  if (iVar1 == 0) {
    *outl = 0;
  }
  else {
    if (inl + iVar1 < (int)sVar3) {
      memcpy(ctx->buf + iVar1,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      return 1;
    }
    __n_00 = sVar3 - iVar1;
    memcpy(ctx->buf + iVar1,in,__n_00);
    iVar1 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar3);
    if (iVar1 == 0) {
      return 0;
    }
    inl = inl - __n_00;
    in = in + __n_00;
    out = out + sVar3;
    *outl = sVar3;
  }
  __n = sVar3 - 1 & inl;
  sVar3 = inl - __n;
  if (0 < (int)sVar3) {
    iVar1 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar3);
    if (iVar1 == 0) {
      return 0;
    }
    *outl = *outl + sVar3;
  }
  if (__n != 0) {
    memcpy(ctx->buf,in + sVar3,__n);
  }
  ctx->buf_len = __n;
  return 1;
}

