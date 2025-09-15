
/* WARNING: Removing unreachable block (ram,0x0000d3d2) */

uint i2c_read(uint param_1)

{
  uint uVar1;
  
  i2c_write(param_1 | 0x2000000);
  do {
    usleep(5000);
    uVar1 = read_axi_fpga(0xc);
  } while (-1 < (int)uVar1);
  return uVar1 & 0xff;
}

