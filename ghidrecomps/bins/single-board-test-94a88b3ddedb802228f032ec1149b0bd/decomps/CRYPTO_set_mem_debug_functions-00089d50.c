
int CRYPTO_set_mem_debug_functions(m *m,r *r,f *f,so *so,go *go)

{
  m **ppmVar1;
  
  if (*(int *)(DAT_00089d7c + 0x24) == 0) {
    return 0;
  }
  OPENSSL_init();
  ppmVar1 = DAT_00089d80;
  *DAT_00089d80 = m;
  ppmVar1[1] = (m *)r;
  ppmVar1[2] = (m *)f;
  ppmVar1[3] = (m *)so;
  ppmVar1[4] = (m *)go;
  return 1;
}

