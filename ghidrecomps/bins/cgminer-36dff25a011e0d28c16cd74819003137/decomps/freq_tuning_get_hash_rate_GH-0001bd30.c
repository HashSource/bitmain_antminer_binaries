
int freq_tuning_get_hash_rate_GH(freq_tuning_info *freq_info)

{
  int iVar1;
  FILE *__stream;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  int hash_rate;
  
  iVar1 = freq_tuning_get_hash_rate_MH(freq_info);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: hash rate = %d (GH)\n","freq_tuning.c",0xa4c,
              "freq_tuning_get_hash_rate_GH",iVar1 / 1000);
    }
    fclose(__stream);
  }
  return iVar1 / 1000;
}

