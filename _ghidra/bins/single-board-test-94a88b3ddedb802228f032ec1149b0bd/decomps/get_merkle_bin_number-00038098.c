
uint get_merkle_bin_number(void)

{
  FILE *__stream;
  uint uVar1;
  
  uVar1 = *(uint *)(axi_fpga_addr + 0x114) & 0xffff;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: MERKLE_BIN_NUMBER is 0x%x\n","znyq7010.c",0x29c,uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

