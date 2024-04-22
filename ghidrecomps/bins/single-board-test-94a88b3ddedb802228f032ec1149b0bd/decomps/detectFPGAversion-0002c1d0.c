
void detectFPGAversion(void)

{
  uint uVar1;
  FILE *__stream;
  
  reset_fpga();
  uVar1 = get_hardware_version();
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: DETECT HW version=%08x\n","main.c",0x212a,uVar1);
    }
    fclose(__stream);
  }
  fpga_version = uVar1 & 0xff;
  fpga_major_version = uVar1 >> 8 & 0xff;
  return;
}

