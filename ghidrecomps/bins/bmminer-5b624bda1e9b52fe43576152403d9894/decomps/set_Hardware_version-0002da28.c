
/* WARNING: Unknown calling convention */

void set_Hardware_version(uint value)

{
  *axi_fpga_addr = value;
  return;
}

