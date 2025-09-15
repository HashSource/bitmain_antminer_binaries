
int dsPIC33EP16GS202_crab_circuit_control(uint8_t chain,uchar enable)

{
  FILE *pFVar1;
  uchar enable_local;
  uint8_t chain_local;
  uint8_t cmd [2];
  uint8_t read_back_data [2];
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile;
  FILE *pFile_1;
  int retry_count;
  
  retry_count = 0;
  cmd[0] = '1';
  cmd[1] = enable;
  while( true ) {
    retry_count = retry_count + 1;
    send_pic_cmd(chain,cmd,'\x02',read_back_data,'\x02');
    if ((read_back_data[0] == '1') && (read_back_data[1] == '\x01')) break;
    if (2 < retry_count) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: ERROR! failed on Chain[%d] after %d times try!\n",
                  "dspic33ep16gs202.c",0x277,"dsPIC33EP16GS202_crab_circuit_control",(uint)chain,
                  retry_count);
        }
        fclose(pFVar1);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: DEBUG! 0x%08x, 0x%08x\n","dspic33ep16gs202.c",0x278,
                  "dsPIC33EP16GS202_crab_circuit_control",(uint)read_back_data[0],
                  (uint)read_back_data[1]);
        }
        fclose(pFVar1);
      }
      return -1;
    }
    sleep(1);
  }
  if (enable == '\0') {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Disable pic crab(qian wei) for chain %d success!\n",
                "dspic33ep16gs202.c",0x271,"dsPIC33EP16GS202_crab_circuit_control",(uint)chain);
      }
      fclose(pFVar1);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Enable pic crab(qian wei) for chain %d success!\n",
              "dspic33ep16gs202.c",0x26f,"dsPIC33EP16GS202_crab_circuit_control",(uint)chain);
    }
    fclose(pFVar1);
  }
  return 0;
}

