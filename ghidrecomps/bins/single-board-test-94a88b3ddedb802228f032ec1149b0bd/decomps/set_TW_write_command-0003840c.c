
void set_TW_write_command(int param_1)

{
  uint local_c;
  
  for (local_c = 0; local_c < 0xd; local_c = local_c + 1) {
    *(undefined4 *)((local_c + 0x10) * 4 + axi_fpga_addr) = *(undefined4 *)(local_c * 4 + param_1);
  }
  return;
}

