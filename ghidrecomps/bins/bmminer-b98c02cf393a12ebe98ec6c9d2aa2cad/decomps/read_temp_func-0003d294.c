
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void read_temp_func(void)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  pthread_mutex_t *__mutex;
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
  undefined4 local_428;
  undefined4 uStack_424;
  undefined4 uStack_420;
  undefined4 uStack_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined2 uStack_3fc;
  undefined local_3fa;
  
  bVar5 = false;
  local_440 = 0;
  bVar3 = false;
  clearTempLogFile();
  do {
    while (bVar19 = enable_read_temp, enable_read_temp == 0) {
      sleep(1);
    }
    clearTempLogFile();
    local_428._0_1_ = s_do_read_temp_func_once____00064b38[0];
    local_428._1_1_ = s_do_read_temp_func_once____00064b38[1];
    local_428._2_1_ = s_do_read_temp_func_once____00064b38[2];
    local_428._3_1_ = s_do_read_temp_func_once____00064b38[3];
    uStack_424._0_1_ = s_do_read_temp_func_once____00064b38[4];
    uStack_424._1_1_ = s_do_read_temp_func_once____00064b38[5];
    uStack_424._2_1_ = s_do_read_temp_func_once____00064b38[6];
    uStack_424._3_1_ = s_do_read_temp_func_once____00064b38[7];
    uStack_420._0_1_ = s_do_read_temp_func_once____00064b38[8];
    uStack_420._1_1_ = s_do_read_temp_func_once____00064b38[9];
    uStack_420._2_1_ = s_do_read_temp_func_once____00064b38[10];
    uStack_420._3_1_ = s_do_read_temp_func_once____00064b38[11];
    uStack_41c._0_1_ = s_do_read_temp_func_once____00064b38[12];
    uStack_41c._1_1_ = s_do_read_temp_func_once____00064b38[13];
    uStack_41c._2_1_ = s_do_read_temp_func_once____00064b38[14];
    uStack_41c._3_1_ = s_do_read_temp_func_once____00064b38[15];
    local_418._0_1_ = s_do_read_temp_func_once____00064b38[16];
    local_418._1_1_ = s_do_read_temp_func_once____00064b38[17];
    local_418._2_1_ = s_do_read_temp_func_once____00064b38[18];
    local_418._3_1_ = s_do_read_temp_func_once____00064b38[19];
    local_414._0_1_ = s_do_read_temp_func_once____00064b38[20];
    local_414._1_1_ = s_do_read_temp_func_once____00064b38[21];
    local_414._2_1_ = s_do_read_temp_func_once____00064b38[22];
    local_414._3_1_ = s_do_read_temp_func_once____00064b38[23];
    local_410._0_3_ = (undefined3)ram0x00064b50;
    writeLogFile(&local_428);
    pthread_mutex_lock(DAT_0003d644);
    if (doTestPatten == '\0') {
      iVar21 = check_asic_reg(8);
      if (iVar21 == 0) {
        local_428._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[0];
        local_428._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[1];
        local_428._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[2];
        local_428._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[3];
        uStack_424._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[4];
        uStack_424._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[5];
        uStack_424._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[6];
        uStack_424._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[7];
        uStack_420._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[8];
        uStack_420._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[9];
        uStack_420._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[10];
        uStack_420._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[11];
        uStack_41c._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[12];
        uStack_41c._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[13];
        uStack_41c._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[14];
        uStack_41c._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[15];
        local_418._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[16];
        local_418._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[17];
        local_418._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[18];
        local_418._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[19];
        local_414._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[20];
        local_414._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[21];
        local_414._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[22];
        local_414._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[23];
        local_410._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[24];
        local_410._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[25];
        local_410._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[26];
        local_410._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[27];
        local_40c._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[28];
        local_40c._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[29];
        local_40c._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[30];
        local_40c._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[31];
        local_408._0_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[32];
        local_408._1_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[33];
        local_408._2_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[34];
        local_408._3_1_ = s_Error__check_asic_reg_0x08_timeo_00064b54[35];
        writeInitLogFile(&local_428);
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
    local_428._0_1_ = s_Done_check_asic_reg_00064b78[0];
    local_428._1_1_ = s_Done_check_asic_reg_00064b78[1];
    local_428._2_1_ = s_Done_check_asic_reg_00064b78[2];
    local_428._3_1_ = s_Done_check_asic_reg_00064b78[3];
    uStack_424._0_1_ = s_Done_check_asic_reg_00064b78[4];
    uStack_424._1_1_ = s_Done_check_asic_reg_00064b78[5];
    uStack_424._2_1_ = s_Done_check_asic_reg_00064b78[6];
    uStack_424._3_1_ = s_Done_check_asic_reg_00064b78[7];
    uStack_420._0_1_ = s_Done_check_asic_reg_00064b78[8];
    uStack_420._1_1_ = s_Done_check_asic_reg_00064b78[9];
    uStack_420._2_1_ = s_Done_check_asic_reg_00064b78[10];
    uStack_420._3_1_ = s_Done_check_asic_reg_00064b78[11];
    uStack_41c._0_1_ = s_Done_check_asic_reg_00064b78[12];
    uStack_41c._1_1_ = s_Done_check_asic_reg_00064b78[13];
    uStack_41c._2_1_ = s_Done_check_asic_reg_00064b78[14];
    uStack_41c._3_1_ = s_Done_check_asic_reg_00064b78[15];
    local_418._0_1_ = s_Done_check_asic_reg_00064b78[16];
    local_418._1_1_ = s_Done_check_asic_reg_00064b78[17];
    local_418._2_1_ = s_Done_check_asic_reg_00064b78[18];
    local_418._3_1_ = s_Done_check_asic_reg_00064b78[19];
    local_414._0_1_ = (char)ram0x00064b8c;
    writeLogFile(&local_428);
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
          pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: do read temp on Chain[%d]\n","driver-btm-c5.c",0x211d,
                    DAT_0003da4c,iVar25);
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
              pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar11 != (FILE *)0x0) {
                iVar14 = dev + iVar23 + iVar21;
                fprintf(pFVar11,"%s:%d:%s: Chain[%d] Chip[%d] TempTypeID=%02x middle offset=%d\n",
                        "driver-btm-c5.c",0x212c,DAT_0003d6fc,iVar25,
                        (*(byte *)(iVar14 + 0x4e8) >> 2) + 1,(uint)*(byte *)(iVar14 + 0x468),
                        (int)*(char *)(DAT_0003d6f8 + iVar21 + iVar23));
              }
              fclose(pFVar11);
            }
            iVar10 = check_reg_temp(DEVICEADDR[iVar25],0,0,0,
                                    *(undefined *)(dev + iVar23 + iVar21 + 0x4e8),iVar25);
            iVar14 = dev;
            uVar9 = log_level;
            if (iVar10 == 0) {
              if (log_level < 6) {
                bVar6 = true;
              }
              else {
                pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar11 != (FILE *)0x0) {
                  fprintf(pFVar11,
                          "%s:%d:%s: read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n",
                          "driver-btm-c5.c",0x213e,DAT_0003d648,iVar25,
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
                pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar11 != (FILE *)0x0) {
                  fprintf(pFVar11,"%s:%d:%s: Chain[%d] Chip[%d] local Temp=%d\n","driver-btm-c5.c",
                          0x2133,DAT_0003d6fc,iVar25,(uint)*(byte *)(dev + iVar23 + iVar21 + 0x4e8),
                          (int)*(short *)(dev + iVar10 * 8));
                }
                fclose(pFVar11);
                sVar15 = *(short *)(dev + (iVar23 + iVar21 + 0xad) * 8);
                iVar14 = dev;
              }
              sprintf((char *)&local_428,"Chain[%d] Chip[%d] pcb temperature=%d\n",iVar25,
                      (uint)*(byte *)(iVar14 + iVar23 + iVar21 + 0x4e8),(int)sVar15);
              writeLogFile(&local_428);
            }
            uVar9 = check_reg_temp(DEVICEADDR[iVar25],1,0,0,
                                   *(undefined *)(dev + iVar23 + iVar21 + 0x4e8),iVar25);
            iVar14 = dev;
            if (uVar9 == 0) {
              sprintf((char *)&local_428,
                      "read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",iVar25,
                      (*(byte *)(dev + iVar23 + iVar21 + 0x4e8) >> 2) + 1,
                      (int)*(short *)(dev + (iVar23 + iVar21) * 8 + 0x56a));
              writeLogFile(&local_428);
            }
            else {
              uVar8 = get_remote(uVar9 & 0xff);
              iVar10 = dev;
              iVar18 = (iVar23 + iVar21) * 8;
              iVar20 = dev + iVar23;
              *(undefined2 *)(iVar14 + iVar18 + 0x56a) = uVar8;
              sprintf((char *)&local_428,"Chain[%d] Chip[%d] junction temperature=%d\n",iVar25,
                      (*(byte *)(iVar20 + iVar21 + 0x4e8) >> 2) + 1,
                      (int)*(short *)(iVar18 + iVar10 + 0x56a));
              writeLogFile(&local_428);
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
              sprintf((char *)&local_428,"Special fix Chain[%d] Chip[%d] middle Temp = %d\n",iVar25,
                      (*(byte *)(iVar14 + iVar21 + 0x4e8) >> 2) + 1,(int)(short)(sVar15 + 0xf));
              writeLogFile(&local_428);
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
            *(int *)(DAT_0003da40 + iVar25 * 4) = *(int *)(DAT_0003da40 + iVar25 * 4) + 1;
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
          if (*(int *)(DAT_0003da44 + iVar25 * 4) == 0) {
LAB_0003d7c2:
            local_430 = sVar17;
          }
        }
        else if (local_430 == 0) goto LAB_0003d7c2;
        sVar17 = *(short *)(iVar23 + iVar21 + 0x9ea);
        if (sVar17 < sStack_42e && 0 < sVar17) {
          if (*(int *)(DAT_0003da44 + iVar25 * 4) == 0) {
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
        if (((bVar27 != 0) && (*(int *)(DAT_0003da44 + iVar25 * 4) == 0)) || (sVar4 == 0)) {
          sVar4 = sVar13;
        }
        iVar14 = iVar25 + 1;
        sprintf((char *)&local_428,"Done read temp on Chain[%d]\n",iVar25);
        writeLogFile(&local_428);
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
      pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar11 != (FILE *)0x0) {
        fprintf(pFVar11,"%s:%d:%s: bring_up_pcb_temp = %d\n","driver-btm-c5.c",0x222b,DAT_0003ddf0,
                bring_up_pcb_temp);
      }
      bVar5 = true;
      fclose(pFVar11);
    }
    check_fan();
    sprintf((char *)&local_428,"Max pcb temp : %d\n",*(undefined4 *)(dev + 0x5408));
    writeLogFile(&local_428);
    iVar21 = dev;
    if ((int)((uint)config_parameter[4] << 0x1e) < 0) {
      if (config_parameter[10] < 0x65) {
        sprintf((char *)&local_428,"Set fixed fan speed=%d\n");
        writeLogFile(&local_428);
        set_PWM(config_parameter[10]);
      }
      else {
        if (!bVar6) goto LAB_0003dc1e;
        *(undefined *)(dev + 0x53fc) = 100;
        *(undefined4 *)(iVar21 + 4) = 0x320000;
        set_fan_control(0x320000);
        local_428._0_1_ = s_Set_fixed_full_fan_speed_00064d9c[0];
        local_428._1_1_ = s_Set_fixed_full_fan_speed_00064d9c[1];
        local_428._2_1_ = s_Set_fixed_full_fan_speed_00064d9c[2];
        local_428._3_1_ = s_Set_fixed_full_fan_speed_00064d9c[3];
        uStack_424._0_1_ = s_Set_fixed_full_fan_speed_00064d9c[4];
        uStack_424._1_1_ = s_Set_fixed_full_fan_speed_00064d9c[5];
        uStack_424._2_1_ = s_Set_fixed_full_fan_speed_00064d9c[6];
        uStack_424._3_1_ = s_Set_fixed_full_fan_speed_00064d9c[7];
        uStack_420._0_1_ = s_Set_fixed_full_fan_speed_00064d9c[8];
        uStack_420._1_1_ = s_Set_fixed_full_fan_speed_00064d9c[9];
        uStack_420._2_1_ = s_Set_fixed_full_fan_speed_00064d9c[10];
        uStack_420._3_1_ = s_Set_fixed_full_fan_speed_00064d9c[11];
        uStack_41c._0_1_ = s_Set_fixed_full_fan_speed_00064d9c[12];
        uStack_41c._1_1_ = s_Set_fixed_full_fan_speed_00064d9c[13];
        uStack_41c._2_1_ = s_Set_fixed_full_fan_speed_00064d9c[14];
        uStack_41c._3_1_ = s_Set_fixed_full_fan_speed_00064d9c[15];
        *(undefined *)(dev + 0x5442) = 100;
        local_418._0_1_ = s_Set_fixed_full_fan_speed_00064d9c[16];
        local_418._1_1_ = s_Set_fixed_full_fan_speed_00064d9c[17];
        local_418._2_1_ = s_Set_fixed_full_fan_speed_00064d9c[18];
        local_418._3_1_ = s_Set_fixed_full_fan_speed_00064d9c[19];
        local_414._0_1_ = s_Set_fixed_full_fan_speed_00064d9c[20];
        local_414._1_1_ = s_Set_fixed_full_fan_speed_00064d9c[21];
        local_414._2_1_ = s_Set_fixed_full_fan_speed_00064d9c[22];
        local_414._3_1_ = s_Set_fixed_full_fan_speed_00064d9c[23];
        local_410._0_2_ = (short)ram0x00064db4;
        writeLogFile(&local_428);
      }
LAB_0003d8fe:
      if (startCheckNetworkJob == 0) goto LAB_0003d90a;
LAB_0003dbb4:
      cgtime(DAT_0003dde8);
      iVar21 = (int)tv_send - (int)tv_send_job;
      if (tv_send._4_4_ - tv_send_job._4_4_ < 0) {
        iVar21 = iVar21 + -1;
      }
      uVar9 = (uint)*(byte *)(dev + 0x53fe);
      if (iVar21 < 0x79) {
        bVar19 = uVar9 < 2;
        goto LAB_0003d910;
      }
      local_428._0_1_ = s_Fatal_Error__network_connection_l_00064de4[0];
      local_428._1_1_ = s_Fatal_Error__network_connection_l_00064de4[1];
      local_428._2_1_ = s_Fatal_Error__network_connection_l_00064de4[2];
      local_428._3_1_ = s_Fatal_Error__network_connection_l_00064de4[3];
      uStack_424._0_1_ = s_Fatal_Error__network_connection_l_00064de4[4];
      uStack_424._1_1_ = s_Fatal_Error__network_connection_l_00064de4[5];
      uStack_424._2_1_ = s_Fatal_Error__network_connection_l_00064de4[6];
      uStack_424._3_1_ = s_Fatal_Error__network_connection_l_00064de4[7];
      uStack_420._0_1_ = s_Fatal_Error__network_connection_l_00064de4[8];
      uStack_420._1_1_ = s_Fatal_Error__network_connection_l_00064de4[9];
      uStack_420._2_1_ = s_Fatal_Error__network_connection_l_00064de4[10];
      uStack_420._3_1_ = s_Fatal_Error__network_connection_l_00064de4[11];
      uStack_41c._0_1_ = s_Fatal_Error__network_connection_l_00064de4[12];
      uStack_41c._1_1_ = s_Fatal_Error__network_connection_l_00064de4[13];
      uStack_41c._2_1_ = s_Fatal_Error__network_connection_l_00064de4[14];
      uStack_41c._3_1_ = s_Fatal_Error__network_connection_l_00064de4[15];
      local_418._0_1_ = s_Fatal_Error__network_connection_l_00064de4[16];
      local_418._1_1_ = s_Fatal_Error__network_connection_l_00064de4[17];
      local_418._2_1_ = s_Fatal_Error__network_connection_l_00064de4[18];
      local_418._3_1_ = s_Fatal_Error__network_connection_l_00064de4[19];
      local_414._0_1_ = s_Fatal_Error__network_connection_l_00064de4[20];
      local_414._1_1_ = s_Fatal_Error__network_connection_l_00064de4[21];
      local_414._2_1_ = s_Fatal_Error__network_connection_l_00064de4[22];
      local_414._3_1_ = s_Fatal_Error__network_connection_l_00064de4[23];
      local_410._0_1_ = s_Fatal_Error__network_connection_l_00064de4[24];
      local_410._1_1_ = s_Fatal_Error__network_connection_l_00064de4[25];
      local_410._2_1_ = s_Fatal_Error__network_connection_l_00064de4[26];
      local_410._3_1_ = s_Fatal_Error__network_connection_l_00064de4[27];
      local_40c._0_1_ = s_Fatal_Error__network_connection_l_00064de4[28];
      local_40c._1_1_ = s_Fatal_Error__network_connection_l_00064de4[29];
      local_40c._2_1_ = s_Fatal_Error__network_connection_l_00064de4[30];
      local_40c._3_1_ = s_Fatal_Error__network_connection_l_00064de4[31];
      local_408._0_1_ = s_Fatal_Error__network_connection_l_00064de4[32];
      local_408._1_1_ = s_Fatal_Error__network_connection_l_00064de4[33];
      local_408._2_1_ = s_Fatal_Error__network_connection_l_00064de4[34];
      local_408._3_1_ = s_Fatal_Error__network_connection_l_00064de4[35];
      uStack_404._0_3_ = (undefined3)ram0x00064e08;
      writeInitLogFile(&local_428);
      iVar21 = *(int *)(dev + 0x5408);
LAB_0003da82:
      local_440 = local_440 + 1;
      iVar25 = local_440;
      sprintf((char *)&local_428,"max pcb temperature:%d, fan num:%d, error counter:%d\n",iVar21,
              uVar9,local_440);
      writeInitLogFile(&local_428);
      __mutex = DAT_0003ddec;
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
          local_428._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[0];
          local_428._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[1];
          local_428._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[2];
          local_428._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[3];
          uStack_424._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[4];
          uStack_424._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[5];
          uStack_424._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[6];
          uStack_424._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[7];
          uStack_420._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[8];
          uStack_420._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[9];
          uStack_420._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[10];
          uStack_420._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[11];
          uStack_41c._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[12];
          uStack_41c._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[13];
          uStack_41c._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[14];
          uStack_41c._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[15];
          status_error = '\x01';
          local_418._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[16];
          local_418._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[17];
          local_418._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[18];
          local_418._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[19];
          local_414._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[20];
          local_414._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[21];
          local_414._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[22];
          local_414._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[23];
          local_410._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[24];
          local_410._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[25];
          local_410._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[26];
          local_410._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[27];
          local_40c._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[28];
          local_40c._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[29];
          local_40c._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[30];
          local_40c._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[31];
          once_error = '\x01';
          uVar22 = 0;
          local_408._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[32];
          local_408._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[33];
          local_408._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[34];
          local_408._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[35];
          uStack_404._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[36];
          uStack_404._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[37];
          uStack_404._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[38];
          uStack_404._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[39];
          uStack_400._0_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[40];
          uStack_400._1_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[41];
          uStack_400._2_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[42];
          uStack_400._3_1_ = s_Fatal_error__turning_off_hash_bo_00064e44[43];
          uStack_3fc = (undefined2)ram0x00064e70;
          local_3fa = (undefined)((uint)ram0x00064e70 >> 0x10);
          writeInitLogFile(&local_428);
          sprintf((char *)&local_428,"max pcb temperature : %d, fan num : %d\n",
                  *(undefined4 *)(dev + 0x5408),uVar9,iVar25);
          writeInitLogFile(&local_428);
          do {
            if (*(int *)(dev + (uVar22 + 2) * 4) == 1) {
              pthread_mutex_lock(__mutex);
              disable_pic_dac(uVar22 & 0xff);
              pthread_mutex_unlock(__mutex);
            }
            uVar22 = uVar22 + 1;
          } while (uVar22 != 0x10);
        }
        if (3 < log_level) {
          pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: Do not clear run bit\n","driver-btm-c5.c",0x2361,DAT_0003ddf0
                   );
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
      *(undefined *)(dev + 0x53fc) = 100;
      *(undefined4 *)(iVar21 + 4) = 0x320000;
      set_fan_control(0x320000);
      local_428._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[0];
      local_428._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[1];
      local_428._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[2];
      local_428._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[3];
      uStack_424._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[4];
      uStack_424._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[5];
      uStack_424._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[6];
      uStack_424._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[7];
      uStack_420._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[8];
      uStack_420._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[9];
      uStack_420._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[10];
      uStack_420._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[11];
      uStack_41c._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[12];
      uStack_41c._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[13];
      uStack_41c._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[14];
      uStack_41c._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[15];
      *(undefined *)(dev + 0x5442) = 100;
      last_temperature = 0x4b;
      local_418._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[16];
      local_418._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[17];
      local_418._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[18];
      local_418._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[19];
      local_414._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[20];
      local_414._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[21];
      local_414._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[22];
      local_414._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[23];
      local_410._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[24];
      local_410._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[25];
      local_410._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[26];
      local_410._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[27];
      local_40c._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[28];
      local_40c._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[29];
      local_40c._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[30];
      local_40c._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[31];
      local_408._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[32];
      local_408._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[33];
      local_408._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[34];
      local_408._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[35];
      uStack_404._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[36];
      uStack_404._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[37];
      uStack_404._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[38];
      uStack_404._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[39];
      uStack_400._0_1_ = s_Read_temp_failed__set_fixed_full_00064db8[40];
      uStack_400._1_1_ = s_Read_temp_failed__set_fixed_full_00064db8[41];
      uStack_400._2_1_ = s_Read_temp_failed__set_fixed_full_00064db8[42];
      uStack_400._3_1_ = s_Read_temp_failed__set_fixed_full_00064db8[43];
      writeLogFile(&local_428);
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
          local_428._0_1_ = s_Network_connection_restore__00064ebc[0];
          local_428._1_1_ = s_Network_connection_restore__00064ebc[1];
          local_428._2_1_ = s_Network_connection_restore__00064ebc[2];
          local_428._3_1_ = s_Network_connection_restore__00064ebc[3];
          uStack_424._0_1_ = s_Network_connection_restore__00064ebc[4];
          uStack_424._1_1_ = s_Network_connection_restore__00064ebc[5];
          uStack_424._2_1_ = s_Network_connection_restore__00064ebc[6];
          uStack_424._3_1_ = s_Network_connection_restore__00064ebc[7];
          uStack_420._0_1_ = s_Network_connection_restore__00064ebc[8];
          uStack_420._1_1_ = s_Network_connection_restore__00064ebc[9];
          uStack_420._2_1_ = s_Network_connection_restore__00064ebc[10];
          uStack_420._3_1_ = s_Network_connection_restore__00064ebc[11];
          uStack_41c._0_1_ = s_Network_connection_restore__00064ebc[12];
          uStack_41c._1_1_ = s_Network_connection_restore__00064ebc[13];
          uStack_41c._2_1_ = s_Network_connection_restore__00064ebc[14];
          uStack_41c._3_1_ = s_Network_connection_restore__00064ebc[15];
          local_418._0_1_ = s_Network_connection_restore__00064ebc[16];
          local_418._1_1_ = s_Network_connection_restore__00064ebc[17];
          local_418._2_1_ = s_Network_connection_restore__00064ebc[18];
          local_418._3_1_ = s_Network_connection_restore__00064ebc[19];
          local_414._0_1_ = s_Network_connection_restore__00064ebc[20];
          local_414._1_1_ = s_Network_connection_restore__00064ebc[21];
          local_414._2_1_ = s_Network_connection_restore__00064ebc[22];
          local_414._3_1_ = s_Network_connection_restore__00064ebc[23];
          local_410._0_1_ = s_Network_connection_restore__00064ebc[24];
          local_410._1_1_ = s_Network_connection_restore__00064ebc[25];
          local_410._2_1_ = s_Network_connection_restore__00064ebc[26];
          local_410._3_1_ = s_Network_connection_restore__00064ebc[27];
          local_40c._0_1_ = (char)ram0x00064ed8;
          writeInitLogFile(&local_428);
          goto LAB_0003dade;
        }
        goto LAB_0003d952;
      }
      if (FatalErrorValue == 3) goto LAB_0003ddb8;
      local_440 = 0;
