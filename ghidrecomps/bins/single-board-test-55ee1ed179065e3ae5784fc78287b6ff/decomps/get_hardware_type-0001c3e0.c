
undefined4 get_hardware_type(void)

{
  undefined4 uVar1;
  int local_c;
  
  local_c = 0;
  if (platform_inited == 0) {
    printf("%s:%d","get_hardware_type",0xde);
    puts("platform not inited");
    uVar1 = 2;
  }
  else {
    if (platform_is_t9 == 0) {
      fpga_read(v9_fpga_map._0_4_,&local_c);
    }
    else {
      fpga_read(t9_fpga_map,&local_c);
    }
    if (local_c < 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

