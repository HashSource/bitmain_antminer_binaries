
/* WARNING: Unknown calling convention */

void get_return_nonce(uint *buf)

{
  uint *puVar1;
  
  puVar1 = axi_fpga_addr;
  *buf = axi_fpga_addr[4];
  buf[1] = puVar1[5];
  return;
}