LAB_0003dade:
      if (status_error != '\0') {
        if (FatalErrorValue == 2) {
          local_428._0_1_ = s_Fatal_Error__Fan_lost__00064f04[0];
          local_428._1_1_ = s_Fatal_Error__Fan_lost__00064f04[1];
          local_428._2_1_ = s_Fatal_Error__Fan_lost__00064f04[2];
          local_428._3_1_ = s_Fatal_Error__Fan_lost__00064f04[3];
          uStack_424._0_1_ = s_Fatal_Error__Fan_lost__00064f04[4];
          uStack_424._1_1_ = s_Fatal_Error__Fan_lost__00064f04[5];
          uStack_424._2_1_ = s_Fatal_Error__Fan_lost__00064f04[6];
          uStack_424._3_1_ = s_Fatal_Error__Fan_lost__00064f04[7];
          uStack_420._0_1_ = s_Fatal_Error__Fan_lost__00064f04[8];
          uStack_420._1_1_ = s_Fatal_Error__Fan_lost__00064f04[9];
          uStack_420._2_1_ = s_Fatal_Error__Fan_lost__00064f04[10];
          uStack_420._3_1_ = s_Fatal_Error__Fan_lost__00064f04[11];
          uStack_41c._0_1_ = s_Fatal_Error__Fan_lost__00064f04[12];
          uStack_41c._1_1_ = s_Fatal_Error__Fan_lost__00064f04[13];
          uStack_41c._2_1_ = s_Fatal_Error__Fan_lost__00064f04[14];
          uStack_41c._3_1_ = s_Fatal_Error__Fan_lost__00064f04[15];
          local_418._0_1_ = s_Fatal_Error__Fan_lost__00064f04[16];
          local_418._1_1_ = s_Fatal_Error__Fan_lost__00064f04[17];
          local_418._2_1_ = s_Fatal_Error__Fan_lost__00064f04[18];
          local_418._3_1_ = s_Fatal_Error__Fan_lost__00064f04[19];
          local_414._0_1_ = s_Fatal_Error__Fan_lost__00064f04[20];
          local_414._1_1_ = s_Fatal_Error__Fan_lost__00064f04[21];
          local_414._2_1_ = s_Fatal_Error__Fan_lost__00064f04[22];
          local_414._3_1_ = s_Fatal_Error__Fan_lost__00064f04[23];
        }
        else {
          if (FatalErrorValue == 3) {
            pcVar24 = "Fatal Error: network connection lost!\n";
          }
          else {
            if (FatalErrorValue != 1) {
              local_428._0_1_ = s_Fatal_Error__unkown_status__00064f1c[0];
              local_428._1_1_ = s_Fatal_Error__unkown_status__00064f1c[1];
              local_428._2_1_ = s_Fatal_Error__unkown_status__00064f1c[2];
              local_428._3_1_ = s_Fatal_Error__unkown_status__00064f1c[3];
              uStack_424._0_1_ = s_Fatal_Error__unkown_status__00064f1c[4];
              uStack_424._1_1_ = s_Fatal_Error__unkown_status__00064f1c[5];
              uStack_424._2_1_ = s_Fatal_Error__unkown_status__00064f1c[6];
              uStack_424._3_1_ = s_Fatal_Error__unkown_status__00064f1c[7];
              uStack_420._0_1_ = s_Fatal_Error__unkown_status__00064f1c[8];
              uStack_420._1_1_ = s_Fatal_Error__unkown_status__00064f1c[9];
              uStack_420._2_1_ = s_Fatal_Error__unkown_status__00064f1c[10];
              uStack_420._3_1_ = s_Fatal_Error__unkown_status__00064f1c[11];
              uStack_41c._0_1_ = s_Fatal_Error__unkown_status__00064f1c[12];
              uStack_41c._1_1_ = s_Fatal_Error__unkown_status__00064f1c[13];
              uStack_41c._2_1_ = s_Fatal_Error__unkown_status__00064f1c[14];
              uStack_41c._3_1_ = s_Fatal_Error__unkown_status__00064f1c[15];
              local_418._0_1_ = s_Fatal_Error__unkown_status__00064f1c[16];
              local_418._1_1_ = s_Fatal_Error__unkown_status__00064f1c[17];
              local_418._2_1_ = s_Fatal_Error__unkown_status__00064f1c[18];
              local_418._3_1_ = s_Fatal_Error__unkown_status__00064f1c[19];
              local_414._0_1_ = s_Fatal_Error__unkown_status__00064f1c[20];
              local_414._1_1_ = s_Fatal_Error__unkown_status__00064f1c[21];
              local_414._2_1_ = s_Fatal_Error__unkown_status__00064f1c[22];
              local_414._3_1_ = s_Fatal_Error__unkown_status__00064f1c[23];
              local_410._0_1_ = s_Fatal_Error__unkown_status__00064f1c[24];
              local_410._1_1_ = s_Fatal_Error__unkown_status__00064f1c[25];
              local_410._2_1_ = s_Fatal_Error__unkown_status__00064f1c[26];
              local_410._3_1_ = s_Fatal_Error__unkown_status__00064f1c[27];
              local_40c._0_1_ = (char)ram0x00064f38;
              goto LAB_0003db28;
            }
            pcVar24 = "Fatal Error: Temperature is too high!\n";
          }
          local_428 = *(undefined4 *)pcVar24;
          uStack_424 = *(undefined4 *)((int)pcVar24 + 4);
          uStack_420 = *(undefined4 *)((int)pcVar24 + 8);
          uStack_41c = *(undefined4 *)((int)pcVar24 + 0xc);
          local_418 = *(undefined4 *)((int)pcVar24 + 0x10);
          local_414 = *(undefined4 *)((int)pcVar24 + 0x14);
          local_410 = *(undefined4 *)((int)pcVar24 + 0x18);
          local_40c = *(undefined4 *)((int)pcVar24 + 0x1c);
          local_408 = *(undefined4 *)((int)pcVar24 + 0x20);
                    /* WARNING: Ignoring partial resolution of indirect */
          uStack_404._0_2_ = (short)*(undefined4 *)((int)pcVar24 + 0x24);
        }
LAB_0003db28:
        writeInitLogFile(&local_428);
      }
    }
