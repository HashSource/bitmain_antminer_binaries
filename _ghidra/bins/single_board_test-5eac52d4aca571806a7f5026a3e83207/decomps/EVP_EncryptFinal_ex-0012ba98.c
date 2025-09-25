
int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx,uchar *out,int *outl)

{
  uint uVar1;
  int iVar2;
  EVP_CIPHER *pEVar3;
  uint inl;
  
  if (ctx->encrypt == 0) {
    ERR_put_error(6,0x7f,0x94,"crypto/evp/evp_enc.c",0x1a8);
    return 0;
  }
  pEVar3 = ctx->cipher;
  if ((pEVar3->flags & 0x100000) == 0) {
    inl = pEVar3->block_size;
    if (0x20 < inl) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: b <= sizeof(ctx->buf)","crypto/evp/evp_enc.c",0x1b6);
    }
    if (inl != 1) {
      uVar1 = ctx->buf_len;
      if (-1 < (int)(ctx->flags << 0x17)) {
        if (uVar1 < inl) {
          memset(ctx->buf + uVar1,inl - uVar1 & 0xff,inl - uVar1);
        }
        iVar2 = (*pEVar3->do_cipher)(ctx,out,ctx->buf,inl);
        if (iVar2 != 0) {
          *outl = inl;
        }
        return iVar2;
      }
      if (uVar1 != 0) {
        ERR_put_error(6,0x7f,0x8a,"crypto/evp/evp_enc.c",0x1bf);
        return 0;
      }
    }
    iVar2 = 1;
    *outl = 0;
  }
  else {
    iVar2 = (*pEVar3->do_cipher)(ctx,out,(uchar *)0x0,0);
    if (-1 < iVar2) {
      *outl = iVar2;
      return 1;
    }
    iVar2 = 0;
  }
  return iVar2;
}

