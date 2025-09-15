
undefined4 json_object_set_new(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (iVar1 = utf8_check_string(param_2,0xffffffff), iVar1 == 0)) {
    json_decref(param_3);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = json_object_set_new_nocheck(param_1,param_2,param_3);
  }
  return uVar2;
}

