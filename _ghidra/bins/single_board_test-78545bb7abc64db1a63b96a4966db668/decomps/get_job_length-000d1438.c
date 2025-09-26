
/* WARNING: Unknown calling convention */

uint32_t get_job_length(void)

{
  uint32_t val;
  
  fpga_read(0x2a,&val);
  return val;
}

