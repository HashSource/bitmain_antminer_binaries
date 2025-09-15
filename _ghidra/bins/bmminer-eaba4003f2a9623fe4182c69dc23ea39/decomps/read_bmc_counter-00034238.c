
/* WARNING: Unknown calling convention */

uint read_bmc_counter(void)

{
  uint ret;
  
  return axi_fpga_addr[0xe];
}

