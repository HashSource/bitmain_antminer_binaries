
void dupcounters(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x14);
    *param_2 = *(undefined4 *)(iVar1 + 0x10);
    param_2[1] = uVar2;
    uVar2 = *(undefined4 *)(iVar1 + 0x1c);
    *param_3 = *(undefined4 *)(iVar1 + 0x18);
    param_3[1] = uVar2;
    return;
  }
  *param_2 = 0;
  param_2[1] = 0;
  *param_3 = 0;
  param_3[1] = 0;
  return;
}

