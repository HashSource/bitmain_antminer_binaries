
void set_reset_allhashboard(int param_1)

{
  FILE *__stream;
  uint local_c;
  
  if (param_1 < 1) {
    local_c = *(uint *)(axi_fpga_addr + 0x34) & 0xffff0000;
  }
  else {
    local_c = ~(~(*(uint *)(axi_fpga_addr + 0x34) >> 0x10) << 0x10);
  }
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set_reset_allhashboard = 0x%08x\n","znyq7010.c",0xce,local_c);
    }
    fclose(__stream);
  }
  *(uint *)(axi_fpga_addr + 0x34) = local_c;
  return;
}

