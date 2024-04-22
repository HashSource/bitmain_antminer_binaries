
void app_config_handle(char *param_1)

{
  char *pcVar1;
  char acStack_814 [1024];
  char local_414;
  char local_413;
  FILE *local_14;
  char *local_10;
  undefined1 *local_c;
  
  local_c = app_conf;
  memset(&local_414,0,0x400);
  local_10 = (char *)0x0;
  local_14 = fopen(param_1,"r");
  if ((local_14 == (FILE *)0x0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    snprintf(acStack_814,0x400,"open %s failed\n",param_1);
    _applog(2,acStack_814,0);
  }
  while (pcVar1 = fgets(&local_414,0x3ff,local_14), pcVar1 != (char *)0x0) {
    if ((local_414 != '#') && (local_413 != '#')) {
      local_10 = strstr(&local_414,"Name=");
      if (local_10 == (char *)0x0) {
        local_10 = strstr(&local_414,"type=");
        if (local_10 == (char *)0x0) {
          local_10 = strstr(&local_414,"comport=");
          if (local_10 == (char *)0x0) {
            local_10 = strstr(&local_414,"baudrate=");
            if (local_10 == (char *)0x0) {
              local_10 = strstr(&local_414,"miner_mode=");
              if (local_10 == (char *)0x0) {
                local_10 = strstr(&local_414,"reg_ticket_mask=");
                if (local_10 == (char *)0x0) {
                  local_10 = strstr(&local_414,"reg_core_timeout=");
                  if (local_10 == (char *)0x0) {
                    local_10 = strstr(&local_414,"reg_misc=");
                    if (local_10 == (char *)0x0) {
                      local_10 = strstr(&local_414,"workstr=");
                      if (local_10 == (char *)0x0) {
                        local_10 = strstr(&local_414,"single_pattern_send_timeout=");
                        if (local_10 == (char *)0x0) {
                          local_10 = strstr(&local_414,"single_chip_return_nonce=");
                          if (local_10 == (char *)0x0) {
                            local_10 = strstr(&local_414,"single_chip_hw=");
                            if (local_10 == (char *)0x0) {
                              local_10 = strstr(&local_414,"TunelPath=");
                              if (local_10 == (char *)0x0) {
                                local_10 = strstr(&local_414,"CP210xRuntime=");
                                if (local_10 == (char *)0x0) {
                                  local_10 = strstr(&local_414,"pattern_number=");
                                  if (local_10 == (char *)0x0) {
                                    local_10 = strstr(&local_414,"repeat_ctrl=");
                                    if (local_10 == (char *)0x0) {
                                      local_10 = strstr(&local_414,"AsicNum=");
                                      if (local_10 == (char *)0x0) {
                                        local_10 = strstr(&local_414,"CoreNum=");
                                        if (local_10 == (char *)0x0) {
                                          local_10 = strstr(&local_414,"Freq=");
                                          if (local_10 == (char *)0x0) {
                                            local_10 = strstr(&local_414,"Voltage=");
                                            if (local_10 == (char *)0x0) {
                                              local_10 = strstr(&local_414,"slt_method=");
                                              if (local_10 == (char *)0x0) {
                                                local_10 = strstr(&local_414,"bin1_freq=");
                                                if (local_10 == (char *)0x0) {
                                                  local_10 = strstr(&local_414,"bin2_freq=");
                                                  if (local_10 == (char *)0x0) {
                                                    local_10 = strstr(&local_414,"bin3_freq=");
                                                    if (local_10 == (char *)0x0) {
                                                      local_10 = strstr(&local_414,
                                                                        "bin1_require_nonce=");
                                                      if (local_10 == (char *)0x0) {
                                                        local_10 = strstr(&local_414,
                                                                          "bin2_require_nonce=");
                                                        if (local_10 == (char *)0x0) {
                                                          local_10 = strstr(&local_414,
                                                                            "bin3_require_nonce=");
                                                          if (local_10 == (char *)0x0) {
                                                            local_10 = strstr(&local_414,
                                                                              "bin1_max_hw=");
                                                            if (local_10 == (char *)0x0) {
                                                              local_10 = strstr(&local_414,
                                                                                "bin2_max_hw=");
                                                              if (local_10 == (char *)0x0) {
                                                                local_10 = strstr(&local_414,
                                                                                  "bin3_max_hw=");
                                                                if (local_10 == (char *)0x0) {
                                                                  local_10 = strstr(&local_414,
                                                                                    "bin1_rate=");
                                                                  if (local_10 == (char *)0x0) {
                                                                    local_10 = strstr(&local_414,
                                                                                      "bin2_rate=");
                                                                    if (local_10 == (char *)0x0) {
                                                                      local_10 = strstr(&local_414,
                                                                                        "bin3_rate="
                                                                                       );
                                                                      if (local_10 == (char *)0x0) {
                                                                        local_10 = strstr(&local_414
                                                                                          ,
                                                  "tempture_high=");
                                                  if (local_10 == (char *)0x0) {
                                                    local_10 = strstr(&local_414,"tempture_low=");
                                                    if (local_10 == (char *)0x0) {
                                                      local_10 = strstr(&local_414,"slt_delay=");
                                                      if (local_10 == (char *)0x0) {
                                                        local_10 = strstr(&local_414,
                                                                          "enable_adjust_vol=");
                                                        if (local_10 == (char *)0x0) {
                                                          local_10 = strstr(&local_414,"timeout=");
                                                          if (local_10 != (char *)0x0) {
                                                            local_10 = local_10 + 8;
                                                            __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                            local_c + 0x1b0);
                                                          }
                                                        }
                                                        else {
                                                          local_10 = local_10 + 0x12;
                                                          __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                          local_c + 0x1a4);
                                                        }
                                                      }
                                                      else {
                                                        local_10 = local_10 + 10;
                                                        __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                        local_c + 0x268);
                                                      }
                                                    }
                                                    else {
                                                      local_10 = local_10 + 0xd;
                                                      __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                      local_c + 0x1ac);
                                                    }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0xe;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x1a8);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 10;
                                                    __isoc99_sscanf(local_10,&DAT_00036868,
                                                                    local_c + 0x264);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 10;
                                                    __isoc99_sscanf(local_10,&DAT_00036868,
                                                                    local_c + 0x260);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 10;
                                                    __isoc99_sscanf(local_10,&DAT_00036868,
                                                                    local_c + 0x25c);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0xc;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 600);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0xc;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x254);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0xc;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x250);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0x13;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x24c);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0x13;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x248);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 0x13;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x244);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 10;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x240);
                                                  }
                                                  }
                                                  else {
                                                    local_10 = local_10 + 10;
                                                    __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                    local_c + 0x23c);
                                                  }
                                                }
                                                else {
                                                  local_10 = local_10 + 10;
                                                  __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                  local_c + 0x238);
                                                }
                                              }
                                              else {
                                                local_10 = local_10 + 0xb;
                                                __isoc99_sscanf(local_10,&DAT_000366ac,
                                                                local_c + 0x234);
                                              }
                                            }
                                            else {
                                              local_10 = local_10 + 8;
                                              __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x1a0
                                                             );
                                            }
                                          }
                                          else {
                                            local_10 = local_10 + 5;
                                            __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x19c);
                                          }
                                        }
                                        else {
                                          local_10 = local_10 + 8;
                                          __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x198);
                                        }
                                      }
                                      else {
                                        local_10 = local_10 + 8;
                                        __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x194);
                                      }
                                    }
                                    else {
                                      local_10 = local_10 + 0xc;
                                      __isoc99_sscanf(local_10,&DAT_00036694,local_c + 0x184);
                                    }
                                  }
                                  else {
                                    local_10 = local_10 + 0xf;
                                    __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x180);
                                  }
                                }
                                else {
                                  local_10 = local_10 + 0xe;
                                  __isoc99_sscanf(local_10,&DAT_00036694,local_c + 500);
                                }
                              }
                              else {
                                local_10 = local_10 + 10;
                                __isoc99_sscanf(local_10,&DAT_00036694,local_c + 0x1b4);
                              }
                            }
                            else {
                              local_10 = local_10 + 0xf;
                              __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x17c);
                            }
                          }
                          else {
                            local_10 = local_10 + 0x19;
                            __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x178);
                          }
                        }
                        else {
                          local_10 = local_10 + 0x1c;
                          __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x174);
                        }
                      }
                      else {
                        local_10 = local_10 + 8;
                        __isoc99_sscanf(local_10,&DAT_00036694,local_c + 0x50);
                      }
                    }
                    else {
                      local_10 = local_10 + 9;
                      __isoc99_sscanf(local_10,&DAT_000366f0,local_c + 0x170);
                    }
                  }
                  else {
                    local_10 = local_10 + 0x11;
                    __isoc99_sscanf(local_10,&DAT_000366f0,local_c + 0x16c);
                  }
                }
                else {
                  local_10 = local_10 + 0x10;
                  __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x168);
                }
              }
              else {
                local_10 = local_10 + 0xb;
                __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x2c);
              }
            }
            else {
              local_10 = local_10 + 9;
              __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x28);
            }
          }
          else {
            local_10 = local_10 + 8;
            __isoc99_sscanf(local_10,&DAT_000366ac,local_c + 0x14);
          }
        }
        else {
          local_10 = local_10 + 5;
          __isoc99_sscanf(local_10,&DAT_00036694,local_c + 0x18);
        }
      }
      else {
        local_10 = local_10 + 5;
        __isoc99_sscanf(local_10,&DAT_00036694,local_c + 4);
      }
    }
  }
  fclose(local_14);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_814,0x400,"%s done=========\n ","app_config_handle");
    _applog(2,acStack_814,0);
  }
  return;
}

