
void singleboard_sensor_test(void)

{
  int iVar1;
  char acStack_428 [1024];
  int local_28 [4];
  byte local_16;
  byte local_15;
  uint local_14;
  uint local_10;
  int local_c;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_428,0x400,"%s Begin\n","singleboard_sensor_test");
    _applog(2,acStack_428,0);
  }
  set_i2c_enable();
  usleep(200000);
  local_15 = 0;
  local_16 = 0;
  local_10 = 0;
  local_14 = 100;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  do {
    sleep(5);
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      local_15 = 0;
      local_16 = 0;
      iVar1 = read_sensor(0,local_c,0x4c,1,&local_16);
      if (iVar1 == 5) {
        local_28[local_c * 2 + 1] = 1;
        *(byte *)((int)&sensor_info + local_c * 4 + 1) = local_16;
        if ((int)local_10 < (int)(uint)local_16) {
          local_10 = (uint)local_16;
        }
        if ((int)(uint)local_16 < (int)local_14) {
          local_14 = (uint)local_16;
        }
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_428,0x400,"Read Success Sensor%d ext-temp=%d\n\n",local_c,(uint)local_16)
          ;
          _applog(2,acStack_428,0);
        }
      }
      else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_428,0x400,"Read Fail ext-temp Sensor%d, try again\n",local_c);
        _applog(2,acStack_428,0);
      }
      usleep(100000);
      iVar1 = read_sensor(0,local_c,0x4c,0,&local_15);
      if (iVar1 == 5) {
        local_28[local_c * 2] = 1;
        *(byte *)((int)&sensor_info + local_c * 4) = local_15;
        if ((int)local_10 < (int)(uint)local_15) {
          local_10 = (uint)local_15;
        }
        if ((int)(uint)local_15 < (int)local_14) {
          local_14 = (uint)local_15;
        }
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_428,0x400,"Read Success Sensor%d local-temp=%d\n\n",local_c,
                   (uint)local_15);
          _applog(2,acStack_428,0);
        }
      }
      else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_428,0x400,"Read Fail local-temp Sensor%d, try again\n",local_c);
        _applog(2,acStack_428,0);
      }
      usleep(100000);
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_428,0x400,"%s high %d low %d\n","singleboard_sensor_test",local_10,local_14);
      _applog(2,acStack_428,0);
    }
    if ((((local_28[0] < 1) || (local_28[1] < 1)) || (local_28[2] < 1)) || (local_28[3] < 1)) {
      read_temp_test_result = 0xffffffff;
    }
    else {
      read_temp_test_result = 1;
      if (((int)local_10 < (int)app_conf._424_4_) && ((int)app_conf._428_4_ < (int)local_14)) {
        tempture_value_test_result = 1;
      }
      else {
        tempture_value_test_result = 0xffffffff;
      }
    }
  } while( true );
}

