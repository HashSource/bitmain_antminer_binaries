
bool is_bypass_mode_enable(void)

{
  bool bVar1;
  uint local_c;
  
  local_c = 0;
  if (platform_inited == 0) {
    printf("%s:%d","is_bypass_mode_enable",0x120);
    puts("platform not inited");
    bVar1 = false;
  }
  else {
    if (platform_is_t9 == 0) {
      fpga_read(v9_fpga_map._0_4_,&local_c);
    }
    else {
      fpga_read(t9_fpga_map,&local_c);
    }
    bVar1 = (local_c & 0x20000000) != 0;
  }
  return bVar1;
}

