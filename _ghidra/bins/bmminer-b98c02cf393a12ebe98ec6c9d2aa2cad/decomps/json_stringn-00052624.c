
undefined4 json_stringn(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = utf8_check_string();
  if (iVar1 != 0) {
    uVar2 = string_create(param_1,param_2,0,param_4);
    return uVar2;
  }
  return 0;
}

