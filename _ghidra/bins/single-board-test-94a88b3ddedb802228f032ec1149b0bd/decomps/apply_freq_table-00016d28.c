
void apply_freq_table(int *param_1)

{
  FILE *__stream;
  uint local_10;
  uint local_c;
  
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set_vol_and_frq_all_chain enter\n","board_frq_tuning.c",0x5c4);
    }
    fclose(__stream);
  }
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      set_pic_voltage(local_c & 0xff,param_1[local_c + 0x15002] & 0xff);
      for (local_10 = 0; (int)local_10 < *param_1; local_10 = local_10 + 1) {
        set_frequency_with_addr_plldatai
                  (param_1[local_10 + local_c * 0x100 + 2],0,(local_10 & 0x7f) << 1,local_c & 0xff);
      }
    }
  }
  return;
}

