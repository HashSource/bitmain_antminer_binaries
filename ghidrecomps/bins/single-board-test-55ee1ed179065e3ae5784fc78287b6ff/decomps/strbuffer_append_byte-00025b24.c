
undefined4 strbuffer_append_byte(undefined4 param_1,undefined param_2)

{
  undefined4 uVar1;
  undefined local_d;
  undefined4 local_c;
  
  local_d = param_2;
  local_c = param_1;
  uVar1 = strbuffer_append_bytes(param_1,&local_d,1);
  return uVar1;
}

