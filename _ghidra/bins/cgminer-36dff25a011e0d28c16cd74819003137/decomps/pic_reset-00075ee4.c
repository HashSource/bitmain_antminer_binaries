
int pic_reset(uint8_t chain)

{
  undefined2 uVar1;
  FILE *pFVar2;
  uint8_t chain_local;
  uint8_t read_back_data [2];
  uint8_t crc_data [2];
  FILE *pFile;
  FILE *pFile_1;
  ushort crc;
  uint8_t length;
  int retry_count;
  
  retry_count = 0;
  uVar1 = 0xb;
  while( true ) {
    crc_data[0] = (uint8_t)((ushort)uVar1 >> 8);
    crc_data[1] = (uint8_t)uVar1;
    if (2 < retry_count) {
      return 0;
    }
    send_pic_cmd(chain,'\a','\x04',crc_data,read_back_data,'\x02');
    if ((read_back_data[0] == '\a') && (read_back_data[1] == '\x01')) break;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,
                "%s:%d:%s: failed on Chain[%d]! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x\n"
                ,"dspic33ep16gs202.c",0xf0,"pic_reset",(uint)chain,(uint)read_back_data[0],
                (uint)read_back_data[1]);
      }
      fclose(pFVar2);
    }
    sleep(3);
    uVar1 = CONCAT11(crc_data[0],crc_data[1]);
    retry_count = retry_count + 1;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: chain[%d] ok\n","dspic33ep16gs202.c",0xf6,"pic_reset",(uint)chain);
    }
    fclose(pFVar2);
  }
  sleep(3);
  return 1;
}

