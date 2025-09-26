
/* WARNING: Unknown calling convention */

int32_t set_nonce2_length(uint16_t len)

{
  uint32_t tmp;
  
  fpga_read(0x24,&tmp);
  _set_coinbase_length_and_nonce2_length(tmp & 0xffff00ff | (uint)len << 8);
  return 0;
}

