
undefined4 get_target_bits(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x138);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: TARGET_BITS is 0x%x\n","znyq7010.c",0x289,DAT_0004d554,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

