
void pkey_dh_cleanup(int param_1)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x14);
  if (ptr != (void *)0x0) {
    if (*(void **)((int)ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x2c));
    }
    if (*(ASN1_OBJECT **)((int)ptr + 0x24) != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(*(ASN1_OBJECT **)((int)ptr + 0x24));
    }
    CRYPTO_free(ptr);
    return;
  }
  return;
}

