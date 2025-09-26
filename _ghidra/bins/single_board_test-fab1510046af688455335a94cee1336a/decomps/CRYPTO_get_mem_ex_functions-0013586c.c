
void CRYPTO_get_mem_ex_functions(m **m,r **r,f **f)

{
  m *pmVar1;
  r *prVar2;
  
  if (m != (m **)0x0) {
    pmVar1 = malloc_ex_func;
    if (malloc_ex_func == (m *)0x1356ed) {
      pmVar1 = (m *)0x0;
    }
    *m = pmVar1;
  }
  if (r != (r **)0x0) {
    prVar2 = realloc_ex_func;
    if (realloc_ex_func == (r *)0x1356fd) {
      prVar2 = (r *)0x0;
    }
    *r = prVar2;
  }
  if (f != (f **)0x0) {
    *f = free_func;
  }
  return;
}

