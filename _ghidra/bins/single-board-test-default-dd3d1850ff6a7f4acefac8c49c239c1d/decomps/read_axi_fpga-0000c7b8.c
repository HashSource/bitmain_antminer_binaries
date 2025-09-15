
undefined4 read_axi_fpga(int param_1)

{
  return *(undefined4 *)(axi_fpga_addr + param_1 * 4);
}

