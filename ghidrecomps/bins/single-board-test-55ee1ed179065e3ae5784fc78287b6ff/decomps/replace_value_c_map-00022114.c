
void replace_value_c_map(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  int *local_c;
  
  local_c = *(int **)(param_1 + 0xc);
  if (*(int *)(*local_c + 0x20) != 0) {
    get_raw_clib_object(*(undefined4 *)(param_1 + 0x14),&local_10);
    (**(code **)(*local_c + 0x20))(local_10);
  }
  replace_raw_clib_object(*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14),param_2,param_3);
  return;
}

