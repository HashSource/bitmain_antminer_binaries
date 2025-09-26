
void ll_append_head(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (*param_1 != param_2) {
    if (*param_3 == param_2) {
      *param_3 = *(int *)(param_2 + 0x10);
    }
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      *(int *)(*(int *)(param_2 + 0x10) + 0xc) = iVar1;
    }
    *(int *)(*param_1 + 0x10) = param_2;
    iVar1 = *param_1;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(int *)(param_2 + 0xc) = iVar1;
    *param_1 = param_2;
  }
  return;
}

