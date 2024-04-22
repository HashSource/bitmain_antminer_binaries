
/* WARNING: Unknown calling convention */

uint read_bmc_counter(void)

{
  return axi_fpga_addr[0xe];
}

