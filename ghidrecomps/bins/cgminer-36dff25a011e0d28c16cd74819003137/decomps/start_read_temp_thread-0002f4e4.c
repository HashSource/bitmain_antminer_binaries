
/* WARNING: Unknown calling convention */

int start_read_temp_thread(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  read_temp_id = (thr_info *)calloc(1,0x40);
  iVar1 = thr_info_create(read_temp_id,(pthread_attr_t *)0x0,read_temp_func,read_temp_id);
  if (iVar1 == 0) {
    pthread_detach(read_temp_id->pth);
    iVar1 = 0;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: create thread for read temp\n","driver-btm-soc.c",0x1bdf,
                "start_read_temp_thread");
      }
      fclose(__stream);
    }
    iVar1 = -7;
  }
  return iVar1;
}

