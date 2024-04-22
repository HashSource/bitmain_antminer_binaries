
undefined4 get_fan_control(void)

{
  return *(undefined4 *)(axi_fpga_addr + 0x84);
}

