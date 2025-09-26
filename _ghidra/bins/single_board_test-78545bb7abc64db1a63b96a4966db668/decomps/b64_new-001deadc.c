
bool b64_new(undefined4 param_1)

{
  void *ptr;
  int iVar1;
  
  ptr = (void *)CRYPTO_zalloc(0xa00,"crypto/evp/bio_b64.c",0x49);
  if (ptr != (void *)0x0) {
    *(undefined4 *)((int)ptr + 0x18) = 1;
    *(undefined4 *)((int)ptr + 0x14) = 1;
    iVar1 = EVP_ENCODE_CTX_new();
    *(int *)((int)ptr + 0x1c) = iVar1;
    if (iVar1 == 0) {
      CRYPTO_free(ptr);
    }
    else {
      BIO_set_data(param_1,ptr);
      BIO_set_init(param_1,1);
    }
    return iVar1 != 0;
  }
  ERR_put_error(6,0xc6,0x41,"crypto/evp/bio_b64.c",0x4a);
  return false;
}

