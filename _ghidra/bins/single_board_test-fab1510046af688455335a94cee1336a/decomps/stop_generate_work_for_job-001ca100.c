
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void stop_generate_work_for_job(void)

{
  int iVar1;
  uint32_t value;
  
  iVar1 = 10;
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffffbf);
  do {
    usleep(1000);
    value = 0;
    fpga_read(0x23,&value);
    if (-1 < (int)(value << 0x19)) {
      return;
    }
    value = 0;
    fpga_read(0x23,&value);
    fpga_write(0x23,value & 0xffffffbf);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

