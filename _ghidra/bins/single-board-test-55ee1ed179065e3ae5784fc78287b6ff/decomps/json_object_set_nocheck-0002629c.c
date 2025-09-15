
undefined4 json_object_set_nocheck(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = json_incref(param_3);
  uVar1 = json_object_set_new_nocheck(param_1,param_2,uVar1);
  return uVar1;
}

