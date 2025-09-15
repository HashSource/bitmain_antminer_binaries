
uchar set_iic(uint data)

{
  uint uVar1;
  FILE *__stream;
  uint data_local;
  FILE *pFile;
  uchar ret_data;
  uint ret;
  int wait_counter;
  
  wait_counter = 0;
  axi_fpga_addr[0xc] = data & 0x3fffffff;
  while( true ) {
    uVar1 = get_iic();
    if ((int)uVar1 < 0) {
      return (uchar)uVar1;
    }
    if (100 < wait_counter) break;
    usleep(5000);
    wait_counter = wait_counter + 1;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: could not get iic, ret = 0x%08x\n","zynq.c",0x3f,"set_iic",uVar1);
    }
    fclose(__stream);
  }
  return '\0';
}

