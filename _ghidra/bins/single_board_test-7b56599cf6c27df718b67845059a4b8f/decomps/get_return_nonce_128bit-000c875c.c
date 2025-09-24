
/* WARNING: Unknown calling convention */

void get_return_nonce_128bit(uint32_t *buf)

{
  uint32_t val0;
  uint32_t val1;
  uint32_t val2;
  uint32_t val3;
  
  val0 = 0;
  val1 = 0;
  val2 = 0;
  val3 = 0;
  fpga_read(4,&val0);
  fpga_read(5,&val1);
  fpga_read(4,&val2);
  fpga_read(5,&val3);
  *buf = val0;
  buf[1] = val1;
  buf[2] = val2;
  buf[3] = val3;
  return;
}

