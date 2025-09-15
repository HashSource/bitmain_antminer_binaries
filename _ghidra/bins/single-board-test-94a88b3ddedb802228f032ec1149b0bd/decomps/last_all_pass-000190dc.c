
undefined4 last_all_pass(int param_1)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x53 < local_c) {
      return 1;
    }
    if (*(int *)(last_result + (local_c + param_1 * 0x100) * 4) == 0) break;
    local_c = local_c + 1;
  }
  return 0;
}

