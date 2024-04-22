
/* WARNING: Removing unreachable block (ram,0x0002a91c) */
/* WARNING: Removing unreachable block (ram,0x0002a7de) */

void read_config(void)

{
  FILE *__stream;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  char local_420;
  char local_41f;
  
  memset(&local_420,0,0x400);
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
      iVar3 = 0;
      pcVar1 = pcVar1 + 8;
      cVar4 = *pcVar1;
      pcVar2 = DAT_0002a428;
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
                                                                    sscanf(pcVar1 + 10,"%d",
                                                                           DAT_0002a948);
                                                                    sscanf(pcVar1 + 10,"%d");
                                                                    Conf._208_4_ = 0;
                                                                  }
                                                                }
                                                                else {
                                                                  sscanf(pcVar1 + 0xc,"%d",
                                                                         DAT_0002a944);
                                                                }
                                                              }
                                                              else {
                                                                sscanf(pcVar1 + 7,"%d",DAT_0002a940)
                                                                ;
                                                              }
                                                            }
                                                            else {
                                                              sscanf(pcVar1 + 7,"%d",DAT_0002a93c);
                                                            }
                                                          }
                                                          else {
                                                            sscanf(pcVar1 + 5,"%d",DAT_0002a938);
                                                          }
                                                        }
                                                        else {
                                                          sscanf(pcVar1 + 5,"%d",DAT_0002a934);
                                                        }
                                                      }
                                                      else {
                                                        sscanf(pcVar1 + 6,"%d",DAT_0002a930);
                                                      }
                                                    }
                                                    else {
                                                      sscanf(pcVar1 + 5,"%d",DAT_0002a92c);
                                                    }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0x12,"%d");
                                                    Conf[176] = 0;
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",DAT_0002a7b4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",DAT_0002a7b0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",DAT_0002a7ac);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",DAT_0002a7a8);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 8,"%ud",DAT_0002a7a4);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%ud",DAT_0002a7a0);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 4,"%ud",DAT_0002a79c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a798);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a794);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a790);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a78c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 7,"%d",DAT_0002a788);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 10,"%d",DAT_0002a784);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xc,"%d",DAT_0002a780);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 9,"%ud",DAT_0002a77c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a778);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a774);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar1 + 0xf,"%ud",DAT_0002a770);
                                                  }
                                                }
                                                else {
                                                  sscanf(pcVar1 + 9,"%d",DAT_0002a76c);
                                                }
                                              }
                                              else {
                                                sscanf(pcVar1 + 9,"%d",DAT_0002a768);
                                              }
                                            }
                                            else {
                                              sscanf(pcVar1 + 9,"%d",DAT_0002a764);
                                            }
                                          }
                                          else {
                                            sscanf(pcVar1 + 0xc,"%d",DAT_0002a760);
                                          }
                                        }
                                        else {
                                          sscanf(pcVar1 + 0xc,"%d",DAT_0002a470);
                                        }
                                      }
                                      else {
                                        sscanf(pcVar1 + 0xc,"%d",DAT_0002a46c);
                                      }
                                    }
                                    else {
                                      sscanf(pcVar1 + 0xc,"%d",DAT_0002a468);
                                    }
                                  }
                                  else {
                                    sscanf(pcVar1 + 0xc,"%d",DAT_0002a464);
                                  }
                                }
                                else {
                                  sscanf(pcVar1 + 0xb,"%d",DAT_0002a460);
                                }
                              }
                              else {
                                sscanf(pcVar1 + 9,"%d",DAT_0002a45c);
                              }
                            }
                            else {
                              sscanf(pcVar1 + 0xb,"%d",DAT_0002a458);
                            }
                          }
                          else {
                            sscanf(pcVar1 + 8,"%d",DAT_0002a454);
                          }
                        }
                      }
                      else {
                        sscanf(pcVar1 + 7,"%d",DAT_0002a450);
                      }
                    }
                    else {
                      sscanf(pcVar1 + 7,"%d",DAT_0002a44c);
                    }
                  }
                  else {
                    sscanf(pcVar1 + 7,"%d",DAT_0002a448);
                  }
                }
                else {
                  sscanf(pcVar1 + 0xd,"%d",DAT_0002a444);
                }
              }
              else {
                sscanf(pcVar1 + 7,"%d",DAT_0002a440);
              }
            }
            else {
              sscanf(pcVar1 + 5,"%d",DAT_0002a43c);
              Conf._196_4_ = 0;
            }
          }
          else {
            sscanf(pcVar1 + 0xb,"%d",DAT_0002a438);
          }
        }
        else {
          sscanf(pcVar1 + 0xb,"%d",DAT_0002a434);
        }
      }
      else {
        sscanf(pcVar1 + 0xb,"%d",DAT_0002a430);
      }
    }
    else {
      sscanf(pcVar1 + 10,"%d",DAT_0002a42c);
    }
  } while( true );
}

