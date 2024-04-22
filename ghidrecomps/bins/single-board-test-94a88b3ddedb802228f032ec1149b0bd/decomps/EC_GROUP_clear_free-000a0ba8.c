
void EC_GROUP_clear_free(EC_GROUP *group)

{
  void **ptr;
  code *pcVar1;
  int *ptr_00;
  void *pvVar2;
  
  if (group != (EC_GROUP *)0x0) {
    pcVar1 = *(code **)(*(int *)group + 0x10);
    if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(*(int *)group + 0xc), pcVar1 != (code *)0x0)
       ) {
      (*pcVar1)();
    }
    ptr = (void **)*(void **)(group + 0x44);
    while (ptr != (void **)0x0) {
      pvVar2 = *ptr;
      (*(code *)ptr[4])(ptr[1]);
      CRYPTO_free(ptr);
      ptr = (void **)pvVar2;
    }
    *(undefined4 *)(group + 0x44) = 0;
    if ((*(int *)(group + 0x34) < 0) && (*(BN_MONT_CTX **)(group + 0xac) != (BN_MONT_CTX *)0x0)) {
      BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0xac));
    }
    ptr_00 = *(int **)(group + 4);
    if (ptr_00 != (int *)0x0) {
      pcVar1 = *(code **)(*ptr_00 + 0x30);
      if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(*ptr_00 + 0x2c), pcVar1 != (code *)0x0)) {
        (*pcVar1)(ptr_00);
      }
      OPENSSL_cleanse(ptr_00,0x44);
      CRYPTO_free(ptr_00);
    }
    BN_clear_free((BIGNUM *)(group + 8));
    BN_clear_free((BIGNUM *)(group + 0x1c));
    if (*(void **)(group + 0x3c) != (void *)0x0) {
      OPENSSL_cleanse(*(void **)(group + 0x3c),*(size_t *)(group + 0x40));
      CRYPTO_free(*(void **)(group + 0x3c));
    }
    OPENSSL_cleanse(group,0xb0);
    CRYPTO_free(group);
    return;
  }
  return;
}

