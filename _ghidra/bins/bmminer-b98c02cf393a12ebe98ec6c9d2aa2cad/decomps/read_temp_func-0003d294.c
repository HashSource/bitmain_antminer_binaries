
void read_temp_func(void)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  FILE *pFVar11;
  undefined4 uVar12;
  short sVar13;
  int iVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  int iVar18;
  byte bVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  char *pcVar24;
  int iVar25;
  short sVar26;
  byte bVar27;
  short sVar28;
  short sVar29;
  int iVar30;
  int local_468;
  int local_460;
  int local_45c;
  int local_440;
  short local_430;
  short sStack_42e;
  char local_428 [20];
  uint local_414;
  undefined4 local_410;
  uint local_40c;
  char local_408 [4];
  undefined4 uStack_404;
  char acStack_400 [4];
  undefined2 local_3fc;
  undefined1 uStack_3fa;
  
  bVar5 = false;
  local_440 = 0;
  bVar3 = false;
  clearTempLogFile();
  do {
    while (bVar19 = enable_read_temp, enable_read_temp == 0) {
      sleep(1);
    }
    clearTempLogFile();
    builtin_strncpy(local_428,"do read_temp_func on",0x14);
    local_414._0_1_ = 'c';
    local_414._1_1_ = 'e';
    local_414._2_1_ = '.';
    local_414._3_1_ = '.';
    local_410._0_3_ = 0xa2e;
    writeLogFile(local_428);
    pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
    if (doTestPatten == '\0') {
      iVar21 = check_asic_reg(8);
      if (iVar21 == 0) {
        builtin_strncpy(local_428,"Error: check_asic_re",0x14);
        local_414._0_1_ = 'g';
        local_414._1_1_ = ' ';
        local_414._2_1_ = '0';
        local_414._3_1_ = 'x';
        local_410._0_1_ = '0';
        local_410._1_1_ = '8';
        local_410._2_1_ = ' ';
        local_410._3_1_ = 't';
        local_40c._0_1_ = 'i';
        local_40c._1_1_ = 'm';
        local_40c._2_1_ = 'e';
        local_40c._3_1_ = 'o';
        builtin_strncpy(local_408,"ut\n",4);
        writeInitLogFile(local_428);
      }
      else {
        showAllBadRTInfo();
      }
    }
    else {
      usleep(100000);
    }
    local_468 = -100;
    local_45c = -100;
    local_460 = -100;
    builtin_strncpy(local_428,"Done check_asic_reg\n",0x14);
    local_414 = local_414 & 0xffffff00;
    writeLogFile(local_428);
    bVar6 = false;
    local_430 = 0;
    sStack_42e = 0;
    sVar4 = 0;
    iVar21 = dev;
    iVar25 = 0;
    do {
      while (*(int *)(iVar21 + (iVar25 + 2) * 4) == 1) {
        if (log_level < 6) {
          if ('\0' < *(char *)(iVar21 + iVar25 + 0x458)) goto LAB_0003d3c8;
LAB_0003da26:
          sVar13 = 1000;
          sVar29 = 1000;
          iVar18 = -100;
          iVar23 = iVar25 << 3;
          iVar14 = iVar18;
          iVar10 = iVar18;
          sVar17 = sVar29;
          bVar27 = bVar19;
        }
        else {
          pFVar11 = fopen(log_file,"a+");
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: do read temp on Chain[%d]\n","driver-btm-c5.c",0x211d,
                    "read_temp_func",iVar25);
          }
          fclose(pFVar11);
          iVar21 = dev;
          if (*(char *)(dev + iVar25 + 0x458) < '\x01') goto LAB_0003da26;
LAB_0003d3c8:
          sVar28 = -100;
          sVar29 = 1000;
          iVar23 = iVar25 * 8;
          sVar26 = -100;
          iVar21 = 0;
          sVar16 = -100;
          sVar17 = 1000;
          sVar13 = 1000;
          do {
            if (5 < log_level) {
              pFVar11 = fopen(log_file,"a+");
              if (pFVar11 != (FILE *)0x0) {
                iVar14 = dev + iVar23 + iVar21;
                fprintf(pFVar11,"%s:%d:%s: Chain[%d] Chip[%d] TempTypeID=%02x middle offset=%d\n",
                        "driver-btm-c5.c",0x212c,"read_temp_func",iVar25,
                        (*(byte *)(iVar14 + 0x4e8) >> 2) + 1,(uint)*(byte *)(iVar14 + 0x468),
                        (int)(char)middle_Offset[iVar23 + iVar21]);
              }
              fclose(pFVar11);
            }
            iVar10 = check_reg_temp(DEVICEADDR[iVar25],0,0,0,
                                    *(undefined1 *)(dev + iVar23 + iVar21 + 0x4e8),iVar25);
            iVar14 = dev;
            uVar9 = log_level;
            if (iVar10 == 0) {
              if (log_level < 6) {
                bVar6 = true;
              }
              else {
                pFVar11 = fopen(log_file,"a+");
                if (pFVar11 != (FILE *)0x0) {
                  fprintf(pFVar11,
                          "%s:%d:%s: read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n",
                          "driver-btm-c5.c",0x213e,"read_temp_func",iVar25,
                          (uint)*(byte *)(dev + iVar23 + iVar21 + 0x4e8),
                          (int)*(short *)(dev + (iVar23 + iVar21 + 0xad) * 8));
                }
                bVar6 = true;
                fclose(pFVar11);
              }
            }
            else {
              sVar15 = ((ushort)iVar10 & 0xff) - 0x40;
              iVar10 = iVar23 + iVar21 + 0xad;
              *(short *)(dev + iVar10 * 8) = sVar15;
              if (5 < uVar9) {
                pFVar11 = fopen(log_file,"a+");
                if (pFVar11 != (FILE *)0x0) {
                  fprintf(pFVar11,"%s:%d:%s: Chain[%d] Chip[%d] local Temp=%d\n","driver-btm-c5.c",
                          0x2133,"read_temp_func",iVar25,
                          (uint)*(byte *)(dev + iVar23 + iVar21 + 0x4e8),
                          (int)*(short *)(dev + iVar10 * 8));
                }
                fclose(pFVar11);
                sVar15 = *(short *)(dev + (iVar23 + iVar21 + 0xad) * 8);
                iVar14 = dev;
              }
              sprintf(local_428,"Chain[%d] Chip[%d] pcb temperature=%d\n",iVar25,
                      (uint)*(byte *)(iVar14 + iVar23 + iVar21 + 0x4e8),(int)sVar15);
              writeLogFile(local_428);
            }
            uVar9 = check_reg_temp(DEVICEADDR[iVar25],1,0,0,
                                   *(undefined1 *)(dev + iVar23 + iVar21 + 0x4e8),iVar25);
            iVar14 = dev;
            if (uVar9 == 0) {
              sprintf(local_428,"read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",
                      iVar25,(*(byte *)(dev + iVar23 + iVar21 + 0x4e8) >> 2) + 1,
                      (int)*(short *)(dev + (iVar23 + iVar21) * 8 + 0x56a));
              writeLogFile(local_428);
            }
            else {
              uVar8 = get_remote(uVar9 & 0xff);
              iVar10 = dev;
              iVar18 = (iVar23 + iVar21) * 8;
              iVar20 = dev + iVar23;
              *(undefined2 *)(iVar14 + iVar18 + 0x56a) = uVar8;
              sprintf(local_428,"Chain[%d] Chip[%d] junction temperature=%d\n",iVar25,
                      (*(byte *)(iVar20 + iVar21 + 0x4e8) >> 2) + 1,
                      (int)*(short *)(iVar18 + iVar10 + 0x56a));
              writeLogFile(local_428);
            }
            if ((is218_Temp == '\0') && (chip_hasNoMiddle == '\0')) {
              sVar15 = *(short *)(dev + (iVar23 + iVar21 + 0xad) * 8);
              sVar1 = *(short *)(dev + (iVar23 + iVar21) * 8 + 0x56a);
              if (sVar1 < sVar15) goto LAB_0003d4dc;
            }
            else {
              sVar15 = *(short *)(dev + (iVar23 + iVar21 + 0xad) * 8);
LAB_0003d4dc:
              iVar10 = (iVar23 + iVar21) * 8;
              iVar14 = dev + iVar23;
              *(short *)(dev + iVar10 + 0x56a) = sVar15 + 0xf;
              sprintf(local_428,"Special fix Chain[%d] Chip[%d] middle Temp = %d\n",iVar25,
                      (*(byte *)(iVar14 + iVar21 + 0x4e8) >> 2) + 1,(int)(short)(sVar15 + 0xf));
              writeLogFile(local_428);
              sVar15 = *(short *)(dev + (iVar23 + iVar21 + 0xad) * 8);
              sVar1 = *(short *)(iVar10 + dev + 0x56a);
            }
            if (sVar28 < sVar15) {
              sVar28 = sVar15;
            }
            iVar14 = iVar23 + iVar21;
            iVar21 = iVar21 + 1;
            sVar2 = *(short *)(dev + iVar14 * 8 + 0x56c);
            if (sVar26 < sVar1) {
              sVar26 = sVar1;
            }
            if (sVar15 <= sVar29) {
              sVar29 = sVar15;
            }
            if (sVar1 <= sVar17) {
              sVar17 = sVar1;
            }
            if (sVar16 < sVar2) {
              sVar16 = sVar2;
            }
            if (sVar2 <= sVar13) {
              sVar13 = sVar2;
            }
          } while (iVar21 < *(char *)(dev + iVar25 + 0x458));
          iVar18 = (int)sVar16;
          iVar21 = dev;
          iVar14 = (int)sVar26;
          iVar10 = (int)sVar28;
          if (sVar13 < 1) {
            bVar27 = 0;
          }
          else {
            bVar27 = 1;
          }
        }
        cVar7 = check_temp_offside;
        iVar20 = iVar21 + iVar23;
        *(short *)(iVar20 + 0x9e8) = sVar29;
        iVar30 = (int)(short)iVar14;
        *(short *)(iVar20 + 0x968) = (short)iVar10;
        *(short *)(iVar20 + 0x96a) = (short)iVar14;
        *(short *)(iVar20 + 0x96c) = (short)iVar18;
        *(short *)(iVar20 + 0x9ea) = sVar17;
        *(short *)(iVar20 + 0x9ec) = sVar13;
        if (cVar7 != '\0') {
          iVar30 = (int)*(short *)(iVar20 + 0x96a);
          if ((iVar30 - 0x4bU & 0xffff) < 0x33) {
            bVar3 = false;
          }
          else if (!bVar3) {
            bVar3 = true;
            *(int *)(temp_offside + iVar25 * 4) = *(int *)(temp_offside + iVar25 * 4) + 1;
          }
        }
        sVar17 = *(short *)(iVar20 + 0x9e8);
        if (local_45c < iVar30) {
          local_45c = iVar30;
        }
        if (local_460 < iVar18) {
          local_460 = iVar18;
        }
        if (local_468 < *(short *)(iVar20 + 0x968)) {
          local_468 = (int)*(short *)(iVar20 + 0x968);
        }
        if (sVar17 < local_430 && 0 < sVar17) {
          if (*(int *)(chain_temp_toolow + iVar25 * 4) == 0) {
LAB_0003d7c2:
            local_430 = sVar17;
          }
        }
        else if (local_430 == 0) goto LAB_0003d7c2;
        sVar17 = *(short *)(iVar23 + iVar21 + 0x9ea);
        if (sVar17 < sStack_42e && 0 < sVar17) {
          if (*(int *)(chain_temp_toolow + iVar25 * 4) == 0) {
LAB_0003d7ec:
            sStack_42e = sVar17;
          }
        }
        else if (sStack_42e == 0) goto LAB_0003d7ec;
        if (sVar13 < sVar4) {
          bVar27 = bVar27 & 1;
        }
        else {
          bVar27 = 0;
        }
        if (((bVar27 != 0) && (*(int *)(chain_temp_toolow + iVar25 * 4) == 0)) || (sVar4 == 0)) {
          sVar4 = sVar13;
        }
        iVar14 = iVar25 + 1;
        sprintf(local_428,"Done read temp on Chain[%d]\n",iVar25);
        writeLogFile(local_428);
        iVar21 = dev;
        iVar25 = iVar14;
        if (iVar14 == 0x10) goto LAB_0003d830;
      }
      iVar25 = iVar25 + 1;
    } while (iVar25 != 0x10);
