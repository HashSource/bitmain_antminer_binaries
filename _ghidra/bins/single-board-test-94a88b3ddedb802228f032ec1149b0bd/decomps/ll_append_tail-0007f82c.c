
void ll_append_tail(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (*param_3 != param_2) {
    if (*param_1 == param_2) {
      *param_1 = *(int *)(param_2 + 0xc);
    }
    iVar1 = *(int *)(param_2 + 0x10);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    }
    if (*(int *)(param_2 + 0xc) != 0) {
      *(int *)(*(int *)(param_2 + 0xc) + 0x10) = iVar1;
    }
    *(int *)(*param_3 + 0xc) = param_2;
    iVar1 = *param_3;
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(int *)(param_2 + 0x10) = iVar1;
    *param_3 = param_2;
  }
  return;
}

