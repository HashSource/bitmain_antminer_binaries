
undefined4 disable_bypass_mode(void)

{
  undefined4 uVar1;
  uint local_c;
  
  local_c = 0;
  if (platform_inited == 0) {
    printf("%s:%d","disable_bypass_mode",0x112);
    puts("platform not inited");
    uVar1 = 0xfffffffe;
  }
  else {
    if (platform_is_t9 == 0) {
      fpga_read(v9_fpga_map._0_4_,&local_c);
    }
    else {
      fpga_read(t9_fpga_map,&local_c);
    }
    local_c = local_c & 0xdfffffff;
    if (platform_is_t9 == 0) {
      fpga_write(v9_fpga_map._0_4_,local_c);
    }
    else {
      fpga_write(t9_fpga_map,local_c);
    }
    uVar1 = 0;
  }
  return uVar1;
}

