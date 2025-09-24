
void * CRYPTO_memdup(void *param_1,size_t param_2,char *param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 != (void *)0x0 && param_2 < 0x7fffffff) {
    pvVar1 = CRYPTO_malloc(param_2,param_3,param_4);
    if (pvVar1 != (void *)0x0) {
      pvVar1 = memcpy(pvVar1,param_1,param_2);
      return pvVar1;
    }
    ERR_put_error(0xf,0x73,0x41,"crypto/o_str.c",0x42);
  }
  return (void *)0x0;
}

