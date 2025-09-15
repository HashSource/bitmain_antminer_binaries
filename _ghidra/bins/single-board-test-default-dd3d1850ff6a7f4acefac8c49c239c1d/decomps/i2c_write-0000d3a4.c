
/* WARNING: Removing unreachable block (ram,0x0000d3c0) */

void i2c_write(undefined4 param_1)

{
  int iVar1;
  
  while (iVar1 = read_axi_fpga(0xc), -1 < iVar1) {
    usleep(5000);
  }
  write_axi_fpga(0xc,param_1);
  return;
}

