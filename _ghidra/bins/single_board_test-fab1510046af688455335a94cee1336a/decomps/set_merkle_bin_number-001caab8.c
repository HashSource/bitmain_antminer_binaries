
/* WARNING: Unknown calling convention */

void set_merkle_bin_number(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x28,value & 0xffff);
  fpga_read(0x28,&tmp);
  return;
}

