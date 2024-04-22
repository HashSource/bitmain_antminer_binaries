
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uint uVar1;
  int iVar2;
  uint __n;
  EVP_CIPHER *pEVar3;
  uchar *out_00;
  
  pEVar3 = ctx->cipher;
  if ((pEVar3->flags & 0x100000) == 0) {
    if (inl < 1) {
      *outl = 0;
      uVar1 = (uint)(inl == 0);
    }
    else {
      if ((ctx->flags & 0x100) != 0) {
        iVar2 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
        return iVar2;
      }
      __n = pEVar3->block_size;
      if (0x20 < __n) {
        OpenSSLDie(DAT_000af1e0,0x1c7,DAT_000af1e4);
      }
      iVar2 = ctx->final_used;
      out_00 = out;
      if (iVar2 != 0) {
        out_00 = out + __n;
        memcpy(out,ctx->final,__n);
        iVar2 = 1;
      }
      uVar1 = EVP_EncryptUpdate(ctx,out_00,outl,in,inl);
      if (uVar1 != 0) {
        if ((__n < 2) || (ctx->buf_len != 0)) {
          ctx->final_used = 0;
        }
        else {
          *outl = *outl - __n;
          ctx->final_used = 1;
          memcpy(ctx->final,out_00 + *outl,__n);
        }
        uVar1 = 1;
        if (iVar2 != 0) {
          uVar1 = 1;
          *outl = *outl + __n;
        }
      }
    }
  }
  else {
    iVar2 = (*pEVar3->do_cipher)(ctx,out,in,inl);
    if (iVar2 < 0) {
      *outl = 0;
    }
    else {
      *outl = iVar2;
    }
    uVar1 = (uint)(iVar2 >= 0);
  }
  return uVar1;
}

