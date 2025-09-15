
void set_bt8d_control(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0xf] = value;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set_bt8d_control is 0x%x\n","zynq.c",0x157,"set_bt8d_control",
              value);
    }
    fclose(__stream);
  }
  get_bt8d_control();
  return;
}

