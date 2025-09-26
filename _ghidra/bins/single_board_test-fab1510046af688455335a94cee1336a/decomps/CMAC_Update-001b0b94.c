
int CMAC_Update(CMAC_CTX *ctx,void *data,size_t dlen)

{
  uint inl;
  int iVar1;
  uchar *in;
  uint __n;
  
  if (*(int *)(ctx + 0x10c) == -1) {
    return 0;
  }
  if (dlen != 0) {
    inl = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
    iVar1 = *(int *)(ctx + 0x10c);
    if (0 < iVar1) {
      __n = inl - iVar1;
      if (dlen <= inl - iVar1) {
        __n = dlen;
      }
      memcpy(ctx + iVar1 + 0xec,data,__n);
      dlen = dlen - __n;
      *(uint *)(ctx + 0x10c) = *(int *)(ctx + 0x10c) + __n;
      if (dlen == 0) {
        return 1;
      }
      iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)(ctx + 0xcc),(uchar *)(ctx + 0xec),inl);
      if (iVar1 == 0) {
        return 0;
      }
      data = (void *)((int)data + __n);
    }
    if (inl < dlen) {
      in = (uchar *)data;
      do {
        dlen = dlen - inl;
        data = in + inl;
        iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)(ctx + 0xcc),in,inl);
        if (iVar1 == 0) {
          return 0;
        }
        in = (uchar *)data;
      } while (inl < dlen);
    }
    memcpy(ctx + 0xec,data,dlen);
    *(size_t *)(ctx + 0x10c) = dlen;
    return 1;
  }
  return 1;
}

