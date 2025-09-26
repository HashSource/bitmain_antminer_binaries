
/* WARNING: Unknown calling convention */

uint32_t get_crc_count(void)

{
  uint32_t val;
  
  fpga_read(0x21,&val);
  return (uint)(ushort)val;
}

