
/* WARNING: Unknown calling convention */

uint get_crc_count(void)

{
  uint ret;
  
  return axi_fpga_addr[0x3e] & 0xffff;
}

