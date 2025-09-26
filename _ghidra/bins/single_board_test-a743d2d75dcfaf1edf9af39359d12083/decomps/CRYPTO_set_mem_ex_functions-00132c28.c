
int CRYPTO_set_mem_ex_functions(m *m,r *r,f *f)

{
  int iVar1;
  
  iVar1 = allow_customize;
  if (allow_customize != 0) {
    if (m == (m *)0x0 || r == (r *)0x0) {
      iVar1 = 0;
    }
    else if (f == (f *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
      malloc_func = 0;
      realloc_func = 0;
      malloc_locked_func = 0;
      malloc_ex_func = m;
      realloc_ex_func = r;
      free_func = f;
      malloc_locked_ex_func = m;
      free_locked_func = f;
    }
  }
  return iVar1;
}