LAB_0003d952:
    processTEST();
    sprintf((char *)&local_428,"FAN PWM: %d\n",(uint)*(byte *)(dev + 0x5442));
    writeLogFile(&local_428);
    pthread_mutex_unlock(DAT_0003da48);
    local_428._0_1_ = s_read_temp_func_Done__00064f4c[0];
    local_428._1_1_ = s_read_temp_func_Done__00064f4c[1];
    local_428._2_1_ = s_read_temp_func_Done__00064f4c[2];
    local_428._3_1_ = s_read_temp_func_Done__00064f4c[3];
    uStack_424._0_1_ = s_read_temp_func_Done__00064f4c[4];
    uStack_424._1_1_ = s_read_temp_func_Done__00064f4c[5];
    uStack_424._2_1_ = s_read_temp_func_Done__00064f4c[6];
    uStack_424._3_1_ = s_read_temp_func_Done__00064f4c[7];
    uStack_420._0_1_ = s_read_temp_func_Done__00064f4c[8];
    uStack_420._1_1_ = s_read_temp_func_Done__00064f4c[9];
    uStack_420._2_1_ = s_read_temp_func_Done__00064f4c[10];
    uStack_420._3_1_ = s_read_temp_func_Done__00064f4c[11];
    uStack_41c._0_1_ = s_read_temp_func_Done__00064f4c[12];
    uStack_41c._1_1_ = s_read_temp_func_Done__00064f4c[13];
    uStack_41c._2_1_ = s_read_temp_func_Done__00064f4c[14];
    uStack_41c._3_1_ = s_read_temp_func_Done__00064f4c[15];
    local_418._0_1_ = s_read_temp_func_Done__00064f4c[16];
    local_418._1_1_ = s_read_temp_func_Done__00064f4c[17];
    local_418._2_1_ = s_read_temp_func_Done__00064f4c[18];
    local_418._3_1_ = s_read_temp_func_Done__00064f4c[19];
    local_414 = CONCAT22(local_414._2_2_,(short)ram0x00064f60);
    writeLogFile(&local_428);
    uVar12 = get_crc_count();
    sprintf((char *)&local_428,"CRC error counter=%d\n",uVar12);
    writeLogFile(&local_428);
    system("cp /tmp/temp /tmp/lasttemp");
    sleep(10);
  } while( true );
}

