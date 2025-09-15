
void set_BC_command_buffer_t(uint *value)

{
  int iVar1;
  uint *value_local;
  uint buf [4];
  
  while (iVar1 = get_BC_write_command(), iVar1 < 0) {
    usleep(1000);
  }
  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
  buf[3] = 0;
  axi_fpga_addr[0x31] = *value;
  axi_fpga_addr[0x32] = value[1];
  axi_fpga_addr[0x33] = value[2];
  get_BC_command_buffer(buf);
  return;
}

