
int CMAC_CTX_copy(CMAC_CTX *out,CMAC_CTX *in)

{
  int iVar1;
  size_t __n;
  
  if ((*(int *)(in + 0x84) != -1) &&
     (iVar1 = EVP_CIPHER_CTX_copy(*(EVP_CIPHER_CTX **)out,*(EVP_CIPHER_CTX **)in), iVar1 != 0)) {
    __n = EVP_CIPHER_CTX_block_size(*(EVP_CIPHER_CTX **)in);
    memcpy(out + 4,in + 4,__n);
    memcpy(out + 0x24,in + 0x24,__n);
    memcpy(out + 0x44,in + 0x44,__n);
    memcpy(out + 100,in + 100,__n);
    *(undefined4 *)(out + 0x84) = *(undefined4 *)(in + 0x84);
    return 1;
  }
  return 0;
}

