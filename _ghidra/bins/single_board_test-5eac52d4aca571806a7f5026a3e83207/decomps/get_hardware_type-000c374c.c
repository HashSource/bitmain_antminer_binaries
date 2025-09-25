
/* WARNING: Unknown calling convention */

bitmain_hardware_type_e get_hardware_type(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0,&val);
  return val >> 0x1f;
}

