
/* WARNING: Unknown calling convention */

void _set_job_id(uint32_t value)

{
  uint32_t tmp;
  
  fpga_write(0x2c,value);
  fpga_read(0x2c,&tmp);
  return;
}

