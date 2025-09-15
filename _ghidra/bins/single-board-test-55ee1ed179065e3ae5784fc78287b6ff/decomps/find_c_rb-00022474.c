
undefined4 * find_c_rb(undefined4 *param_1,undefined4 param_2)

{
  void *local_14;
  int local_10;
  undefined4 *local_c;
  
  local_c = (undefined4 *)*param_1;
  while (param_1 + 1 != local_c) {
    local_10 = 0;
    get_raw_clib_object(local_c[4],&local_14);
    local_10 = (*(code *)param_1[9])(param_2,local_14);
    free(local_14);
    if (local_10 == 0) break;
    if (local_10 < 0) {
      local_c = (undefined4 *)*local_c;
    }
    else {
      local_c = (undefined4 *)local_c[1];
    }
  }
  if (param_1 + 1 == local_c) {
    local_c = (undefined4 *)0x0;
  }
  return local_c;
}

