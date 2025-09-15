
void hashtable_iter_set(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != -1) {
      iVar2 = *(int *)(iVar1 + 4) + -1;
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 == 0) {
        json_delete();
        *(undefined4 *)(param_1 + 0xc) = param_2;
        return;
      }
    }
  }
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

