
undefined4 get_hardware_version(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *axi_fpga_addr;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: HARDWARE_VERSION is 0x%x\n","znyq7010.c",0x16b,uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

