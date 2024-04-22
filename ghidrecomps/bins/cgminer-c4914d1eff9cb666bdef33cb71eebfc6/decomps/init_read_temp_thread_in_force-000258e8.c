
/* WARNING: Unknown calling convention */

void init_read_temp_thread_in_force(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  read_temp_id_in_force = (thr_info *)calloc(1,0x40);
  iVar1 = thr_info_create(read_temp_id_in_force,(pthread_attr_t *)0x0,read_temp_func + 1,
                          read_temp_id_in_force);
  if (iVar1 == 0) {
    pthread_detach(read_temp_id_in_force->pth);
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: create thread for read temp\n","driver-btm-soc.c",0x1635,
              "init_read_temp_thread_in_force");
    }
    fclose(__stream);
  }
  return;
}

