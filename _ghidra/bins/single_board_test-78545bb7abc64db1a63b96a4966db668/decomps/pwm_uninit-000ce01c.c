
/* WARNING: Unknown calling convention */

void pwm_uninit(int32_t ctx)

{
  char tmp42 [2048];
  
  if (ctx < 3) {
    pwm_param[ctx + -1].freq = 0;
    pwm_param[ctx + -1].inited = '\0';
    return;
  }
  builtin_strncpy(tmp42,"bad para",8);
  tmp42[8] = 'm';
  tmp42[9] = '\n';
  tmp42[10] = '\0';
  _applog(0,tmp42,false);
  return;
}

