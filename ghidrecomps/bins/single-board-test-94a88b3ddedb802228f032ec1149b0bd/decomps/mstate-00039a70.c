
void mstate(int param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  
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
    pcVar2 = *(code **)(DAT_00039a94 + param_2 * 4);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)();
    }
  }
  return;
}

