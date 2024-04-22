
int CRYPTO_set_locked_mem_functions(m *m,free_func *free_func)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r4;
  bool bVar5;
  
  iVar3 = DAT_00089d20;
  uVar4 = *(uint *)(DAT_00089d20 + 0xc);
  if (uVar4 != 0) {
    bVar5 = m != (m *)0x0;
    bVar1 = free_func != (free_func *)0x0;
    uVar2 = DAT_00089d24;
    if (!bVar5 || !bVar1) {
      uVar2 = unaff_r4;
    }
    uVar4 = (uint)(bVar5 && bVar1);
    if (bVar5 && bVar1) {
      *(m **)(DAT_00089d20 + 8) = m;
    }
    if (bVar5 && bVar1) {
      *(free_func **)(iVar3 + 0x20) = free_func;
    }
    if (bVar5 && bVar1) {
      *(undefined4 *)(iVar3 + 0x1c) = uVar2;
    }
  }
  return uVar4;
}

