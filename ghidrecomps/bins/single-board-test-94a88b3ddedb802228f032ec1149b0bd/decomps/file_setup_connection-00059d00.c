
undefined4
file_setup_connection(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  uVar1 = (**DAT_00059d24)(1,0xc,param_3,*DAT_00059d24,param_4);
  iVar2 = *param_1;
  *(undefined4 *)(iVar3 + 0x14c) = uVar1;
  if (*(int *)(iVar2 + 0x14c) == 0) {
    uVar1 = 0x1b;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

