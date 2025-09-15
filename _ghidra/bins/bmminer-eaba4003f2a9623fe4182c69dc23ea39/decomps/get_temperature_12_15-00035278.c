
/* WARNING: Unknown calling convention */

int get_temperature_12_15(void)

{
  int ret;
  
  return axi_fpga_addr[0xb];
}

