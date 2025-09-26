
/* WARNING: Unknown calling convention */

int32_t set_nonce2_offset(uint16_t len)

{
  uint32_t tmp;
  
  fpga_read(0x24,&tmp);
  _set_coinbase_length_and_nonce2_length(CONCAT22(len,(undefined2)tmp));
  return 0;
}

