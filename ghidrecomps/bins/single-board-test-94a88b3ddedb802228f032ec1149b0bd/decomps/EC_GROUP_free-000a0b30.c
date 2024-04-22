
void EC_GROUP_free(EC_GROUP *group)

{
  void **ptr;
  int *ptr_00;
  void *pvVar1;
  
  if (group == (EC_GROUP *)0x0) {
    return;
  }
  if (*(code **)(*(int *)group + 0xc) != (code *)0x0) {
    (**(code **)(*(int *)group + 0xc))();
  }
  ptr = (void **)*(void **)(group + 0x44);
  while (ptr != (void **)0x0) {
    pvVar1 = *ptr;
    (*(code *)ptr[3])(ptr[1]);
    CRYPTO_free(ptr);
    ptr = (void **)pvVar1;
  }
  *(undefined4 *)(group + 0x44) = 0;
  if ((*(int *)(group + 0x34) < 0) && (*(BN_MONT_CTX **)(group + 0xac) != (BN_MONT_CTX *)0x0)) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0xac));
  }
  ptr_00 = *(int **)(group + 4);
  if (ptr_00 != (int *)0x0) {
    if (*(code **)(*ptr_00 + 0x2c) != (code *)0x0) {
      (**(code **)(*ptr_00 + 0x2c))(ptr_00);
    }
    CRYPTO_free(ptr_00);
  }
  BN_free((BIGNUM *)(group + 8));
  BN_free((BIGNUM *)(group + 0x1c));
  if (*(void **)(group + 0x3c) != (void *)0x0) {
    CRYPTO_free(*(void **)(group + 0x3c));
  }
  CRYPTO_free(group);
  return;
}

