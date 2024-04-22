
uint get_merkle_bin_number(void)

{
  FILE *__stream;
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(axi_fpga_addr + 0x114);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: MERKLE_BIN_NUMBER is 0x%x\n","znyq7010.c",0x2d8,DAT_0004d968,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

