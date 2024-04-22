
/* WARNING: Unknown calling convention */

float temp_get_environment_temp(void)

{
  int iVar1;
  float local_temp;
  FILE *pFile;
  int try_count;
  float env_temp;
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
    else if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile = (FILE *)fopen(log_file,"a+");
      if (pFile != (FILE *)0x0) {
        fprintf((FILE *)pFile,"%s:%d:%s: Get too many bad air in tempture.\n","temperature.c",0x467,
                "temp_get_environment_temp");
      }
      fclose((FILE *)pFile);
    }
  }
  if (good_temp_count == 0) {
    env_temp = 80.0;
  }
  else {
    env_temp = sum / (float)(longlong)good_temp_count;
  }
  return env_temp;
}

