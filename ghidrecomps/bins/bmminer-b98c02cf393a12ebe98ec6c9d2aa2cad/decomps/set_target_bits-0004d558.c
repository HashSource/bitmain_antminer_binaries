
void set_target_bits(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x138) = param_1;
  if (uVar1 < 6) {
    get_target_bits();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set TARGET_BITS is 0x%x\n","znyq7010.c",0x290,DAT_0004d5c8,param_1);
  }
  fclose(__stream);
  get_target_bits();
  return;
}

