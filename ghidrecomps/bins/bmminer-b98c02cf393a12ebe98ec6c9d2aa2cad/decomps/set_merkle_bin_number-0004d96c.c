
void set_merkle_bin_number(uint param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(uint *)(axi_fpga_addr + 0x114) = param_1 & 0xffff;
  if (uVar1 < 6) {
    get_merkle_bin_number();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set MERKLE_BIN_NUMBER is 0x%x\n","znyq7010.c",0x2df,DAT_0004d9e0,
            param_1 & 0xffff);
  }
  fclose(__stream);
  get_merkle_bin_number();
  return;
}

