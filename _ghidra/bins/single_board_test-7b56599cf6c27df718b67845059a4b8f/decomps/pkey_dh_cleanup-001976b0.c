
void pkey_dh_cleanup(int param_1)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x14);
  if (ptr != (void *)0x0) {
    CRYPTO_free(*(void **)((int)ptr + 0x34));
    ASN1_OBJECT_free(*(ASN1_OBJECT **)((int)ptr + 0x2c));
    CRYPTO_free(ptr);
    return;
  }
  return;
}

