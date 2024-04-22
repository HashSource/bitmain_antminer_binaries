
void init_pic_one_chain(int chain)

{
  int iVar1;
  FILE *__stream;
  int chain_local;
  FILE *pFile;
  
  if ((dev->chain_exist[chain] == 1) && (iVar1 = pic_init((uint8_t)chain), iVar1 == 0)) {
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Chain[%d] PIC init failed!\n","driver-btm-soc.c",0x14e5,
                "init_pic_one_chain",chain);
      }
      fclose(__stream);
    }
    stop_mining("PIC init failed!\n");
  }
  return;
}

