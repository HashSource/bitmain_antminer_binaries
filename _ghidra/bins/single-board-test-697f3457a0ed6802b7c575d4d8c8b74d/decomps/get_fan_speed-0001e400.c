
/* WARNING: Unknown calling convention */

uint get_fan_speed(void)

{
  uint uVar1;
  
  uVar1 = read_axi_fpga(1);
  return uVar1;
}

