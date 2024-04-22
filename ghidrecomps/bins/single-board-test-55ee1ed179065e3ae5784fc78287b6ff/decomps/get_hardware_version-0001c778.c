
uint get_hardware_version(void)

{
  uint local_c;
  
  local_c = 0;
  if (platform_inited == 0) {
    printf("%s:%d","get_hardware_version",0x12d);
    puts("platform not inited");
    local_c = 0;
  }
  else {
    if (platform_is_t9 == 0) {
      fpga_read(v9_fpga_map._0_4_,&local_c);
    }
    else {
      fpga_read(t9_fpga_map,&local_c);
    }
    local_c = local_c & 0xffff;
  }
  return local_c;
}

