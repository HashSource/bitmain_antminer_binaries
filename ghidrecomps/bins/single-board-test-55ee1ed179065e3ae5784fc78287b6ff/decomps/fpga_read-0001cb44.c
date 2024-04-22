
undefined4 fpga_read(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(axi_fpga_addr + param_1 * 4);
  return 0;
}

