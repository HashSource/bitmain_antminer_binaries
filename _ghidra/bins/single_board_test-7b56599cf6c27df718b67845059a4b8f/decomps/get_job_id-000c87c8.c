
/* WARNING: Unknown calling convention */

uint32_t get_job_id(void)

{
  uint32_t val;
  
  fpga_read(0x2c,&val);
  return val;
}

