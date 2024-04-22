
undefined4 json_string_copy(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = json_string_value(param_1);
  uVar1 = json_string_nocheck(uVar1);
  return uVar1;
}

