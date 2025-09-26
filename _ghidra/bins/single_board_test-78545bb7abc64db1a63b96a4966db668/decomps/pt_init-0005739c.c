
int32_t pt_init(char *pattern_file_path,void *conf)

{
  int32_t iVar1;
  void *conf_local;
  char *pattern_file_path_local;
  char time_stamp [48];
  char tmp1 [256];
  
  g_rt.config = (config_ctx *)malloc(0x1cc);
  memset(g_rt.config,0,0x1cc);
  memcpy(g_rt.config,conf,0x1cc);
  dump_config(g_rt.config);
  iVar1 = platform_init();
  if (iVar1 == 0) {
    g_fan = pwm_init(PWM_CTRL_FAN,0);
    if (g_fan < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : init fan failed\n","pt_init");
      builtin_strncpy(tmp1,"init fan failed",0x10);
      log_to_file(tmp1,time_stamp);
      set_sweep_err_state(5,false);
      iVar1 = 5;
    }
    else {
      ((g_rt.config)->board).sensor.sensor_i2c_addr = 0x48;
      ((g_rt.config)->board).sensor.sensor_reg_addr = 0;
      iVar1 = 0;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : hal platform init failed\n","pt_init");
    builtin_strncpy(tmp1,"hal platform init failed",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
    set_sweep_err_state(4,false);
    iVar1 = 4;
  }
  return iVar1;
}

