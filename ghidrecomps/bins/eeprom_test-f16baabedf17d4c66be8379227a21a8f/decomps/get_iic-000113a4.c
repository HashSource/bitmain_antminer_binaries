
/* WARNING: Unknown calling convention */

uint get_iic(void)

{
  int ret;
  
  return axi_fpga_addr[0xc];
}

