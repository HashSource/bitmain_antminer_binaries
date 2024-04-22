
undefined4 json_string(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (iVar1 = utf8_check_string(param_1,0xffffffff), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = json_string_nocheck(param_1);
  }
  return uVar2;
}

