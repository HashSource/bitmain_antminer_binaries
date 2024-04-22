
/* WARNING: Unknown calling convention */

int start_check_system_work_thread(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  check_system_work_id = (thr_info *)calloc(1,0x40);
  iVar1 = thr_info_create(check_system_work_id,(pthread_attr_t *)0x0,check_system_work,
                          check_system_work_id);
  if (iVar1 == 0) {
    pthread_detach(check_system_work_id->pth);
    iVar1 = 0;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: create thread for check system\n","driver-btm-soc.c",0x1bfb,
                "start_check_system_work_thread");
      }
      fclose(__stream);
    }
    iVar1 = -6;
  }
  return iVar1;
}

