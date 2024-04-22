
/* WARNING: Unknown calling convention */

void set_fpga_baud(uchar asic_baud)

{
  fpga_bt8d_t fpga_bt8d;
  
  axi_fpga_addr[0xf] = axi_fpga_addr[0xf] & 0xffc0ffff | (asic_baud & 0x3f) << 0x10;
  return;
}

