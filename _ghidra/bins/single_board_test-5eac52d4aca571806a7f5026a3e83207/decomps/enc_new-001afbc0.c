
bool enc_new(undefined4 param_1)

{
  void *ptr;
  EVP_CIPHER_CTX *pEVar1;
  
  ptr = (void *)CRYPTO_zalloc(0x1140,"crypto/evp/bio_enc.c",0x44);
  if (ptr != (void *)0x0) {
    pEVar1 = EVP_CIPHER_CTX_new();
    *(EVP_CIPHER_CTX **)((int)ptr + 0x14) = pEVar1;
    if (pEVar1 == (EVP_CIPHER_CTX *)0x0) {
      CRYPTO_free(ptr);
    }
    else {
      *(int *)((int)ptr + 0x18) = (int)ptr + 0x140;
      *(int *)((int)ptr + 0x1c) = (int)ptr + 0x140;
      *(undefined4 *)((int)ptr + 8) = 1;
      *(undefined4 *)((int)ptr + 0x10) = 1;
      BIO_set_data(param_1,ptr);
      BIO_set_init(param_1,1);
    }
    return pEVar1 != (EVP_CIPHER_CTX *)0x0;
  }
  ERR_put_error(6,199,0x41,"crypto/evp/bio_enc.c",0x45);
  return false;
}

