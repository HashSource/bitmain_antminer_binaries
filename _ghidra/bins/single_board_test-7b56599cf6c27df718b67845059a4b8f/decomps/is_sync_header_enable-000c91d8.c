
/* WARNING: Unknown calling convention */

uchar is_sync_header_enable(void)

{
  uint32_t local_c [2];
  
  local_c[0] = 0;
  fpga_read(0,local_c);
  return (uchar)((local_c[0] << 1) >> 0x1f);
}

