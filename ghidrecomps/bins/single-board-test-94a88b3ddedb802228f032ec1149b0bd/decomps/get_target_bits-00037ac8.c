
undefined4 get_target_bits(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x138);
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: TARGET_BITS is 0x%x\n","znyq7010.c",0x24d,uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

