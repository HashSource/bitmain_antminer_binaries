
/* WARNING: Unknown calling convention */

void set_fan_speed(uint speed)

{
  write_axi_fpga(0x21,speed);
  return;
}

