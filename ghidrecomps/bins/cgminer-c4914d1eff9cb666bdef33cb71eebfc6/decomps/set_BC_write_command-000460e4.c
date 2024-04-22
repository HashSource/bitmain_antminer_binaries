
void set_BC_write_command(uint value)

{
  FILE *__stream;
  int iVar1;
  uint value_local;
  FILE *pFile;
  int wait_count;
  
  wait_count = 0;
  axi_fpga_addr[0x30] = value;
  if ((int)value < 0) {
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) {
        return;
      }
      cgsleep_ms(1);
      wait_count = wait_count + 1;
    } while (wait_count < 0xbb9);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Error: set_BC_write_command wait buffer ready timeout!\n",
                "zynq.c",0x1c7,"set_BC_write_command");
      }
      fclose(__stream);
    }
  }
  else {
    get_BC_write_command();
  }
  return;
}

