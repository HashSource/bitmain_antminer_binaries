
void EC_EX_DATA_free_all_data(void **param_1)

{
  void **ptr;
  void *pvVar1;
  
  if (param_1 == (void **)0x0) {
    return;
  }
  ptr = (void **)*param_1;
  while (ptr != (void **)0x0) {
    pvVar1 = *ptr;
    (*(code *)ptr[3])(ptr[1]);
    CRYPTO_free(ptr);
    ptr = (void **)pvVar1;
  }
  *param_1 = (void *)0x0;
  return;
}

