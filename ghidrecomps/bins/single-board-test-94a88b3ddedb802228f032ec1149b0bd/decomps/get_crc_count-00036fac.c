
uint get_crc_count(void)

{
  return *(uint *)(axi_fpga_addr + 0xf8) & 0xffff;
}

