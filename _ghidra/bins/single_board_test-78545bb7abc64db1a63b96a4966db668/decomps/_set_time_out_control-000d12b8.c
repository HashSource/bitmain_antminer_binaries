
/* WARNING: Unknown calling convention */

void _set_time_out_control(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x14,value);
  fpga_read(0x14,&tmp);
  return;
}

