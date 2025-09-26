
/* WARNING: Unknown calling convention */

void _set_hardware_version(uint32_t value)

{
  fpga_write(0,value);
  return;
}

