
void * CRYPTO_remalloc(void *addr,int num,char *file,int line)

{
  void *pvVar1;
  
  if (addr != (void *)0x0) {
    if (free_debug_func != (code *)0x0) {
      (*free_debug_func)(addr,0);
    }
    (*free_func)(addr);
    if (free_debug_func != (code *)0x0) {
      (*free_debug_func)(0,1);
    }
  }
  pvVar1 = CRYPTO_malloc(num,"mem.c",0x1c3);
  return pvVar1;
}

