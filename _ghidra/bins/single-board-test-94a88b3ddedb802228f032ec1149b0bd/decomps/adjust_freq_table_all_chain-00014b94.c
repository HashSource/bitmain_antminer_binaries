
void adjust_freq_table_all_chain(undefined4 param_1)

{
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      adjust_freq_table(local_c,param_1);
    }
  }
  return;
}

