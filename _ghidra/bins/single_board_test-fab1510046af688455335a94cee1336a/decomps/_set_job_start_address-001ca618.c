
/* WARNING: Unknown calling convention */

void _set_job_start_address(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x29,value);
  fpga_read(0x29,&tmp);
  return;
}

