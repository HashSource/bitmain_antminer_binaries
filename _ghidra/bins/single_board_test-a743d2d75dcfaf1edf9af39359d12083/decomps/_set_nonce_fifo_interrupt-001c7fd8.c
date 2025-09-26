
/* WARNING: Unknown calling convention */

void _set_nonce_fifo_interrupt(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(7,value);
  fpga_read(7,&tmp);
  return;
}

