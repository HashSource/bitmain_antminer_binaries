
undefined4
insert_c_rb(void **param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  void *local_30;
  void *local_2c;
  void *local_28;
  void *local_24;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  void **local_10;
  void **local_c;
  
  local_14 = 0;
  local_18 = (undefined4 *)malloc(0x18);
  if (local_18 == (undefined4 *)0x0) {
    local_14 = 2;
  }
  else {
    *local_18 = param_1 + 1;
    local_18[1] = param_1 + 1;
    local_18[3] = 1;
    uVar1 = new_clib_object(param_2,param_3);
    *(undefined4 *)((int)local_18 + 0x10) = uVar1;
    if (param_4 == 0) {
      *(undefined4 *)((int)local_18 + 0x14) = 0;
    }
    else {
      uVar1 = new_clib_object(param_4,param_5);
      *(undefined4 *)((int)local_18 + 0x14) = uVar1;
    }
    local_c = (void **)*param_1;
    local_10 = (void **)0x0;
    while (param_1 + 1 != local_c) {
      local_1c = 0;
      get_raw_clib_object(local_c[4],&local_24);
      get_raw_clib_object(*(undefined4 *)((int)local_18 + 0x10),&local_28);
      local_1c = (*(code *)param_1[9])(local_28,local_24);
      free(local_24);
      free(local_28);
      if (local_1c == 0) {
        return 0x191;
      }
      local_10 = local_c;
      if (local_1c < 0) {
        local_c = (void **)*local_c;
      }
      else {
        local_c = (void **)local_c[1];
      }
    }
    *(void ***)((int)local_18 + 8) = local_10;
    if (local_10 == (void **)0x0) {
      *param_1 = local_18;
    }
    else {
      local_20 = 0;
      get_raw_clib_object(local_10[4],&local_2c);
      get_raw_clib_object(*(undefined4 *)((int)local_18 + 0x10),&local_30);
      local_20 = (*(code *)param_1[9])(local_30,local_2c);
      free(local_2c);
      free(local_30);
      if (local_20 < 0) {
        *local_10 = local_18;
      }
      else {
        local_10[1] = local_18;
      }
    }
    __rb_insert_fixup(param_1,local_18);
    debug_verify_properties(param_1);
  }
  return local_14;
}

