
undefined4 set_hardware_type(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  
  local_c = 0;
  if (platform_inited == 0) {
    printf("%s:%d","set_hardware_type",0xed);
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
    if (param_1 == 0) {
      local_c = local_c & 0x7fffffff;
    }
    else if (param_1 == 1) {
      local_c = local_c | 0x80000000;
    }
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

