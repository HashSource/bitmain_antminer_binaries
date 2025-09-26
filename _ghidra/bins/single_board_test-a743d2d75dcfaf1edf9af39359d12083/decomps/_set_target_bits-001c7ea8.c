
/* WARNING: Unknown calling convention */

void _set_target_bits(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x30,value);
  fpga_read(0x30,&tmp);
  return;
}

