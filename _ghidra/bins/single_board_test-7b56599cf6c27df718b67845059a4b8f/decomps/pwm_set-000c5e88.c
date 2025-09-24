
/* WARNING: Unknown calling convention */

int32_t pwm_set(int32_t ctx,uint32_t duty)

{
  int32_t iVar1;
  uint val;
  char tmp42 [2048];
  
  if (ctx < 3) {
    if (ctx + -1 == 0) {
      if (99 < duty) {
        duty = 100;
      }
      val = 100 - duty | duty << 0x10;
      fpga_write(0x13,val);
      fpga_write(0x17,val);
      return 0;
    }
    iVar1 = 0;
    snprintf(tmp42,0x800,"pwm type %d not supported\n",ctx + -1);
    _applog(0,tmp42,false);
  }
  else {
    iVar1 = -3;
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
  }
  return iVar1;
}

