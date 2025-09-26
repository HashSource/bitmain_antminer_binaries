
int bread_conv(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 0) {
    param_3 = 0x7fffffff;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))
                    (param_1,param_2,param_3,*(code **)(*param_1 + 0x14),param_4);
  if (iVar1 < 1) {
    iVar2 = iVar1;
    iVar1 = 0;
  }
  else {
    iVar2 = 1;
  }
  *param_4 = iVar1;
  return iVar2;
}

