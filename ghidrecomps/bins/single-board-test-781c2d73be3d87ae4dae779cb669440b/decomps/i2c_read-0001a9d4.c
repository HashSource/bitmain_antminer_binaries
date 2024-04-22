
/* WARNING: Unknown calling convention */

uchar i2c_read(uint config_data)

{
  uint uVar1;
  
  i2c_write(config_data | 0x2000000);
  do {
    usleep(5000);
    uVar1 = read_axi_fpga(0xc);
  } while (-1 < (int)uVar1);
  return (uchar)uVar1;
}

