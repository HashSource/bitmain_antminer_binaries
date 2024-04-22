
undefined4 delete_c_map(undefined4 *param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 != (undefined4 *)0x0) {
    local_c = delete_c_rb(*param_1);
    free(param_1);
  }
  return local_c;
}

