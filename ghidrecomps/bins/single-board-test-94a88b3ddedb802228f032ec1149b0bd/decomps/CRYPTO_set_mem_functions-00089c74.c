
int CRYPTO_set_mem_functions(m *m,r *r,f *f)

{
  m **ppmVar1;
  m *pmVar2;
  m *pmVar3;
  m *pmVar4;
  
  OPENSSL_init();
  pmVar4 = DAT_00089cbc;
  pmVar3 = DAT_00089cb8;
  pmVar2 = DAT_00089cb4;
  ppmVar1 = DAT_00089cb0;
  if (((DAT_00089cb0[3] != (m *)0x0) && (m != (m *)0x0 && r != (r *)0x0)) && (f != (f *)0x0)) {
    *DAT_00089cb0 = m;
    ppmVar1[1] = (m *)r;
    ppmVar1[6] = (m *)f;
    ppmVar1[2] = m;
    ppmVar1[8] = (m *)f;
    ppmVar1[4] = pmVar2;
    ppmVar1[5] = pmVar3;
    ppmVar1[7] = pmVar4;
    return 1;
  }
  return 0;
}

