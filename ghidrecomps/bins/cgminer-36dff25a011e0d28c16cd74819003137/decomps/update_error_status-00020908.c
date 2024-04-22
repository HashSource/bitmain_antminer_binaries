
/* WARNING: Unknown calling convention */

void update_error_status(void)

{
  FILE *pFVar1;
  timeval diff;
  FILE *pFile_4;
  FILE *pFile_5;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  
  if (startCheckNetworkJob) {
    cgtime(&tv_send);
    diff.tv_sec = tv_send.tv_sec - tv_send_job.tv_sec;
    if (tv_send.tv_usec - tv_send_job.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
    }
    if ((0x78 < diff.tv_sec) && (status_value = ERROR_NETCONN_LOST, 1 < log_level)) {
      print_crt_time_to_file(log_file,1);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Fatal Error: network connection lost!\n","temperature.c",0x391,
                "update_error_status");
      }
      fclose(pFVar1);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(temp_log,3);
    pFVar1 = fopen(temp_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: dev->temp_top1[TEMP_POS_LOCAL] = %d\n","temperature.c",0x39a,
              "update_error_status",dev->temp_top1[0]);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    print_crt_time_to_file(temp_log,3);
    pFVar1 = fopen(temp_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: dev->temp_top1[TEMP_POS_MIDDLE] = %d\n","temperature.c",0x39b,
              "update_error_status",dev->temp_top1[1]);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    print_crt_time_to_file(temp_log,3);
    pFVar1 = fopen(temp_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: flast_testpatten_highest_pcb_temp = %d\n","temperature.c",0x39c,
              "update_error_status",last_testpatten_highest_pcb_temp);
    }
    fclose(pFVar1);
  }
  if ((dev->temp_top1[0] < 0x51) && (dev->temp_top1[1] < 0x65)) {
    if (dev->fan_num < 2) {
      if (1 < log_level) {
        print_crt_time_to_file(log_file,1);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Fatal Error: Fan lost!cnt: %d.\n","temperature.c",0x3a6,
                  "update_error_status",(uint)dev->fan_num);
        }
        fclose(pFVar1);
      }
      status_value = ERROR_FAN_LOST;
    }
  }
  else {
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Fatal Error: temp too high! pcb_temp = %d, chip_temp = %d\n",
                "temperature.c",0x3a1,"update_error_status",dev->temp_top1[0],dev->temp_top1[1]);
      }
      fclose(pFVar1);
    }
    status_value = ERROR_OVER_MAXTEMP;
  }
  return;
}

