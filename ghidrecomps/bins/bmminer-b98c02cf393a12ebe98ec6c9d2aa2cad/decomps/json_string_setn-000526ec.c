
undefined4 json_string_setn(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = utf8_check_string(param_2,param_3);
  if (iVar1 != 0) {
    uVar2 = json_string_setn_nocheck(param_1,param_2,param_3);
    return uVar2;
  }
  return 0xffffffff;
}

