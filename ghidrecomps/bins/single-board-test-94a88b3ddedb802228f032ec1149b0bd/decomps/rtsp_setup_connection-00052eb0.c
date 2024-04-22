
undefined4 rtsp_setup_connection(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = (**DAT_00052ecc)(1,0x68);
  *(int *)(iVar3 + 0x14c) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x1b;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

