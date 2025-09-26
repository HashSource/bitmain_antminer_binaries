
/* WARNING: Unknown calling convention */

uint32_t _get_nonce_fifo_interrupt(void)

{
  uint32_t val;
  
  fpga_read(7,&val);
  return val;
}

