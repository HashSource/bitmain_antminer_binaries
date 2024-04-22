
/* WARNING: Unknown calling convention */

void set_TW_write_command(uint *value)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = axi_fpga_addr;
  puVar2 = value + 0xc;
  axi_fpga_addr[0x10] = *value;
  do {
    value = value + 1;
    puVar1[0x11] = *value;
  } while (value != puVar2);
  return;
}

