
void set_work_nonce2(uint *value)

{
  FILE *__stream;
  uint *value_local;
  uint buf [2];
  FILE *pFile;
  
  buf[0] = 0;
  buf[1] = 0;
  axi_fpga_addr[0x42] = *value;
  axi_fpga_addr[0x43] = value[1];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set WORK_NONCE_2 value[0]: 0x%x, value[1]: 0x%x\n","zynq.c",0x290,
              "set_work_nonce2",*value,value[1]);
    }
    fclose(__stream);
  }
  get_work_nonce2(buf);
  return;
}

