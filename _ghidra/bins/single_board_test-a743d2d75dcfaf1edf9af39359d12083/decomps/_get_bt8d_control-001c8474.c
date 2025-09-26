
/* WARNING: Unknown calling convention */

uint32_t _get_bt8d_control(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0xf,&val);
  return val;
}

