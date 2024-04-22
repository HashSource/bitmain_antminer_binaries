
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int OBJ_NAME_init(void)

{
  _LHASH *p_Var1;
  int iVar2;
  
  iVar2 = DAT_0008bb80;
  if (*(int *)(DAT_0008bb80 + 8) != 0) {
    return 1;
  }
  CRYPTO_mem_ctrl(3);
  p_Var1 = lh_new(DAT_0008bb88,DAT_0008bb84);
  *(_LHASH **)(iVar2 + 8) = p_Var1;
  CRYPTO_mem_ctrl(2);
  iVar2 = *(int *)(iVar2 + 8);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

