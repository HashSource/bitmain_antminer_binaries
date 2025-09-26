
/* WARNING: Unknown calling convention */

void _set_ticket_mask(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x15,value);
  fpga_read(0x15,&tmp);
  return;
}

