
void print_OpenCoreDetails(int param_1,int param_2,int param_3)

{
  FILE *__stream;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
      if ((*(int *)(asic_core_nonce_num + (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4) !=
           param_2 / 0x72) && (3 < log_level)) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: chain[%d] asic[%d] core[%d] get %d nonce < 8 !\n",
                  "driver-bitmain.c",0x124e,param_1,local_c,local_10,
                  *(undefined4 *)
                   (asic_core_nonce_num + (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4));
        }
        fclose(__stream);
      }
    }
  }
  return;
}

