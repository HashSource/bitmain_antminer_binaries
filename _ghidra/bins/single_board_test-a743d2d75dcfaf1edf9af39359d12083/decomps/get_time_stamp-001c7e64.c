
/* WARNING: Unknown calling convention */

uint32_t get_time_stamp(void)

{
  uint32_t val;
  
  fpga_read(0x2f,&val);
  return val;
}

