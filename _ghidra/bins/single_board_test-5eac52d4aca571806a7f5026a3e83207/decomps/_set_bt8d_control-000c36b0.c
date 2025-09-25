
/* WARNING: Unknown calling convention */

void _set_bt8d_control(uint32_t value)

{
  fpga_write(0xf,value);
  return;
}

