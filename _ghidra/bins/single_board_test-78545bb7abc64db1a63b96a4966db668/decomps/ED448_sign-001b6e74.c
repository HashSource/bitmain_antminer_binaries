
bool ED448_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = c448_ed448_sign(param_1,param_5,param_4,param_2,param_3,0,param_6,param_7);
  return iVar1 == -1;
}

