
int CMAC_CTX_copy(CMAC_CTX *out,CMAC_CTX *in)

{
  int iVar1;
  size_t __n;
  
  if ((*(int *)(in + 0x10c) != -1) &&
     (iVar1 = EVP_CIPHER_CTX_copy((EVP_CIPHER_CTX *)out,(EVP_CIPHER_CTX *)in), iVar1 != 0)) {
    __n = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)in);
    memcpy(out + 0x8c,in + 0x8c,__n);
    memcpy(out + 0xac,in + 0xac,__n);
    memcpy(out + 0xcc,in + 0xcc,__n);
    memcpy(out + 0xec,in + 0xec,__n);
    *(undefined4 *)(out + 0x10c) = *(undefined4 *)(in + 0x10c);
    return 1;
  }
  return 0;
}

