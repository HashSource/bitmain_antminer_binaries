
void freq_tuning_pre_test(freq_tuning_info *freq_info)

{
  _Bool _Var1;
  FILE *pFVar2;
  freq_tuning_info *freq_info_local;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int max_balance_count;
  int try;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Pre-test: start.\n","freq_tuning.c",0x70e,"freq_tuning_pre_test");
    }
    fclose(pFVar2);
  }
  try = 0;
  do {
    if (2 < try) {
LAB_00018ccc:
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Pre-test: done.\n","freq_tuning.c",0x71f,"freq_tuning_pre_test")
          ;
        }
        fclose(pFVar2);
      }
      return;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Pre-test: times %d\n","freq_tuning.c",0x712,"freq_tuning_pre_test"
                ,try);
      }
      fclose(pFVar2);
    }
    _Var1 = freq_tuning_single_pre_test(freq_info);
    if (_Var1) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Pre-test: set to init freq %fM.\n","freq_tuning.c",0x715,
                  "freq_tuning_pre_test");
        }
        fclose(pFVar2);
      }
      set_pll(init_freq);
      goto LAB_00018ccc;
    }
    freq_tuning_single_pre_test_prepare();
    try = try + 1;
  } while( true );
}

