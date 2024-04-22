
undefined4 pwm_set(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 + -1 < 2) {
    if (param_1 == 1) {
      if (99 < param_2) {
        param_2 = 100;
      }
      if (platform_is_t9 == 0) {
        fpga_write(v9_fpga_map._72_4_,100 - param_2 | param_2 << 0x10);
      }
      else {
        fpga_write(DAT_00035598,100 - param_2 | param_2 << 0x10);
      }
    }
    else {
      printf("%s:%d","pwm_set",0x37);
      printf("pwm type %d not supported\n",param_1 + -1);
    }
    uVar1 = 0;
  }
  else {
    printf("%s:%d","pwm_set",0x2d);
    puts("bad param");
    uVar1 = 0xfffffffd;
  }
  return uVar1;
}

