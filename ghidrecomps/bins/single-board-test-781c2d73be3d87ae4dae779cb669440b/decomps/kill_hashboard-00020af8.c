
/* WARNING: Unknown calling convention */

void kill_hashboard(void)

{
  uint uVar1;
  
  puts("\npower off hashboard");
  enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
  power_off();
  uVar1 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar1 & 0xffffffbf);
  return;
}

