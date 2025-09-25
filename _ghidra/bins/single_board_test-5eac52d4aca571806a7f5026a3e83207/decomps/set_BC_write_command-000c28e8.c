
/* WARNING: Unknown calling convention */

void set_BC_write_command(uint32_t value)

{
  int iVar1;
  uint32_t val;
  
  fpga_write(0x1b,value);
  if ((int)value < 0) {
    iVar1 = 0xbb9;
    do {
      fpga_read(0x1b,&val);
      if (-1 < (int)val) {
        return;
      }
      usleep(1000);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    fpga_read(0x1b,&val);
  }
  return;
}

