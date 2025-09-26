
/* WARNING: Unknown calling convention */

int32_t set_hardware_type(bitmain_hardware_type_e type)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0,&val);
  if (type == S9_HARDWARE) {
    val = val & 0x7fffffff;
  }
  else if (type == T9_PLUS_HARDWARE) {
    val = val | 0x80000000;
  }
  fpga_write(0,val);
  return 0;
}

