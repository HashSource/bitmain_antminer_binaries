
/* WARNING: Unknown calling convention */

void set_BC_command_buffer(uint *value)

{
  uint *puVar1;
  
  puVar1 = axi_fpga_addr;
  axi_fpga_addr[0x31] = *value;
  puVar1[0x32] = value[1];
  puVar1[0x33] = value[2];
  return;
}

