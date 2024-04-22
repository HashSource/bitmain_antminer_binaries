
void set_BC_command_buffer(uint *value)

{
  FILE *__stream;
  uint *value_local;
  uint buf [4];
  FILE *pFile;
  
  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
  buf[3] = 0;
  axi_fpga_addr[0x31] = *value;
  axi_fpga_addr[0x32] = value[1];
  axi_fpga_addr[0x33] = value[2];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,
              "%s:%d:%s: set BC_COMMAND_BUFFER value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x\n",
              "zynq.c",0x16e,"set_BC_command_buffer",*value,value[1],value[2]);
    }
    fclose(__stream);
  }
  get_BC_command_buffer(buf);
  return;
}

