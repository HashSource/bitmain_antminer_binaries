
void CRYPTO_get_locked_mem_functions(m **m,f **f)

{
  m *pmVar1;
  
  if (m != (m **)0x0) {
    pmVar1 = malloc_locked_func;
    if (malloc_locked_ex_func != 0x132bcd) {
      pmVar1 = (m *)0x0;
    }
    *m = pmVar1;
  }
  if (f != (f **)0x0) {
    *f = free_locked_func;
  }
  return;
}

