
/* WARNING: Unknown calling convention */

void i2c_write(uint config_data)

{
  uint uVar1;
  
  while (uVar1 = read_axi_fpga(0xc), -1 < (int)uVar1) {
    usleep(5000);
  }
  write_axi_fpga(0xc,config_data);
  return;
}

