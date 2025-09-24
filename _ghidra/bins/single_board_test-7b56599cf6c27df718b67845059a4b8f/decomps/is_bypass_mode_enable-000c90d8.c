
/* WARNING: Unknown calling convention */

uchar is_bypass_mode_enable(void)

{
  uint32_t local_c [2];
  
  local_c[0] = 0;
  fpga_read(0,local_c);
  return (uchar)((local_c[0] << 2) >> 0x1f);
}

