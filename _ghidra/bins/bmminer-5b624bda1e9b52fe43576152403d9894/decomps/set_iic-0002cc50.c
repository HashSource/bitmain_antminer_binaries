
/* WARNING: Unknown calling convention */

uchar set_iic(uint data)

{
  axi_fpga_addr[0xc] = data & 0x7fffffff;
  do {
    usleep(1000);
  } while (-1 < (int)axi_fpga_addr[0xc]);
  return (uchar)axi_fpga_addr[0xc];
}

