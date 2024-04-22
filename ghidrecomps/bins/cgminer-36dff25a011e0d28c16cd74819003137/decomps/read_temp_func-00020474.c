
/* WARNING: Unknown calling convention */

void * read_temp_func(void)

{
  bool bVar1;
  FILE *pFVar2;
  uint uVar3;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint32_t counter;
  _Bool is_bringup_temp_collected;
  
  fatal_error_counter = 0;
  bVar1 = false;
  counter = 0;
  if ((config_parameter._4_1_ & 2) == 0) {
    dev->fan_pwm = 'F';
  }
  do {
    counter = counter + 1;
    if (counter % 10 == 0) {
      copy_log_to_latest(temp_log);
      clear_log(temp_log);
    }
    pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
    temp_get_local_and_remote_temp();
    temp_get_statistics();
    last_testpatten_lowest_pcb_temp = dev->temp_low1[0];
    last_testpatten_highest_pcb_temp = dev->temp_top1[0];
    if ((!bVar1) && (last_testpatten_lowest_pcb_temp != 0)) {
      bVar1 = true;
      bring_up_pcb_temp = last_testpatten_lowest_pcb_temp;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: bring_up_pcb_temp = %d\n","temperature.c",0x36c,"read_temp_func"
                  ,bring_up_pcb_temp);
        }
        fclose(pFVar2);
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: lowest temp = %d, highest temp = %d \n","temperature.c",0x36f,
                "read_temp_func",last_testpatten_lowest_pcb_temp,last_testpatten_highest_pcb_temp);
      }
      fclose(pFVar2);
    }
    check_fan();
    set_pwm_by_temp();
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: fan map is 0x%08x, num = %d\n","temperature.c",0x376,
                "read_temp_func",dev->fan_exist_map,(uint)dev->fan_num);
      }
      fclose(pFVar2);
    }
    check_error_protect();
    pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: read_temp_func Done!\n","temperature.c",0x37c,"read_temp_func");
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        uVar3 = get_crc_count();
        fprintf(pFVar2,"%s:%d:%s: CRC error counter=%d\n","temperature.c",0x37e,"read_temp_func",
                uVar3);
      }
      fclose(pFVar2);
    }
    sleep(10);
  } while( true );
}

