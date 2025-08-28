
void * CRYPTO_realloc(void *addr,int num,char *file,int line)

{
  void *pvVar1;
  
  if (addr != (void *)0x0) {
    if (num < 1) {
      pvVar1 = (void *)0x0;
    }
    else {
      if (realloc_debug_func != (code *)0x0) {
        (*realloc_debug_func)(addr,0,num,file,line,0);
      }
      pvVar1 = (void *)(*realloc_ex_func)(addr,num,file,line);
      if (realloc_debug_func != (code *)0x0) {
        (*realloc_debug_func)(addr,pvVar1,num,file,line,1);
      }
    }
    return pvVar1;
  }
  pvVar1 = CRYPTO_malloc(num,file,line);
  return pvVar1;
}

