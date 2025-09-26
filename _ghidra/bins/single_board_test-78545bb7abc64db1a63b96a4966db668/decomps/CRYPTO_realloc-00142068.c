
void * CRYPTO_realloc(void *addr,int num,char *file,int line)

{
  void *pvVar1;
  
  if (realloc_impl != (code *)(undefined *)0x142069 && realloc_impl != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00142088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pvVar1 = (void *)(*realloc_impl)();
    return pvVar1;
  }
  if (addr != (void *)0x0) {
    if (num == 0) {
      CRYPTO_free(addr);
      return (void *)0x0;
    }
    pvVar1 = realloc(addr,num);
    return pvVar1;
  }
  pvVar1 = CRYPTO_malloc(num,file,line);
  return pvVar1;
}

