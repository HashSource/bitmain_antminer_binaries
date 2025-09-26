
/* WARNING: Unknown calling convention */

int32_t flush_nonce3_buffer(void)

{
  uint32_t val;
  
  fpga_read(7,&val);
  _set_nonce_fifo_interrupt(val | 0x10000);
  return 0;
}

