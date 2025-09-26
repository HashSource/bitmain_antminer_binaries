
/* WARNING: Unknown calling convention */

int32_t set_coinbase_length(uint16_t len)

{
  uint32_t tmp;
  
  fpga_read(0x24,&tmp);
  _set_coinbase_length_and_nonce2_length(tmp & 0xffffff00 | (uint)len);
  return 0;
}

