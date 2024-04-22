
/* WARNING: Unknown calling convention */

int init_pic(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  int ret;
  uint8_t i;
  
  ret = 0;
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    iVar1 = init_pic_one_chain(i);
    if (iVar1 != 0) {
      freq_scan_error_code_set(4,(uint)i);
      dev->chain_exist[i] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      ret = -1;
    }
  }
  if (pic_heart_beat == (thr_info *)0x0) {
    pic_heart_beat = (thr_info *)calloc(1,0x40);
    iVar1 = thr_info_create(pic_heart_beat,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,
                            pic_heart_beat);
    if (iVar1 != 0) {
      if (1 < log_level) {
        print_crt_time_to_file(log_file,1);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: create thread for get nonce and register from FPGA failed\n",
                  "driver-btm-soc.c",0x1355,"init_pic");
        }
        fclose(__stream);
      }
      ret = -5;
    }
  }
  return ret;
}

