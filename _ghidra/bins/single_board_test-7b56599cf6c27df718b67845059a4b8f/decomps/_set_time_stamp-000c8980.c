
/* WARNING: Unknown calling convention */

void _set_time_stamp(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x2f,value);
  fpga_read(0x2f,&tmp);
  return;
}

