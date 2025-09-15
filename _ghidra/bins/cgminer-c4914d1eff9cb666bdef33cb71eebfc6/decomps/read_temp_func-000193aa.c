
/* WARNING: Unknown calling convention */

void * read_temp_func(void)

{
  bool bVar1;
  _Bool _Var2;
  int iVar3;
  FILE *pFVar4;
  uint uVar5;
  __pthread_unwind_buf_t __cancel_buf;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int __not_first_call;
  void *__cancel_arg;
  _func_void_void_ptr *__cancel_routine;
  _Bool fatal_flag;
  _Bool is_bringup_temp_collected;
  uint32_t counter;
  
  counter = 0;
  bVar1 = false;
  fatal_flag = false;
  do {
    counter = counter + 1;
    if (counter % 10 == 0) {
      copy_log_to_latest(temp_log);
      clear_log(temp_log);
    }
    pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
    iVar3 = __sigsetjmp(&__cancel_buf,0);
    if (iVar3 != 0) {
      read_temp_func_clean_up((void *)0x0);
      __pthread_unwind_next((__pthread_unwind_buf_t *)&__cancel_buf);
    }
    __pthread_register_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
    read_temp_and_get_statistics();
    store_max_min_temperature();
    if ((!bVar1) && (last_testpatten_lowest_pcb_temp != 0)) {
      bring_up_pcb_temp = last_testpatten_lowest_pcb_temp;
      bVar1 = true;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: bring_up_pcb_temp = %d\n","temperature.c",0x58a,"read_temp_func"
                  ,bring_up_pcb_temp);
        }
        fclose(pFVar4);
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar4 = fopen(temp_log,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: lowest temp = %d, highest temp = %d \n","temperature.c",0x58d,
                "read_temp_func",last_testpatten_lowest_pcb_temp,last_testpatten_highest_pcb_temp);
      }
      fclose(pFVar4);
    }
    _Var2 = is_force_mode();
    if ((!_Var2) || (freq_scan_status != 0)) {
      set_pwm_by_temp();
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar4 = fopen(temp_log,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: fan map is 0x%08x, num = %d\n","temperature.c",0x592,
                "read_temp_func",dev->fan_exist_map,(uint)dev->fan_num);
      }
      fclose(pFVar4);
    }
    check_status_value(fatal_flag);
    fatal_flag = process_status_value();
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar4 = fopen(temp_log,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: FAN PWM: %d\n","temperature.c",0x597,"read_temp_func",
                (uint)dev->fan_pwm);
      }
      fclose(pFVar4);
    }
    environemnt_temp = _get_env_temperature();
    __pthread_unregister_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
    pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar4 = fopen(temp_log,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: read_temp_func Done!\n","temperature.c",0x59e,"read_temp_func");
      }
      fclose(pFVar4);
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar4 = fopen(temp_log,"a+");
      if (pFVar4 != (FILE *)0x0) {
        uVar5 = get_crc_count();
        fprintf(pFVar4,"%s:%d:%s: CRC error counter=%d\n","temperature.c",0x59f,"read_temp_func",
                uVar5);
      }
      fclose(pFVar4);
    }
    sleep(10);
  } while( true );
}

