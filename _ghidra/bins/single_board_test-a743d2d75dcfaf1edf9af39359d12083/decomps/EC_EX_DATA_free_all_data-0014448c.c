
void EC_EX_DATA_free_all_data(undefined4 *param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  ptr = (undefined4 *)*param_1;
  while (ptr != (undefined4 *)0x0) {
    pvVar1 = (void *)*ptr;
    (*(code *)ptr[3])(ptr[1]);
    CRYPTO_free(ptr);
    ptr = (undefined4 *)pvVar1;
  }
  *param_1 = 0;
  return;
}

