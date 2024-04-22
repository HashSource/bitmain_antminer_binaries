
/* WARNING: Unknown calling convention */

uint get_crc_count(void)

{
  return (uint)*(ushort *)(axi_fpga_addr + 0x3e);
}

