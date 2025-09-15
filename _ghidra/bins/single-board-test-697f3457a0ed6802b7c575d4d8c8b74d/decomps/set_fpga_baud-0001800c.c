
void set_fpga_baud(uchar asic_baud)

{
  byte bVar1;
  uchar asic_baud_local;
  uchar fpga_baud;
  
  bVar1 = asic_baud_to_fpga_baud(asic_baud);
  write_axi_fpga(0xf,(uint)bVar1);
  return;
}

