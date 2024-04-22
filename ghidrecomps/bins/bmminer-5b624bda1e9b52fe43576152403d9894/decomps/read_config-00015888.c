
/* WARNING: Removing unreachable block (ram,0x00015f30) */
/* WARNING: Removing unreachable block (ram,0x00015d88) */
/* WARNING: Unknown calling convention */

int read_config(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  FILE *__stream;
  char *pcVar4;
  char *temp;
  char cVar5;
  int iVar6;
  int iVar7;
  FILE *file;
  int offset;
  int starttemp;
  char str [1024];
  
  iVar1 = DAT_00015ae4;
  memset(str,0,0x400);
  __stream = fopen(DAT_00015ae8,DAT_00015aec);
  do {
    while( true ) {
      do {
        pcVar4 = fgets(str,0x3ff,__stream);
        if (pcVar4 == (char *)0x0) {
          *(undefined4 *)(iVar1 + 0xf10) = 0x12;
          *(undefined4 *)(iVar1 + 0xf24) = 0x56b;
          *(undefined4 *)(iVar1 + 0xf0c) = 0x72;
          return 0;
        }
      } while ((str[0] == '#') || (str[1] == '#'));
      pcVar4 = strstr(str,DAT_00015af0);
      iVar2 = DAT_00015af4;
      if (pcVar4 != (char *)0x0) break;
      pcVar4 = strstr(str,DAT_00015b00);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = strstr(str,DAT_00015b0c);
        if (pcVar4 == (char *)0x0) {
          pcVar4 = strstr(str,DAT_00015b14);
          if (pcVar4 == (char *)0x0) {
            pcVar4 = strstr(str,DAT_00015b1c);
            if (pcVar4 == (char *)0x0) {
              pcVar4 = strstr(str,DAT_00015b24);
              if (pcVar4 == (char *)0x0) {
                pcVar4 = strstr(str,DAT_00015b2c);
                if (pcVar4 == (char *)0x0) {
                  pcVar4 = strstr(str,DAT_00015b34);
                  if (pcVar4 == (char *)0x0) {
                    pcVar4 = strstr(str,DAT_00015b3c);
                    if (pcVar4 == (char *)0x0) {
                      pcVar4 = strstr(str,DAT_00015b44);
                      if (pcVar4 == (char *)0x0) {
                        pcVar4 = strstr(str,DAT_00015b4c);
                        if (pcVar4 == (char *)0x0) {
                          pcVar4 = strstr(str,DAT_00015b54);
                          if (pcVar4 == (char *)0x0) {
                            pcVar4 = strstr(str,DAT_00015b58);
                            if (pcVar4 == (char *)0x0) {
                              pcVar4 = strstr(str,DAT_00015b60);
                              if (pcVar4 == (char *)0x0) {
                                pcVar4 = strstr(str,DAT_00015b68);
                                if (pcVar4 == (char *)0x0) {
                                  pcVar4 = strstr(str,DAT_00015b70);
                                  if (pcVar4 == (char *)0x0) {
                                    pcVar4 = strstr(str,DAT_00015b78);
                                    if (pcVar4 == (char *)0x0) {
                                      pcVar4 = strstr(str,DAT_00015b80);
                                      if (pcVar4 == (char *)0x0) {
                                        pcVar4 = strstr(str,DAT_00015b88);
                                        if (pcVar4 == (char *)0x0) {
                                          pcVar4 = strstr(str,DAT_00015b90);
                                          if (pcVar4 == (char *)0x0) {
                                            pcVar4 = strstr(str,DAT_00015b98);
                                            if (pcVar4 == (char *)0x0) {
                                              pcVar4 = strstr(str,DAT_00015de0);
                                              if (pcVar4 == (char *)0x0) {
                                                pcVar4 = strstr(str,DAT_00015dec);
                                                if (pcVar4 == (char *)0x0) {
                                                  pcVar4 = strstr(str,DAT_00015df4);
                                                  if (pcVar4 == (char *)0x0) {
                                                    pcVar4 = strstr(str,DAT_00015dfc);
                                                    if (pcVar4 == (char *)0x0) {
                                                      pcVar4 = strstr(str,DAT_00015e08);
                                                      if (pcVar4 == (char *)0x0) {
                                                        pcVar4 = strstr(str,DAT_00015e10);
                                                        if (pcVar4 == (char *)0x0) {
                                                          pcVar4 = strstr(str,DAT_00015e18);
                                                          if (pcVar4 == (char *)0x0) {
                                                            pcVar4 = strstr(str,DAT_00015e20);
                                                            if (pcVar4 == (char *)0x0) {
                                                              pcVar4 = strstr(str,DAT_00015e28);
                                                              if (pcVar4 == (char *)0x0) {
                                                                pcVar4 = strstr(str,DAT_00015e30);
                                                                if (pcVar4 == (char *)0x0) {
                                                                  pcVar4 = strstr(str,DAT_00015e38);
                                                                  if (pcVar4 == (char *)0x0) {
                                                                    pcVar4 = strstr(str,DAT_00015e40
                                                                                   );
                                                                    if (pcVar4 == (char *)0x0) {
                                                                      pcVar4 = strstr(str,
                                                  DAT_00015e48);
                                                  if (pcVar4 == (char *)0x0) {
                                                    pcVar4 = strstr(str,DAT_00015e50);
                                                    if (pcVar4 == (char *)0x0) {
                                                      pcVar4 = strstr(str,DAT_00015e58);
                                                      if (pcVar4 == (char *)0x0) {
                                                        pcVar4 = strstr(str,DAT_00015e60);
                                                        if (pcVar4 == (char *)0x0) {
                                                          pcVar4 = strstr(str,DAT_00015e68);
                                                          if (pcVar4 == (char *)0x0) {
                                                            pcVar4 = strstr(str,DAT_00015e70);
                                                            if (pcVar4 == (char *)0x0) {
                                                              pcVar4 = strstr(str,DAT_00015e78);
                                                              if (pcVar4 == (char *)0x0) {
                                                                pcVar4 = strstr(str,DAT_00015e80);
                                                                if (pcVar4 == (char *)0x0) {
                                                                  pcVar4 = strstr(str,DAT_00015e88);
                                                                  if (pcVar4 == (char *)0x0) {
                                                                    pcVar4 = strstr(str,DAT_00015e90
                                                                                   );
                                                                    if (pcVar4 == (char *)0x0) {
                                                                      pcVar4 = strstr(str,
                                                  DAT_00015e94);
                                                  if (pcVar4 == (char *)0x0) {
                                                    pcVar4 = strstr(str,DAT_00015e9c);
                                                    if (pcVar4 == (char *)0x0) {
                                                      pcVar4 = strstr(str,DAT_00015ea4);
                                                      if (pcVar4 == (char *)0x0) {
                                                        pcVar4 = strstr(str,DAT_00015f40);
                                                        if (pcVar4 == (char *)0x0) {
                                                          pcVar4 = strstr(str,DAT_00015f4c);
                                                          if (pcVar4 == (char *)0x0) {
                                                            pcVar4 = strstr(str,DAT_00015f54);
                                                            if (pcVar4 == (char *)0x0) {
                                                              pcVar4 = strstr(str,DAT_00015f5c);
                                                              if (pcVar4 == (char *)0x0) {
                                                                pcVar4 = strstr(str,DAT_00015f64);
                                                                if (pcVar4 != (char *)0x0) {
                                                                  sscanf(pcVar4 + 10,DAT_00015f44,
                                                                         DAT_00015f68);
                                                                  sscanf(pcVar4 + 10,DAT_00015f44);
                                                                  *(undefined4 *)(iVar1 + 0xfac) = 0
                                                                  ;
                                                                }
                                                              }
                                                              else {
                                                                sscanf(pcVar4 + 0xc,DAT_00015f44,
                                                                       DAT_00015f60);
                                                              }
                                                            }
                                                            else {
                                                              sscanf(pcVar4 + 7,DAT_00015f44,
                                                                     DAT_00015f58);
                                                            }
                                                          }
                                                          else {
                                                            sscanf(pcVar4 + 7,DAT_00015f44,
                                                                   DAT_00015f50);
                                                          }
                                                        }
                                                        else {
                                                          sscanf(pcVar4 + 5,DAT_00015f44,
                                                                 DAT_00015f48);
                                                        }
                                                      }
                                                      else {
                                                        sscanf(pcVar4 + 5,DAT_00015de4,DAT_00015ea8)
                                                        ;
                                                      }
                                                    }
                                                    else {
                                                      sscanf(pcVar4 + 6,DAT_00015de4,DAT_00015ea0);
                                                    }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 5,DAT_00015de4,DAT_00015e98);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0x12,DAT_00015de4);
                                                    *(undefined *)(iVar1 + 0xf8c) = 0;
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xc,DAT_00015e00,DAT_00015e8c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xc,DAT_00015e00,DAT_00015e84);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xc,DAT_00015e00,DAT_00015e7c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xc,DAT_00015e00,DAT_00015e74);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 8,DAT_00015e00,DAT_00015e6c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xc,DAT_00015e00,DAT_00015e64);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 4,DAT_00015e00,DAT_00015e5c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e54);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e4c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e44);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e3c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 7,DAT_00015de4,DAT_00015e34);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 10,DAT_00015de4,DAT_00015e2c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xc,DAT_00015de4,DAT_00015e24);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 9,DAT_00015e00,DAT_00015e1c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e14);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e0c);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 0xf,DAT_00015e00,DAT_00015e04);
                                                  }
                                                  }
                                                  else {
                                                    sscanf(pcVar4 + 9,DAT_00015de4,DAT_00015df8);
                                                  }
                                                }
                                                else {
                                                  sscanf(pcVar4 + 9,DAT_00015de4,DAT_00015df0);
                                                }
                                              }
                                              else {
                                                sscanf(pcVar4 + 9,DAT_00015de4,DAT_00015de8);
                                              }
                                            }
                                            else {
                                              sscanf(pcVar4 + 0xc,DAT_00015b04,DAT_00015b9c);
                                            }
                                          }
                                          else {
                                            sscanf(pcVar4 + 0xc,DAT_00015b04,DAT_00015b94);
                                          }
                                        }
                                        else {
                                          sscanf(pcVar4 + 0xc,DAT_00015b04,DAT_00015b8c);
                                        }
                                      }
                                      else {
                                        sscanf(pcVar4 + 0xc,DAT_00015b04,DAT_00015b84);
                                      }
                                    }
                                    else {
                                      sscanf(pcVar4 + 0xc,DAT_00015b04,DAT_00015b7c);
                                    }
                                  }
                                  else {
                                    sscanf(pcVar4 + 0xb,DAT_00015b04,DAT_00015b74);
                                  }
                                }
                                else {
                                  sscanf(pcVar4 + 9,DAT_00015b04,DAT_00015b6c);
                                }
                              }
                              else {
                                sscanf(pcVar4 + 0xb,DAT_00015b04,DAT_00015b64);
                              }
                            }
                            else {
                              sscanf(pcVar4 + 8,DAT_00015b04,DAT_00015b5c);
                            }
                          }
                        }
                        else {
                          sscanf(pcVar4 + 7,DAT_00015b04,DAT_00015b50);
                        }
                      }
                      else {
                        sscanf(pcVar4 + 7,DAT_00015b04,DAT_00015b48);
                      }
                    }
                    else {
                      sscanf(pcVar4 + 7,DAT_00015b04,DAT_00015b40);
                    }
                  }
                  else {
                    sscanf(pcVar4 + 0xd,DAT_00015b04,DAT_00015b38);
                  }
                }
                else {
                  sscanf(pcVar4 + 7,DAT_00015b04,DAT_00015b30);
                }
              }
              else {
                sscanf(pcVar4 + 5,DAT_00015b04,DAT_00015b28);
                *(undefined4 *)(iVar1 + 4000) = 0;
              }
            }
            else {
              sscanf(pcVar4 + 0xb,DAT_00015b04,DAT_00015b20);
            }
          }
          else {
            sscanf(pcVar4 + 0xb,DAT_00015b04,DAT_00015b18);
          }
        }
        else {
          sscanf(pcVar4 + 0xb,DAT_00015b04,DAT_00015b10);
        }
      }
      else {
        sscanf(pcVar4 + 10,DAT_00015b04,DAT_00015b08);
      }
    }
    cVar5 = pcVar4[8];
    iVar6 = 0;
    do {
      *(char *)(iVar2 + iVar6 + 0x25c) = cVar5;
      __format = DAT_00015afc;
      uVar3 = DAT_00015af8;
      iVar7 = iVar6 + 1;
      cVar5 = pcVar4[iVar6 + 9];
      if (cVar5 == '\n' || cVar5 == '\r') goto LAB_000158f8;
      iVar6 = iVar7;
    } while (iVar7 != 0x40);
    iVar7 = 0x41;
LAB_000158f8:
    *(undefined *)(iVar2 + iVar7 + 0x25c) = 0;
    printf(__format,uVar3);
  } while( true );
}

