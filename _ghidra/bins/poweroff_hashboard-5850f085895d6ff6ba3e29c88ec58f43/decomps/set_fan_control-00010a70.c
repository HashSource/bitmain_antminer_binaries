
void set_fan_control(undefined4 param_1)

{
  *(undefined4 *)(axi_fpga_addr + 0x84) = param_1;
  get_fan_control();
  return;
}

