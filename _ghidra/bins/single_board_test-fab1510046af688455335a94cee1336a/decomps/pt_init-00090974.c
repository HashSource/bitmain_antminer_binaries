
int32_t pt_init(char *pattern_file_path,void *conf)

{
  int32_t iVar1;
  void *conf_local;
  char *pattern_file_path_local;
  char tmp42 [256];
  
  g_rt.config = (config_ctx *)malloc(0x198);
  memset(g_rt.config,0,0x198);
  memcpy(g_rt.config,conf,0x198);
  dump_config(g_rt.config);
  iVar1 = platform_init();
  if (iVar1 == 0) {
    g_fan = pwm_init(PWM_CTRL_FAN,0);
    if (g_fan < 0) {
      builtin_strncpy(tmp42,"init fan failed",0x10);
      puts(tmp42);
      iVar1 = 6;
    }
    else {
      ((g_rt.config)->board).sensor.sensor_i2c_addr = 0x48;
      ((g_rt.config)->board).sensor.sensor_reg_addr = 0;
      iVar1 = 0;
    }
  }
  else {
    builtin_strncpy(tmp42,"hal platform init failed",0x18);
    tmp42[0x18] = '\0';
    puts(tmp42);
    iVar1 = 5;
  }
  return iVar1;
}

