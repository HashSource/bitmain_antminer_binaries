
int int_thread_get(int param_1)

{
  int iVar1;
  _LHASH *p_Var2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_000ac694;
  CRYPTO_lock(9,1,DAT_000ac698,0x1c4);
  iVar4 = *(int *)(iVar1 + 8);
  iVar3 = iVar4;
  if (iVar4 == 0) {
    if (param_1 == 0) goto LAB_000ac65a;
    CRYPTO_push_info_(DAT_000ac69c,DAT_000ac698,0x1c6);
    p_Var2 = lh_new(DAT_000ac6a4,DAT_000ac6a0);
    *(_LHASH **)(iVar1 + 8) = p_Var2;
    CRYPTO_pop_info();
    iVar3 = *(int *)(iVar1 + 8);
    if (iVar3 == 0) goto LAB_000ac65a;
  }
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  iVar4 = iVar3;
LAB_000ac65a:
  CRYPTO_lock(10,1,DAT_000ac698,0x1ce);
  return iVar4;
}

