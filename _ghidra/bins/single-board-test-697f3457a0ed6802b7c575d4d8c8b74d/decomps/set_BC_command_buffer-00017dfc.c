
void set_BC_command_buffer(uint *value)

{
  uint *value_local;
  
  write_axi_fpga(0x31,*value);
  write_axi_fpga(0x32,value[1]);
  write_axi_fpga(0x33,value[2]);
  return;
}

