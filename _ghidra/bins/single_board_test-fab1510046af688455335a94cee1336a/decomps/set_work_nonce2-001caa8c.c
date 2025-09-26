
/* WARNING: Unknown calling convention */

void set_work_nonce2(uint32_t *value)

{
  uint32_t tmp;
  
  fpga_write(0x25,*value);
  fpga_write(0x26,value[1]);
  fpga_read(0x25,&tmp);
  fpga_read(0x26,&tmp);
  return;
}

