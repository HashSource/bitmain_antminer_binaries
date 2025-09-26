
/* WARNING: Unknown calling convention */

uint32_t get_ticket_mask(void)

{
  uint32_t val;
  
  fpga_read(0x15,&val);
  return val;
}

