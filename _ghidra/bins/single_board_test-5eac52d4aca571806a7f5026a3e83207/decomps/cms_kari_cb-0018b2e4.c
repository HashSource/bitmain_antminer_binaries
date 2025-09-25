
undefined4 cms_kari_cb(int param_1,int *param_2)

{
  EVP_CIPHER_CTX *ctx;
  int iVar1;
  
  iVar1 = *param_2;
  if (param_1 == 1) {
    ctx = EVP_CIPHER_CTX_new();
    *(EVP_CIPHER_CTX **)(iVar1 + 0x18) = ctx;
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      EVP_CIPHER_CTX_set_flags(ctx,1);
      *(undefined4 *)(iVar1 + 0x14) = 0;
      return 1;
    }
    return 0;
  }
  if (param_1 != 3) {
    return 1;
  }
  EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar1 + 0x14));
  EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(iVar1 + 0x18));
  return 1;
}

