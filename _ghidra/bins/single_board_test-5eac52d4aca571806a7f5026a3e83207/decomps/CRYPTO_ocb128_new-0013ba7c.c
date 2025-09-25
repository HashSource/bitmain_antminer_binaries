
void * CRYPTO_ocb128_new(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5)

{
  void *ptr;
  int iVar1;
  
  ptr = CRYPTO_malloc(0x98,"crypto/modes/ocb128.c",0x89);
  if ((ptr != (void *)0x0) &&
     (iVar1 = CRYPTO_ocb128_init(ptr,param_1,param_2,param_3,param_4,param_5), iVar1 == 0)) {
    CRYPTO_free(ptr);
    ptr = (void *)0x0;
  }
  return ptr;
}

