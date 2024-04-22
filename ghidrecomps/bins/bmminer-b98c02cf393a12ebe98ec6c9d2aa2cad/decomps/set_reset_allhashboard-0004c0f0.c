
void set_reset_allhashboard(int param_1)

{
  FILE *__stream;
  uint uVar1;
  
  if (param_1 < 1) {
    uVar1 = *(uint *)(axi_fpga_addr + 0x34) >> 0x10;
  }
  else {
    uVar1 = ~(*(uint *)(axi_fpga_addr + 0x34) >> 0x10);
  }
  if (param_1 < 1) {
    uVar1 = uVar1 << 0x10;
  }
  else {
    uVar1 = ~(uVar1 << 0x10);
  }
  if (5 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set_reset_allhashboard = 0x%08x\n","znyq7010.c",0xce,DAT_0004c168,
              uVar1);
    }
    fclose(__stream);
    *(uint *)(axi_fpga_addr + 0x34) = uVar1;
    return;
  }
  *(uint *)(axi_fpga_addr + 0x34) = uVar1;
  return;
}

