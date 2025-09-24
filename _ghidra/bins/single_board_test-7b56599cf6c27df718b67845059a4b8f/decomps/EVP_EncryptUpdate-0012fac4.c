
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  EVP_CIPHER *cipher;
  ulong uVar2;
  size_t sVar3;
  uint uVar4;
  size_t __n;
  
  if (ctx->encrypt == 0) {
    ERR_put_error(6,0xa7,0x94,"crypto/evp/evp_enc.c",0x193);
    return 0;
  }
  iVar1 = EVP_CIPHER_CTX_test_flags(ctx,0x2000);
  uVar4 = inl + 7U >> 3;
  if (iVar1 == 0) {
    uVar4 = inl;
  }
  if (inl < 0) {
LAB_0012fb24:
    *outl = 0;
    return (uint)(inl == 0);
  }
  cipher = ctx->cipher;
  sVar3 = cipher->block_size;
  if (inl == 0) {
    uVar2 = EVP_CIPHER_flags(cipher);
    if ((uVar2 & 0xf0007) != 7) goto LAB_0012fb24;
    cipher = ctx->cipher;
  }
  if ((cipher->flags & 0x100000) == 0) {
    iVar1 = is_partially_overlapping(out + ctx->buf_len,in,uVar4);
    if (iVar1 != 0) {
      ERR_put_error(6,0xdb,0xa2,"crypto/evp/evp_enc.c",0x151);
      return 0;
    }
    iVar1 = ctx->buf_len;
    if (iVar1 == 0) {
      if ((inl & ctx->block_mask) == 0) {
        iVar1 = (*ctx->cipher->do_cipher)(ctx,out,in,inl);
        if (iVar1 != 0) {
          *outl = inl;
          return 1;
        }
        *outl = 0;
        return 0;
      }
      if (0x20 < (int)sVar3) goto LAB_0012fc32;
      *outl = 0;
    }
    else {
      if (0x20 < (int)sVar3) {
LAB_0012fc32:
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: bl <= (int)sizeof(ctx->buf)","crypto/evp/evp_enc.c",0x15f);
      }
      __n = sVar3 - iVar1;
      if (inl < (int)__n) {
        memcpy(ctx->buf + iVar1,in,inl);
        ctx->buf_len = ctx->buf_len + inl;
        *outl = 0;
        return 1;
      }
      inl = inl - __n;
      if ((int)(0x7fffffff - sVar3) < (int)(-sVar3 & inl)) {
        ERR_put_error(6,0xdb,0xb8,"crypto/evp/evp_enc.c",0x172);
        return 0;
      }
      memcpy(ctx->buf + iVar1,in,__n);
      iVar1 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar3);
      if (iVar1 == 0) goto LAB_0012fb54;
      in = in + __n;
      out = out + sVar3;
      *outl = sVar3;
    }
    uVar4 = sVar3 - 1 & inl;
    sVar3 = inl - uVar4;
    if (0 < (int)sVar3) {
      iVar1 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar3);
      if (iVar1 == 0) goto LAB_0012fb54;
      *outl = *outl + sVar3;
    }
    if (uVar4 != 0) {
      memcpy(ctx->buf,in + sVar3,uVar4);
    }
    ctx->buf_len = uVar4;
    iVar1 = 1;
  }
  else {
    if (sVar3 == 1) {
      iVar1 = is_partially_overlapping(out,in,uVar4);
      if (iVar1 != 0) {
        ERR_put_error(6,0xdb,0xa2,"crypto/evp/evp_enc.c",0x144);
        return 0;
      }
      cipher = ctx->cipher;
    }
    iVar1 = (*cipher->do_cipher)(ctx,out,in,inl);
    if (-1 < iVar1) {
      *outl = iVar1;
      return 1;
    }
LAB_0012fb54:
    iVar1 = 0;
  }
  return iVar1;
}

