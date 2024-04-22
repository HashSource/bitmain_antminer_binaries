
undefined4 read_config(void)

{
  char *pcVar1;
  int local_420;
  char local_41c;
  char local_41b;
  FILE *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  int local_10;
  char *local_c;
  
  local_14 = Conf;
  memset(&local_41c,0,0x400);
  local_18 = 0;
  local_420 = 0;
  local_1c = fopen("/mnt/card/Config.ini","r");
  do {
    do {
      pcVar1 = fgets(&local_41c,0x3ff,local_1c);
      if (pcVar1 == (char *)0x0) {
        return 0;
      }
    } while ((local_41c == '#') || (local_41b == '#'));
    local_c = strstr(&local_41c,"Name=");
    if (local_c == (char *)0x0) {
      local_c = strstr(&local_41c,"pattern_number=");
      if (local_c == (char *)0x0) {
        local_c = strstr(&local_41c,"AsicNum=");
        if (local_c == (char *)0x0) {
          local_c = strstr(&local_41c,"AsicType=");
          if (local_c == (char *)0x0) {
            local_c = strstr(&local_41c,"Freq1=");
            if (local_c == (char *)0x0) {
              local_c = strstr(&local_41c,"Freq2=");
              if (local_c == (char *)0x0) {
                local_c = strstr(&local_41c,"Freq3=");
                if (local_c == (char *)0x0) {
                  local_c = strstr(&local_41c,"Freq4=");
                  if (local_c == (char *)0x0) {
                    local_c = strstr(&local_41c,"Freq5=");
                    if (local_c == (char *)0x0) {
                      local_c = strstr(&local_41c,"Freq6=");
                      if (local_c == (char *)0x0) {
                        local_c = strstr(&local_41c,"Freq7=");
                        if (local_c == (char *)0x0) {
                          local_c = strstr(&local_41c,"Freq8=");
                          if (local_c == (char *)0x0) {
                            local_c = strstr(&local_41c,"Freq9=");
                            if (local_c == (char *)0x0) {
                              local_c = strstr(&local_41c,"Voltage1=");
                              if (local_c == (char *)0x0) {
                                local_c = strstr(&local_41c,"Voltage2=");
                                if (local_c == (char *)0x0) {
                                  local_c = strstr(&local_41c,"Voltage3=");
                                  if (local_c == (char *)0x0) {
                                    local_c = strstr(&local_41c,"Voltage4=");
                                    if (local_c == (char *)0x0) {
                                      local_c = strstr(&local_41c,"Voltage5=");
                                      if (local_c == (char *)0x0) {
                                        local_c = strstr(&local_41c,"Voltage6=");
                                        if (local_c == (char *)0x0) {
                                          local_c = strstr(&local_41c,"Voltage7=");
                                          if (local_c == (char *)0x0) {
                                            local_c = strstr(&local_41c,"Voltage8=");
                                            if (local_c == (char *)0x0) {
                                              local_c = strstr(&local_41c,"Voltage9=");
                                              if (local_c == (char *)0x0) {
                                                local_c = strstr(&local_41c,"OpenCoreGap=");
                                                if (local_c == (char *)0x0) {
                                                  local_c = strstr(&local_41c,"CheckTemp=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_41c,"Open_Core_Num1=");
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_41c,"Open_Core_Num2=")
                                                      ;
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_41c,
                                                                         "Open_Core_Num3=");
                                                        if (local_c == (char *)0x0) {
                                                          local_c = strstr(&local_41c,
                                                                           "Open_Core_Num4=");
                                                          if (local_c == (char *)0x0) {
                                                            local_c = strstr(&local_41c,
                                                                             "sensor_model=");
                                                            if (local_c == (char *)0x0) {
                                                              local_c = strstr(&local_41c,
                                                                               "remote_local_gap=");
                                                              if (local_c == (char *)0x0) {
                                                                local_c = strstr(&local_41c,
                                                                                 "TempSensor1=");
                                                                if (local_c == (char *)0x0) {
                                                                  local_c = strstr(&local_41c,
                                                                                   "TempSensor2=");
                                                                  if (local_c == (char *)0x0) {
                                                                    local_c = strstr(&local_41c,
                                                                                     "TempSensor3=")
                                                                    ;
                                                                    if (local_c == (char *)0x0) {
                                                                      local_c = strstr(&local_41c,
                                                                                                                                                                              
                                                  "StartSensor=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_41c,"StartTemp=");
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_41c,"TargetTemp=");
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_41c,
                                                                                                                                                  
                                                  "add_voltage_after_test_ok=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_41c,"add_voltage_value="
                                                                    );
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_41c,"AlarmTemp=");
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_41c,"HeatingUpTime="
                                                                        );
                                                        if (local_c == (char *)0x0) {
                                                          local_c = strstr(&local_41c,"MaxTempGap=")
                                                          ;
                                                          if (local_c == (char *)0x0) {
                                                            local_c = strstr(&local_41c,
                                                                             "Invalid_Core_Num=");
                                                            if (local_c != (char *)0x0) {
                                                              local_c = local_c + 0x11;
                                                              __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                              local_14 + 0xf4);
                                                            }
                                                          }
                                                          else {
                                                            local_c = local_c + 0xb;
                                                            __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                            local_14 + 0xe8);
                                                          }
                                                        }
                                                        else {
                                                          local_c = local_c + 0xe;
                                                          __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                          local_14 + 0xe4);
                                                        }
                                                      }
                                                      else {
                                                        local_c = local_c + 10;
                                                        __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                        local_14 + 0xe2);
                                                      }
                                                    }
                                                    else {
                                                      local_c = local_c + 0x12;
                                                      __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                      local_14 + 0xf0);
                                                    }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x1a;
                                                    __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                    local_14 + 0xec);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xb;
                                                    __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                    local_14 + 0xe1);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 10;
                                                    __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                    local_14 + 0xe0);
                                                    __isoc99_sscanf(local_c,&DAT_0001a014,&local_420
                                                                   );
                                                    if (local_420 < 0) {
                                                      local_420 = -local_420;
                                                      local_14[0xe0] = (char)local_420;
                                                      local_14[0xe0] = -local_14[0xe0];
                                                    }
                                                    else {
                                                      local_14[0xe0] = (char)local_420;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                    local_14 + 0xdf);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0001a154,
                                                                    local_14 + 0xde);
                                                    if (local_14[0xde] != '\0') {
                                                      gSensor_number = gSensor_number + 1;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0001a154,
                                                                    local_14 + 0xdd);
                                                    if (local_14[0xdd] != '\0') {
                                                      gSensor_number = gSensor_number + 1;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0001a154,
                                                                    local_14 + 0xdc);
                                                    if (local_14[0xdc] != '\0') {
                                                      gSensor_number = gSensor_number + 1;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x11;
                                                    __isoc99_sscanf(local_c,&DAT_0001a154,
                                                                    local_14 + 0xfc);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xd;
                                                    __isoc99_sscanf(local_c,&DAT_0001a154,
                                                                    local_14 + 0xf8);
                                                    if (local_14[0xf8] == '\x06') {
                                                      gSensor_i2c_addr_high_4_bit = 0x9a0000;
                                                    }
                                                    else if (local_14[0xf8] == '\a') {
                                                      gSensor_i2c_addr_high_4_bit = 0x9c0000;
                                                    }
                                                    else {
                                                      gSensor_i2c_addr_high_4_bit = 0x980000;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0001a110,
                                                                    local_14 + 0xd8);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0001a110,
                                                                    local_14 + 0xd4);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0001a110,
                                                                    local_14 + 0xd0);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0001a110,
                                                                    local_14 + 0xcc);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 10;
                                                    __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                    local_14 + 200);
                                                  }
                                                }
                                                else {
                                                  local_c = local_c + 0xc;
                                                  __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                  local_14 + 0xc0);
                                                }
                                              }
                                              else {
                                                local_c = local_c + 9;
                                                __isoc99_sscanf(local_c,&DAT_0001a014,
                                                                local_14 + 0xbc);
                                                if (*(int *)(local_14 + 0xbc) != 0) {
                                                  gHowManyVoltageLevel =
                                                       gHowManyVoltageLevel + '\x01';
                                                }
                                              }
                                            }
                                            else {
                                              local_c = local_c + 9;
                                              __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xb8)
                                              ;
                                              if (*(int *)(local_14 + 0xb8) != 0) {
                                                gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01'
                                                ;
                                              }
                                            }
                                          }
                                          else {
                                            local_c = local_c + 9;
                                            __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xb4);
                                            if (*(int *)(local_14 + 0xb4) != 0) {
                                              gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                            }
                                          }
                                        }
                                        else {
                                          local_c = local_c + 9;
                                          __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xb0);
                                          if (*(int *)(local_14 + 0xb0) != 0) {
                                            gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                          }
                                        }
                                      }
                                      else {
                                        local_c = local_c + 9;
                                        __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xac);
                                        if (*(int *)(local_14 + 0xac) != 0) {
                                          gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                        }
                                      }
                                    }
                                    else {
                                      local_c = local_c + 9;
                                      __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xa8);
                                      if (*(int *)(local_14 + 0xa8) != 0) {
                                        gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                      }
                                    }
                                  }
                                  else {
                                    local_c = local_c + 9;
                                    __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xa4);
                                    if (*(int *)(local_14 + 0xa4) != 0) {
                                      gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                    }
                                  }
                                }
                                else {
                                  local_c = local_c + 9;
                                  __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0xa0);
                                  if (*(int *)(local_14 + 0xa0) != 0) {
                                    gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                  }
                                }
                              }
                              else {
                                local_c = local_c + 9;
                                __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x9c);
                                if (*(int *)(local_14 + 0x9c) != 0) {
                                  gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                }
                              }
                            }
                            else {
                              local_c = local_c + 6;
                              __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x68);
                            }
                          }
                          else {
                            local_c = local_c + 6;
                            __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 100);
                          }
                        }
                        else {
                          local_c = local_c + 6;
                          __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x60);
                        }
                      }
                      else {
                        local_c = local_c + 6;
                        __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x5c);
                      }
                    }
                    else {
                      local_c = local_c + 6;
                      __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x58);
                    }
                  }
                  else {
                    local_c = local_c + 6;
                    __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x54);
                  }
                }
                else {
                  local_c = local_c + 6;
                  __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x50);
                }
              }
              else {
                local_c = local_c + 6;
                __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x4c);
              }
            }
            else {
              local_c = local_c + 6;
              __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x48);
            }
          }
          else {
            local_c = local_c + 9;
            __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x74);
          }
        }
        else {
          local_c = local_c + 8;
          __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x6c);
          if (*(int *)(local_14 + 0x6c) == 1) {
            gChain_Asic_Interval = 0x100;
          }
        }
      }
      else {
        local_c = local_c + 0xf;
        __isoc99_sscanf(local_c,&DAT_0001a014,local_14 + 0x40);
        gPattern_number = *(undefined4 *)(local_14 + 0x40);
      }
    }
    else {
      local_c = local_c + 5;
      for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
        local_14[local_10] = *local_c;
        local_c = local_c + 1;
        if ((*local_c == '\n') || (*local_c == '\r')) break;
      }
      local_10 = local_10 + 1;
      gName_len = local_10;
      local_14[local_10] = '\0';
      gHashBoard_S9 = 0;
      gHashBoard_T9 = 0;
      gHashBoard_T9_plus = '\0';
      gHashBoard_R4 = 0;
      gHashBoard_V9 = '\0';
      if ((*local_14 == 'R') && (local_14[1] == '4')) {
        gHashBoard_R4 = 1;
        printf("\n---%s: gHashBoard_R4\n\n","read_config");
      }
      if (((*local_14 == 'T') && (local_14[1] == '9')) && (local_14[2] == '+')) {
        gHashBoard_T9_plus = '\x01';
        printf("\n---%s: gHashBoard_T9_plus\n\n","read_config");
      }
      if (((*local_14 == 'T') && (local_14[1] == '9')) && (gHashBoard_T9_plus != '\x01')) {
        gHashBoard_T9 = 1;
        printf("\n---%s: gHashBoard_T9\n\n","read_config");
      }
      if ((*local_14 == 'S') && (local_14[1] == '9')) {
        gHashBoard_S9 = 1;
        printf("\n---%s: gHashBoard_S9\n\n","read_config");
      }
      if (((*local_14 == 'S') && (local_14[1] == '1')) && (local_14[2] == '1')) {
        gHashBoard_S11 = 1;
        printf("\n---%s: gHashBoard_S11\n\n","read_config");
      }
      if ((*local_14 == 'V') && (local_14[1] == '9')) {
        gHashBoard_V9 = '\x01';
        printf("\n---%s: gHashBoard_V9\n\n","read_config");
      }
    }
    if ((*(int *)(local_14 + 0x6c) == 1) && (*(int *)(local_14 + 0x74) == 0x569)) {
      strcpy(DAT_0000c378,Single_BM1385_WorkDataPathPrefix);
      strcpy(DAT_0000c37c,BTC_WorkDataFilePrefix);
      *(undefined4 *)(local_14 + 0x70) = 0x32;
    }
    if (gHashBoard_V9 != '\0') {
      strcpy(DAT_0000c378,V9_WorkDataPathPrefix);
      strcpy(DAT_0000c37c,BTC_WorkDataFilePrefix);
      *(undefined4 *)(local_14 + 0x6c) = 0x2d;
      *(undefined4 *)(local_14 + 0x70) = 0x32;
      *(undefined4 *)(local_14 + 0x74) = 0x569;
      gPic_addr_high_4_bit = 0xa00000;
      gChain_Asic_Interval = 4;
    }
  } while( true );
}

