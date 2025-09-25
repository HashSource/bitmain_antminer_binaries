
int CMAC_Update(CMAC_CTX *ctx,void *data,size_t dlen)

{
  uint inl;
  int iVar1;
  uint uVar2;
  
  if (*(int *)(ctx + 0x84) == -1) {
    return 0;
  }
  if (dlen == 0) {
    return 1;
  }
  inl = EVP_CIPHER_CTX_block_size(*(EVP_CIPHER_CTX **)ctx);
  iVar1 = *(int *)(ctx + 0x84);
  if (0 < iVar1) {
    uVar2 = inl - iVar1;
    if (dlen <= inl - iVar1) {
      uVar2 = dlen;
    }
    memcpy(ctx + 100 + iVar1,data,uVar2);
    dlen = dlen - uVar2;
    *(uint *)(ctx + 0x84) = *(int *)(ctx + 0x84) + uVar2;
    if (dlen == 0) {
      return 1;
    }
    iVar1 = EVP_Cipher(*(EVP_CIPHER_CTX **)ctx,(uchar *)(ctx + 0x44),(uchar *)(ctx + 100),inl);
    data = (void *)((int)data + uVar2);
    if (iVar1 < 1) {
      return 0;
    }
  }
  if (inl < dlen) {
    uVar2 = dlen - inl;
    do {
      dlen = uVar2;
      iVar1 = EVP_Cipher(*(EVP_CIPHER_CTX **)ctx,(uchar *)(ctx + 0x44),(uchar *)data,inl);
      data = (void *)((int)data + inl);
      if (iVar1 < 1) {
        return 0;
      }
      uVar2 = dlen - inl;
    } while (inl < dlen);
  }
  memcpy(ctx + 100,data,dlen);
  *(size_t *)(ctx + 0x84) = dlen;
  return 1;
}

