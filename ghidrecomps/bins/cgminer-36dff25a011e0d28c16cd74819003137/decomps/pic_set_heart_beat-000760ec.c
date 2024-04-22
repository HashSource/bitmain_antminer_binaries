
int pic_set_heart_beat(uint8_t chain)

{
  FILE *pFVar1;
  uint8_t chain_local;
  uint8_t read_back_data [6];
  uint8_t crc_data [2];
  FILE *pFile;
  FILE *pFile_1;
  ushort crc;
  uint8_t length;
  int retry_count;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  retry_count = 0;
  crc_data[0] = '\0';
  crc_data[1] = '\x1a';
  while( true ) {
    if (2 < retry_count) {
      return 0;
    }
    send_pic_cmd(chain,'\x16','\x04',crc_data,read_back_data,'\x06');
    if ((read_back_data[1] == '\x16') && (read_back_data[2] == '\x01')) break;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: Heartbeat failed on Chain[%d], retry_count=%d! read_back_data[1] = 0x%x, read_back_data[2] = 0x%x\n"
                ,"dspic33ep16gs202.c",0x110,"pic_set_heart_beat",(uint)chain,retry_count + 1,
                (uint)read_back_data._0_4_ >> 8 & 0xff,(uint)read_back_data._0_4_ >> 0x10 & 0xff);
      }
      fclose(pFVar1);
    }
    sleep(1);
    retry_count = retry_count + 1;
  }
  if (5 < log_level) {
    print_crt_time_to_file(log_file,5);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: success on chain[%d],ret = %d\n","dspic33ep16gs202.c",0x115,
              "pic_set_heart_beat",(uint)chain,(uint)read_back_data._0_4_ >> 0x18);
    }
    fclose(pFVar1);
  }
  return 1;
}

