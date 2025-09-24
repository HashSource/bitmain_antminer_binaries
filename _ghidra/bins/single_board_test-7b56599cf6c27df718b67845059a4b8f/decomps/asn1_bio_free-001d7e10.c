
undefined4 asn1_bio_free(int param_1)

{
  void *ptr;
  
  if (param_1 == 0) {
    return 0;
  }
  ptr = (void *)BIO_get_data();
  if (ptr != (void *)0x0) {
    if (*(code **)((int)ptr + 0x24) != (code *)0x0) {
      (**(code **)((int)ptr + 0x24))(param_1,(int)ptr + 0x30,(int)ptr + 0x34,(int)ptr + 0x3c);
    }
    if (*(code **)((int)ptr + 0x2c) != (code *)0x0) {
      (**(code **)((int)ptr + 0x2c))(param_1,(int)ptr + 0x30,(int)ptr + 0x34,(int)ptr + 0x3c);
    }
    CRYPTO_free(*(void **)((int)ptr + 4));
    CRYPTO_free(ptr);
    BIO_set_data(param_1,0);
    BIO_set_init(param_1,0);
    return 1;
  }
  return 0;
}

