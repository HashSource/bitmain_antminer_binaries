
/* WARNING: Unknown calling convention */

int32_t set_coinbase_length(uint16_t len)

{
  uint32_t tmp;
  uint32_t tmp_1;
  
  fpga_read(0x24,&tmp);
  fpga_write(0x24,tmp & 0xffffff00 | (uint)len);
  fpga_read(0x24,&tmp_1);
  return 0;
}

