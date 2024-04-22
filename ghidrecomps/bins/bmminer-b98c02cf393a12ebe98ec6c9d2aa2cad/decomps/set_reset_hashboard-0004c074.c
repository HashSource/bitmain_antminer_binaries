
void set_reset_hashboard(uint param_1,int param_2)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = 1 << (param_1 & 0xff);
  if (param_2 < 1) {
    uVar1 = *(uint *)(axi_fpga_addr + 0x34) & ~uVar1;
  }
  else {
    uVar1 = *(uint *)(axi_fpga_addr + 0x34) | uVar1;
  }
  if (5 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set_reset_hashboard = 0x%08x\n","znyq7010.c",0xc0,DAT_0004c0ec,
              uVar1);
    }
    fclose(__stream);
    *(uint *)(axi_fpga_addr + 0x34) = uVar1;
    return;
  }
  *(uint *)(axi_fpga_addr + 0x34) = uVar1;
  return;
}

