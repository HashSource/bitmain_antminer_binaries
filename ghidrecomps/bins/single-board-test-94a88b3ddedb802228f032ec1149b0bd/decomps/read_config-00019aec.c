
undefined4 read_config(void)

{
  char *pcVar1;
  int local_430;
  int local_42c;
  char local_428;
  char local_427;
  int local_28;
  FILE *local_24;
  FILE *local_20;
  int local_1c;
  FILE *local_18;
  undefined1 *local_14;
  int local_10;
  char *local_c;
  
  local_14 = Conf;
  memset(&local_428,0,0x400);
  local_42c = 0;
  local_430 = 0;
  local_18 = fopen("/etc/config/Config.ini","r");
LAB_0001ab3c:
  do {
    while( true ) {
      do {
        pcVar1 = fgets(&local_428,0x3ff,local_18);
        if (pcVar1 == (char *)0x0) {
          *(undefined4 *)(local_14 + 0x70) = 0x54;
          return 0;
        }
      } while ((local_428 == '#') || (local_427 == '#'));
      local_c = strstr(&local_428,"Name=");
      if (local_c == (char *)0x0) break;
      local_c = local_c + 5;
      for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
        pcVar1 = local_c + 1;
        local_14[local_10] = *local_c;
        local_c = pcVar1;
        if ((*pcVar1 == '\n') || (*pcVar1 == '\r')) break;
      }
      local_10 = local_10 + 1;
      gName_len = local_10;
      local_14[local_10] = 0;
    }
    local_c = strstr(&local_428,"TestDir=");
    if (local_c != (char *)0x0) {
      local_c = local_c + 8;
      for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
        pcVar1 = local_c + 1;
        cgpu[local_10 + 0x260] = *local_c;
        local_c = pcVar1;
        if ((*pcVar1 == '\n') || (*pcVar1 == '\r')) break;
      }
      cgpu[local_10 + 0x261] = 0;
      local_10 = local_10 + 1;
      printf("workdataPathPrefix:%s\n",DAT_0001a044);
      goto LAB_0001ab3c;
    }
    local_c = strstr(&local_428,"DataCount=");
    if (local_c == (char *)0x0) {
      local_c = strstr(&local_428,"PassCount1=");
      if (local_c == (char *)0x0) {
        local_c = strstr(&local_428,"PassCount2=");
        if (local_c == (char *)0x0) {
          local_c = strstr(&local_428,"PassCount3=");
          if (local_c == (char *)0x0) {
            local_c = strstr(&local_428,"Freq=");
            if (local_c == (char *)0x0) {
              local_c = strstr(&local_428,"freq_e=");
              if (local_c == (char *)0x0) {
                local_c = strstr(&local_428,"UseConfigVol=");
                if (local_c == (char *)0x0) {
                  local_c = strstr(&local_428,"freq_m=");
                  if (local_c == (char *)0x0) {
                    local_c = strstr(&local_428,"freq_a=");
                    if (local_c == (char *)0x0) {
                      local_c = strstr(&local_428,"freq_t=");
                      if (local_c == (char *)0x0) {
                        local_c = strstr(&local_428,"force_freq=");
                        if (local_c == (char *)0x0) {
                          local_c = strstr(&local_428,"Timeout=");
                          if (local_c == (char *)0x0) {
                            local_c = strstr(&local_428,"AsicNum=");
                            if (local_c == (char *)0x0) {
                              local_c = strstr(&local_428,"UseFreqPIC=");
                              if (local_c == (char *)0x0) {
                                local_c = strstr(&local_428,"TestMode=");
                                if (local_c == (char *)0x0) {
                                  local_c = strstr(&local_428,"CheckChain=");
                                  if (local_c == (char *)0x0) {
                                    local_c = strstr(&local_428,"CommandMode=");
                                    if (local_c == (char *)0x0) {
                                      local_c = strstr(&local_428,"ValidNonce1=");
                                      if (local_c == (char *)0x0) {
                                        local_c = strstr(&local_428,"ValidNonce2=");
                                        if (local_c == (char *)0x0) {
                                          local_c = strstr(&local_428,"ValidNonce3=");
                                          if (local_c == (char *)0x0) {
                                            local_c = strstr(&local_428,"Pic_VOLTAGE=");
                                            if (local_c == (char *)0x0) {
                                              local_c = strstr(&local_428,"Voltage1=");
                                              if (local_c == (char *)0x0) {
                                                local_c = strstr(&local_428,"Voltage2=");
                                                if (local_c == (char *)0x0) {
                                                  local_c = strstr(&local_428,"Voltage3=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_428,"final_voltage1=");
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_428,"final_voltage2=")
                                                      ;
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_428,
                                                                         "final_voltage3=");
                                                        if (local_c == (char *)0x0) {
                                                          local_c = strstr(&local_428,"freq_gap=");
                                                          if (local_c == (char *)0x0) {
                                                            local_c = strstr(&local_428,
                                                                             "OpenCoreGap=");
                                                            if (local_c == (char *)0x0) {
                                                              local_c = strstr(&local_428,
                                                                               "CheckTemp=");
                                                              if (local_c == (char *)0x0) {
                                                                local_c = strstr(&local_428,
                                                                                 "IICPic=");
                                                                if (local_c == (char *)0x0) {
                                                                  local_c = strstr(&local_428,
                                                                                   "Open_Core_Num1="
                                                                                  );
                                                                  if (local_c == (char *)0x0) {
                                                                    local_c = strstr(&local_428,
                                                                                                                                                                          
                                                  "Open_Core_Num2=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_428,"Open_Core_Num3=");
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_428,"Open_Core_Num4=")
                                                      ;
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_428,"DAC=");
                                                        if (local_c == (char *)0x0) {
                                                          local_c = strstr(&local_428,"GetTempFrom="
                                                                          );
                                                          if (local_c == (char *)0x0) {
                                                            local_c = strstr(&local_428,"TempSel=");
                                                            if (local_c == (char *)0x0) {
                                                              local_c = strstr(&local_428,
                                                                               "TempSensor1=");
                                                              if (local_c == (char *)0x0) {
                                                                local_c = strstr(&local_428,
                                                                                 "TempSensor2=");
                                                                if (local_c == (char *)0x0) {
                                                                  local_c = strstr(&local_428,
                                                                                   "TempSensor3=");
                                                                  if (local_c == (char *)0x0) {
                                                                    local_c = strstr(&local_428,
                                                                                     "TempSensor4=")
                                                                    ;
                                                                    if (local_c == (char *)0x0) {
                                                                      local_c = strstr(&local_428,
                                                                                                                                                                              
                                                  "DefaultTempOffset=");
                                                  if (local_c == (char *)0x0) {
                                                    local_c = strstr(&local_428,"year=");
                                                    if (local_c == (char *)0x0) {
                                                      local_c = strstr(&local_428,"month=");
                                                      if (local_c == (char *)0x0) {
                                                        local_c = strstr(&local_428,"date=");
                                                        if (local_c == (char *)0x0) {
                                                          local_c = strstr(&local_428,"hour=");
                                                          if (local_c == (char *)0x0) {
                                                            local_c = strstr(&local_428,"minute=");
                                                            if (local_c == (char *)0x0) {
                                                              local_c = strstr(&local_428,"second=")
                                                              ;
                                                              if (local_c == (char *)0x0) {
                                                                local_c = strstr(&local_428,
                                                                                 "StartTemp=");
                                                                if (local_c != (char *)0x0) {
                                                                  local_c = local_c + 10;
                                                                  __isoc99_sscanf(local_c,&
                                                  DAT_0012e50c,local_14 + 0x104);
                                                  __isoc99_sscanf(local_c,&DAT_0012e50c,&local_430);
                                                  if (local_430 < 0) {
                                                    local_430 = -local_430;
                                                    *(int *)(local_14 + 0x104) =
                                                         (int)(char)local_430;
                                                    *(int *)(local_14 + 0x104) =
                                                         -*(int *)(local_14 + 0x104);
                                                  }
                                                  else {
                                                    *(int *)(local_14 + 0x104) = local_430;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 7;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x11c);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 7;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x118);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 5;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x114);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 5;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x110);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 6;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x10c);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 5;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x108);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0x12;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,&local_42c
                                                                   );
                                                    if (local_42c < 0) {
                                                      local_42c = -local_42c;
                                                      local_14[0xe8] = (char)local_42c;
                                                      local_14[0xe8] = -local_14[0xe8];
                                                    }
                                                    else {
                                                      local_14[0xe8] = (char)local_42c;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xe4);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xe0);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xdc);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xd8);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 8;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xd4);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xd0);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 4;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xcc);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 200);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xc4);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xc0);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xbc);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 7;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0xb8);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 10;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0xb4);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xc;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0xb0);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 9;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xac);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xa8);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xa4);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 0xf;
                                                    __isoc99_sscanf(local_c,&DAT_0012e700,
                                                                    local_14 + 0xa0);
                                                  }
                                                  }
                                                  else {
                                                    local_c = local_c + 9;
                                                    __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                    local_14 + 0x9c);
                                                  }
                                                }
                                                else {
                                                  local_c = local_c + 9;
                                                  __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                  local_14 + 0x98);
                                                }
                                              }
                                              else {
                                                local_c = local_c + 9;
                                                __isoc99_sscanf(local_c,&DAT_0012e50c,
                                                                local_14 + 0x94);
                                              }
                                            }
                                            else {
                                              local_c = local_c + 0xc;
                                              __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x90)
                                              ;
                                            }
                                          }
                                          else {
                                            local_c = local_c + 0xc;
                                            __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x8c);
                                          }
                                        }
                                        else {
                                          local_c = local_c + 0xc;
                                          __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x88);
                                        }
                                      }
                                      else {
                                        local_c = local_c + 0xc;
                                        __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x84);
                                      }
                                    }
                                    else {
                                      local_c = local_c + 0xc;
                                      __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x80);
                                    }
                                  }
                                  else {
                                    local_c = local_c + 0xb;
                                    __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x7c);
                                  }
                                }
                                else {
                                  local_c = local_c + 9;
                                  __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x78);
                                }
                              }
                              else {
                                local_c = local_c + 0xb;
                                __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x74);
                              }
                            }
                            else {
                              local_c = local_c + 8;
                              __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x70);
                            }
                          }
                          else {
                            local_c = local_c + 8;
                            __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x5c);
                          }
                        }
                        else {
                          local_c = local_c + 0xb;
                        }
                      }
                      else {
                        local_c = local_c + 7;
                        __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0xf8);
                      }
                    }
                    else {
                      local_c = local_c + 7;
                      __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0xf4);
                    }
                  }
                  else {
                    local_c = local_c + 7;
                    __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0xf0);
                  }
                }
                else {
                  local_c = local_c + 0xd;
                  __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x100);
                }
              }
              else {
                local_c = local_c + 7;
                __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0xec);
              }
            }
            else {
              local_c = local_c + 5;
              __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x58);
              *(undefined4 *)(local_14 + 0xfc) = 0;
              local_1c = GetForceFreq(&local_28);
              if (3 < log_level) {
                local_20 = fopen(log_file,"a+");
                if (local_20 != (FILE *)0x0) {
                  fprintf(local_20,"%s:%d: forceFreq=%d forceFlag=%d\n","driver-bitmain.c",0x3e3,
                          local_1c,local_28);
                }
                fclose(local_20);
              }
              if ((0 < local_28) && (199 < local_1c)) {
                *(int *)(local_14 + 0x58) = local_1c;
                *(undefined4 *)(local_14 + 0xfc) = 1;
                if (3 < log_level) {
                  local_24 = fopen(log_file,"a+");
                  if (local_24 != (FILE *)0x0) {
                    fprintf(local_24,"%s:%d: Find Force Freq=%d will search Freq again!\n",
                            "driver-bitmain.c",0x3ec,local_1c);
                  }
                  fclose(local_24);
                }
              }
            }
          }
          else {
            local_c = local_c + 0xb;
            __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x54);
          }
        }
        else {
          local_c = local_c + 0xb;
          __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x50);
        }
      }
      else {
        local_c = local_c + 0xb;
        __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x4c);
      }
    }
    else {
      local_c = local_c + 10;
      __isoc99_sscanf(local_c,&DAT_0012e50c,local_14 + 0x48);
    }
  } while( true );
}

