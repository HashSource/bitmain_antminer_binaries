
void set_fan_speed(undefined4 param_1)

{
  write_axi_fpga(0x21,param_1);
  return;
}

