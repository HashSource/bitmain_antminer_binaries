
undefined4 read_bmc_counter(void)

{
  return *(undefined4 *)(axi_fpga_addr + 0x38);
}

