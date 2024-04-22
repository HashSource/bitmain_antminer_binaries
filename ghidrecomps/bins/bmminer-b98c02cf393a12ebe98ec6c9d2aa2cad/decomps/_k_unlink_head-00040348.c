
int _k_unlink_head(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == 0) {
    if (*(char *)(param_1 + 4) != '\0') {
      return 0;
    }
    k_alloc_items();
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar2 + 8);
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x2c) != '\0') {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  else {
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(int *)(param_1 + 0x1c) = iVar1 + -1;
  return iVar2;
}

