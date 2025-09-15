
int dsPIC33EP16GS202_enable_pic_dc_dc(uint8_t chain,uint8_t enable)

{
  FILE *pFVar1;
  uint8_t enable_local;
  uint8_t chain_local;
  uint8_t cmd [2];
  uint8_t read_back_data [2];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int retry_count;
  
  retry_count = 0;
  cmd[0] = '\x15';
  cmd[1] = enable;
  while( true ) {
    retry_count = retry_count + 1;
    send_pic_cmd(chain,cmd,'\x02',read_back_data,'\x02');
    if ((read_back_data[0] == '\x15') && (read_back_data[1] == '\x01')) break;
    if (2 < retry_count) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: ERROR! failed on Chain[%d] after %d times try!\n",
                  "dspic33ep16gs202.c",0xf2,"dsPIC33EP16GS202_enable_pic_dc_dc",(uint)chain,
                  retry_count);
        }
        fclose(pFVar1);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: DEBUG! 0x%08x, 0x%08x\n","dspic33ep16gs202.c",0xf3,
                  "dsPIC33EP16GS202_enable_pic_dc_dc",(uint)read_back_data[0],
                  (uint)read_back_data[1]);
        }
        fclose(pFVar1);
      }
      return -1;
    }
    sleep(1);
  }
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: chain[%d] ok!\n","dspic33ep16gs202.c",0xed,
              "dsPIC33EP16GS202_enable_pic_dc_dc",(uint)chain);
    }
    fclose(pFVar1);
  }
  return 0;
}

