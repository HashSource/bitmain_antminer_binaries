
/* WARNING: Unknown calling convention */

void killall_hashboard(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint uVar3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int i;
  
  status_error = true;
  once_error = true;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (_Var1 = is_hashboard_dead(), !_Var1)) {
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,
                  "%s:%d:%s: ****power off hashboard-->*Fatal error reached the threshold: %d\n",
                  "temperature.c",0x3f7,"killall_hashboard",status_value);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: ****bad_tmp_cnt: %d\n","temperature.c",0x3f8,"killall_hashboard"
                  ,dev->temp_bad_count);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: ****Good temp: %d\n","temperature.c",0x3f9,"killall_hashboard",
                  dev->temp_air_out_good_count);
        }
        fclose(pFVar2);
      }
      hashboard_power_off((uint8_t)i);
    }
  }
  fatal_error_counter = 0xdead;
  uVar3 = get_dhash_acc_control();
  set_dhash_acc_control(uVar3 & 0xffffffbf);
  return;
}

