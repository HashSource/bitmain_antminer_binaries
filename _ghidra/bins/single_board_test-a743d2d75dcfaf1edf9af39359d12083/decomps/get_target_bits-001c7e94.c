
/* WARNING: Unknown calling convention */

uint32_t get_target_bits(void)

{
  uint32_t val;
  
  fpga_read(0x30,&val);
  return val;
}

