
int CRYPTO_set_locked_mem_ex_functions(m *m,free_func *free_func)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00089d4c;
  iVar2 = *(int *)(DAT_00089d4c + 0xc);
  if (iVar2 != 0) {
    if (m != (m *)0x0 && free_func != (free_func *)0x0) {
      *(undefined4 *)(DAT_00089d4c + 8) = 0;
      *(m **)(iVar1 + 0x1c) = m;
      *(free_func **)(iVar1 + 0x18) = free_func;
      return 1;
    }
    iVar2 = 0;
  }
  return iVar2;
}

