
/* WARNING: Unknown calling convention */

void get_pic_software_version_all_chain(void)

{
  uint8_t version;
  FILE *pFile;
  int ret;
  int chain;
  
  ret = 0;
  version = '\0';
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      ret = dsPIC33EP16GS202_get_software_version((uint8_t)chain,&version);
      if ((ret == 0) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,"%s:%d:%s: chain[%d] PIC software version: %d\n",
                  "dspic33ep16gs202.c",0x1e6,"get_pic_software_version_all_chain",chain,
                  (uint)version);
        }
        fclose((FILE *)pFile);
      }
    }
  }
  return;
}

