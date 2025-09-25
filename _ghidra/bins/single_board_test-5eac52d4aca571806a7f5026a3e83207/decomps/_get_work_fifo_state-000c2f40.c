
/* WARNING: Unknown calling convention */

uint32_t _get_work_fifo_state(void)

{
  uint32_t val;
  
  fpga_read(3,&val);
  return val;
}

