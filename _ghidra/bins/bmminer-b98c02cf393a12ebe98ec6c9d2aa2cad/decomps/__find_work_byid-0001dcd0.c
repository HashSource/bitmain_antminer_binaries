
int __find_work_byid(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x160), param_2 != *(int *)(param_1 + 0x154))) {
    do {
      iVar1 = iVar2;
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = *(int *)(iVar1 + 0x160);
    } while (*(int *)(iVar1 + 0x154) != param_2);
    return iVar1;
  }
  return param_1;
}

