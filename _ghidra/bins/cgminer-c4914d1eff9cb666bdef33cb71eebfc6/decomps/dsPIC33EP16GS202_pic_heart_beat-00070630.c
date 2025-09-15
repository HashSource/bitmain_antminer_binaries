
int dsPIC33EP16GS202_pic_heart_beat(uint8_t chain)

{
  FILE *pFVar1;
  uint8_t chain_local;
  uint8_t cmd [1];
  uint8_t read_back_data [6];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int retry_count;
  
  retry_count = 0;
  cmd[0] = '\x16';
  while( true ) {
    retry_count = retry_count + 1;
    send_pic_cmd(chain,cmd,'\x01',read_back_data,'\x06');
    if ((read_back_data[1] == '\x16') && (read_back_data[2] == '\x01')) break;
    if (2 < retry_count) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: ERROR! failed on Chain[%d] after %d times try!\n",
                  "dspic33ep16gs202.c",0xd5,"dsPIC33EP16GS202_pic_heart_beat",(uint)chain,
                  retry_count);
        }
        fclose(pFVar1);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: DEBUG! 0x%08x, 0x%08x\n","dspic33ep16gs202.c",0xd6,
                  "dsPIC33EP16GS202_pic_heart_beat",(uint)read_back_data[1],(uint)read_back_data[2])
          ;
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
      fprintf(pFVar1,"%s:%d:%s: chain[%d] ok!\n","dspic33ep16gs202.c",0xd0,
              "dsPIC33EP16GS202_pic_heart_beat",(uint)chain);
    }
    fclose(pFVar1);
  }
  return 0;
}

