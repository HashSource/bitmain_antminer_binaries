
void adjust_freq_table(int param_1,size_t *param_2)

{
  void *__s;
  FILE *__stream;
  int local_c;
  
  __s = malloc(*param_2);
  if (__s != (void *)0x0) {
    memset(__s,0,*param_2);
    for (local_c = 0; local_c < (int)param_2[1]; local_c = local_c + 1) {
      adjust_freq_table_with_flag_table(param_2 + param_1 * 0x100 + 2,__s,*param_2,param_2[1]);
    }
    free(__s);
    return;
  }
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"Assert fail!! %s:%d: malloc fail!\n","board_frq_tuning.c",0x34a);
  }
  fclose(__stream);
                    /* WARNING: Subroutine does not return */
  __assert_fail("flag_table != ((void *)0)","board_frq_tuning.c",0x34a,"adjust_freq_table");
}

