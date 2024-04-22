
int CRYPTO_set_mem_ex_functions(m *m,r *r,f *f)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_00089cf8;
  iVar2 = DAT_00089cf8[3];
  if (iVar2 != 0) {
    if (m == (m *)0x0 || r == (r *)0x0) {
      iVar2 = 0;
    }
    else if (f == (f *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
      *DAT_00089cf8 = 0;
      puVar1[4] = m;
      puVar1[1] = 0;
      puVar1[5] = r;
      puVar1[6] = f;
      puVar1[2] = 0;
      puVar1[7] = m;
      puVar1[8] = f;
    }
  }
  return iVar2;
}

