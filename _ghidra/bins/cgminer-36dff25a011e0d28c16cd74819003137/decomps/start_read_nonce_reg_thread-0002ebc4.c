
/* WARNING: Unknown calling convention */

int start_read_nonce_reg_thread(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  read_nonce_reg_id = (thr_info *)calloc(1,0x40);
  iVar1 = thr_info_create(read_nonce_reg_id,(pthread_attr_t *)0x0,get_nonce_and_register,
                          read_nonce_reg_id);
  if (iVar1 == 0) {
    pthread_detach(read_nonce_reg_id->pth);
    iVar1 = 0;
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: create thread for get nonce and register from FPGA failed\n",
                "driver-btm-soc.c",0x1b5f,"start_read_nonce_reg_thread");
      }
      fclose(__stream);
    }
    iVar1 = -5;
  }
  return iVar1;
}

