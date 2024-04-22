
int pwm_init(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  if (platform_inited == 0) {
    printf("%s:%d","pwm_init",0x10);
    puts("please init platform first!!");
    iVar1 = -2;
  }
  else if (param_1 < 2) {
    *(undefined4 *)(&pwm_param + param_1 * 8) = param_2;
    (&DAT_00235de8)[param_1 * 8] = 1;
    iVar1 = param_1 + 1;
  }
  else {
    printf("%s:%d","pwm_init",0x14);
    puts("bad param");
    iVar1 = -3;
  }
  return iVar1;
}

