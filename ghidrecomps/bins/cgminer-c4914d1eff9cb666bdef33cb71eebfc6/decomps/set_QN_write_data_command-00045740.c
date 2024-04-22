
void set_QN_write_data_command(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x20] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set QN_WRITE_DATA_COMMAND is 0x%x\n","zynq.c",0xc4,
              "set_QN_write_data_command",value);
    }
    fclose(__stream);
  }
  get_QN_write_data_command();
  return;
}

