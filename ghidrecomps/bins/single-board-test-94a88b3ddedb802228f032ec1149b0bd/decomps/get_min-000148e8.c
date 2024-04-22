
int get_min(int *param_1,uint param_2)

{
  uint local_10;
  int local_c;
  
  local_c = *param_1;
  for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
    if (param_1[local_10] < local_c) {
      local_c = param_1[local_10];
    }
  }
  return local_c;
}

