
void write_axi_fpga(uint address,uint data)

{
  uint data_local;
  uint address_local;
  
  axi_fpga_addr[address] = data;
  return;
}

