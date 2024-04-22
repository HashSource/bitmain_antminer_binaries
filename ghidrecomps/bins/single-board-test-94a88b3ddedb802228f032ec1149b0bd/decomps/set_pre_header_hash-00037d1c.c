
void set_pre_header_hash(undefined4 *param_1)

{
  FILE *__stream;
  
  *(undefined4 *)(axi_fpga_addr + 0x140) = *param_1;
  *(undefined4 *)(axi_fpga_addr + 0x144) = param_1[1];
  *(undefined4 *)(axi_fpga_addr + 0x148) = param_1[2];
  *(undefined4 *)(axi_fpga_addr + 0x14c) = param_1[3];
  *(undefined4 *)(axi_fpga_addr + 0x150) = param_1[4];
  *(undefined4 *)(axi_fpga_addr + 0x154) = param_1[5];
  *(undefined4 *)(axi_fpga_addr + 0x158) = param_1[6];
  *(undefined4 *)(axi_fpga_addr + 0x15c) = param_1[7];
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,
              "%s:%d: set PRE_HEADER_HASH value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x, value[3]: 0x%x, value[4]: 0x%x, value[5]: 0x%x, value[6]: 0x%x, value[7]: 0x%x\n"
              ,"znyq7010.c",0x272,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],
              param_1[6],param_1[7]);
    }
    fclose(__stream);
  }
  return;
}

