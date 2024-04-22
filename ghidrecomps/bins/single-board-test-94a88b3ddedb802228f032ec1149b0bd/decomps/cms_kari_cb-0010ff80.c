
undefined4 cms_kari_cb(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (param_1 == 1) {
    EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)(iVar1 + 0x18));
    EVP_CIPHER_CTX_set_flags((EVP_CIPHER_CTX *)(iVar1 + 0x18),1);
    *(undefined4 *)(iVar1 + 0x14) = 0;
  }
  else if (param_1 == 3) {
    if (*(EVP_PKEY_CTX **)(iVar1 + 0x14) != (EVP_PKEY_CTX *)0x0) {
      EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar1 + 0x14));
    }
    EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)(iVar1 + 0x18));
    return 1;
  }
  return 1;
}

