
/* WARNING: Unknown calling convention */

uchar wait4i2c_ready(void)

{
  int iVar1;
  uint32_t iic;
  
  iVar1 = 0x259;
  iic = 0;
  do {
    fpga_read(0xc,&iic);
    if (-((int)iic >> 0x1f) != 0) {
      return (uchar)-((int)iic >> 0x1f);
    }
    usleep(5000);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return '\0';
}

