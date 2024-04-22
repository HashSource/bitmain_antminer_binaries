
void CRYPTO_get_mem_functions(m **m,r **r,f **f)

{
  m *pmVar1;
  r *prVar2;
  
  if (m != (m **)0x0) {
    if (DAT_00089db8[4] == DAT_00089dbc) {
      pmVar1 = *DAT_00089db8;
    }
    else {
      pmVar1 = (m *)0x0;
    }
    *m = pmVar1;
  }
  if (r != (r **)0x0) {
    if (DAT_00089db8[5] == DAT_00089dc0) {
      prVar2 = (r *)DAT_00089db8[1];
    }
    else {
      prVar2 = (r *)0x0;
    }
    *r = prVar2;
  }
  if (f != (f **)0x0) {
    *f = (f *)DAT_00089db8[6];
  }
  return;
}

