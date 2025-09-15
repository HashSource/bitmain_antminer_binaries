
void set_reset_hashboard(uint param_1,int param_2)

{
  FILE *__stream;
  uint local_c;
  
  local_c = 1 << (param_1 & 0xff);
  if (param_2 < 1) {
    local_c = ~local_c & *(uint *)(axi_fpga_addr + 0x34);
  }
  else {
    local_c = local_c | *(uint *)(axi_fpga_addr + 0x34);
  }
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set_reset_hashboard = 0x%08x\n","znyq7010.c",0xc0,local_c);
    }
    fclose(__stream);
  }
  *(uint *)(axi_fpga_addr + 0x34) = local_c;
  return;
}

