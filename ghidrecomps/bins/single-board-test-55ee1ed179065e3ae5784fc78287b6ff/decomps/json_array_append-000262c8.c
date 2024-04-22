
undefined4 json_array_append(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = json_incref(param_2);
  uVar1 = json_array_append_new(param_1,uVar1);
  return uVar1;
}

