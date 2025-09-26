
int CRYPTO_set_locked_mem_functions(m *m,free_func *free_func)

{
  int iVar1;
  
  iVar1 = allow_customize;
  if (allow_customize != 0) {
    if (m == (m *)0x0 || free_func == (free_func *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
      malloc_locked_ex_func = 0x132bcd;
      malloc_locked_func = m;
      free_locked_func = free_func;
    }
  }
  return iVar1;
}

