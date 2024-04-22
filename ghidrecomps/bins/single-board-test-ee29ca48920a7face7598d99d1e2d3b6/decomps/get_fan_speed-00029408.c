
undefined4 get_fan_speed(void)

{
  undefined4 uVar1;
  
  uVar1 = read_axi_fpga(1);
  return uVar1;
}

