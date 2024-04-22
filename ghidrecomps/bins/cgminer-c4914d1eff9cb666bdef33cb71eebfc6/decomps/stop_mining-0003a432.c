
void stop_mining(char *str)

{
  FILE *__stream;
  char *str_local;
  FILE *pFile;
  int chain;
  
  if (1 < log_level) {
    print_crt_time_to_file(log_file,1);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: fetal error: stop ming: %s\n","power.c",0x54,"stop_mining",str);
    }
    fclose(__stream);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      disable_pic_dac((uint8_t)chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
    }
  }
  do {
    sleep(1);
  } while( true );
}

