
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void * scanfreq_read_temp_func(void)

{
  all_parameters *paVar1;
  int16_t iVar2;
  uint uVar3;
  char tmp42 [2048];
  int mintemp [4];
  int maxtemp [4];
  int16_t temp_low [4];
  int16_t temp_top [4];
  int chain_asic_temp_error [16] [8];
  timeval diff;
  char error_info [256];
  char logstr [1024];
  _Bool readTempHasSomeOneFailed;
  int fatal_error_counter;
  int cur_fan_num;
  Temp_Type_E temp_Type;
  _Bool already_offside;
  uint ret3;
  uint ret2;
  uint ret1;
  uint ret0;
  uint ret;
  int j;
  int i;
  
  memset(chain_asic_temp_error,0,0x200);
  do {
    pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
    memset(temp_top,0,8);
    memset(temp_low,0,8);
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        maxtemp[0] = 0;
        maxtemp[1] = 0;
        maxtemp[2] = 0;
        mintemp[0] = 1000;
        mintemp[1] = 1000;
        mintemp[2] = 1000;
        for (j = 0; j < dev->chain_asic_temp_num[i]; j = j + 1) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Chain[%d] Chip[%d] TempTypeID=%02x middle offset=%d\n",i,
                     (dev->TempChipAddr[i][j] >> 1) + 1,(uint)dev->TempChipType[i][j],
                     (int)middle_Offset[i][j]);
            _applog(7,tmp42,false);
          }
          uVar3 = check_reg_temp(DEVICEADDR[i],0,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar1 = dev;
          if (uVar3 == 0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][0]);
              _applog(7,tmp42,false);
            }
          }
          else {
            iVar2 = get_local((ushort)uVar3 & 0xff);
            paVar1->chain_asic_temp[i][j][0] = iVar2;
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"Chain[%d] Chip[%d] local Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][0]);
              _applog(5,tmp42,false);
            }
          }
          uVar3 = check_reg_temp(DEVICEADDR[i],1,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar1 = dev;
          if (uVar3 == 0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][1]);
              _applog(7,tmp42,false);
            }
          }
          else {
            iVar2 = get_remote((ushort)uVar3 & 0xff);
            paVar1->chain_asic_temp[i][j][1] = iVar2;
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"Chain[%d] Chip[%d] Chip Temp=%d\n",i,
                       (dev->TempChipAddr[i][j] >> 1) + 1,(int)dev->chain_asic_temp[i][j][1]);
              _applog(5,tmp42,false);
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
    set_PWM_according_to_temperature();
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
      tmp42._20_2_ = (undefined2)ram0x00077908;
      _applog(7,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      uVar3 = get_crc_count();
      snprintf(tmp42,0x800,"CRC error counter=%d\n",uVar3);
      _applog(7,tmp42,false);
    }
    if (doTestPatten == false) {
      sleep(5);
    }
    else {
      sleep(3);
    }
  } while( true );
}

