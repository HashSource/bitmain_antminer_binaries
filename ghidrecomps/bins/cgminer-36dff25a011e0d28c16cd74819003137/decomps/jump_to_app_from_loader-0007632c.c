
int jump_to_app_from_loader(uint32_t chain)

{
  FILE *pFVar1;
  uint32_t chain_local;
  uint8_t read_back_data [2];
  uint8_t crc_data [2];
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_2;
  ushort crc;
  uint8_t length;
  int retry_count;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  retry_count = 0;
  crc_data[0] = '\0';
  crc_data[1] = '\n';
  while( true ) {
    if (2 < retry_count) {
      return 0;
    }
    send_pic_cmd((uint8_t)chain,'\x06','\x04',crc_data,read_back_data,'\x02');
    if ((read_back_data[0] == '\x06') && (read_back_data[1] == '\x01')) break;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: failed on Chain[%d]! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x\n"
                ,"dspic33ep16gs202.c",0x1fc,"jump_to_app_from_loader",chain,(uint)read_back_data[0],
                (uint)read_back_data[1]);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Reset Chian[%d] PIC again!\n","dspic33ep16gs202.c",0x1fd,
                "jump_to_app_from_loader",chain);
      }
      fclose(pFVar1);
    }
    pic_reset((uint8_t)chain);
    sleep(1);
    retry_count = retry_count + 1;
  }
  sleep(1);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: chain[%d] ok\n","dspic33ep16gs202.c",0x205,"jump_to_app_from_loader"
              ,chain);
    }
    fclose(pFVar1);
  }
  return 1;
}

