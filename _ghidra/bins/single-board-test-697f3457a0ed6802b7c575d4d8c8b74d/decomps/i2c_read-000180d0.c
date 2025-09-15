
/* WARNING: Removing unreachable block (ram,0x00018118) */
/* WARNING: Removing unreachable block (ram,0x00018126) */
/* WARNING: Removing unreachable block (ram,0x00018134) */
/* WARNING: Removing unreachable block (ram,0x00018142) */
/* WARNING: Removing unreachable block (ram,0x0001816c) */

uchar i2c_read(uint config_data)

{
  uint uVar1;
  uint config_data_local;
  char tmp42 [1024];
  uint ret_data;
  uint send_counter;
  
  i2c_write(config_data | 0x2000000);
  do {
    usleep(5000);
    uVar1 = read_axi_fpga(0xc);
  } while (-1 < (int)uVar1);
  return (uchar)uVar1;
}

