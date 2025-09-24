
/* WARNING: Unknown calling convention */

int32_t pwm_init(bitmain_pwm_type_e type,uint32_t freq)

{
  int iVar1;
  char tmp42 [2048];
  
  if (platform_inited == 0) {
    builtin_strncpy(tmp42,"please init platform first!!",0x1c);
    tmp42[0x1c] = '\n';
    tmp42[0x1d] = '\0';
    _applog(0,tmp42,false);
    iVar1 = -2;
  }
  else if (type < PWM_CTRL_MAX) {
    iVar1 = type + PWM_CTRL_POWER;
  }
  else {
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
    iVar1 = -3;
  }
  return iVar1;
}

