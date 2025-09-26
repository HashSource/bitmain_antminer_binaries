
/* WARNING: Unknown calling convention */

void _set_coinbase_length_and_nonce2_length(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x24,value);
  fpga_read(0x24,&tmp);
  return;
}

