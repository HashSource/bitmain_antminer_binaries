
int app_config_handle(app_config_t *m_conf,char *config_filename)

{
  FILE *__stream;
  int iVar1;
  char *pcVar2;
  char *config_filename_local;
  app_config_t *m_conf_local;
  char tmp42 [1024];
  char str [1024];
  int num;
  int num_3;
  int num_2;
  int num_1;
  FILE *fd;
  char *temp;
  
  memset(str,0,0x400);
  __stream = fopen(config_filename,"r");
  if ((__stream == (FILE *)0x0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    snprintf(tmp42,0x400,"open %s failed\n",config_filename);
    _applog(2,tmp42,false);
  }
  do {
    do {
      pcVar2 = fgets(str,0x3ff,__stream);
      if (pcVar2 == (char *)0x0) {
        fclose(__stream);
        return 0;
      }
    } while (((str[0] == '#') || (str[1] == '#')) || (str[0] == '\0'));
    pcVar2 = strstr(str,"Name=");
    if (pcVar2 != (char *)0x0) {
      __isoc99_sscanf(pcVar2 + 5,&DAT_00036900,m_conf->name);
    }
    pcVar2 = strstr(str,"AsicNum=");
    if (pcVar2 != (char *)0x0) {
      __isoc99_sscanf(pcVar2 + 8,&DAT_00036910,&m_conf->asic_num);
    }
    pcVar2 = strstr(str,"CoreNum=");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(str,"WorkMode=");
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr(str,"Comport=");
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr(str,"SensorPos=");
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr(str,"EnableCp210x=");
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr(str,"Baudrate=");
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr(str,"TicketMask=");
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr(str,"CoreTimeout=");
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr(str,"ChipAlarmTemp=");
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = strstr(str,"BringupFreq=");
                      if (pcVar2 == (char *)0x0) {
                        pcVar2 = strstr(str,"BringupVoltage=");
                        if (pcVar2 == (char *)0x0) {
                          pcVar2 = strstr(str,"BringupWorkIntervalS=");
                          if (pcVar2 == (char *)0x0) {
                            pcVar2 = strstr(str,"BringupAutoJHVolt=");
                            if (pcVar2 == (char *)0x0) {
                              pcVar2 = strstr(str,"BringupAutoJHFreq=");
                              if (pcVar2 == (char *)0x0) {
                                pcVar2 = strstr(str,"PattenNum=");
                                if (pcVar2 == (char *)0x0) {
                                  pcVar2 = strstr(str,"SltTestMode=");
                                  if (pcVar2 == (char *)0x0) {
                                    pcVar2 = strstr(str,"SltTunelPath=");
                                    if (pcVar2 == (char *)0x0) {
                                      pcVar2 = strstr(str,"SltCP210xRuntime=");
                                      if (pcVar2 == (char *)0x0) {
                                        pcVar2 = strstr(str,"SltBinRate=");
                                        if (pcVar2 == (char *)0x0) {
                                          pcVar2 = strstr(str,"SltDelay=");
                                          if (pcVar2 == (char *)0x0) {
                                            pcVar2 = strstr(str,"SltFreq=");
                                            if (pcVar2 == (char *)0x0) {
                                              pcVar2 = strstr(str,"SltWorkIntervalMs=");
                                              if (pcVar2 == (char *)0x0) {
                                                pcVar2 = strstr(str,"SltEnableReadTemp=");
                                                if (pcVar2 == (char *)0x0) {
                                                  pcVar2 = strstr(str,"PcbaRepeatCtrl=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"PcbaFreq=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"PcbaVoltage=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"PcbaTemptureHigh=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"PcbaTemptureLow=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,"PcbaOnlyFindASIC=")
                                                            ;
                                                            if (pcVar2 == (char *)0x0) {
                                                              pcVar2 = strstr(str,
                                                  "PcbaPatternPassRate=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"PcbaSendPtTimeout=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"PcbaEnableLevel=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"PcbaLevelRate=");
                                                        if ((pcVar2 != (char *)0x0) &&
                                                           (iVar1 = parse_config_ini_array
                                                                              (pcVar2 + 0xe,
                                                                               &m_conf->
                                                  pcba_level_rate), iVar1 != 3)) {
                                                    if ((use_syslog != false) ||
                                                       ((opt_log_output != false ||
                                                        (1 < opt_log_level)))) {
                                                      snprintf(tmp42,0x400,
                                                                                                                              
                                                  "PcbaLevelRate number should be 3, but not %d\n",
                                                  iVar1);
                                                  _applog(2,tmp42,false);
                                                  }
                                                  return -1;
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x10,&DAT_00036910,
                                                                    &m_conf->pcba_enable_level);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x12,&DAT_00036910,
                                                                    &m_conf->send_pattern_timeout);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x14,&DAT_00036910,
                                                                    &m_conf->pcba_pattern_pass_rate)
                                                    ;
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x11,&DAT_00036910,
                                                                    &m_conf->pcba_only_find_asic);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x10,&DAT_00036910,
                                                                    &m_conf->pcba_tempture_low);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x11,&DAT_00036910,
                                                                    &m_conf->pcba_tempture_high);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_00036910,
                                                                    &m_conf->pcba_voltage);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,
                                                                    &m_conf->pcba_freq);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_00036900,
                                                                    m_conf->pcba_repeat_ctrl);
                                                  }
                                                }
                                                else {
                                                  __isoc99_sscanf(pcVar2 + 0x12,&DAT_00036910,
                                                                  &m_conf->slt_enable_read_temp);
                                                }
                                              }
                                              else {
                                                __isoc99_sscanf(pcVar2 + 0x12,&DAT_00036910,
                                                                &m_conf->slt_work_interval_ms);
                                              }
                                            }
                                            else {
                                              __isoc99_sscanf(pcVar2 + 8,&DAT_00036910,
                                                              &m_conf->slt_freq);
                                            }
                                          }
                                          else {
                                            __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,
                                                            &m_conf->slt_delay);
                                          }
                                        }
                                        else {
                                          iVar1 = parse_config_ini_array
                                                            (pcVar2 + 0xb,&m_conf->slt_bin_rate);
                                          if (iVar1 != 3) {
                                            if (((use_syslog != false) || (opt_log_output != false))
                                               || (1 < opt_log_level)) {
                                              snprintf(tmp42,0x400,"SltBinRate number error %d\n",
                                                       iVar1);
                                              _applog(2,tmp42,false);
                                            }
                                            return -1;
                                          }
                                        }
                                      }
                                      else {
                                        __isoc99_sscanf(pcVar2 + 0x11,&DAT_00036900,
                                                        m_conf->slt_cp210x_runtime);
                                      }
                                    }
                                    else {
                                      __isoc99_sscanf(pcVar2 + 0xd,&DAT_00036900,
                                                      m_conf->slt_tunel_path);
                                    }
                                  }
                                  else {
                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_00036910,
                                                    &m_conf->slt_test_mode);
                                  }
                                }
                                else {
                                  __isoc99_sscanf(pcVar2 + 10,&DAT_00036910,&m_conf->pattern_num);
                                }
                              }
                              else {
                                iVar1 = parse_config_ini_array
                                                  (pcVar2 + 0x12,&m_conf->bringup_autojh_freq);
                                if (iVar1 != 3) {
                                  if (((use_syslog != false) || (opt_log_output != false)) ||
                                     (1 < opt_log_level)) {
                                    snprintf(tmp42,0x400,"BringupAutoJHFreq number error %d\n",iVar1
                                            );
                                    _applog(2,tmp42,false);
                                  }
                                  return -1;
                                }
                              }
                            }
                            else {
                              iVar1 = parse_config_ini_array
                                                (pcVar2 + 0x12,&m_conf->bringup_autojh_volt);
                              if (iVar1 != 3) {
                                if (((use_syslog != false) || (opt_log_output != false)) ||
                                   (1 < opt_log_level)) {
                                  snprintf(tmp42,0x400,"BringupAutoJHVolt number error %d\n",iVar1);
                                  _applog(2,tmp42,false);
                                }
                                return -1;
                              }
                            }
                          }
                          else {
                            __isoc99_sscanf(pcVar2 + 0x15,&DAT_00036910,
                                            &m_conf->bringup_work_interval_s);
                          }
                        }
                        else {
                          __isoc99_sscanf(pcVar2 + 0xf,&DAT_00036910,&m_conf->bringup_voltage);
                        }
                      }
                      else {
                        __isoc99_sscanf(pcVar2 + 0xc,&DAT_00036910,&m_conf->bringup_freq);
                      }
                    }
                    else {
                      __isoc99_sscanf(pcVar2 + 0xe,&DAT_00036910,&m_conf->chip_alarm_temp);
                    }
                  }
                  else {
                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0003697c,&m_conf->core_timeout);
                  }
                }
                else {
                  __isoc99_sscanf(pcVar2 + 0xb,&DAT_00036910,&m_conf->ticket_mask);
                }
              }
              else {
                __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,&m_conf->baudrate);
              }
            }
            else {
              __isoc99_sscanf(pcVar2 + 0xd,&DAT_00036910,&m_conf->enable_cp210x);
            }
          }
          else {
            iVar1 = parse_config_ini_array(pcVar2 + 10,&m_conf->sensor_pos);
            m_conf->sensor_num = iVar1;
          }
        }
        else {
          iVar1 = parse_config_ini_array(pcVar2 + 8,&m_conf->comport);
          m_conf->comport_num = iVar1;
        }
      }
      else {
        __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,&m_conf->work_mode);
      }
    }
    else {
      __isoc99_sscanf(pcVar2 + 8,&DAT_00036910,&m_conf->core_num);
    }
    memset(str,0,0x400);
  } while( true );
}

