
/* WARNING: Unknown calling convention */

void write_axi_fpga(uint address,uint data)

{
  axi_fpga_addr[address] = data;
  return;
}