LAB_0003d830:
    *(int *)(iVar21 + 0x5418) = (int)local_430;
    *(int *)(iVar21 + 0x541c) = (int)sStack_42e;
    *(int *)(iVar21 + 0x5408) = local_468;
    *(int *)(iVar21 + 0x5420) = (int)sVar4;
    last_testpatten_highest_pcb_temp = local_468;
    *(int *)(iVar21 + 0x540c) = local_45c;
    *(int *)(iVar21 + 0x5410) = local_460;
    if (bVar5) {
LAB_0003db4a:
      bVar5 = true;
    }
    else if (local_468 != 0) {
      saveTestPattenHighestTemp(local_468);
      bring_up_pcb_temp = last_testpatten_highest_pcb_temp;
      if (log_level < 4) goto LAB_0003db4a;
      pFVar11 = fopen(log_file,"a+");
      if (pFVar11 != (FILE *)0x0) {
        fprintf(pFVar11,"%s:%d:%s: bring_up_pcb_temp = %d\n","driver-btm-c5.c",0x222b,
                "read_temp_func",bring_up_pcb_temp);
      }
      bVar5 = true;
      fclose(pFVar11);
    }
    check_fan();
    sprintf(local_428,"Max pcb temp : %d\n",*(undefined4 *)(dev + 0x5408));
    writeLogFile(local_428);
    iVar21 = dev;
    if ((int)((uint)config_parameter[4] << 0x1e) < 0) {
      if (config_parameter[10] < 0x65) {
        sprintf(local_428,"Set fixed fan speed=%d\n");
        writeLogFile(local_428);
        set_PWM(config_parameter[10]);
      }
      else {
        if (!bVar6) goto LAB_0003dc1e;
        *(undefined1 *)(dev + 0x53fc) = 100;
        *(undefined4 *)(iVar21 + 4) = 0x320000;
        set_fan_control(0x320000);
        builtin_strncpy(local_428,"Set fixed full f",0x10);
        *(undefined1 *)(dev + 0x5442) = 100;
        builtin_strncpy(local_428 + 0x10,"an s",4);
        local_414._0_1_ = 'p';
        local_414._1_1_ = 'e';
        local_414._2_1_ = 'e';
        local_414._3_1_ = 'd';
        local_410._0_2_ = 10;
        writeLogFile(local_428);
      }
LAB_0003d8fe:
      if (startCheckNetworkJob == 0) goto LAB_0003d90a;
LAB_0003dbb4:
      cgtime(&tv_send);
      iVar21 = (int)tv_send - (int)tv_send_job;
      if (tv_send._4_4_ - tv_send_job._4_4_ < 0) {
        iVar21 = iVar21 + -1;
      }
      uVar9 = (uint)*(byte *)(dev + 0x53fe);
      if (iVar21 < 0x79) {
        bVar19 = uVar9 < 2;
        goto LAB_0003d910;
      }
      builtin_strncpy(local_428,"Fatal Error: network",0x14);
      local_414._0_1_ = ' ';
      local_414._1_1_ = 'c';
      local_414._2_1_ = 'o';
      local_414._3_1_ = 'n';
      local_410._0_1_ = 'n';
      local_410._1_1_ = 'e';
      local_410._2_1_ = 'c';
      local_410._3_1_ = 't';
      local_40c._0_1_ = 'i';
      local_40c._1_1_ = 'o';
      local_40c._2_1_ = 'n';
      local_40c._3_1_ = ' ';
      builtin_strncpy(local_408,"lost",4);
      uStack_404._0_3_ = 0xa21;
      writeInitLogFile(local_428);
      iVar21 = *(int *)(dev + 0x5408);
LAB_0003da82:
      local_440 = local_440 + 1;
      iVar25 = local_440;
      sprintf(local_428,"max pcb temperature:%d, fan num:%d, error counter:%d\n",iVar21,uVar9,
              local_440);
      writeInitLogFile(local_428);
      if (local_440 != 1) {
        FatalErrorValue = 1;
        global_stop = 1;
        if (*(int *)(dev + 0x5408) < 0x5b) {
          if (uVar9 < 2) {
            FatalErrorValue = 2;
            goto LAB_0003dc26;
          }
          FatalErrorValue = 3;
        }
        else {
LAB_0003dc26:
          builtin_strncpy(local_428,"Fatal error, turning",0x14);
          status_error = '\x01';
          local_414._0_1_ = ' ';
          local_414._1_1_ = 'o';
          local_414._2_1_ = 'f';
          local_414._3_1_ = 'f';
          local_410._0_1_ = ' ';
          local_410._1_1_ = 'h';
          local_410._2_1_ = 'a';
          local_410._3_1_ = 's';
          local_40c._0_1_ = 'h';
          local_40c._1_1_ = ' ';
          local_40c._2_1_ = 'b';
          local_40c._3_1_ = 'o';
          once_error = '\x01';
          uVar22 = 0;
          builtin_strncpy(local_408,"ards",4);
          uStack_404._0_1_ = ' ';
          uStack_404._1_1_ = 'p';
          uStack_404._2_1_ = 'o';
          uStack_404._3_1_ = 'w';
          builtin_strncpy(acStack_400,"er..",4);
          local_3fc = 0xa2e;
          uStack_3fa = 0;
          writeInitLogFile(local_428);
          sprintf(local_428,"max pcb temperature : %d, fan num : %d\n",*(undefined4 *)(dev + 0x5408)
                  ,uVar9,iVar25);
          writeInitLogFile(local_428);
          do {
            if (*(int *)(dev + (uVar22 + 2) * 4) == 1) {
              pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
              disable_pic_dac(uVar22 & 0xff);
              pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
            }
            uVar22 = uVar22 + 1;
          } while (uVar22 != 0x10);
        }
        if (3 < log_level) {
          pFVar11 = fopen(log_file,"a+");
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: Do not clear run bit\n","driver-btm-c5.c",0x2361,
                    "read_temp_func");
          }
          fclose(pFVar11);
        }
        goto LAB_0003dade;
      }
      global_stop = 0;
      if (once_error != '\0') goto LAB_0003dade;
      status_error = '\0';
    }
    else {
      if (!bVar6) {
LAB_0003dc1e:
        set_PWM_according_to_temperature();
        goto LAB_0003d8fe;
      }
      *(undefined1 *)(dev + 0x53fc) = 100;
      *(undefined4 *)(iVar21 + 4) = 0x320000;
      set_fan_control(0x320000);
      builtin_strncpy(local_428,"Read temp failed",0x10);
      *(undefined1 *)(dev + 0x5442) = 100;
      last_temperature = 0x4b;
      builtin_strncpy(local_428 + 0x10,", se",4);
      local_414._0_1_ = 't';
      local_414._1_1_ = ' ';
      local_414._2_1_ = 'f';
      local_414._3_1_ = 'i';
      local_410._0_1_ = 'x';
      local_410._1_1_ = 'e';
      local_410._2_1_ = 'd';
      local_410._3_1_ = ' ';
      local_40c._0_1_ = 'f';
      local_40c._1_1_ = 'u';
      local_40c._2_1_ = 'l';
      local_40c._3_1_ = 'l';
      builtin_strncpy(local_408," fan",4);
      uStack_404._0_1_ = ' ';
      uStack_404._1_1_ = 's';
      uStack_404._2_1_ = 'p';
      uStack_404._3_1_ = 'e';
      builtin_strncpy(acStack_400,"ed\n",4);
      writeLogFile(local_428);
      if (startCheckNetworkJob != 0) goto LAB_0003dbb4;
LAB_0003d90a:
      uVar9 = 2;
      bVar19 = startCheckNetworkJob;
LAB_0003d910:
      iVar21 = *(int *)(dev + 0x5408);
      if (0x5a < iVar21) {
        bVar19 = bVar19 | 1;
      }
      if (bVar19 != 0) goto LAB_0003da82;
      global_stop = 0;
      if (once_error == '\0') {
        if (FatalErrorValue != 3) {
          local_440 = 0;
        }
        status_error = once_error;
        if (FatalErrorValue == 3) {
LAB_0003ddb8:
          FatalErrorValue = 0;
          local_440 = 0;
          builtin_strncpy(local_428,"Network connection r",0x14);
          local_414._0_1_ = 'e';
          local_414._1_1_ = 's';
          local_414._2_1_ = 't';
          local_414._3_1_ = 'o';
          local_410._0_1_ = 'r';
          local_410._1_1_ = 'e';
          local_410._2_1_ = '.';
          local_410._3_1_ = '\n';
          local_40c = local_40c & 0xffffff00;
          writeInitLogFile(local_428);
          goto LAB_0003dade;
        }
        goto LAB_0003d952;
      }
      if (FatalErrorValue == 3) goto LAB_0003ddb8;
      local_440 = 0;
LAB_0003dade:
      if (status_error != '\0') {
        if (FatalErrorValue == 2) {
          local_428[0] = 'F';
          local_428[1] = 'a';
          local_428[2] = 't';
          local_428[3] = 'a';
          local_428[4] = 'l';
          local_428[5] = ' ';
          local_428[6] = 'E';
          local_428[7] = 'r';
          local_428[8] = 'r';
          local_428[9] = 'o';
          local_428[10] = 'r';
          local_428[0xb] = ':';
          local_428[0xc] = ' ';
          local_428[0xd] = 'F';
          local_428[0xe] = 'a';
          local_428[0xf] = 'n';
          local_428[0x10] = ' ';
          local_428[0x11] = 'l';
          local_428[0x12] = 'o';
          local_428[0x13] = 's';
          local_414._0_1_ = 't';
          local_414._1_1_ = '!';
          local_414._2_1_ = '\n';
          local_414._3_1_ = '\0';
        }
        else {
          if (FatalErrorValue == 3) {
            pcVar24 = "Fatal Error: network connection lost!\n";
          }
          else {
            if (FatalErrorValue != 1) {
              builtin_strncpy(local_428,"Fatal Error: unkown ",0x14);
              local_414._0_1_ = 's';
              local_414._1_1_ = 't';
              local_414._2_1_ = 'a';
              local_414._3_1_ = 't';
              local_410._0_1_ = 'u';
              local_410._1_1_ = 's';
              local_410._2_1_ = '.';
              local_410._3_1_ = '\n';
              local_40c = local_40c & 0xffffff00;
              goto LAB_0003db28;
            }
            pcVar24 = "Fatal Error: Temperature is too high!\n";
          }
          local_428._0_4_ = *(undefined4 *)pcVar24;
          local_428._4_4_ = *(undefined4 *)(pcVar24 + 4);
          local_428._8_4_ = *(undefined4 *)(pcVar24 + 8);
          local_428._12_4_ = *(undefined4 *)(pcVar24 + 0xc);
          local_428._16_4_ = *(undefined4 *)(pcVar24 + 0x10);
          local_414 = *(uint *)(pcVar24 + 0x14);
          local_410 = *(undefined4 *)(pcVar24 + 0x18);
          local_40c = *(uint *)(pcVar24 + 0x1c);
          local_408 = *(char (*) [4])(pcVar24 + 0x20);
                    /* WARNING: Ignoring partial resolution of indirect */
          uStack_404._0_2_ = (short)*(undefined4 *)(pcVar24 + 0x24);
        }
LAB_0003db28:
        writeInitLogFile(local_428);
      }
    }
LAB_0003d952:
    processTEST();
    sprintf(local_428,"FAN PWM: %d\n",(uint)*(byte *)(dev + 0x5442));
    writeLogFile(local_428);
    pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
    builtin_strncpy(local_428,"read_temp_func Done!",0x14);
    local_414 = CONCAT22(local_414._2_2_,10);
    writeLogFile(local_428);
    uVar12 = get_crc_count();
    sprintf(local_428,"CRC error counter=%d\n",uVar12);
    writeLogFile(local_428);
    system("cp /tmp/temp /tmp/lasttemp");
    sleep(10);
  } while( true );
}

