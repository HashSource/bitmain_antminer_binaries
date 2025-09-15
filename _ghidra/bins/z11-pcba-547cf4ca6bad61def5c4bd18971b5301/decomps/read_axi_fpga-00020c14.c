
undefined4 read_axi_fpga(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + axi_fpga_addr);
}

