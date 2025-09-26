
bool ED448ph_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = c448_ed448_sign_prehash(param_1,param_4,param_3,param_2,param_5,param_6);
  return iVar1 == -1;
}

