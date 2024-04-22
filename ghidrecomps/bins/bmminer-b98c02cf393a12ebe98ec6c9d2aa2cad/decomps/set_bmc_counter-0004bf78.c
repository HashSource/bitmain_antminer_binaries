
void set_bmc_counter(undefined4 param_1)

{
  *(undefined4 *)(axi_fpga_addr + 0x38) = param_1;
  return;
}

