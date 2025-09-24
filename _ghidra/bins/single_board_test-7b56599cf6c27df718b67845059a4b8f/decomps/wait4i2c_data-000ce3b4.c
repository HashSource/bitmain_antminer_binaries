
/* WARNING: Unknown calling convention */

uchar wait4i2c_data(uint8_t *data)

{
  int iVar1;
  uint32_t iic;
  
  iVar1 = 0x259;
  iic = 0;
  do {
    fpga_read(0xc,&iic);
    if (iic >> 0x1e == 2) {
      *data = (uint8_t)iic;
      return '\x01';
    }
    usleep(5000);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return '\0';
}

