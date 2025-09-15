
double dsPIC33EP16GS202_pic_get_an_voltage2(uint8_t chain)

{
  FILE *pFVar1;
  double dVar2;
  uint8_t chain_local;
  uint8_t cmd [1];
  uint8_t read_back_data [9];
  FILE *pFile_1;
  FILE *pFile;
  int retry_count;
  
  retry_count = 0;
  cmd[0] = ')';
  while( true ) {
    retry_count = retry_count + 1;
    send_pic_cmd(chain,cmd,'\x01',read_back_data,'\t');
    if ((read_back_data[1] == ')') && (read_back_data[2] == '\x01')) break;
    if (2 < retry_count) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: ERROR! failed on Chain[%d] after %d times try!\n",
                  "dspic33ep16gs202.c",0x2eb,"dsPIC33EP16GS202_pic_get_an_voltage2",(uint)chain,
                  retry_count);
        }
        fclose(pFVar1);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: DEBUG! 0x%08x, 0x%08x,  0x%08x\n","dspic33ep16gs202.c",0x2ec,
                  "dsPIC33EP16GS202_pic_get_an_voltage2",(uint)read_back_data[0],
                  (uint)read_back_data[1],(uint)read_back_data[2]);
        }
        fclose(pFVar1);
      }
      dump_mem("read_back_data:",read_back_data,9);
      return -1.0;
    }
    sleep(1);
  }
  dVar2 = decode_an_voltage_buf(read_back_data);
  return dVar2;
}

