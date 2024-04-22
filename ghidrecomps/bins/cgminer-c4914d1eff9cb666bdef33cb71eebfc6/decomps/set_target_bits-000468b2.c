
void set_target_bits(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x4e] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set TARGET_BITS is 0x%x\n","zynq.c",0x250,"set_target_bits",value)
      ;
    }
    fclose(__stream);
  }
  get_target_bits();
  return;
}

