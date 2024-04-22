
void calc_sum_of_all_freq(int *param_1,int param_2,int param_3)

{
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
    *(undefined4 *)(local_c * 4 + param_2) = 0;
    for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
      *(int *)(param_2 + local_c * 4) =
           param_1[local_c + (param_3 * 0x14 + local_10) * 0x100 + 0x1002] +
           *(int *)(local_c * 4 + param_2);
    }
  }
  return;
}

