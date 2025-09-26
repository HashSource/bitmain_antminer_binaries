
/* WARNING: Unknown calling convention */

uint32_t _get_hardware_version(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0,&val);
  return val;
}

