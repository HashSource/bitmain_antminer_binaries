
undefined4 isDisabledChipCore(int param_1,uint param_2,uint param_3)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (*(int *)(disabled_cores_num + param_1 * 4) <= local_c) {
      return 0;
    }
    if (((byte)disabled_cores_pos[(local_c + param_1 * 8) * 2] == param_2) &&
       ((byte)disabled_cores_pos[(local_c + param_1 * 8) * 2 + 1] == param_3)) break;
    local_c = local_c + 1;
  }
  return 1;
}

