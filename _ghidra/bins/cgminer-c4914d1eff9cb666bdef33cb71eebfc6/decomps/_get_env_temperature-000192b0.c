
/* WARNING: Unknown calling convention */

float _get_env_temperature(void)

{
  int iVar1;
  float local_temp;
  FILE *pFile;
  int try_count;
  float sum;
  int good_temp_count;
  int i;
  
  try_count = 5;
  good_temp_count = 0;
  sum = 0.0;
  for (i = 0; i < try_count; i = i + 1) {
    iVar1 = _temp_get_local_temp(&local_temp);
    if (iVar1 == 0) {
      sum = sum + local_temp;
      good_temp_count = good_temp_count + 1;
    }
    else if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFile = (FILE *)fopen(log_file,"a+");
      if (pFile != (FILE *)0x0) {
        fprintf((FILE *)pFile,"%s:%d:%s: Get too many bad air in temperature.\n","temperature.c",
                0x55f,"_get_env_temperature");
      }
      fclose((FILE *)pFile);
    }
    cgsleep_ms(0x14);
  }
  if (good_temp_count != 0) {
    _get_env_temperature::env_temp = sum / (float)(longlong)good_temp_count;
  }
  return _get_env_temperature::env_temp;
}

