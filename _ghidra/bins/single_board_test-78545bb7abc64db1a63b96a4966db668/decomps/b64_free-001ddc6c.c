
undefined4 b64_free(int param_1)

{
  void *ptr;
  
  if (param_1 == 0) {
    return 0;
  }
  ptr = (void *)BIO_get_data();
  if (ptr != (void *)0x0) {
    EVP_ENCODE_CTX_free(*(undefined4 *)((int)ptr + 0x1c));
    CRYPTO_free(ptr);
    BIO_set_data(param_1,0);
    BIO_set_init(param_1,0);
    return 1;
  }
  return 0;
}

