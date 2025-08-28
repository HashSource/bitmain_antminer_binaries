
void mstate(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != param_2) {
    *(int *)(param_1 + 0xc) = param_2;
    if (param_2 == 0x11) {
      iVar1 = *(int *)(param_1 + 0x40);
      param_3 = *(int *)(iVar1 + 0x10) + -1;
    }
    if (param_2 == 0x11) {
      *(int *)(iVar1 + 0x10) = param_3;
    }
    if (*(code **)(&finit_23424 + param_2 * 4) != (code *)0x0) {
      (**(code **)(&finit_23424 + param_2 * 4))();
    }
  }
  return;
}

