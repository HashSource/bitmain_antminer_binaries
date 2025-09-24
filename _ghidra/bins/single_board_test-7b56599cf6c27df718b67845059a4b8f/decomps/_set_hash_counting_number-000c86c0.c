
/* WARNING: Unknown calling convention */

void _set_hash_counting_number(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x16,value);
  fpga_read(0x16,&tmp);
  return;
}

