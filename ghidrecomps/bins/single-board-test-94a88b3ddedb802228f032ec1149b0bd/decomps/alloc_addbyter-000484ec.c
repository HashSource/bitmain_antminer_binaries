
uint alloc_addbyter(byte param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    iVar1 = (**DAT_00048548)(0x20);
    *param_2 = iVar1;
    if (iVar1 == 0) {
LAB_0004853a:
      param_2[3] = 1;
      return 0xffffffff;
    }
    iVar2 = 0;
    param_2[2] = 0x20;
    param_2[1] = 0;
  }
  else {
    iVar2 = param_2[1];
    if ((uint)param_2[2] <= iVar2 + 1U) {
      iVar1 = (**DAT_00048544)(iVar1,param_2[2] << 1,iVar2 + 1U,*DAT_00048544,param_4);
      if (iVar1 == 0) goto LAB_0004853a;
      iVar2 = param_2[1];
      *param_2 = iVar1;
      param_2[2] = param_2[2] << 1;
    }
  }
  *(byte *)(iVar1 + iVar2) = param_1;
  param_2[1] = param_2[1] + 1;
  return (uint)param_1;
}

