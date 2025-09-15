
void read_config(void)

{
  FILE *__stream;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  int local_428;
  int local_424;
  char local_420;
  char local_41f;
  
  memset(&local_420,0,0x400);
  local_428 = 0;
  local_424 = 0;
  __stream = fopen("/etc/config/Config.ini","r");
LAB_0002a11c:
  do {
    pcVar1 = fgets(&local_420,0x3ff,__stream);
    while( true ) {
      if (pcVar1 == (char *)0x0) {
        Conf._52_4_ = 0x54;
        Conf._72_4_ = 0x56b;
        Conf._48_4_ = 0x72;
        return;
      }
      if ((local_420 == '#') || (local_41f == '#')) goto LAB_0002a11c;
      pcVar1 = strstr(&local_420,"TestDir=");
      if (pcVar1 == (char *)0x0) break;
      pcVar2 = (char *)0x82e6b;
      iVar3 = 0;
      pcVar1 = pcVar1 + 8;
      cVar4 = *pcVar1;
      do {
        pcVar2 = pcVar2 + 1;
        *pcVar2 = cVar4;
        iVar3 = iVar3 + 1;
        pcVar1 = pcVar1 + 1;
        cVar4 = *pcVar1;
        if (cVar4 == '\r' || cVar4 == '\n') goto LAB_0002a164;
      } while (iVar3 != 0x40);
      iVar3 = 0x41;
LAB_0002a164:
      (&DAT_00082e6c)[iVar3] = 0;
      printf("workdataPathPrefix:%s\n",&DAT_00082e6c);
      pcVar1 = fgets(&local_420,0x3ff,__stream);
    }
    pcVar1 = strstr(&local_420,"DataCount=");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strstr(&local_420,"PassCount1=");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = strstr(&local_420,"PassCount2=");
        if (pcVar1 == (char *)0x0) {
          pcVar1 = strstr(&local_420,"PassCount3=");
          if (pcVar1 == (char *)0x0) {
            pcVar1 = strstr(&local_420,"Freq=");
            if (pcVar1 == (char *)0x0) {
              pcVar1 = strstr(&local_420,"freq_e=");
              if (pcVar1 == (char *)0x0) {
                pcVar1 = strstr(&local_420,"UseConfigVol=");
                if (pcVar1 == (char *)0x0) {
                  pcVar1 = strstr(&local_420,"freq_m=");
                  if (pcVar1 == (char *)0x0) {
                    pcVar1 = strstr(&local_420,"freq_a=");
                    if (pcVar1 == (char *)0x0) {
                      pcVar1 = strstr(&local_420,"freq_t=");
                      if (pcVar1 == (char *)0x0) {
                        pcVar1 = strstr(&local_420,"force_freq=");
                        if (pcVar1 == (char *)0x0) {
                          pcVar1 = strstr(&local_420,"Timeout=");
                          if (pcVar1 == (char *)0x0) {
                            pcVar1 = strstr(&local_420,"UseFreqPIC=");
                            if (pcVar1 == (char *)0x0) {
                              pcVar1 = strstr(&local_420,"TestMode=");
                              if (pcVar1 == (char *)0x0) {
                                pcVar1 = strstr(&local_420,"CheckChain=");
                                if (pcVar1 == (char *)0x0) {
                                  pcVar1 = strstr(&local_420,"CommandMode=");
                                  if (pcVar1 == (char *)0x0) {
                                    pcVar1 = strstr(&local_420,"ValidNonce1=");
                                    if (pcVar1 == (char *)0x0) {
                                      pcVar1 = strstr(&local_420,"ValidNonce2=");
                                      if (pcVar1 == (char *)0x0) {
                                        pcVar1 = strstr(&local_420,"ValidNonce3=");
                                        if (pcVar1 == (char *)0x0) {
                                          pcVar1 = strstr(&local_420,"Pic_VOLTAGE=");
                                          if (pcVar1 == (char *)0x0) {
                                            pcVar1 = strstr(&local_420,"Voltage1=");
                                            if (pcVar1 == (char *)0x0) {
                                              pcVar1 = strstr(&local_420,"Voltage2=");
                                              if (pcVar1 == (char *)0x0) {
                                                pcVar1 = strstr(&local_420,"Voltage3=");
                                                if (pcVar1 == (char *)0x0) {
                                                  pcVar1 = strstr(&local_420,"final_voltage1=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(&local_420,"final_voltage2=");
                                                    if (pcVar1 == (char *)0x0) {
                                                      pcVar1 = strstr(&local_420,"final_voltage3=");
                                                      if (pcVar1 == (char *)0x0) {
                                                        pcVar1 = strstr(&local_420,"freq_gap=");
                                                        if (pcVar1 == (char *)0x0) {
                                                          pcVar1 = strstr(&local_420,"OpenCoreGap=")
                                                          ;
                                                          if (pcVar1 == (char *)0x0) {
                                                            pcVar1 = strstr(&local_420,"CheckTemp=")
                                                            ;
                                                            if (pcVar1 == (char *)0x0) {
                                                              pcVar1 = strstr(&local_420,"IICPic=");
                                                              if (pcVar1 == (char *)0x0) {
                                                                pcVar1 = strstr(&local_420,
                                                                                "Open_Core_Num1=");
                                                                if (pcVar1 == (char *)0x0) {
                                                                  pcVar1 = strstr(&local_420,
                                                                                  "Open_Core_Num2=")
                                                                  ;
                                                                  if (pcVar1 == (char *)0x0) {
                                                                    pcVar1 = strstr(&local_420,
                                                                                                                                                                        
                                                  "Open_Core_Num3=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(&local_420,"Open_Core_Num4=");
                                                    if (pcVar1 == (char *)0x0) {
                                                      pcVar1 = strstr(&local_420,"DAC=");
                                                      if (pcVar1 == (char *)0x0) {
                                                        pcVar1 = strstr(&local_420,"GetTempFrom=");
                                                        if (pcVar1 == (char *)0x0) {
                                                          pcVar1 = strstr(&local_420,"TempSel=");
                                                          if (pcVar1 == (char *)0x0) {
                                                            pcVar1 = strstr(&local_420,
                                                                            "TempSensor1=");
                                                            if (pcVar1 == (char *)0x0) {
                                                              pcVar1 = strstr(&local_420,
                                                                              "TempSensor2=");
                                                              if (pcVar1 == (char *)0x0) {
                                                                pcVar1 = strstr(&local_420,
                                                                                "TempSensor3=");
                                                                if (pcVar1 == (char *)0x0) {
                                                                  pcVar1 = strstr(&local_420,
                                                                                  "TempSensor4=");
                                                                  if (pcVar1 == (char *)0x0) {
                                                                    pcVar1 = strstr(&local_420,
                                                                                                                                                                        
                                                  "DefaultTempOffset=");
                                                  if (pcVar1 == (char *)0x0) {
                                                    pcVar1 = strstr(&local_420,"year=");
                                                    if (pcVar1 == (char *)0x0) {
                                                      pcVar1 = strstr(&local_420,"month=");
                                                      if (pcVar1 == (char *)0x0) {
                                                        pcVar1 = strstr(&local_420,"date=");
                                                        if (pcVar1 == (char *)0x0) {
                                                          pcVar1 = strstr(&local_420,"hour=");
                                                          if (pcVar1 == (char *)0x0) {
                                                            pcVar1 = strstr(&local_420,"minute=");
                                                            if (pcVar1 == (char *)0x0) {
                                                              pcVar1 = strstr(&local_420,"second=");
                                                              if (pcVar1 == (char *)0x0) {
                                                                pcVar1 = strstr(&local_420,
                                                                                "StartSensor=");
                                                                if (pcVar1 == (char *)0x0) {
                                                                  pcVar1 = strstr(&local_420,
                                                                                  "StartTemp=");
                                                                  if (pcVar1 != (char *)0x0) {
                                                                    sscanf(pcVar1 + 10,"%d",0x2f4654
                                                                          );
                                                                    sscanf(pcVar1 + 10,"%d",
                                                                           &local_424);
                                                                    Conf._208_4_ = local_424;
                                                                    if (local_424 < 0) {
                                                                      local_424 = -local_424;
                                                                      Conf._208_4_ = -(int)(char)
                                                  local_424;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%d",0x2f4650);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",0x2f466c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",0x2f4668);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 5,"%d",0x2f4664);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 5,"%d",0x2f4660);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 6,"%d",0x2f465c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 5,"%d",0x2f4658);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0x12,"%d",&local_428);
                                                    iVar3 = local_428;
                                                    if (local_428 < 0) {
                                                      local_428 = -local_428;
                                                    }
                                                    Conf[0xb0] = (undefined1)iVar3;
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2f4630);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2f462c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2f4628);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2f4624);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 8,"%ud",0x2f4620);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",0x2f461c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 4,"%ud",0x2f4618);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f4614);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f4610);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f460c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f4608);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",0x2f4604);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 10,"%d",0x2f4600);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%d",0x2f45fc);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 9,"%ud",0x2f45f8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f45f4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f45f0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",0x2f45ec);
                                                  }
                                                }
                                                else {
                                                  sscanf(pcVar1 + 9,"%d",0x2f45e8);
                                                }
                                              }
                                              else {
                                                sscanf(pcVar1 + 9,"%d",0x2f45e4);
                                              }
                                            }
                                            else {
                                              sscanf(pcVar1 + 9,"%d",0x2f45e0);
                                            }
                                          }
                                          else {
                                            sscanf(pcVar1 + 0xc,"%d",0x2f45dc);
                                          }
                                        }
                                        else {
                                          sscanf(pcVar1 + 0xc,"%d",0x2f45d8);
                                        }
                                      }
                                      else {
                                        sscanf(pcVar1 + 0xc,"%d",0x2f45d4);
                                      }
                                    }
                                    else {
                                      sscanf(pcVar1 + 0xc,"%d",0x2f45d0);
                                    }
                                  }
                                  else {
                                    sscanf(pcVar1 + 0xc,"%d",0x2f45c8);
                                  }
                                }
                                else {
                                  sscanf(pcVar1 + 0xb,"%d",0x2f45c4);
                                }
                              }
                              else {
                                sscanf(pcVar1 + 9,"%d",0x2f45c0);
                              }
                            }
                            else {
                              sscanf(pcVar1 + 0xb,"%d",0x2f45bc);
                            }
                          }
                          else {
                            sscanf(pcVar1 + 8,"%d",0x2f45a0);
                          }
                        }
                      }
                      else {
                        sscanf(pcVar1 + 7,"%d",0x2f4644);
                      }
                    }
                    else {
                      sscanf(pcVar1 + 7,"%d",0x2f4640);
                    }
                  }
                  else {
                    sscanf(pcVar1 + 7,"%d",0x2f463c);
                  }
                }
                else {
                  sscanf(pcVar1 + 0xd,"%d",0x2f464c);
                }
              }
              else {
                sscanf(pcVar1 + 7,"%d",0x2f4638);
              }
            }
            else {
              sscanf(pcVar1 + 5,"%d",0x2f459c);
              Conf._196_4_ = 0;
            }
          }
          else {
            sscanf(pcVar1 + 0xb,"%d",0x2f4598);
          }
        }
        else {
          sscanf(pcVar1 + 0xb,"%d",0x2f4594);
        }
      }
      else {
        sscanf(pcVar1 + 0xb,"%d",0x2f4590);
      }
    }
    else {
      sscanf(pcVar1 + 10,"%d",0x2f458c);
    }
  } while( true );
}

