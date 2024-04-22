
void * def_create(int param_1)

{
  void *ptr;
  int iVar1;
  
  ptr = CRYPTO_malloc(0x10,DAT_0010da44,0x85);
  if ((ptr != (void *)0x0) && (iVar1 = (**(code **)(param_1 + 8))(), iVar1 == 0)) {
    CRYPTO_free(ptr);
    ptr = (void *)0x0;
  }
  return ptr;
}

