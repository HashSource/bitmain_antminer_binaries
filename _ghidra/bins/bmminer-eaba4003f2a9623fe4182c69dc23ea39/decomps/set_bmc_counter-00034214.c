
void set_bmc_counter(uint value)

{
  uint value_local;
  
  axi_fpga_addr[0xe] = value;
  return;
}

