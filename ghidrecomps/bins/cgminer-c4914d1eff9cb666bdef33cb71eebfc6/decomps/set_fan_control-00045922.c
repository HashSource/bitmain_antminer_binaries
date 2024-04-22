
void set_fan_control(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x21] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set FAN_CONTROL is 0x%x\n","zynq.c",0x103,"set_fan_control",value)
      ;
    }
    fclose(__stream);
  }
  get_fan_control();
  return;
}

