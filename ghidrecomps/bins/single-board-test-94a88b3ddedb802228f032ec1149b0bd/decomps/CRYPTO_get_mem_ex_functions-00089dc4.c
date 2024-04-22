
void CRYPTO_get_mem_ex_functions(m **m,r **r,f **f)

{
  m *pmVar1;
  r *prVar2;
  
  if (m != (m **)0x0) {
    pmVar1 = *(m **)(DAT_00089df4 + 0x10);
    if (pmVar1 == DAT_00089df8) {
      pmVar1 = (m *)0x0;
    }
    *m = pmVar1;
  }
  if (r != (r **)0x0) {
    prVar2 = *(r **)(DAT_00089df4 + 0x14);
    if (prVar2 == DAT_00089dfc) {
      prVar2 = (r *)0x0;
    }
    *r = prVar2;
  }
  if (f != (f **)0x0) {
    *f = *(f **)(DAT_00089df4 + 0x18);
  }
  return;
}

