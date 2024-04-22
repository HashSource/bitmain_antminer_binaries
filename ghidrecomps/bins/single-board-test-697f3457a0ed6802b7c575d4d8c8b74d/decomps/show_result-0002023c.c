
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void show_result(void)

{
  char cVar1;
  runtime_base_t *prVar2;
  int iVar3;
  char tmp42 [1024];
  int which_asic;
  runtime_base_t *runtime;
  int i;
  
  prVar2 = cgpu.runtime;
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    memcpy(tmp42,
           "---------------------------------result-----------------------------------------------\n"
           ,0x58);
    _applog(2,tmp42,false);
  }
  read_temp_test_result = 1;
  for (i = 0; i < prVar2->sensor_num; i = i + 1) {
    iVar3 = prVar2->sensor_pos[i];
    if (((int)(uint)chip_temp[iVar3] < app_conf->pcba_tempture_low) ||
       (app_conf->pcba_tempture_high < (int)(uint)chip_temp[iVar3])) {
      if ((use_syslog != false) || ((opt_log_output != false || (-1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"Sensor %d CHIP temp wrong!\n",prVar2->sensor_pos[0] + 1);
        _applog(0,tmp42,false);
      }
      read_temp_test_result = -1;
    }
    if (((int)(uint)pcb_temp[iVar3] < app_conf->pcba_tempture_low) ||
       (app_conf->pcba_tempture_high < (int)(uint)pcb_temp[iVar3])) {
      if ((use_syslog != false) || ((opt_log_output != false || (-1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"Sensor %d PCB temp wrong!\n",prVar2->sensor_pos[0] + 1);
        _applog(0,tmp42,false);
      }
      read_temp_test_result = -1;
    }
  }
  if (read_temp_test_result < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      tmp42[0] = s_Sensor_NG__000364b4[0];
      tmp42[1] = s_Sensor_NG__000364b4[1];
      tmp42[2] = s_Sensor_NG__000364b4[2];
      tmp42[3] = s_Sensor_NG__000364b4[3];
      tmp42[4] = s_Sensor_NG__000364b4[4];
      tmp42[5] = s_Sensor_NG__000364b4[5];
      tmp42[6] = s_Sensor_NG__000364b4[6];
      tmp42[7] = s_Sensor_NG__000364b4[7];
      tmp42[8] = s_Sensor_NG__000364b4[8];
      tmp42[9] = s_Sensor_NG__000364b4[9];
      tmp42[10] = s_Sensor_NG__000364b4[10];
      tmp42[11] = s_Sensor_NG__000364b4[11];
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_Sensor_OK__000364a8[0];
    tmp42[1] = s_Sensor_OK__000364a8[1];
    tmp42[2] = s_Sensor_OK__000364a8[2];
    tmp42[3] = s_Sensor_OK__000364a8[3];
    tmp42[4] = s_Sensor_OK__000364a8[4];
    tmp42[5] = s_Sensor_OK__000364a8[5];
    tmp42[6] = s_Sensor_OK__000364a8[6];
    tmp42[7] = s_Sensor_OK__000364a8[7];
    tmp42[8] = s_Sensor_OK__000364a8[8];
    tmp42[9] = s_Sensor_OK__000364a8[9];
    tmp42[10] = s_Sensor_OK__000364a8[10];
    tmp42[11] = s_Sensor_OK__000364a8[11];
    _applog(2,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Expect pass rate: %d, real pattern rate: %.2f\n",
             app_conf->pcba_pattern_pass_rate,(double)(g_patten.total_rate * DAT_00020808));
    _applog(2,tmp42,false);
  }
  cVar1 = (char)ram0x000364fc;
  if (app_conf->pcba_enable_level == 1) {
    pattern_result = 1;
    if ((double)(g_patten.total_rate * DAT_00020808) < *app_conf->pcba_level_rate ==
        (NAN((double)(g_patten.total_rate * DAT_00020808)) || NAN(*app_conf->pcba_level_rate))) {
      pattern_level = 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Pattern_OK__000364f0[0];
        tmp42[1] = s_Pattern_OK__000364f0[1];
        tmp42[2] = s_Pattern_OK__000364f0[2];
        tmp42[3] = s_Pattern_OK__000364f0[3];
        tmp42[4] = s_Pattern_OK__000364f0[4];
        tmp42[5] = s_Pattern_OK__000364f0[5];
        tmp42[6] = s_Pattern_OK__000364f0[6];
        tmp42[7] = s_Pattern_OK__000364f0[7];
        tmp42[8] = s_Pattern_OK__000364f0[8];
        tmp42[9] = s_Pattern_OK__000364f0[9];
        tmp42[10] = s_Pattern_OK__000364f0[10];
        tmp42[11] = s_Pattern_OK__000364f0[11];
        tmp42[12] = cVar1;
        _applog(2,tmp42,false);
      }
    }
    else if ((double)(g_patten.total_rate * DAT_00020808) < app_conf->pcba_level_rate[1] ==
             (NAN((double)(g_patten.total_rate * DAT_00020808)) || NAN(app_conf->pcba_level_rate[1])
             )) {
      pattern_level = 2;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Pattern_OK__000364f0[0];
        tmp42[1] = s_Pattern_OK__000364f0[1];
        tmp42[2] = s_Pattern_OK__000364f0[2];
        tmp42[3] = s_Pattern_OK__000364f0[3];
        tmp42[4] = s_Pattern_OK__000364f0[4];
        tmp42[5] = s_Pattern_OK__000364f0[5];
        tmp42[6] = s_Pattern_OK__000364f0[6];
        tmp42[7] = s_Pattern_OK__000364f0[7];
        tmp42[8] = s_Pattern_OK__000364f0[8];
        tmp42[9] = s_Pattern_OK__000364f0[9];
        tmp42[10] = s_Pattern_OK__000364f0[10];
        tmp42[11] = s_Pattern_OK__000364f0[11];
        tmp42[12] = cVar1;
        _applog(2,tmp42,false);
      }
    }
    else if ((double)(g_patten.total_rate * DAT_00020808) < app_conf->pcba_level_rate[2] ==
             (NAN((double)(g_patten.total_rate * DAT_00020808)) || NAN(app_conf->pcba_level_rate[2])
             )) {
      pattern_level = 3;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Pattern_OK__000364f0[0];
        tmp42[1] = s_Pattern_OK__000364f0[1];
        tmp42[2] = s_Pattern_OK__000364f0[2];
        tmp42[3] = s_Pattern_OK__000364f0[3];
        tmp42[4] = s_Pattern_OK__000364f0[4];
        tmp42[5] = s_Pattern_OK__000364f0[5];
        tmp42[6] = s_Pattern_OK__000364f0[6];
        tmp42[7] = s_Pattern_OK__000364f0[7];
        tmp42[8] = s_Pattern_OK__000364f0[8];
        tmp42[9] = s_Pattern_OK__000364f0[9];
        tmp42[10] = s_Pattern_OK__000364f0[10];
        tmp42[11] = s_Pattern_OK__000364f0[11];
        tmp42[12] = cVar1;
        _applog(2,tmp42,false);
      }
    }
    else {
      pattern_level = 4;
      pattern_result = -1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Pattern_NG__00036500[0];
        tmp42[1] = s_Pattern_NG__00036500[1];
        tmp42[2] = s_Pattern_NG__00036500[2];
        tmp42[3] = s_Pattern_NG__00036500[3];
        tmp42[4] = s_Pattern_NG__00036500[4];
        tmp42[5] = s_Pattern_NG__00036500[5];
        tmp42[6] = s_Pattern_NG__00036500[6];
        tmp42[7] = s_Pattern_NG__00036500[7];
        tmp42[8] = s_Pattern_NG__00036500[8];
        tmp42[9] = s_Pattern_NG__00036500[9];
        tmp42[10] = s_Pattern_NG__00036500[10];
        tmp42[11] = s_Pattern_NG__00036500[11];
        tmp42[12] = (char)ram0x0003650c;
        _applog(2,tmp42,false);
      }
    }
  }
  else {
    pattern_level = 1;
    if (g_patten.total_rate * DAT_00020808 < (float)(longlong)app_conf->pcba_pattern_pass_rate ==
        (NAN(g_patten.total_rate * DAT_00020808) ||
        NAN((float)(longlong)app_conf->pcba_pattern_pass_rate))) {
      pattern_result = 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Pattern_OK__000364f0[0];
        tmp42[1] = s_Pattern_OK__000364f0[1];
        tmp42[2] = s_Pattern_OK__000364f0[2];
        tmp42[3] = s_Pattern_OK__000364f0[3];
        tmp42[4] = s_Pattern_OK__000364f0[4];
        tmp42[5] = s_Pattern_OK__000364f0[5];
        tmp42[6] = s_Pattern_OK__000364f0[6];
        tmp42[7] = s_Pattern_OK__000364f0[7];
        tmp42[8] = s_Pattern_OK__000364f0[8];
        tmp42[9] = s_Pattern_OK__000364f0[9];
        tmp42[10] = s_Pattern_OK__000364f0[10];
        tmp42[11] = s_Pattern_OK__000364f0[11];
        tmp42[12] = cVar1;
        _applog(2,tmp42,false);
      }
    }
    else {
      pattern_result = -1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Pattern_NG__00036500[0];
        tmp42[1] = s_Pattern_NG__00036500[1];
        tmp42[2] = s_Pattern_NG__00036500[2];
        tmp42[3] = s_Pattern_NG__00036500[3];
        tmp42[4] = s_Pattern_NG__00036500[4];
        tmp42[5] = s_Pattern_NG__00036500[5];
        tmp42[6] = s_Pattern_NG__00036500[6];
        tmp42[7] = s_Pattern_NG__00036500[7];
        tmp42[8] = s_Pattern_NG__00036500[8];
        tmp42[9] = s_Pattern_NG__00036500[9];
        tmp42[10] = s_Pattern_NG__00036500[10];
        tmp42[11] = s_Pattern_NG__00036500[11];
        tmp42[12] = (char)ram0x0003650c;
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

