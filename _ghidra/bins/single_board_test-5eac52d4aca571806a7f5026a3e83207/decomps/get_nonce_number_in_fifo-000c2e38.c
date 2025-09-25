
/* WARNING: Unknown calling convention */

uint32_t get_nonce_number_in_fifo(void)

{
  uint32_t val;
  
  fpga_read(6,&val);
  return val & 0x7fff;
}

