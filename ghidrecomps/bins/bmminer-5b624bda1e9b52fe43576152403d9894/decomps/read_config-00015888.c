
/* WARNING: Unknown calling convention */

int read_config(void)

{
  FILE *__stream;
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  FILE *file;
  int local_420;
  int local_41c;
  char str [1024];
  
  memset(str,0,0x400);
  local_420 = 0;
  local_41c = 0;
  __stream = fopen("/etc/config/Config.ini","r");
  do {
    while( true ) {
      do {
        pcVar1 = fgets(str,0x3ff,__stream);
        if (pcVar1 == (char *)0x0) {
          Conf.AsicNum = 0x12;
          Conf.AsicType = 0x56b;
          Conf.CoreNum = 0x72;
          return 0;
        }
      } while ((str[0] == '#') || (str[1] == '#'));
      pcVar1 = strstr(str,"TestDir=");
      if (pcVar1 != (char *)0x0) break;
      pcVar1 = strstr(str,"DataCount=");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = strstr(str,"PassCount1=");
        if (pcVar1 == (char *)0x0) {
          pcVar1 = strstr(str,"PassCount2=");
          if (pcVar1 == (char *)0x0) {
            pcVar1 = strstr(str,"PassCount3=");
            if (pcVar1 == (char *)0x0) {
              pcVar1 = strstr(str,"Freq=");
              if (pcVar1 == (char *)0x0) {
                pcVar1 = strstr(str,"freq_e=");
                if (pcVar1 == (char *)0x0) {
                  pcVar1 = strstr(str,"UseConfigVol=");
                  if (pcVar1 == (char *)0x0) {
                    pcVar1 = strstr(str,"freq_m=");
                    if (pcVar1 == (char *)0x0) {
                      pcVar1 = strstr(str,"freq_a=");
                      if (pcVar1 == (char *)0x0) {
                        pcVar1 = strstr(str,"freq_t=");
                        if (pcVar1 == (char *)0x0) {
                          pcVar1 = strstr(str,"force_freq=");
                          if (pcVar1 == (char *)0x0) {
                            pcVar1 = strstr(str,"Timeout=");
                            if (pcVar1 == (char *)0x0) {
                              pcVar1 = strstr(str,"UseFreqPIC=");
                              if (pcVar1 == (char *)0x0) {
                                pcVar1 = strstr(str,"TestMode=");
                                if (pcVar1 == (char *)0x0) {
                                  pcVar1 = strstr(str,"CheckChain=");
                                  if (pcVar1 == (char *)0x0) {
                                    pcVar1 = strstr(str,"CommandMode=");
                                    if (pcVar1 == (char *)0x0) {
                                      pcVar1 = strstr(str,"ValidNonce1=");
                                      if (pcVar1 == (char *)0x0) {
                                        pcVar1 = strstr(str,"ValidNonce2=");
                                        if (pcVar1 == (char *)0x0) {
                                          pcVar1 = strstr(str,"ValidNonce3=");
                                          if (pcVar1 == (char *)0x0) {
                                            pcVar1 = strstr(str,"Pic_VOLTAGE=");
                                            if (pcVar1 == (char *)0x0) {
                                              pcVar1 = strstr(str,"Voltage1=");
                                              if (pcVar1 == (char *)0x0) {
                                                pcVar1 = strstr(str,"Voltage2=");
                                                if (pcVar1 == (char *)0x0) {
                                                  pcVar1 = strstr(str,"Voltage3=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(str,"final_voltage1=");
                                                    if (pcVar1 == (char *)0x0) {
                                                      pcVar1 = strstr(str,"final_voltage2=");
                                                      if (pcVar1 == (char *)0x0) {
                                                        pcVar1 = strstr(str,"final_voltage3=");
                                                        if (pcVar1 == (char *)0x0) {
                                                          pcVar1 = strstr(str,"freq_gap=");
                                                          if (pcVar1 == (char *)0x0) {
                                                            pcVar1 = strstr(str,"OpenCoreGap=");
                                                            if (pcVar1 == (char *)0x0) {
                                                              pcVar1 = strstr(str,"CheckTemp=");
                                                              if (pcVar1 == (char *)0x0) {
                                                                pcVar1 = strstr(str,"IICPic=");
                                                                if (pcVar1 == (char *)0x0) {
                                                                  pcVar1 = strstr(str,
                                                  "Open_Core_Num1=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(str,"Open_Core_Num2=");
                                                    if (pcVar1 == (char *)0x0) {
                                                      pcVar1 = strstr(str,"Open_Core_Num3=");
                                                      if (pcVar1 == (char *)0x0) {
                                                        pcVar1 = strstr(str,"Open_Core_Num4=");
                                                        if (pcVar1 == (char *)0x0) {
                                                          pcVar1 = strstr(str,"DAC=");
                                                          if (pcVar1 == (char *)0x0) {
                                                            pcVar1 = strstr(str,"GetTempFrom=");
                                                            if (pcVar1 == (char *)0x0) {
                                                              pcVar1 = strstr(str,"TempSel=");
                                                              if (pcVar1 == (char *)0x0) {
                                                                pcVar1 = strstr(str,"TempSensor1=");
                                                                if (pcVar1 == (char *)0x0) {
                                                                  pcVar1 = strstr(str,"TempSensor2="
                                                                                 );
                                                                  if (pcVar1 == (char *)0x0) {
                                                                    pcVar1 = strstr(str,
                                                  "TempSensor3=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(str,"TempSensor4=");
                                                    if (pcVar1 == (char *)0x0) {
                                                      pcVar1 = strstr(str,"DefaultTempOffset=");
                                                      if (pcVar1 == (char *)0x0) {
                                                        pcVar1 = strstr(str,"year=");
                                                        if (pcVar1 == (char *)0x0) {
                                                          pcVar1 = strstr(str,"month=");
                                                          if (pcVar1 == (char *)0x0) {
                                                            pcVar1 = strstr(str,"date=");
                                                            if (pcVar1 == (char *)0x0) {
                                                              pcVar1 = strstr(str,"hour=");
                                                              if (pcVar1 == (char *)0x0) {
                                                                pcVar1 = strstr(str,"minute=");
                                                                if (pcVar1 == (char *)0x0) {
                                                                  pcVar1 = strstr(str,"second=");
                                                                  if (pcVar1 == (char *)0x0) {
                                                                    pcVar1 = strstr(str,
                                                  "StartSensor=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(str,"StartTemp=");
                                                    if (pcVar1 != (char *)0x0) {
                                                      sscanf(pcVar1 + 10,"%d",0x2d450c);
                                                      sscanf(pcVar1 + 10,"%d",&local_41c);
                                                      Conf.StartTemp = local_41c;
                                                      if (local_41c < 0) {
                                                        local_41c = -local_41c;
                                                        Conf.StartTemp = -(int)(char)local_41c;
                                                      }
                                                    }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%d",0x2d4508);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",0x2d4524);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",0x2d4520);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 5,"%d",0x2d451c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 5,"%d",0x2d4518);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 6,"%d",0x2d4514);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 5,"%d",0x2d4510);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0x12,"%d",&local_420);
                                                    iVar3 = local_420;
                                                    if (local_420 < 0) {
                                                      local_420 = -local_420;
                                                    }
                                                    Conf.DefaultTempOffset = (char)iVar3;
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2d44e8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2d44e4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2d44e0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2d44dc);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 8,"%ud",0x2d44d8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2d44d4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 4,"%ud",0x2d44d0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44cc);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44c8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44c4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44c0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",0x2d44bc);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 10,"%d",0x2d44b8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%d",0x2d44b4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 9,"%ud",0x2d44b0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44ac);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44a8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2d44a4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 9,"%d",0x2d44a0);
                                                  }
                                                }
                                                else {
                                                  sscanf(pcVar1 + 9,"%d",0x2d449c);
                                                }
                                              }
                                              else {
                                                sscanf(pcVar1 + 9,"%d",0x2d4498);
                                              }
                                            }
                                            else {
                                              sscanf(pcVar1 + 0xc,"%d",0x2d4494);
                                            }
                                          }
                                          else {
                                            sscanf(pcVar1 + 0xc,"%d",0x2d4490);
                                          }
                                        }
                                        else {
                                          sscanf(pcVar1 + 0xc,"%d",0x2d448c);
                                        }
                                      }
                                      else {
                                        sscanf(pcVar1 + 0xc,"%d",0x2d4488);
                                      }
                                    }
                                    else {
                                      sscanf(pcVar1 + 0xc,"%d",0x2d4480);
                                    }
                                  }
                                  else {
                                    sscanf(pcVar1 + 0xb,"%d",0x2d447c);
                                  }
                                }
                                else {
                                  sscanf(pcVar1 + 9,"%d",0x2d4478);
                                }
                              }
                              else {
                                sscanf(pcVar1 + 0xb,"%d",0x2d4474);
                              }
                            }
                            else {
                              sscanf(pcVar1 + 8,"%d",0x2d4458);
                            }
                          }
                        }
                        else {
                          sscanf(pcVar1 + 7,"%d",0x2d44fc);
                        }
                      }
                      else {
                        sscanf(pcVar1 + 7,"%d",0x2d44f8);
                      }
                    }
                    else {
                      sscanf(pcVar1 + 7,"%d",0x2d44f4);
                    }
                  }
                  else {
                    sscanf(pcVar1 + 0xd,"%d",0x2d4504);
                  }
                }
                else {
                  sscanf(pcVar1 + 7,"%d",0x2d44f0);
                }
              }
              else {
                sscanf(pcVar1 + 5,"%d",0x2d4454);
                Conf.force_freq = 0;
              }
            }
            else {
              sscanf(pcVar1 + 0xb,"%d",0x2d4450);
            }
          }
          else {
            sscanf(pcVar1 + 0xb,"%d",0x2d444c);
          }
        }
        else {
          sscanf(pcVar1 + 0xb,"%d",0x2d4448);
        }
      }
      else {
        sscanf(pcVar1 + 10,"%d",0x2d4444);
      }
    }
    cVar2 = pcVar1[8];
    iVar3 = 0;
    do {
      cgpu.workdataPathPrefix[iVar3] = cVar2;
      iVar4 = iVar3 + 1;
      cVar2 = pcVar1[iVar3 + 9];
      if (cVar2 == '\n' || cVar2 == '\r') goto LAB_000158f8;
      iVar3 = iVar4;
    } while (iVar4 != 0x40);
    iVar4 = 0x41;
LAB_000158f8:
    cgpu.workdataPathPrefix[iVar4] = '\0';
    printf("workdataPathPrefix:%s\n",0x62d24);
  } while( true );
}

