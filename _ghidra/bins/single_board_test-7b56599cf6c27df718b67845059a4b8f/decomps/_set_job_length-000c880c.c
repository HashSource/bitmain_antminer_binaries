
/* WARNING: Unknown calling convention */

void _set_job_length(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x2a,value);
  fpga_read(0x2a,&tmp);
  return;
}

