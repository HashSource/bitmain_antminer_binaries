
undefined4 * read_config(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
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
  local_1c = fopen("/media/card/Config.ini","r");
  do {
    while( true ) {
      do {
        pcVar1 = fgets(&local_41c,0x3ff,local_1c);
        if (pcVar1 == (char *)0x0) {
          if (*(int *)((int)local_14 + 0x6c) == 1) {
            gChain_Asic_Interval = 0x100;
            if (*(int *)((int)local_14 + 0x74) == 0x6ba) {
              strcpy(DAT_0000d32c,BM1722_WorkDataPathPrefix);
              strcpy(DAT_0000d330,DCR_WorkDataFilePrefix);
              *(undefined4 *)((int)local_14 + 0x70) = 0x78;
              puVar3 = (undefined4 *)local_14;
            }
            else {
              puVar3 = (undefined4 *)0x6bd;
              if (*(int *)((int)local_14 + 0x74) == 0x6bd) {
                strcpy(DAT_0000d32c,BM1725_WorkDataPathPrefix);
                strcpy(DAT_0000d330,DCR_WorkDataFilePrefix);
                *(undefined4 *)((int)local_14 + 0x70) = 0x114;
                puVar3 = (undefined4 *)local_14;
              }
            }
          }
          else if ((gHashBoard_BBD12601 != '\0') ||
                  (puVar3 = (undefined4 *)(uint)gHashBoard_BBD25601, puVar3 != (undefined4 *)0x0)) {
            if (*(int *)((int)local_14 + 0x74) == 0x6ba) {
              strcpy(DAT_0000d32c,BM1722_WorkDataPathPrefix);
              strcpy(DAT_0000d330,DCR_WorkDataFilePrefix);
              *(undefined4 *)((int)local_14 + 0x70) = 0x78;
              *(undefined4 *)((int)local_14 + 0x74) = 0x6ba;
              uVar2 = calculate_asic_number(Conf._108_4_);
              gChain_Asic_Interval = __aeabi_idiv(0x100,uVar2);
              puVar3 = &gChain_Asic_Interval;
            }
            else {
              puVar3 = (undefined4 *)0x6bd;
              if (*(int *)((int)local_14 + 0x74) == 0x6bd) {
                strcpy(DAT_0000d32c,BM1725_WorkDataPathPrefix);
                strcpy(DAT_0000d330,DCR_WorkDataFilePrefix);
                *(undefined4 *)((int)local_14 + 0x70) = 0x114;
                *(undefined4 *)((int)local_14 + 0x74) = 0x6bd;
                uVar2 = calculate_asic_number(Conf._108_4_);
                gChain_Asic_Interval = __aeabi_idiv(0x100,uVar2);
                puVar3 = &gChain_Asic_Interval;
              }
            }
          }
          return puVar3;
        }
      } while ((local_41c == '#') || (local_41b == '#'));
      local_c = strstr(&local_41c,"Name=");
      if (local_c != (char *)0x0) break;
      local_c = strstr(&local_41c,"pattern_number=");
      if (local_c == (char *)0x0) {
        local_c = strstr(&local_41c,"AsicNum=");
        if (local_c == (char *)0x0) {
          local_c = strstr(&local_41c,"AsicType=");
          if (local_c == (char *)0x0) {
            local_c = strstr(&local_41c,"Timeout=");
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
                                                      local_c = strstr(&local_41c,"sensor_model=");
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_41c,
                                                                         "remote_local_gap=");
                                                        if (local_c == (char *)0x0) {
                                                          local_c = strstr(&local_41c,"TempSensor1="
                                                                          );
                                                          if (local_c == (char *)0x0) {
                                                            local_c = strstr(&local_41c,
                                                                             "TempSensor2=");
                                                            if (local_c == (char *)0x0) {
                                                              local_c = strstr(&local_41c,
                                                                               "TempSensor3=");
                                                              if (local_c == (char *)0x0) {
                                                                local_c = strstr(&local_41c,
                                                                                 "StartSensor=");
                                                                if (local_c == (char *)0x0) {
                                                                  local_c = strstr(&local_41c,
                                                                                   "StartTemp=");
                                                                  if (local_c == (char *)0x0) {
                                                                    local_c = strstr(&local_41c,
                                                                                     "TargetTemp=");
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
                                                                             "Invalid_Asic_Num=");
                                                            if (local_c == (char *)0x0) {
                                                              local_c = strstr(&local_41c,
                                                                               "Invalid_Core_Num=");
                                                              if (local_c == (char *)0x0) {
                                                                local_c = strstr(&local_41c,
                                                                                                                                                                  
                                                  "Least_nonce_per_core=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_41c,
                                                                     "Most_lost_nonce_total=");
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_41c,"Most_HW_Num=");
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_41c,
                                                                         "close_power_delay=");
                                                        if (local_c != (char *)0x0) {
                                                          local_c = local_c + 0x12;
                                                          __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                          (undefined4 *)
                                                                          ((int)local_14 + 0x108));
                                                        }
                                                      }
                                                      else {
                                                        local_c = local_c + 0xc;
                                                        __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                        (undefined4 *)
                                                                        ((int)local_14 + 0xf8));
                                                      }
                                                    }
                                                    else {
                                                      local_c = local_c + 0x16;
                                                      __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                      (undefined4 *)
                                                                      ((int)local_14 + 0xf4));
                                                    }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x15;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xf0));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x11;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xec));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x11;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xe8));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xb;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xdc));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xe;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xd8));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 10;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (int)local_14 + 0xd6);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x12;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xe4));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x1a;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xe0));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xb;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (int)local_14 + 0xd5);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 10;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xd4));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (int)local_14 + 0xd3);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_00028bb8,
                                                                    (int)local_14 + 0xd2);
                                                    if (*(char *)((int)local_14 + 0xd2) != '\0') {
                                                      gSensor_number = gSensor_number + 1;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_00028bb8,
                                                                    (int)local_14 + 0xd1);
                                                    if (*(char *)((int)local_14 + 0xd1) != '\0') {
                                                      gSensor_number = gSensor_number + 1;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_00028bb8,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xd0));
                                                    if (*(char *)((int)local_14 + 0xd0) != '\0') {
                                                      gSensor_number = gSensor_number + 1;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x11;
                                                    __isoc99_sscanf(local_c,&DAT_00028bb8,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0x100));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xd;
                                                    __isoc99_sscanf(local_c,&DAT_00028bb8,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xfc));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 10;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xcc));
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                    (undefined4 *)
                                                                    ((int)local_14 + 0xc4));
                                                  }
                                                }
                                                else {
                                                  local_c = local_c + 9;
                                                  __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                  (undefined4 *)
                                                                  ((int)local_14 + 0xc0));
                                                  if (*(int *)((int)local_14 + 0xc0) != 0) {
                                                    gHowManyVoltageLevel =
                                                         gHowManyVoltageLevel + '\x01';
                                                  }
                                                }
                                              }
                                              else {
                                                local_c = local_c + 9;
                                                __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                                (undefined4 *)((int)local_14 + 0xbc)
                                                               );
                                                if (*(int *)((int)local_14 + 0xbc) != 0) {
                                                  gHowManyVoltageLevel =
                                                       gHowManyVoltageLevel + '\x01';
                                                }
                                              }
                                            }
                                            else {
                                              local_c = local_c + 9;
                                              __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                              (undefined4 *)((int)local_14 + 0xb8));
                                              if (*(int *)((int)local_14 + 0xb8) != 0) {
                                                gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01'
                                                ;
                                              }
                                            }
                                          }
                                          else {
                                            local_c = local_c + 9;
                                            __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                            (undefined4 *)((int)local_14 + 0xb4));
                                            if (*(int *)((int)local_14 + 0xb4) != 0) {
                                              gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                            }
                                          }
                                        }
                                        else {
                                          local_c = local_c + 9;
                                          __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                          (undefined4 *)((int)local_14 + 0xb0));
                                          if (*(int *)((int)local_14 + 0xb0) != 0) {
                                            gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                          }
                                        }
                                      }
                                      else {
                                        local_c = local_c + 9;
                                        __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                        (undefined4 *)((int)local_14 + 0xac));
                                        if (*(int *)((int)local_14 + 0xac) != 0) {
                                          gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                        }
                                      }
                                    }
                                    else {
                                      local_c = local_c + 9;
                                      __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                      (undefined4 *)((int)local_14 + 0xa8));
                                      if (*(int *)((int)local_14 + 0xa8) != 0) {
                                        gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                      }
                                    }
                                  }
                                  else {
                                    local_c = local_c + 9;
                                    __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                    (undefined4 *)((int)local_14 + 0xa4));
                                    if (*(int *)((int)local_14 + 0xa4) != 0) {
                                      gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                    }
                                  }
                                }
                                else {
                                  local_c = local_c + 9;
                                  __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                  (undefined4 *)((int)local_14 + 0xa0));
                                  if (*(int *)((int)local_14 + 0xa0) != 0) {
                                    gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                                  }
                                }
                              }
                              else {
                                local_c = local_c + 6;
                                __isoc99_sscanf(local_c,&DAT_00028ab0,
                                                (undefined4 *)((int)local_14 + 0x68));
                              }
                            }
                            else {
                              local_c = local_c + 6;
                              __isoc99_sscanf(local_c,&DAT_00028ab0,
                                              (undefined4 *)((int)local_14 + 100));
                            }
                          }
                          else {
                            local_c = local_c + 6;
                            __isoc99_sscanf(local_c,&DAT_00028ab0,
                                            (undefined4 *)((int)local_14 + 0x60));
                          }
                        }
                        else {
                          local_c = local_c + 6;
                          __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x5c)
                                         );
                        }
                      }
                      else {
                        local_c = local_c + 6;
                        __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x58));
                      }
                    }
                    else {
                      local_c = local_c + 6;
                      __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x54));
                    }
                  }
                  else {
                    local_c = local_c + 6;
                    __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x50));
                  }
                }
                else {
                  local_c = local_c + 6;
                  __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x4c));
                }
              }
              else {
                local_c = local_c + 6;
                __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x48));
              }
            }
            else {
              local_c = local_c + 8;
              __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 200));
            }
          }
          else {
            local_c = local_c + 9;
            __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x74));
          }
        }
        else {
          local_c = local_c + 8;
          __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x6c));
        }
      }
      else {
        local_c = local_c + 0xf;
        __isoc99_sscanf(local_c,&DAT_00028ab0,(undefined4 *)((int)local_14 + 0x40));
      }
    }
    local_c = local_c + 5;
    for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
      *(char *)((int)local_14 + local_10) = *local_c;
      local_c = local_c + 1;
      if ((*local_c == '\n') || (*local_c == '\r')) break;
    }
    local_10 = local_10 + 1;
    gName_len = local_10;
    *(undefined *)((int)local_14 + local_10) = 0;
    gHashBoard_BBD12601 = '\0';
    gHashBoard_BBD25601 = 0;
    if ((((*local_14 == 'B') && (*(char *)((int)local_14 + 1) == 'B')) &&
        (*(char *)((int)local_14 + 2) == 'D')) &&
       (((*(char *)((int)local_14 + 3) == '1' && (*(char *)((int)local_14 + 4) == '2')) &&
        ((*(char *)((int)local_14 + 5) == '6' &&
         ((*(char *)((int)local_14 + 6) == '0' && (*(char *)((int)local_14 + 7) == '1')))))))) {
      gHashBoard_BBD12601 = '\x01';
      printf("\n---%s: gHashBoard_BBD12601\n\n","read_config");
    }
    else if ((*local_14 == 'B') &&
            (((((*(char *)((int)local_14 + 1) == 'B' && (*(char *)((int)local_14 + 2) == 'D')) &&
               (*(char *)((int)local_14 + 3) == '2')) &&
              ((*(char *)((int)local_14 + 4) == '5' && (*(char *)((int)local_14 + 5) == '6')))) &&
             ((*(char *)((int)local_14 + 6) == '0' && (*(char *)((int)local_14 + 7) == '1')))))) {
      gHashBoard_BBD25601 = 1;
      printf("\n---%s: gHashBoard_BBD25601\n\n","read_config");
    }
  } while( true );
}

