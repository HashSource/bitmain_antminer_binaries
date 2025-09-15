
void set_TW_write_command(undefined4 *param_1)

{
  uint local_c;
  
  write_axi_fpga(0x10,*param_1);
  for (local_c = 1; local_c < 0xd; local_c = local_c + 1) {
    write_axi_fpga(0x11,param_1[local_c]);
  }
  return;
}

