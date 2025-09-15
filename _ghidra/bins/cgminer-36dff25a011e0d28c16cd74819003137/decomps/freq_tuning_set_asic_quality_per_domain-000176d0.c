
void freq_tuning_set_asic_quality_per_domain(freq_tuning_info *freq_info,int chain)

{
  int *sum_00;
  FILE *__stream;
  int chain_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  int *sum;
  int asic;
  
  sum_00 = (int *)malloc(freq_info->asic_num_per_chain << 2);
  if (sum_00 != (int *)0x0) {
    freq_tuning_calc_sum_of_all_freq(freq_info,sum_00,chain);
    for (asic = 0; asic < freq_info->asic_num_per_chain;
        asic = asic + freq_info->asic_num_per_vol_domain) {
      freq_tuning_sort_array
                (sum_00 + asic,freq_info->asic_quality_per_vol_domain[chain] + asic,
                 freq_info->asic_num_per_vol_domain);
    }
    free(sum_00);
    return;
  }
  print_crt_time_to_file(log_file,1);
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"Assert fail!! %s:%d: Fail to alloc memory for asic quality.\n","freq_tuning.c"
            ,0x5c8);
  }
  fclose(__stream);
                    /* WARNING: Subroutine does not return */
  __assert_fail("sum","freq_tuning.c",0x5c8,"freq_tuning_set_asic_quality_per_domain");
}

