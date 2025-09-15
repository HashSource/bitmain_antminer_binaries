
void set_asic_quality_per_domain(int *param_1,int param_2)

{
  void *__ptr;
  FILE *__stream;
  int local_c;
  
  __ptr = malloc(*param_1 << 2);
  if (__ptr != (void *)0x0) {
    calc_sum_of_all_freq(param_1,__ptr,param_2);
    for (local_c = 0; local_c < *param_1; local_c = param_1[1] + local_c) {
      sort_array((void *)((int)__ptr + local_c * 4),param_1 + local_c + param_2 * 0x100 + 0x15162,
                 param_1[1]);
    }
    free(__ptr);
    return;
  }
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"Assert fail!! %s:%d: malloc failed","board_frq_tuning.c",0x678);
  }
  fclose(__stream);
                    /* WARNING: Subroutine does not return */
  __assert_fail("sum != ((void *)0)","board_frq_tuning.c",0x678,"set_asic_quality_per_domain");
}

