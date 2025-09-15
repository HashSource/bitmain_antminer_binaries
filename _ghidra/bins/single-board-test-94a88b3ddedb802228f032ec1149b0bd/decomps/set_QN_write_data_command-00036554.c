
void set_QN_write_data_command(undefined4 param_1)

{
  FILE *__stream;
  
  *(undefined4 *)(axi_fpga_addr + 0x80) = param_1;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set QN_WRITE_DATA_COMMAND is 0x%x\n","znyq7010.c",0xb0,param_1);
    }
    fclose(__stream);
  }
  get_QN_write_data_command();
  return;
}

