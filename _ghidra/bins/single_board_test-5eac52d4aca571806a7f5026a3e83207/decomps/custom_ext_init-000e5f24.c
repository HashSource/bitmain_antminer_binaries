
void custom_ext_init(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  if (iVar1 != 0) {
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      iVar2 = iVar2 + 0x24;
    } while (iVar3 != iVar1);
  }
  return;
}

