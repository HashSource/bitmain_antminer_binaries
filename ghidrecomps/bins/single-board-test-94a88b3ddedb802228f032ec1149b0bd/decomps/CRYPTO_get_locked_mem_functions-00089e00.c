
void CRYPTO_get_locked_mem_functions(m **m,f **f)

{
  m *pmVar1;
  
  if (m != (m **)0x0) {
    if (*(int *)(DAT_00089e20 + 0x1c) == DAT_00089e24) {
      pmVar1 = *(m **)(DAT_00089e20 + 8);
    }
    else {
      pmVar1 = (m *)0x0;
    }
    *m = pmVar1;
  }
  if (f != (f **)0x0) {
    *f = *(f **)(DAT_00089e20 + 0x20);
  }
  return;
}

