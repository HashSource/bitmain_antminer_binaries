
int get_total_hash(int param_1)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
    local_c = *(int *)(param_1 + (local_10 + 0x16166) * 4) + local_c;
  }
  return local_c;
}

