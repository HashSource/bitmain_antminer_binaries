
/* WARNING: Unknown calling convention */

int start_read_hash_rate_thread(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  read_hash_rate = (thr_info *)calloc(1,0x40);
  iVar1 = thr_info_create(read_hash_rate,(pthread_attr_t *)0x0,get_hash_rate,read_hash_rate);
  if (iVar1 == 0) {
    pthread_detach(read_hash_rate->pth);
    iVar1 = 0;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: create thread for get hashrate from asic failed\n",
                "driver-btm-soc.c",0x1bed,"start_read_hash_rate_thread");
      }
      fclose(__stream);
    }
    iVar1 = -6;
  }
  return iVar1;
}

