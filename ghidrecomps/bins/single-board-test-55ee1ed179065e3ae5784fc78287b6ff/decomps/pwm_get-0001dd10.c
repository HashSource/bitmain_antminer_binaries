
undefined4 pwm_get(int param_1,uint *param_2)

{
  undefined4 local_c;
  
  local_c = 0xfffffffb;
  if (param_1 + -1 < 2) {
    if (param_1 == 1) {
      if (platform_is_t9 == 0) {
        fpga_read(v9_fpga_map._72_4_,param_2);
      }
      else {
        fpga_read(DAT_00035598,param_2);
      }
      *param_2 = *param_2 >> 0x10;
      printf("%s:%d","pwm_get",0x4f);
      printf("duty of fpga = 0x%x\n",*param_2);
      local_c = 0;
    }
  }
  else {
    printf("%s:%d","pwm_get",0x47);
    puts("bad param");
    local_c = 0xfffffffd;
  }
  return local_c;
}

