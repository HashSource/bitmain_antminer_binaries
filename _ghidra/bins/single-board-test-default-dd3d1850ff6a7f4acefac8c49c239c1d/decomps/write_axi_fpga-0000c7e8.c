
void write_axi_fpga(int param_1,undefined4 param_2)

{
  *(undefined4 *)(axi_fpga_addr + param_1 * 4) = param_2;
  return;
}

