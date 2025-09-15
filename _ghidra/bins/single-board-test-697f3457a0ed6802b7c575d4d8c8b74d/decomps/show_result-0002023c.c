
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_result(void)

{
  runtime_base_t *prVar1;
  int iVar2;
  char tmp42 [1024];
  int which_asic;
  runtime_base_t *runtime;
  int i;
  
  prVar1 = cgpu.runtime;
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    memcpy(tmp42,
           "---------------------------------result-----------------------------------------------\n"
           ,0x58);
    _applog(2,tmp42,false);
  }
  read_temp_test_result = 1;
  for (i = 0; i < prVar1->sensor_num; i = i + 1) {
    iVar2 = prVar1->sensor_pos[i];
    if (((int)(uint)chip_temp[iVar2] < app_conf->pcba_tempture_low) ||
       (app_conf->pcba_tempture_high < (int)(uint)chip_temp[iVar2])) {
      if ((use_syslog != false) || ((opt_log_output != false || (-1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"Sensor %d CHIP temp wrong!\n",prVar1->sensor_pos[0] + 1);
        _applog(0,tmp42,false);
      }
      read_temp_test_result = -1;
    }
    if (((int)(uint)pcb_temp[iVar2] < app_conf->pcba_tempture_low) ||
       (app_conf->pcba_tempture_high < (int)(uint)pcb_temp[iVar2])) {
      if ((use_syslog != false) || ((opt_log_output != false || (-1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"Sensor %d PCB temp wrong!\n",prVar1->sensor_pos[0] + 1);
        _applog(0,tmp42,false);
      }
      read_temp_test_result = -1;
    }
  }
  if (read_temp_test_result < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Sensor NG.\n",0xc);
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"Sensor OK.\n",0xc);
    _applog(2,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Expect pass rate: %d, real pattern rate: %.2f\n",
             app_conf->pcba_pattern_pass_rate,(double)(g_patten.total_rate * 100.0));
    _applog(2,tmp42,false);
  }
  if (app_conf->pcba_enable_level == 1) {
    pattern_result = 1;
    if ((double)(g_patten.total_rate * 100.0) < *app_conf->pcba_level_rate) {
      if ((double)(g_patten.total_rate * 100.0) < app_conf->pcba_level_rate[1]) {
        if ((double)(g_patten.total_rate * 100.0) < app_conf->pcba_level_rate[2]) {
          pattern_level = 4;
          pattern_result = -1;
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            builtin_strncpy(tmp42,"Pattern NG.\n",0xc);
            tmp42[0xc] = '\0';
            _applog(2,tmp42,false);
          }
        }
        else {
          pattern_level = 3;
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
            tmp42[0xc] = '\0';
            _applog(2,tmp42,false);
          }
        }
      }
      else {
        pattern_level = 2;
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
          tmp42[0xc] = '\0';
          _applog(2,tmp42,false);
        }
      }
    }
    else {
      pattern_level = 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
        tmp42[0xc] = '\0';
        _applog(2,tmp42,false);
      }
    }
  }
  else {
    pattern_level = 1;
    if (g_patten.total_rate * 100.0 < (float)(longlong)app_conf->pcba_pattern_pass_rate) {
      pattern_result = -1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Pattern NG.\n",0xc);
        tmp42[0xc] = '\0';
        _applog(2,tmp42,false);
      }
    }
    else {
      pattern_result = 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
        tmp42[0xc] = '\0';
        _applog(2,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    memcpy(tmp42,
           "--------------------------------------------------------------------------------------\n"
           ,0x58);
    _applog(2,tmp42,false);
  }
  return;
}

