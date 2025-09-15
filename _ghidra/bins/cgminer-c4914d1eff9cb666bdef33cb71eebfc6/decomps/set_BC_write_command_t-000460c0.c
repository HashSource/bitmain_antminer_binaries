
void set_BC_write_command_t(uint value)

{
  uint value_local;
  
  axi_fpga_addr[0x30] = value;
  return;
}

