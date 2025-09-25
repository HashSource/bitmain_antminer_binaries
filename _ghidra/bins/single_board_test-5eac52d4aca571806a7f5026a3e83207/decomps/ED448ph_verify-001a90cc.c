
bool ED448ph_verify(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined1 param_5)

{
  int iVar1;
  
  iVar1 = c448_ed448_verify_prehash(param_2,param_3,param_1,param_4,param_5);
  return iVar1 == -1;
}

