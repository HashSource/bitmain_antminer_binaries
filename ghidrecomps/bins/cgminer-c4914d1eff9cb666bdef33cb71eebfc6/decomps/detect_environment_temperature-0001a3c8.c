
/* WARNING: Unknown calling convention */

void detect_environment_temperature(void)

{
  FILE *pFVar1;
  uint uVar2;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  char max_test_times;
  char waiting_time;
  char test_index;
  
  test_index = '\0';
  env_temperature = 1000;
  read_temp_and_get_statistics();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    test_index = pFVar1 != (FILE *)0x0;
    if ((bool)test_index) {
      fprintf(pFVar1,"%s:%d:%s: test[%d] environment temperature: %d\n","temperature.c",0x79e,
              "detect_environment_temperature",0,last_testpatten_lowest_pcb_temp);
    }
    fclose(pFVar1);
  }
  if (last_testpatten_lowest_pcb_temp < env_temperature) {
    env_temperature = last_testpatten_lowest_pcb_temp;
  }
  do {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Enter %d secs to cool down hash board...\n","temperature.c",0x7a5,
                "detect_environment_temperature",10);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: waiting..........\n","temperature.c",0x7a6,
                "detect_environment_temperature");
      }
      fclose(pFVar1);
    }
    sleep(10);
    read_temp_and_get_statistics();
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        uVar2 = (uint)(byte)test_index;
        test_index = test_index + '\x01';
        fprintf(pFVar1,"%s:%d:%s: test[%d] environment temperature: %d\n","temperature.c",0x7a9,
                "detect_environment_temperature",uVar2,last_testpatten_lowest_pcb_temp);
      }
      fclose(pFVar1);
    }
    if (last_testpatten_lowest_pcb_temp < env_temperature) {
      env_temperature = last_testpatten_lowest_pcb_temp;
    }
  } while ((byte)test_index < 3);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: environment temperature : [%d]\n","temperature.c",0x7af,
              "detect_environment_temperature",env_temperature);
    }
    fclose(pFVar1);
  }
  return;
}

