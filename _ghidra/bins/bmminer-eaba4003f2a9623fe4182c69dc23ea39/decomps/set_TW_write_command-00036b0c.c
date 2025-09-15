
void set_TW_write_command(uint *value)

{
  uint *value_local;
  uint i;
  
  for (i = 0; i < 0xd; i = i + 1) {
    axi_fpga_addr[i + 0x10] = value[i];
  }
  return;
}

