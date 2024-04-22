
void sort_array(int param_1,int param_2,uint param_3)

{
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    *(undefined4 *)(local_c * 4 + param_2) = 0;
  }
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    local_14 = 0;
    local_18 = 0;
    for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
      if ((*(int *)(local_10 * 4 + param_2) == 0) && (local_14 < *(int *)(local_10 * 4 + param_1)))
      {
        local_14 = *(int *)(local_10 * 4 + param_1);
        local_18 = local_10;
      }
    }
    *(uint *)(local_18 * 4 + param_2) = local_c + 1;
  }
  return;
}

