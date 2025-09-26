
/* WARNING: Unknown calling convention */

void get_return_nonce(uint32_t *buf)

{
  uint32_t val1;
  uint32_t val2;
  
  fpga_read(4,&val1);
  fpga_read(5,&val2);
  *buf = val1;
  buf[1] = val2;
  return;
}

