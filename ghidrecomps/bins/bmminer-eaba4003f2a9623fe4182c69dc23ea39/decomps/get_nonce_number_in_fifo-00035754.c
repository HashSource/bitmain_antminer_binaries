
/* WARNING: Unknown calling convention */

int get_nonce_number_in_fifo(void)

{
  int ret;
  
  return axi_fpga_addr[6];
}

