
/* WARNING: Unknown calling convention */

uint32_t _get_job_start_address(void)

{
  uint32_t val;
  
  fpga_read(0x29,&val);
  return val;
}

