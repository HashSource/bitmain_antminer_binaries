
/* WARNING: Unknown calling convention */

void set_bmc_counter(uint value)

{
  axi_fpga_addr[0xe] = value;
  return;
}

