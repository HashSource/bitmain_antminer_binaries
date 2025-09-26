
/* WARNING: Unknown calling convention */

int32_t disable_bypass_mode(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0,&val);
  val = val & 0xdfffffff;
  fpga_write(0,val);
  return 0;
}

