
/* WARNING: Removing unreachable block (ram,0x00018058) */
/* WARNING: Removing unreachable block (ram,0x00018066) */
/* WARNING: Removing unreachable block (ram,0x00018074) */
/* WARNING: Removing unreachable block (ram,0x00018082) */

void i2c_write(uint config_data)

{
  uint uVar1;
  uint config_data_local;
  char tmp42 [1024];
  uint send_counter;
  
  while (uVar1 = read_axi_fpga(0xc), -1 < (int)uVar1) {
    usleep(5000);
  }
  write_axi_fpga(0xc,config_data);
  return;
}

