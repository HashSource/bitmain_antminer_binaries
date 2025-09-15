
void set_time_out_control(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x22] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set TIME_OUT_CONTROL is 0x%x\n","zynq.c",0x15d,
              "set_time_out_control",value);
    }
    fclose(__stream);
  }
  get_time_out_control();
  return;
}

