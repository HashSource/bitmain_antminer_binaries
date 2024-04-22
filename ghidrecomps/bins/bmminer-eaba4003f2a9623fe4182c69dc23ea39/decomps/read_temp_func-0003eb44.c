
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void * read_temp_func(void)

{
  bool bVar1;
  all_parameters *paVar2;
  int16_t iVar3;
  int iVar4;
  uint uVar5;
  char tmp42 [2048];
  int mintemp [4];
  int maxtemp [4];
  int16_t temp_low [4];
  int16_t temp_top [4];
  int chain_asic_temp_error [16] [8];
  timeval diff;
  char error_info [256];
  char logstr [1024];
  Temp_Type_E temp_Type;
  _Bool already_offside;
  uint ret3;
  uint ret2;
  uint ret1;
  uint ret0;
  uint ret;
  _Bool readTempHasSomeOneFailed;
  int fatal_error_counter;
  int cur_fan_num;
  int j;
  int i;
  
  memset(chain_asic_temp_error,0,0x200);
  fatal_error_counter = 0;
  do {
    pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
    memset(temp_top,0,8);
    memset(temp_low,0,8);
    bVar1 = false;
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        maxtemp[0] = 0;
        maxtemp[1] = 0;
        maxtemp[2] = 0;
        mintemp[0] = 1000;
        mintemp[1] = 1000;
        mintemp[2] = 1000;
        for (j = 0; j < dev->chain_asic_temp_num[i]; j = j + 1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Chain[%d] Chip[%d] TempTypeID=%02x middle offset=%d\n",i,
                     (dev->TempChipAddr[i][j] >> 1) + 1,(uint)dev->TempChipType[i][j],
                     (int)middle_Offset[i][j]);
            _applog(5,tmp42,false);
          }
          uVar5 = check_reg_temp(DEVICEADDR[i],0,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar2 = dev;
          if (uVar5 == 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][0]);
              _applog(5,tmp42,false);
            }
            bVar1 = true;
          }
          else {
            iVar3 = get_local((ushort)uVar5 & 0xff);
            paVar2->chain_asic_temp[i][j][0] = iVar3;
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"Chain[%d] Chip[%d] local Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][0]);
              _applog(5,tmp42,false);
            }
          }
          uVar5 = check_reg_temp(DEVICEADDR[i],1,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar2 = dev;
          if (uVar5 == 0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][1]);
              _applog(7,tmp42,false);
            }
          }
          else {
            iVar3 = get_remote((ushort)uVar5 & 0xff);
            paVar2->chain_asic_temp[i][j][1] = iVar3;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Chain[%d] Chip[%d] middle Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][1]);
              _applog(7,tmp42,false);
            }
          }
          paVar2 = dev;
          if (((is218_Temp != false) || (chip_hasNoMiddle != false)) ||
             (dev->chain_asic_temp[i][j][1] < dev->chain_asic_temp[i][j][0])) {
            iVar4 = fakeMiddleTempFromPCB((int)dev->chain_asic_temp[i][j][0]);
            paVar2->chain_asic_temp[i][j][1] = (int16_t)iVar4;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Special fix Chain[%d] Chip[%d] middle Temp = %d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][1]);
              _applog(7,tmp42,false);
            }
          }
          if (maxtemp[0] < dev->chain_asic_temp[i][j][0]) {
            maxtemp[0] = (int)dev->chain_asic_temp[i][j][0];
          }
          if (maxtemp[1] < dev->chain_asic_temp[i][j][1]) {
            maxtemp[1] = (int)dev->chain_asic_temp[i][j][1];
          }
          if (maxtemp[2] < dev->chain_asic_temp[i][j][2]) {
            maxtemp[2] = (int)dev->chain_asic_temp[i][j][2];
          }
          if (dev->chain_asic_temp[i][j][0] < mintemp[0]) {
            mintemp[0] = (int)dev->chain_asic_temp[i][j][0];
          }
          if (dev->chain_asic_temp[i][j][1] < mintemp[1]) {
            mintemp[1] = (int)dev->chain_asic_temp[i][j][1];
          }
          if (dev->chain_asic_temp[i][j][2] < mintemp[2]) {
            mintemp[2] = (int)dev->chain_asic_temp[i][j][2];
          }
        }
        dev->chain_asic_maxtemp[i][0] = (int16_t)maxtemp[0];
        dev->chain_asic_maxtemp[i][1] = (int16_t)maxtemp[1];
        dev->chain_asic_maxtemp[i][2] = (int16_t)maxtemp[2];
        dev->chain_asic_mintemp[i][0] = (int16_t)mintemp[0];
        dev->chain_asic_mintemp[i][1] = (int16_t)mintemp[1];
        dev->chain_asic_mintemp[i][2] = (int16_t)mintemp[2];
        if (temp_top[0] < dev->chain_asic_maxtemp[i][0]) {
          temp_top[0] = dev->chain_asic_maxtemp[i][0];
        }
        if (temp_top[1] < dev->chain_asic_maxtemp[i][1]) {
          temp_top[1] = dev->chain_asic_maxtemp[i][1];
        }
        if (temp_top[2] < dev->chain_asic_maxtemp[i][2]) {
          temp_top[2] = dev->chain_asic_maxtemp[i][2];
        }
        if ((((dev->chain_asic_mintemp[i][0] < temp_low[0]) && (0 < dev->chain_asic_mintemp[i][0]))
            && (chain_temp_toolow[i] == 0)) || (temp_low[0] == 0)) {
          temp_low[0] = dev->chain_asic_mintemp[i][0];
        }
        if ((((dev->chain_asic_mintemp[i][1] < temp_low[1]) && (0 < dev->chain_asic_mintemp[i][1]))
            && (chain_temp_toolow[i] == 0)) || (temp_low[1] == 0)) {
          temp_low[1] = dev->chain_asic_mintemp[i][1];
        }
        if ((((dev->chain_asic_mintemp[i][2] < temp_low[2]) && (0 < dev->chain_asic_mintemp[i][2]))
            && (chain_temp_toolow[i] == 0)) || (temp_low[2] == 0)) {
          temp_low[2] = dev->chain_asic_mintemp[i][2];
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Done read temp on Chain[%d]\n",i);
          _applog(7,tmp42,false);
        }
      }
    }
    dev->temp_top1[0] = (int)temp_top[0];
    dev->temp_top1[1] = (int)temp_top[1];
    dev->temp_top1[2] = (int)temp_top[2];
    dev->temp_low1[0] = (int)temp_low[0];
    dev->temp_low1[1] = (int)temp_low[1];
    dev->temp_low1[2] = (int)temp_low[2];
    last_testpatten_highest_pcb_temp = dev->temp_top1[0];
    check_fan();
    if ((config_parameter._4_1_ & 2) == 0) {
      if (bVar1) {
        set_PWM('d');
        dev->fan_pwm = 'd';
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Set_fixed_full_fan_speed_00077820[0];
          tmp42[1] = s_Set_fixed_full_fan_speed_00077820[1];
          tmp42[2] = s_Set_fixed_full_fan_speed_00077820[2];
          tmp42[3] = s_Set_fixed_full_fan_speed_00077820[3];
          tmp42[4] = s_Set_fixed_full_fan_speed_00077820[4];
          tmp42[5] = s_Set_fixed_full_fan_speed_00077820[5];
          tmp42[6] = s_Set_fixed_full_fan_speed_00077820[6];
          tmp42[7] = s_Set_fixed_full_fan_speed_00077820[7];
          tmp42[8] = s_Set_fixed_full_fan_speed_00077820[8];
          tmp42[9] = s_Set_fixed_full_fan_speed_00077820[9];
          tmp42[10] = s_Set_fixed_full_fan_speed_00077820[10];
          tmp42[11] = s_Set_fixed_full_fan_speed_00077820[11];
          tmp42[12] = s_Set_fixed_full_fan_speed_00077820[12];
          tmp42[13] = s_Set_fixed_full_fan_speed_00077820[13];
          tmp42[14] = s_Set_fixed_full_fan_speed_00077820[14];
          tmp42[15] = s_Set_fixed_full_fan_speed_00077820[15];
          tmp42[16] = s_Set_fixed_full_fan_speed_00077820[16];
          tmp42[17] = s_Set_fixed_full_fan_speed_00077820[17];
          tmp42[18] = s_Set_fixed_full_fan_speed_00077820[18];
          tmp42[19] = s_Set_fixed_full_fan_speed_00077820[19];
          tmp42[20] = s_Set_fixed_full_fan_speed_00077820[20];
          tmp42[21] = s_Set_fixed_full_fan_speed_00077820[21];
          tmp42[22] = s_Set_fixed_full_fan_speed_00077820[22];
          tmp42[23] = s_Set_fixed_full_fan_speed_00077820[23];
          tmp42[24] = (char)(short)ram0x00077838;
          tmp42[25] = (char)((ushort)(short)ram0x00077838 >> 8);
          _applog(7,tmp42,false);
        }
      }
      else {
        set_PWM_according_to_temperature();
      }
    }
    else if (config_parameter.fan_pwm_percent < 0x65) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Set fixed fan speed=%d\n",(uint)config_parameter.fan_pwm_percent);
        _applog(7,tmp42,false);
      }
      set_PWM(config_parameter.fan_pwm_percent);
    }
    else if (bVar1) {
      set_PWM('d');
      dev->fan_pwm = 'd';
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Set_fixed_full_fan_speed_00077820[0];
        tmp42[1] = s_Set_fixed_full_fan_speed_00077820[1];
        tmp42[2] = s_Set_fixed_full_fan_speed_00077820[2];
        tmp42[3] = s_Set_fixed_full_fan_speed_00077820[3];
        tmp42[4] = s_Set_fixed_full_fan_speed_00077820[4];
        tmp42[5] = s_Set_fixed_full_fan_speed_00077820[5];
        tmp42[6] = s_Set_fixed_full_fan_speed_00077820[6];
        tmp42[7] = s_Set_fixed_full_fan_speed_00077820[7];
        tmp42[8] = s_Set_fixed_full_fan_speed_00077820[8];
        tmp42[9] = s_Set_fixed_full_fan_speed_00077820[9];
        tmp42[10] = s_Set_fixed_full_fan_speed_00077820[10];
        tmp42[11] = s_Set_fixed_full_fan_speed_00077820[11];
        tmp42[12] = s_Set_fixed_full_fan_speed_00077820[12];
        tmp42[13] = s_Set_fixed_full_fan_speed_00077820[13];
        tmp42[14] = s_Set_fixed_full_fan_speed_00077820[14];
        tmp42[15] = s_Set_fixed_full_fan_speed_00077820[15];
        tmp42[16] = s_Set_fixed_full_fan_speed_00077820[16];
        tmp42[17] = s_Set_fixed_full_fan_speed_00077820[17];
        tmp42[18] = s_Set_fixed_full_fan_speed_00077820[18];
        tmp42[19] = s_Set_fixed_full_fan_speed_00077820[19];
        tmp42[20] = s_Set_fixed_full_fan_speed_00077820[20];
        tmp42[21] = s_Set_fixed_full_fan_speed_00077820[21];
        tmp42[22] = s_Set_fixed_full_fan_speed_00077820[22];
        tmp42[23] = s_Set_fixed_full_fan_speed_00077820[23];
        tmp42[24] = (char)(short)ram0x00077838;
        tmp42[25] = (char)((ushort)(short)ram0x00077838 >> 8);
        _applog(7,tmp42,false);
      }
    }
    else {
      set_PWM_according_to_temperature();
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"fan map is 0x%08x, num = %d\n",dev->fan_exist_map,(uint)dev->fan_num);
      _applog(7,tmp42,false);
    }
    if (startCheckNetworkJob == false) {
      diff.tv_sec = 0;
      cur_fan_num = 2;
    }
    else {
      cgtime(&tv_send);
      diff.tv_sec = tv_send.tv_sec - tv_send_job.tv_sec;
      if (tv_send.tv_usec - tv_send_job.tv_usec < 0) {
        diff.tv_sec = diff.tv_sec + -1;
      }
      cur_fan_num = (int)dev->fan_num;
      if (((0x78 < diff.tv_sec) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        tmp42[0] = s_Fatal_Error__network_connection_l_0007785c[0];
        tmp42[1] = s_Fatal_Error__network_connection_l_0007785c[1];
        tmp42[2] = s_Fatal_Error__network_connection_l_0007785c[2];
        tmp42[3] = s_Fatal_Error__network_connection_l_0007785c[3];
        tmp42[4] = s_Fatal_Error__network_connection_l_0007785c[4];
        tmp42[5] = s_Fatal_Error__network_connection_l_0007785c[5];
        tmp42[6] = s_Fatal_Error__network_connection_l_0007785c[6];
        tmp42[7] = s_Fatal_Error__network_connection_l_0007785c[7];
        tmp42[8] = s_Fatal_Error__network_connection_l_0007785c[8];
        tmp42[9] = s_Fatal_Error__network_connection_l_0007785c[9];
        tmp42[10] = s_Fatal_Error__network_connection_l_0007785c[10];
        tmp42[11] = s_Fatal_Error__network_connection_l_0007785c[11];
        tmp42[12] = s_Fatal_Error__network_connection_l_0007785c[12];
        tmp42[13] = s_Fatal_Error__network_connection_l_0007785c[13];
        tmp42[14] = s_Fatal_Error__network_connection_l_0007785c[14];
        tmp42[15] = s_Fatal_Error__network_connection_l_0007785c[15];
        tmp42[16] = s_Fatal_Error__network_connection_l_0007785c[16];
        tmp42[17] = s_Fatal_Error__network_connection_l_0007785c[17];
        tmp42[18] = s_Fatal_Error__network_connection_l_0007785c[18];
        tmp42[19] = s_Fatal_Error__network_connection_l_0007785c[19];
        tmp42[20] = s_Fatal_Error__network_connection_l_0007785c[20];
        tmp42[21] = s_Fatal_Error__network_connection_l_0007785c[21];
        tmp42[22] = s_Fatal_Error__network_connection_l_0007785c[22];
        tmp42[23] = s_Fatal_Error__network_connection_l_0007785c[23];
        tmp42[24] = s_Fatal_Error__network_connection_l_0007785c[24];
        tmp42[25] = s_Fatal_Error__network_connection_l_0007785c[25];
        tmp42[26] = s_Fatal_Error__network_connection_l_0007785c[26];
        tmp42[27] = s_Fatal_Error__network_connection_l_0007785c[27];
        tmp42[28] = s_Fatal_Error__network_connection_l_0007785c[28];
        tmp42[29] = s_Fatal_Error__network_connection_l_0007785c[29];
        tmp42[30] = s_Fatal_Error__network_connection_l_0007785c[30];
        tmp42[31] = s_Fatal_Error__network_connection_l_0007785c[31];
        tmp42[32] = s_Fatal_Error__network_connection_l_0007785c[32];
        tmp42[33] = s_Fatal_Error__network_connection_l_0007785c[33];
        tmp42[34] = s_Fatal_Error__network_connection_l_0007785c[34];
        tmp42[35] = s_Fatal_Error__network_connection_l_0007785c[35];
        tmp42._36_2_ = (undefined2)ram0x00077880;
        tmp42[38] = (char)((uint)ram0x00077880 >> 0x10);
        _applog(7,tmp42,false);
      }
    }
    if (((diff.tv_sec < 0x79) && (dev->temp_top1[0] < 0x60)) && (1 < (uint)cur_fan_num)) {
      fatal_error_counter = 0;
      global_stop = false;
      if (once_error != true) {
        status_error = false;
      }
    }
    else {
      fatal_error_counter = fatal_error_counter + 1;
      if (fatal_error_counter < 3) {
        global_stop = false;
        if (once_error != true) {
          status_error = false;
        }
      }
      else {
        global_stop = true;
        if (dev->temp_top1[0] < 0x60) {
          if ((uint)cur_fan_num < 2) {
            FatalErrorValue = 2;
          }
          else {
            FatalErrorValue = 3;
          }
        }
        else {
          FatalErrorValue = 1;
        }
        if ((0x5f < dev->temp_top1[0]) || ((uint)cur_fan_num < 2)) {
          status_error = true;
          once_error = true;
          for (i = 0; i < 0x10; i = i + 1) {
            if (dev->chain_exist[i] == 1) {
              pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
              disable_pic_dac((uchar)i);
              pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            }
          }
        }
        uVar5 = get_dhash_acc_control();
        set_dhash_acc_control(uVar5 & 0xffffffbf);
      }
    }
    if (status_error != false) {
      if (FatalErrorValue == 2) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Fatal_Error__Fan_lost__000778ac[0];
          tmp42[1] = s_Fatal_Error__Fan_lost__000778ac[1];
          tmp42[2] = s_Fatal_Error__Fan_lost__000778ac[2];
          tmp42[3] = s_Fatal_Error__Fan_lost__000778ac[3];
          tmp42[4] = s_Fatal_Error__Fan_lost__000778ac[4];
          tmp42[5] = s_Fatal_Error__Fan_lost__000778ac[5];
          tmp42[6] = s_Fatal_Error__Fan_lost__000778ac[6];
          tmp42[7] = s_Fatal_Error__Fan_lost__000778ac[7];
          tmp42[8] = s_Fatal_Error__Fan_lost__000778ac[8];
          tmp42[9] = s_Fatal_Error__Fan_lost__000778ac[9];
          tmp42[10] = s_Fatal_Error__Fan_lost__000778ac[10];
          tmp42[11] = s_Fatal_Error__Fan_lost__000778ac[11];
          tmp42[12] = s_Fatal_Error__Fan_lost__000778ac[12];
          tmp42[13] = s_Fatal_Error__Fan_lost__000778ac[13];
          tmp42[14] = s_Fatal_Error__Fan_lost__000778ac[14];
          tmp42[15] = s_Fatal_Error__Fan_lost__000778ac[15];
          tmp42[16] = s_Fatal_Error__Fan_lost__000778ac[16];
          tmp42[17] = s_Fatal_Error__Fan_lost__000778ac[17];
          tmp42[18] = s_Fatal_Error__Fan_lost__000778ac[18];
          tmp42[19] = s_Fatal_Error__Fan_lost__000778ac[19];
          tmp42[20] = s_Fatal_Error__Fan_lost__000778ac[20];
          tmp42[21] = s_Fatal_Error__Fan_lost__000778ac[21];
          tmp42[22] = s_Fatal_Error__Fan_lost__000778ac[22];
          tmp42[23] = s_Fatal_Error__Fan_lost__000778ac[23];
          _applog(7,tmp42,false);
        }
      }
      else if (FatalErrorValue == 3) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Fatal_Error__network_connection_l_0007785c[0];
          tmp42[1] = s_Fatal_Error__network_connection_l_0007785c[1];
          tmp42[2] = s_Fatal_Error__network_connection_l_0007785c[2];
          tmp42[3] = s_Fatal_Error__network_connection_l_0007785c[3];
          tmp42[4] = s_Fatal_Error__network_connection_l_0007785c[4];
          tmp42[5] = s_Fatal_Error__network_connection_l_0007785c[5];
          tmp42[6] = s_Fatal_Error__network_connection_l_0007785c[6];
          tmp42[7] = s_Fatal_Error__network_connection_l_0007785c[7];
          tmp42[8] = s_Fatal_Error__network_connection_l_0007785c[8];
          tmp42[9] = s_Fatal_Error__network_connection_l_0007785c[9];
          tmp42[10] = s_Fatal_Error__network_connection_l_0007785c[10];
          tmp42[11] = s_Fatal_Error__network_connection_l_0007785c[11];
          tmp42[12] = s_Fatal_Error__network_connection_l_0007785c[12];
          tmp42[13] = s_Fatal_Error__network_connection_l_0007785c[13];
          tmp42[14] = s_Fatal_Error__network_connection_l_0007785c[14];
          tmp42[15] = s_Fatal_Error__network_connection_l_0007785c[15];
          tmp42[16] = s_Fatal_Error__network_connection_l_0007785c[16];
          tmp42[17] = s_Fatal_Error__network_connection_l_0007785c[17];
          tmp42[18] = s_Fatal_Error__network_connection_l_0007785c[18];
          tmp42[19] = s_Fatal_Error__network_connection_l_0007785c[19];
          tmp42[20] = s_Fatal_Error__network_connection_l_0007785c[20];
          tmp42[21] = s_Fatal_Error__network_connection_l_0007785c[21];
          tmp42[22] = s_Fatal_Error__network_connection_l_0007785c[22];
          tmp42[23] = s_Fatal_Error__network_connection_l_0007785c[23];
          tmp42[24] = s_Fatal_Error__network_connection_l_0007785c[24];
          tmp42[25] = s_Fatal_Error__network_connection_l_0007785c[25];
          tmp42[26] = s_Fatal_Error__network_connection_l_0007785c[26];
          tmp42[27] = s_Fatal_Error__network_connection_l_0007785c[27];
          tmp42[28] = s_Fatal_Error__network_connection_l_0007785c[28];
          tmp42[29] = s_Fatal_Error__network_connection_l_0007785c[29];
          tmp42[30] = s_Fatal_Error__network_connection_l_0007785c[30];
          tmp42[31] = s_Fatal_Error__network_connection_l_0007785c[31];
          tmp42[32] = s_Fatal_Error__network_connection_l_0007785c[32];
          tmp42[33] = s_Fatal_Error__network_connection_l_0007785c[33];
          tmp42[34] = s_Fatal_Error__network_connection_l_0007785c[34];
          tmp42[35] = s_Fatal_Error__network_connection_l_0007785c[35];
          tmp42._36_2_ = (undefined2)ram0x00077880;
          tmp42[38] = (char)((uint)ram0x00077880 >> 0x10);
          _applog(7,tmp42,false);
        }
      }
      else if (FatalErrorValue == 1) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Fatal_Error__Temperature_is_too_h_00077884[0];
          tmp42[1] = s_Fatal_Error__Temperature_is_too_h_00077884[1];
          tmp42[2] = s_Fatal_Error__Temperature_is_too_h_00077884[2];
          tmp42[3] = s_Fatal_Error__Temperature_is_too_h_00077884[3];
          tmp42[4] = s_Fatal_Error__Temperature_is_too_h_00077884[4];
          tmp42[5] = s_Fatal_Error__Temperature_is_too_h_00077884[5];
          tmp42[6] = s_Fatal_Error__Temperature_is_too_h_00077884[6];
          tmp42[7] = s_Fatal_Error__Temperature_is_too_h_00077884[7];
          tmp42[8] = s_Fatal_Error__Temperature_is_too_h_00077884[8];
          tmp42[9] = s_Fatal_Error__Temperature_is_too_h_00077884[9];
          tmp42[10] = s_Fatal_Error__Temperature_is_too_h_00077884[10];
          tmp42[11] = s_Fatal_Error__Temperature_is_too_h_00077884[11];
          tmp42[12] = s_Fatal_Error__Temperature_is_too_h_00077884[12];
          tmp42[13] = s_Fatal_Error__Temperature_is_too_h_00077884[13];
          tmp42[14] = s_Fatal_Error__Temperature_is_too_h_00077884[14];
          tmp42[15] = s_Fatal_Error__Temperature_is_too_h_00077884[15];
          tmp42[16] = s_Fatal_Error__Temperature_is_too_h_00077884[16];
          tmp42[17] = s_Fatal_Error__Temperature_is_too_h_00077884[17];
          tmp42[18] = s_Fatal_Error__Temperature_is_too_h_00077884[18];
          tmp42[19] = s_Fatal_Error__Temperature_is_too_h_00077884[19];
          tmp42[20] = s_Fatal_Error__Temperature_is_too_h_00077884[20];
          tmp42[21] = s_Fatal_Error__Temperature_is_too_h_00077884[21];
          tmp42[22] = s_Fatal_Error__Temperature_is_too_h_00077884[22];
          tmp42[23] = s_Fatal_Error__Temperature_is_too_h_00077884[23];
          tmp42[24] = s_Fatal_Error__Temperature_is_too_h_00077884[24];
          tmp42[25] = s_Fatal_Error__Temperature_is_too_h_00077884[25];
          tmp42[26] = s_Fatal_Error__Temperature_is_too_h_00077884[26];
          tmp42[27] = s_Fatal_Error__Temperature_is_too_h_00077884[27];
          tmp42[28] = s_Fatal_Error__Temperature_is_too_h_00077884[28];
          tmp42[29] = s_Fatal_Error__Temperature_is_too_h_00077884[29];
          tmp42[30] = s_Fatal_Error__Temperature_is_too_h_00077884[30];
          tmp42[31] = s_Fatal_Error__Temperature_is_too_h_00077884[31];
          tmp42[32] = s_Fatal_Error__Temperature_is_too_h_00077884[32];
          tmp42[33] = s_Fatal_Error__Temperature_is_too_h_00077884[33];
          tmp42[34] = s_Fatal_Error__Temperature_is_too_h_00077884[34];
          tmp42[35] = s_Fatal_Error__Temperature_is_too_h_00077884[35];
          tmp42._36_2_ = (undefined2)ram0x000778a8;
          tmp42[38] = (char)((uint)ram0x000778a8 >> 0x10);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Fatal_Error__unkown_status__000778c4[0];
        tmp42[1] = s_Fatal_Error__unkown_status__000778c4[1];
        tmp42[2] = s_Fatal_Error__unkown_status__000778c4[2];
        tmp42[3] = s_Fatal_Error__unkown_status__000778c4[3];
        tmp42[4] = s_Fatal_Error__unkown_status__000778c4[4];
        tmp42[5] = s_Fatal_Error__unkown_status__000778c4[5];
        tmp42[6] = s_Fatal_Error__unkown_status__000778c4[6];
        tmp42[7] = s_Fatal_Error__unkown_status__000778c4[7];
        tmp42[8] = s_Fatal_Error__unkown_status__000778c4[8];
        tmp42[9] = s_Fatal_Error__unkown_status__000778c4[9];
        tmp42[10] = s_Fatal_Error__unkown_status__000778c4[10];
        tmp42[11] = s_Fatal_Error__unkown_status__000778c4[11];
        tmp42[12] = s_Fatal_Error__unkown_status__000778c4[12];
        tmp42[13] = s_Fatal_Error__unkown_status__000778c4[13];
        tmp42[14] = s_Fatal_Error__unkown_status__000778c4[14];
        tmp42[15] = s_Fatal_Error__unkown_status__000778c4[15];
        tmp42[16] = s_Fatal_Error__unkown_status__000778c4[16];
        tmp42[17] = s_Fatal_Error__unkown_status__000778c4[17];
        tmp42[18] = s_Fatal_Error__unkown_status__000778c4[18];
        tmp42[19] = s_Fatal_Error__unkown_status__000778c4[19];
        tmp42[20] = s_Fatal_Error__unkown_status__000778c4[20];
        tmp42[21] = s_Fatal_Error__unkown_status__000778c4[21];
        tmp42[22] = s_Fatal_Error__unkown_status__000778c4[22];
        tmp42[23] = s_Fatal_Error__unkown_status__000778c4[23];
        tmp42[24] = s_Fatal_Error__unkown_status__000778c4[24];
        tmp42[25] = s_Fatal_Error__unkown_status__000778c4[25];
        tmp42[26] = s_Fatal_Error__unkown_status__000778c4[26];
        tmp42[27] = s_Fatal_Error__unkown_status__000778c4[27];
        tmp42[28] = (char)ram0x000778e0;
        _applog(7,tmp42,false);
      }
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"FAN PWM: %d\n",(uint)dev->fan_pwm);
      _applog(7,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_read_temp_func_Done__000778f4[0];
      tmp42[1] = s_read_temp_func_Done__000778f4[1];
      tmp42[2] = s_read_temp_func_Done__000778f4[2];
      tmp42[3] = s_read_temp_func_Done__000778f4[3];
      tmp42[4] = s_read_temp_func_Done__000778f4[4];
      tmp42[5] = s_read_temp_func_Done__000778f4[5];
      tmp42[6] = s_read_temp_func_Done__000778f4[6];
      tmp42[7] = s_read_temp_func_Done__000778f4[7];
      tmp42[8] = s_read_temp_func_Done__000778f4[8];
      tmp42[9] = s_read_temp_func_Done__000778f4[9];
      tmp42[10] = s_read_temp_func_Done__000778f4[10];
      tmp42[11] = s_read_temp_func_Done__000778f4[11];
      tmp42[12] = s_read_temp_func_Done__000778f4[12];
      tmp42[13] = s_read_temp_func_Done__000778f4[13];
      tmp42[14] = s_read_temp_func_Done__000778f4[14];
      tmp42[15] = s_read_temp_func_Done__000778f4[15];
      tmp42[16] = s_read_temp_func_Done__000778f4[16];
      tmp42[17] = s_read_temp_func_Done__000778f4[17];
      tmp42[18] = s_read_temp_func_Done__000778f4[18];
      tmp42[19] = s_read_temp_func_Done__000778f4[19];
      tmp42[20] = (char)(short)ram0x00077908;
      tmp42[21] = (char)((ushort)(short)ram0x00077908 >> 8);
      _applog(7,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      uVar5 = get_crc_count();
      snprintf(tmp42,0x800,"CRC error counter=%d\n",uVar5);
      _applog(7,tmp42,false);
    }
    if (doTestPatten == false) {
      sleep(1);
    }
    else {
      sleep(3);
    }
  } while( true );
}

