
void * CRYPTO_zalloc(size_t param_1,char *param_2,int param_3)

{
  void *__s;
  
  __s = CRYPTO_malloc(param_1,param_2,param_3);
  if (__s != (void *)0x0) {
    memset(__s,0,param_1);
  }
  return __s;
}

