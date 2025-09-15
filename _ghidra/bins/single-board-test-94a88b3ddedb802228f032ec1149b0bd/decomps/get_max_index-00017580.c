
uint get_max_index(int *param_1,uint param_2)

{
  uint local_14;
  uint local_10;
  int local_c;
  
  local_c = *param_1;
  local_10 = 0;
  for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
    if (local_c < param_1[local_14]) {
      local_c = param_1[local_14];
      local_10 = local_14;
    }
  }
  return local_10;
}

