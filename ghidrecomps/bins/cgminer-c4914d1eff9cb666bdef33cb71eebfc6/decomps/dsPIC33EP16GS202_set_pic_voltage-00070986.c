
int dsPIC33EP16GS202_set_pic_voltage(uint8_t chain,uint8_t pic_voltage)

{
  FILE *pFVar1;
  int iVar2;
  uint8_t pic_voltage_local;
  uint8_t chain_local;
  uint8_t cmd [4];
  uint8_t read_back_data [2];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint8_t voltage3;
  uint8_t voltage2;
  uint8_t voltage1;
  int retry_count;
  
  retry_count = 0;
  cmd[0] = '\x10';
  cmd[2] = '\0';
  cmd[3] = '\0';
  cmd[1] = pic_voltage;
  if ((char)pic_voltage < '\0') {
    iVar2 = -2;
  }
  else {
    while( true ) {
      retry_count = retry_count + 1;
      send_pic_cmd(chain,cmd,'\x04',read_back_data,'\x02');
      if ((read_back_data[0] == '\x10') && (read_back_data[1] == '\x01')) {
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] ok!\n","dspic33ep16gs202.c",0x10f,
                    "dsPIC33EP16GS202_set_pic_voltage",(uint)chain);
          }
          fclose(pFVar1);
        }
        return 0;
      }
      if (2 < retry_count) break;
      sleep(1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: ERROR! failed on Chain[%d] after %d times try!\n",
                "dspic33ep16gs202.c",0x114,"dsPIC33EP16GS202_set_pic_voltage",(uint)chain,
                retry_count);
      }
      fclose(pFVar1);
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: DEBUG! 0x%08x, 0x%08x\n","dspic33ep16gs202.c",0x115,
                "dsPIC33EP16GS202_set_pic_voltage",(uint)read_back_data[0],(uint)read_back_data[1]);
      }
      fclose(pFVar1);
    }
    iVar2 = -1;
  }
  return iVar2;
}

