
void chain_reset_low(uint param_1)

{
  uint local_c;
  
  local_c = 0;
  if (platform_is_t9 == 0) {
    fpga_read(v9_fpga_map._48_4_,&local_c);
  }
  else {
    fpga_read(DAT_00035580,&local_c);
  }
  local_c = local_c | 1 << (param_1 & 0xff);
  if (platform_is_t9 == 0) {
    fpga_write(v9_fpga_map._48_4_,local_c);
  }
  else {
    fpga_write(DAT_00035580,local_c);
  }
  return;
}

