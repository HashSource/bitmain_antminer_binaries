
void CRYPTO_get_locked_mem_ex_functions(m **m,f **f)

{
  m *pmVar1;
  
  if (m != (m **)0x0) {
    pmVar1 = *(m **)(DAT_00089e44 + 0x1c);
    if (pmVar1 == DAT_00089e48) {
      pmVar1 = (m *)0x0;
    }
    *m = pmVar1;
  }
  if (f != (f **)0x0) {
    *f = *(f **)(DAT_00089e44 + 0x20);
  }
  return;
}

