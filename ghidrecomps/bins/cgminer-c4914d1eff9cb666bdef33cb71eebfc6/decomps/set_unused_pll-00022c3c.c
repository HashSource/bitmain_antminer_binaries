
/* WARNING: Unknown calling convention */

void set_unused_pll(void)

{
  uchar which_chain;
  FILE *__stream;
  FILE *pFile;
  int chain;
  
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set unused pll enter\n","driver-btm-soc.c",0x1147,"set_unused_pll"
             );
    }
    fclose(__stream);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      which_chain = (uchar)chain;
      set_config_BM1393_t(which_chain,'\0','\x01','t',0xf0f0f0f);
      set_config_BM1393_t(which_chain,'\0','\x01','`',0x80103f77);
      set_config_BM1393_t(which_chain,'\0','\x01','t',0xf0f0f0f);
      set_config_BM1393_t(which_chain,'\0','\x01','`',0x80103f77);
      set_config_BM1393_t(which_chain,'\0','\x01','x',0xf0f0f0f);
      set_config_BM1393_t(which_chain,'\0','\x01','d',0x80103f77);
      set_config_BM1393_t(which_chain,'\0','\x01','x',0xf0f0f0f);
      set_config_BM1393_t(which_chain,'\0','\x01','d',0x80103f77);
      set_config_BM1393_t(which_chain,'\0','\x01','|',0xf0f0f0f);
      set_config_BM1393_t(which_chain,'\0','\x01','h',0x80103f77);
      set_config_BM1393_t(which_chain,'\0','\x01','|',0xf0f0f0f);
      set_config_BM1393_t(which_chain,'\0','\x01','h',0x80103f77);
    }
  }
  return;
}

