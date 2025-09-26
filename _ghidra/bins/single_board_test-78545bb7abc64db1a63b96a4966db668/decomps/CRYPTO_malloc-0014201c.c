
void * CRYPTO_malloc(int num,char *file,int line)

{
  void *pvVar1;
  
  if (malloc_impl != (code *)0x0 && malloc_impl != (code *)(undefined *)0x14201d) {
                    /* WARNING: Could not recover jumptable at 0x0014203c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pvVar1 = (void *)(*malloc_impl)();
    return pvVar1;
  }
  if (num != 0) {
    if (allow_customize != 0) {
      allow_customize = 0;
    }
    pvVar1 = (void *)(*(code *)(undefined *)0x0)(num);
    return pvVar1;
  }
  return (void *)0x0;
}

