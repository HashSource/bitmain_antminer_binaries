
void set_merkle_bin_number(uint param_1)

{
  FILE *__stream;
  
  *(uint *)(axi_fpga_addr + 0x114) = param_1 & 0xffff;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set MERKLE_BIN_NUMBER is 0x%x\n","znyq7010.c",0x2a3,param_1 & 0xffff)
      ;
    }
    fclose(__stream);
  }
  get_merkle_bin_number();
  return;
}

