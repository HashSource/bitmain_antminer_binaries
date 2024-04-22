
undefined4 json_string_set(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (iVar1 = utf8_check_string(param_2,0xffffffff), iVar1 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = json_string_set_nocheck(param_1,param_2);
  }
  return uVar2;
}

