
/* WARNING: Unknown calling convention */

int32_t set_nonce2_offset(uint16_t len)

{
  uint32_t tmp;
  uint32_t tmp_1;
  
  fpga_read(0x24,&tmp);
  fpga_write(0x24,CONCAT22(len,(undefined2)tmp));
  fpga_read(0x24,&tmp_1);
  return 0;
}

