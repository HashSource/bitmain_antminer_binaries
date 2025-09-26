
/* WARNING: Unknown calling convention */

int32_t flush_nonce3_buffer(void)

{
  uint32_t val;
  
  fpga_read(7,&val);
  fpga_write(7,val | 0x10000);
  fpga_read(7,&val);
  return 0;
}

