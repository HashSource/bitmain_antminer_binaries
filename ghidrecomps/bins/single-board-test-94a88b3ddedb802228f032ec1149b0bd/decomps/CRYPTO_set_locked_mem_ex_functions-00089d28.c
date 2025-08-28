
int CRYPTO_set_locked_mem_ex_functions(m *m,free_func *free_func)

{
  int iVar1;
  
  iVar1 = allow_customize;
  if (allow_customize != 0) {
    if (m != (m *)0x0 && free_func != (free_func *)0x0) {
      malloc_locked_func = 0;
      malloc_locked_ex_func = m;
      ::free_func = free_func;
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

