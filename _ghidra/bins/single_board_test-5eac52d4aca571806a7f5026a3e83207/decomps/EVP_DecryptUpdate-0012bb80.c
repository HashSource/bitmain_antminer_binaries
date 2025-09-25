
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  EVP_CIPHER *pEVar4;
  uint __n;
  uint uVar5;
  
  if (ctx->encrypt != 0) {
    ERR_put_error(6,0xa6,0x94,"crypto/evp/evp_enc.c",0x1da);
    return 0;
  }
  __n = ctx->cipher->block_size;
  iVar2 = EVP_CIPHER_CTX_test_flags(ctx,0x2000);
  uVar5 = inl + 7U >> 3;
  if (iVar2 == 0) {
    uVar5 = inl;
  }
  if ((inl < 0) || ((inl == 0 && (uVar3 = EVP_CIPHER_flags(ctx->cipher), (uVar3 & 0xf0007) != 7))))
  {
    *outl = 0;
    return (uint)(inl == 0);
  }
  pEVar4 = ctx->cipher;
  if ((int)(pEVar4->flags << 0xb) < 0) {
    if (__n != 1) {
LAB_0012bbc4:
      iVar2 = (*pEVar4->do_cipher)(ctx,out,in,inl);
      if (iVar2 < 0) {
        *outl = 0;
      }
      else {
        *outl = iVar2;
      }
      return (uint)(iVar2 >= 0);
    }
    iVar2 = is_partially_overlapping(out,in,uVar5);
    if (iVar2 == 0) {
      pEVar4 = ctx->cipher;
      goto LAB_0012bbc4;
    }
    iVar2 = 0x1f0;
LAB_0012bcd0:
    ERR_put_error(6,0xa6,0xa2,"crypto/evp/evp_enc.c",iVar2);
    iVar2 = 0;
  }
  else {
    if ((int)(ctx->flags << 0x17) < 0) {
      iVar2 = evp_EncryptDecryptUpdate(ctx,out,outl,in);
      return iVar2;
    }
    if (0x20 < __n) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: b <= sizeof(ctx->final)","crypto/evp/evp_enc.c",0x200);
    }
    if (ctx->final_used == 0) {
      bVar1 = false;
    }
    else {
      if ((out == in) || (iVar2 = is_partially_overlapping(out,in,__n), iVar2 != 0)) {
        iVar2 = 0x206;
        goto LAB_0012bcd0;
      }
      if (0x7fffffff - __n < (-__n & inl)) {
        ERR_put_error(6,0xa6,0xb8,"crypto/evp/evp_enc.c",0x213);
        return 0;
      }
      bVar1 = true;
      memcpy(out,ctx->final,__n);
      out = out + __n;
    }
    iVar2 = evp_EncryptDecryptUpdate(ctx,out,outl,in,inl);
    if (iVar2 != 0) {
      if ((__n < 2) || (ctx->buf_len != 0)) {
        ctx->final_used = 0;
      }
      else {
        *outl = *outl - __n;
        ctx->final_used = 1;
        memcpy(ctx->final,out + *outl,__n);
      }
      iVar2 = 1;
      if (bVar1) {
        iVar2 = 1;
        *outl = *outl + __n;
      }
    }
  }
  return iVar2;
}

