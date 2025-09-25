
bool ED448_verify(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6)

{
  int iVar1;
  
  iVar1 = c448_ed448_verify(param_3,param_4,param_1,param_2,0,param_5,param_6);
  return iVar1 == -1;
}

