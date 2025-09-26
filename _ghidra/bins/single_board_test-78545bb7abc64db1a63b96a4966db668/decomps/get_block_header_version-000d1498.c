
/* WARNING: Unknown calling convention */

uint32_t get_block_header_version(void)

{
  uint32_t val;
  
  fpga_read(0x2e,&val);
  return val;
}

