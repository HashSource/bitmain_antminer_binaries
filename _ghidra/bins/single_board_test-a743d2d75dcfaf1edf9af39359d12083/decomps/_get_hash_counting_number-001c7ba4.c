
/* WARNING: Unknown calling convention */

uint32_t _get_hash_counting_number(void)

{
  uint32_t value;
  
  fpga_read(0x16,&value);
  return value;
}

