
void set_fan_speed(uint speed)

{
  uint speed_local;
  
  write_axi_fpga(0x21,speed);
  return;
}

