
/* WARNING: Unknown calling convention */

void set_order_clock(void)

{
  uchar which_chain;
  FILE *__stream;
  FILE *pFile;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: chain[%d]: set order clock, stragegy 3\n","driver-btm-soc.c",
                  0x1d1b,"set_order_clock",chain);
        }
        fclose(__stream);
      }
      which_chain = (uchar)chain;
      set_config_BM1391_t(which_chain,'\0','\x01',0x80,0);
      set_config_BM1391_t(which_chain,'\0','\x01',0x84,0);
      usleep(100000);
      set_config_BM1391_t(which_chain,'\0','\x01',' ',1);
    }
  }
  return;
}

