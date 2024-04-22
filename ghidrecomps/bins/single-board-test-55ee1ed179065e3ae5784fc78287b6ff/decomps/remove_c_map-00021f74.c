
undefined4 remove_c_map(undefined4 *param_1,undefined4 param_2)

{
  void *local_14;
  void *local_10;
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == (undefined4 *)0x0) {
    local_c = 0x1f5;
  }
  else {
    local_10 = (void *)remove_c_rb(*param_1,param_2);
    if (local_10 != (void *)0x0) {
      get_raw_clib_object(*(undefined4 *)((int)local_10 + 0x10),&local_14);
      free(local_14);
      delete_clib_object(*(undefined4 *)((int)local_10 + 0x10));
      get_raw_clib_object(*(undefined4 *)((int)local_10 + 0x14),&local_14);
      free(local_14);
      delete_clib_object(*(undefined4 *)((int)local_10 + 0x14));
      free(local_10);
    }
  }
  return local_c;
}

