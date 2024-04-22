
void CRYPTO_get_mem_debug_functions(m **m,r **r,f **f,so **so,go **go)

{
  if (m != (m **)0x0) {
    *m = *DAT_00089e7c;
  }
  if (r != (r **)0x0) {
    *r = (r *)DAT_00089e7c[1];
  }
  if (f != (f **)0x0) {
    *f = (f *)DAT_00089e7c[2];
  }
  if (so != (so **)0x0) {
    *so = (so *)DAT_00089e7c[3];
  }
  if (go != (go **)0x0) {
    *go = (go *)DAT_00089e7c[4];
  }
  return;
}

