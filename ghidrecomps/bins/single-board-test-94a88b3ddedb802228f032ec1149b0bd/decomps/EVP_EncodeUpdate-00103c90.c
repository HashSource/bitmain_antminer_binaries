
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t __n;
  
  *outl = 0;
  if (0 < inl) {
    iVar2 = ctx->length;
    if (iVar2 < 0x51) {
      iVar3 = ctx->num;
      if (iVar3 + inl < iVar2) {
LAB_00103d14:
        memcpy(ctx->enc_data + iVar3,in,inl);
        ctx->num = ctx->num + inl;
        return;
      }
    }
    else {
      OpenSSLDie(DAT_00103d80,0x8e,DAT_00103d7c);
      iVar3 = ctx->num;
      iVar2 = ctx->length;
      if (iVar3 + inl < iVar2) goto LAB_00103d14;
    }
    if (iVar3 != 0) {
      __n = iVar2 - iVar3;
      inl = inl - __n;
      memcpy(ctx->enc_data + iVar3,in,__n);
      in = in + __n;
      iVar2 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
      ctx->num = 0;
      iVar3 = iVar2 + 1;
      out[iVar2] = '\n';
      out[iVar2 + 1] = '\0';
      out = out + iVar2 + 1;
      iVar2 = ctx->length;
    }
    if (iVar2 <= inl) {
      do {
        iVar1 = EVP_EncodeBlock(out,in,iVar2);
        iVar4 = ctx->length;
        out[iVar1] = '\n';
        out[iVar1 + 1] = '\0';
        iVar2 = ctx->length;
        inl = inl - iVar4;
        iVar3 = iVar3 + iVar1 + 1;
        in = in + iVar4;
        out = out + iVar1 + 1;
      } while (iVar2 <= inl);
    }
    if (inl != 0) {
      memcpy(ctx->enc_data,in,inl);
    }
    ctx->num = inl;
    *outl = iVar3;
  }
  return;
}

