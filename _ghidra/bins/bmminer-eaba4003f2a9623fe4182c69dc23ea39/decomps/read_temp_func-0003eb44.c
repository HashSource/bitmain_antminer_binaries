
/* WARNING: Unknown calling convention */

void * read_temp_func(void)

{
  bool bVar1;
  all_parameters *paVar2;
  undefined4 uVar3;
  int16_t iVar4;
  int iVar5;
  uint uVar6;
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
          uVar6 = check_reg_temp(DEVICEADDR[i],0,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar2 = dev;
          if (uVar6 == 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][0]);
              _applog(5,tmp42,false);
            }
            bVar1 = true;
          }
          else {
            iVar4 = get_local((ushort)uVar6 & 0xff);
            paVar2->chain_asic_temp[i][j][0] = iVar4;
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"Chain[%d] Chip[%d] local Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][0]);
              _applog(5,tmp42,false);
            }
          }
          uVar6 = check_reg_temp(DEVICEADDR[i],1,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar2 = dev;
          if (uVar6 == 0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][1]);
              _applog(7,tmp42,false);
            }
          }
          else {
            iVar4 = get_remote((ushort)uVar6 & 0xff);
            paVar2->chain_asic_temp[i][j][1] = iVar4;
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
            iVar5 = fakeMiddleTempFromPCB((int)dev->chain_asic_temp[i][j][0]);
            paVar2->chain_asic_temp[i][j][1] = (int16_t)iVar5;
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
        uVar3 = tmp42._24_4_;
        dev->fan_pwm = 'd';
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Set fixed full fan speed\n",0x1a);
          tmp42._26_2_ = SUB42(uVar3,2);
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
      uVar3 = tmp42._24_4_;
      dev->fan_pwm = 'd';
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Set fixed full fan speed\n",0x1a);
        tmp42._26_2_ = SUB42(uVar3,2);
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
        builtin_strncpy(tmp42,"Fatal Error: network connection lost",0x24);
        tmp42[0x24] = '!';
        tmp42[0x25] = '\n';
        tmp42[0x26] = '\0';
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
        uVar6 = get_dhash_acc_control();
        set_dhash_acc_control(uVar6 & 0xffffffbf);
      }
    }
    if (status_error != false) {
      if (FatalErrorValue == 2) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Fatal Error: Fan lost!\n",0x18);
          _applog(7,tmp42,false);
        }
      }
      else if (FatalErrorValue == 3) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Fatal Error: network connection lost",0x24);
          tmp42[0x24] = '!';
          tmp42[0x25] = '\n';
          tmp42[0x26] = '\0';
          _applog(7,tmp42,false);
        }
      }
      else if (FatalErrorValue == 1) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Fatal Error: Temperature is too high",0x24);
          tmp42[0x24] = '!';
          tmp42[0x25] = '\n';
          tmp42[0x26] = '\0';
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Fatal Error: unkown status.\n",0x1c);
        tmp42._28_4_ = tmp42._28_4_ & 0xffffff00;
        _applog(7,tmp42,false);
      }
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"FAN PWM: %d\n",(uint)dev->fan_pwm);
      _applog(7,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
    uVar3 = tmp42._20_4_;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"read_temp_func Done!\n",0x16);
      tmp42._22_2_ = SUB42(uVar3,2);
      _applog(7,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      uVar6 = get_crc_count();
      snprintf(tmp42,0x800,"CRC error counter=%d\n",uVar6);
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

