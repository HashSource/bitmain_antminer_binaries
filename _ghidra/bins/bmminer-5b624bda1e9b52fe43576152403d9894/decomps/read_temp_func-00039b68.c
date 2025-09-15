
/* WARNING: Unknown calling convention */

void * read_temp_func(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  bool bVar10;
  int16_t (*paaiVar11) [8] [4];
  int16_t (*paiVar12) [4];
  undefined4 uVar13;
  _Bool _Var14;
  int16_t iVar15;
  uint uVar16;
  all_parameters *paVar17;
  uint uVar18;
  char *pcVar19;
  ushort uVar20;
  ushort uVar21;
  int iVar22;
  int16_t (*paaiVar23) [8] [4];
  int16_t *piVar24;
  all_parameters *paVar25;
  ushort uVar26;
  all_parameters *paVar27;
  uint uVar28;
  int iVar29;
  all_parameters *paVar30;
  int iVar31;
  all_parameters *paVar32;
  int8_t (*paiVar33) [8];
  ushort uVar34;
  ushort uVar35;
  ushort uVar36;
  int local_158;
  int local_140;
  int16_t temp_top [4];
  int16_t temp_low [4];
  char logstr [256];
  
  local_140 = 0;
  bVar10 = false;
  clearTempLogFile();
  do {
    clearTempLogFile();
    uVar13 = logstr._24_4_;
    builtin_strncpy(logstr,"do read_temp_func once...\n",0x1b);
    logstr[0x1b] = SUB41(uVar13,3);
    writeLogFile(logstr);
    pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
    builtin_strncpy(logstr,"do check_asic_reg 0x08\n",0x18);
    writeLogFile(logstr);
    if (doTestPatten == false) {
      _Var14 = check_asic_reg(8);
      if (_Var14) {
        showAllBadRTInfo();
      }
      else {
        builtin_strncpy(logstr,"Error: check_asic_reg 0x08 timeout\n",0x24);
        writeInitLogFile(logstr);
      }
    }
    else {
      usleep(100000);
    }
    paiVar33 = middle_Offset;
    builtin_strncpy(logstr,"Done check_asic_reg\n",0x14);
    logstr._20_4_ = logstr._20_4_ & 0xffffff00;
    writeLogFile(logstr);
    local_158 = 0;
    uVar28 = 0;
    temp_top[0] = 0;
    temp_top[1] = 0;
    uVar8 = 0;
    temp_low[0] = 0;
    temp_low[1] = 0;
    uVar9 = 0;
    paVar30 = dev;
    do {
      if (paVar30->chain_exist[uVar28] == 1) {
        if (fpga_version < 0xe) {
          if ((int)uVar28 % 3 == 1) goto LAB_00039c48;
        }
        else if (((uVar28 & 0xfffffffd) == 8) || (uVar28 == 0xc)) {
LAB_00039c48:
          sprintf(logstr,"do read temp on Chain[%d]\n",uVar28);
          writeLogFile(logstr);
          if (dev->chain_asic_temp_num[uVar28] < '\x01') {
            uVar34 = 1000;
            uVar35 = 1000;
            uVar21 = 0;
            iVar31 = uVar28 << 3;
            uVar26 = uVar21;
            uVar20 = uVar21;
            uVar36 = uVar35;
          }
          else {
            uVar21 = 0;
            iVar31 = uVar28 * 8;
            uVar35 = 1000;
            uVar26 = 0;
            uVar20 = 0;
            uVar36 = 1000;
            uVar34 = 1000;
            iVar29 = 0;
            do {
              sprintf(logstr,"Chain[%d] Chip[%d] TempTypeID=%02x middle offset=%d\n",uVar28,
                      (dev->TempChipAddr[uVar28][iVar29] >> 2) + 1,
                      (uint)dev->TempChipType[uVar28][iVar29],(int)(*paiVar33)[iVar29]);
              writeLogFile(logstr);
              uVar16 = check_reg_temp(0x98,0,'\0','\0',dev->TempChipAddr[uVar28][iVar29],uVar28);
              paVar30 = dev;
              if (uVar16 == 0) {
                pcVar19 = "read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n";
                sVar6 = dev->chain_asic_temp[uVar28][iVar29][0];
                bVar1 = dev->TempChipAddr[uVar28][iVar29];
              }
              else {
                pcVar19 = "Chain[%d] Chip[%d] local Temp=%d\n";
                sVar6 = ((ushort)uVar16 & 0xff) - 0x40;
                dev->chain_asic_temp[uVar28][iVar29][0] = sVar6;
                bVar1 = paVar30->TempChipAddr[uVar28][iVar29];
              }
              sprintf(logstr,pcVar19,uVar28,(bVar1 >> 2) + 1,(int)sVar6);
              writeLogFile(logstr);
              set_baud_with_addr(dev->baud,0,dev->TempChipAddr[uVar28][iVar29],uVar28,1,0,1);
              check_asic_reg_with_addr(0x1c,(uint)dev->TempChipAddr[uVar28][iVar29],uVar28,1);
              uVar16 = check_reg_temp(0x98,1,'\0','\0',dev->TempChipAddr[uVar28][iVar29],uVar28);
              paVar30 = dev;
              if (uVar16 == 0) {
                sprintf(logstr,"read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",uVar28
                        ,(dev->TempChipAddr[uVar28][iVar29] >> 2) + 1,
                        (int)dev->chain_asic_temp[uVar28][iVar29][1]);
                writeLogFile(logstr);
              }
              else {
                iVar15 = get_remote((ushort)uVar16 & 0xff);
                paVar17 = dev;
                bVar1 = dev->TempChipAddr[uVar28][iVar29];
                paVar30->chain_asic_temp[uVar28][iVar29][1] = iVar15;
                sprintf(logstr,"Chain[%d] Chip[%d] middle Temp=%d\n",uVar28,(bVar1 >> 2) + 1,
                        (int)paVar17->chain_asic_temp[uVar28][iVar29][1]);
                writeLogFile(logstr);
              }
              if (is218_Temp != false) {
                iVar22 = (int)dev->chain_asic_temp[uVar28][iVar29][0];
                if (iVar22 < 1) {
                  uVar18 = 0;
                  uVar16 = uVar18;
                }
                else if (iVar22 < 0x33) {
                  uVar18 = iVar22 + 0x19;
                  uVar16 = uVar18 & 0xffff;
                }
                else if (iVar22 < 0x3d) {
                  uVar18 = iVar22 + 0x1e;
                  uVar16 = uVar18 & 0xffff;
                }
                else {
                  uVar18 = (uint)(short)(iVar22 + 0x23U);
                  uVar16 = iVar22 + 0x23U & 0xffff;
                }
                bVar1 = dev->TempChipAddr[uVar28][iVar29];
                dev->chain_asic_temp[uVar28][iVar29][1] = (int16_t)uVar16;
                sprintf(logstr,"218 fix Chain[%d] Chip[%d] middle Temp = %d\n",uVar28,
                        (bVar1 >> 2) + 1,uVar18);
                writeLogFile(logstr);
              }
              iVar22 = iVar29 + 1;
              uVar5 = dev->chain_asic_temp[uVar28][iVar29][0];
              if ((short)uVar21 < (short)uVar5) {
                uVar21 = uVar5;
              }
              uVar3 = dev->chain_asic_temp[uVar28][iVar29][1];
              uVar4 = dev->chain_asic_temp[uVar28][iVar29][2];
              if ((short)uVar5 <= (short)uVar35) {
                uVar35 = uVar5;
              }
              if ((short)uVar26 < (short)uVar3) {
                uVar26 = uVar3;
              }
              if ((short)uVar3 <= (short)uVar36) {
                uVar36 = uVar3;
              }
              if ((short)uVar20 < (short)uVar4) {
                uVar20 = uVar4;
              }
              if ((short)uVar4 <= (short)uVar34) {
                uVar34 = uVar4;
              }
              iVar29 = iVar22;
            } while (iVar22 < dev->chain_asic_temp_num[uVar28]);
          }
          paVar30 = dev;
          _Var14 = check_temp_offside;
          dev->chain_asic_maxtemp[uVar28][0] = uVar21;
          paVar30->chain_asic_mintemp[uVar28][0] = uVar35;
          *(ushort *)((int)paVar30->chain_asic_maxtemp[0] + iVar31 + 2) = uVar26;
          *(ushort *)((int)paVar30->chain_asic_maxtemp[0] + iVar31 + 4) = uVar20;
          *(ushort *)((int)paVar30->chain_asic_mintemp[0] + iVar31 + 2) = uVar36;
          *(ushort *)((int)paVar30->chain_asic_mintemp[0] + iVar31 + 4) = uVar34;
          if (_Var14 != false) {
            uVar26 = *(ushort *)((int)paVar30->chain_asic_maxtemp[0] + iVar31 + 2);
            if (uVar26 - 0x4b < 0x33) {
              bVar10 = false;
            }
            else if (!bVar10) {
              bVar10 = true;
              *(int *)((int)temp_offside + local_158) = *(int *)((int)temp_offside + local_158) + 1;
            }
          }
          sVar6 = paVar30->chain_asic_maxtemp[uVar28][0];
          iVar15 = temp_top[1];
          if (temp_top[0] < sVar6) {
            temp_top[0] = sVar6;
          }
          if (iVar15 < (short)uVar26) {
            temp_top[1] = uVar26;
          }
          sVar6 = paVar30->chain_asic_mintemp[uVar28][0];
          if ((short)uVar8 < (short)uVar20) {
            uVar8 = uVar20;
          }
          if ((((sVar6 < temp_low[0]) && (0 < sVar6)) &&
              (*(int *)((int)chain_temp_toolow + local_158) == 0)) || (temp_low[0] == 0)) {
            temp_low[0] = sVar6;
          }
          sVar6 = *(short *)((int)paVar30->chain_asic_mintemp[0] + iVar31 + 2);
          if ((((sVar6 < temp_low[1]) && (0 < sVar6)) &&
              (*(int *)((int)chain_temp_toolow + local_158) == 0)) || (temp_low[1] == 0)) {
            temp_low[1] = sVar6;
          }
          if (((((short)uVar34 < (short)uVar9) && (0 < (short)uVar34)) &&
              (*(int *)((int)chain_temp_toolow + local_158) == 0)) || (uVar9 == 0)) {
            uVar9 = uVar34;
          }
          sprintf(logstr,"Done read temp on Chain[%d]\n",uVar28);
          writeLogFile(logstr);
          paVar30 = dev;
        }
      }
      uVar28 = uVar28 + 1;
      paiVar33 = paiVar33 + 1;
      local_158 = local_158 + 4;
    } while (uVar28 != 0x10);
    iVar29 = 0;
    paVar30->temp_top1[0] = (int)temp_top[0];
    iVar22 = 0;
    uVar28 = 0;
    paVar30->temp_top1[1] = (int)temp_top[1];
    paVar30->temp_top1[2] = (int)(short)uVar8;
    paVar30->temp_low1[0] = (int)temp_low[0];
    paVar30->temp_low1[1] = (int)temp_low[1];
    paVar30->temp_low1[2] = (int)(short)uVar9;
    iVar31 = fpga_version;
    paVar17 = paVar30;
    paVar27 = paVar30;
    paVar32 = paVar30;
    do {
      if (paVar27->chain_exist[0] == 1) {
        if (iVar31 < 0xe) {
          iVar7 = (int)uVar28 / 3;
          if ((int)uVar28 % 3 != 1) {
            cVar2 = paVar32->chain_asic_temp_num[0];
            if (0 < cVar2) {
              paaiVar23 = paVar30->chain_asic_temp + iVar7 * 3 + 1;
              piVar24 = paVar30->chain_asic_temp[uVar28][0] + 1;
              do {
                (*(int16_t (*) [4])(piVar24 + -1))[0] = (*paaiVar23)[0][0];
                *piVar24 = (*paaiVar23)[0][1];
                paiVar12 = *paaiVar23;
                paaiVar23 = (int16_t (*) [8] [4])(*paaiVar23 + 1);
                piVar24[1] = (*paiVar12)[2];
                piVar24 = piVar24 + 4;
              } while (paaiVar23 !=
                       (int16_t (*) [8] [4])(paVar30->chain_asic_temp[iVar7 * 3 + 1] + cVar2));
            }
            paVar17->chain_asic_maxtemp[0][0] = paVar30->chain_asic_maxtemp[iVar7 * 3 + 1][0];
            paVar17->chain_asic_maxtemp[0][1] = paVar30->chain_asic_maxtemp[iVar7 * 3 + 1][1];
            paVar17->chain_asic_maxtemp[0][2] = paVar30->chain_asic_maxtemp[iVar7 * 3 + 1][2];
            paVar17->chain_asic_mintemp[0][0] = paVar30->chain_asic_mintemp[iVar7 * 3 + 1][0];
            paVar17->chain_asic_mintemp[0][1] = paVar30->chain_asic_mintemp[iVar7 * 3 + 1][1];
            paVar17->chain_asic_mintemp[0][2] = paVar30->chain_asic_mintemp[iVar7 * 3 + 1][2];
          }
        }
        else if (uVar28 < 0xe) {
          uVar16 = 1 << (uVar28 & 0xff);
          if ((uVar16 & 0x2008) == 0) {
            if ((uVar16 & 0x804) == 0) {
              if ((uVar16 & 0x202) != 0) {
                cVar2 = paVar32->chain_asic_temp_num[0];
                if (0 < cVar2) {
                  paaiVar23 = paVar30->chain_asic_temp + uVar28;
                  paVar25 = paVar30;
                  do {
                    *(int16_t *)((int)paVar25->chain_asic_temp[0][0] + iVar29) =
                         paVar25->chain_asic_temp[8][0][0];
                    (*paaiVar23)[0][1] = paVar25->chain_asic_temp[8][0][1];
                    paaiVar11 = paVar25->chain_asic_temp;
                    paVar25 = (all_parameters *)paVar25->chain_exist;
                    (*paaiVar23)[0][2] = paaiVar11[8][0][2];
                    paaiVar23 = (int16_t (*) [8] [4])(*paaiVar23 + 1);
                  } while (paaiVar23 !=
                           (int16_t (*) [8] [4])(paVar30->chain_asic_temp[0] + cVar2 + iVar22));
                }
                paVar17->chain_asic_maxtemp[0][0] = paVar30->chain_asic_maxtemp[8][0];
                paVar17->chain_asic_maxtemp[0][1] = paVar30->chain_asic_maxtemp[8][1];
                paVar17->chain_asic_maxtemp[0][2] = paVar30->chain_asic_maxtemp[8][2];
                paVar17->chain_asic_mintemp[0][0] = paVar30->chain_asic_mintemp[8][0];
                paVar17->chain_asic_mintemp[0][1] = paVar30->chain_asic_mintemp[8][1];
                paVar17->chain_asic_mintemp[0][2] = paVar30->chain_asic_mintemp[8][2];
              }
            }
            else {
              cVar2 = paVar32->chain_asic_temp_num[0];
              if (0 < cVar2) {
                paaiVar23 = paVar30->chain_asic_temp + uVar28;
                paVar25 = paVar30;
                do {
                  *(int16_t *)((int)paVar25->chain_asic_temp[0][0] + iVar29) =
                       paVar25->chain_asic_temp[10][0][0];
                  (*paaiVar23)[0][1] = paVar25->chain_asic_temp[10][0][1];
                  paaiVar11 = paVar25->chain_asic_temp;
                  paVar25 = (all_parameters *)paVar25->chain_exist;
                  (*paaiVar23)[0][2] = paaiVar11[10][0][2];
                  paaiVar23 = (int16_t (*) [8] [4])(*paaiVar23 + 1);
                } while (paaiVar23 !=
                         (int16_t (*) [8] [4])(paVar30->chain_asic_temp[0] + cVar2 + iVar22));
              }
              paVar17->chain_asic_maxtemp[0][0] = paVar30->chain_asic_maxtemp[10][0];
              paVar17->chain_asic_maxtemp[0][1] = paVar30->chain_asic_maxtemp[10][1];
              paVar17->chain_asic_maxtemp[0][2] = paVar30->chain_asic_maxtemp[10][2];
              paVar17->chain_asic_mintemp[0][0] = paVar30->chain_asic_mintemp[10][0];
              paVar17->chain_asic_mintemp[0][1] = paVar30->chain_asic_mintemp[10][1];
              paVar17->chain_asic_mintemp[0][2] = paVar30->chain_asic_mintemp[10][2];
            }
          }
          else {
            cVar2 = paVar32->chain_asic_temp_num[0];
            if (0 < cVar2) {
              paaiVar23 = paVar30->chain_asic_temp + uVar28;
              paVar25 = paVar30;
              do {
                *(int16_t *)((int)paVar25->chain_asic_temp[0][0] + iVar29) =
                     paVar25->chain_asic_temp[0xc][0][0];
                (*paaiVar23)[0][1] = paVar25->chain_asic_temp[0xc][0][1];
                paaiVar11 = paVar25->chain_asic_temp;
                paVar25 = (all_parameters *)paVar25->chain_exist;
                (*paaiVar23)[0][2] = paaiVar11[0xc][0][2];
                paaiVar23 = (int16_t (*) [8] [4])(*paaiVar23 + 1);
              } while (paaiVar23 !=
                       (int16_t (*) [8] [4])(paVar30->chain_asic_temp[0] + cVar2 + iVar22));
            }
            paVar17->chain_asic_maxtemp[0][0] = paVar30->chain_asic_maxtemp[0xc][0];
            paVar17->chain_asic_maxtemp[0][1] = paVar30->chain_asic_maxtemp[0xc][1];
            paVar17->chain_asic_maxtemp[0][2] = paVar30->chain_asic_maxtemp[0xc][2];
            paVar17->chain_asic_mintemp[0][0] = paVar30->chain_asic_mintemp[0xc][0];
            paVar17->chain_asic_mintemp[0][1] = paVar30->chain_asic_mintemp[0xc][1];
            paVar17->chain_asic_mintemp[0][2] = paVar30->chain_asic_mintemp[0xc][2];
          }
        }
      }
      uVar28 = uVar28 + 1;
      paVar27 = (all_parameters *)&paVar27->pwm_value;
      iVar22 = iVar22 + 8;
      paVar17 = (all_parameters *)paVar17->chain_exist;
      paVar32 = (all_parameters *)((int)&paVar32->current_job_start_address + 1);
      iVar29 = iVar29 + 0x40;
    } while (uVar28 != 0x10);
    check_fan();
    set_PWM_according_to_temperature();
    if (startCheckNetworkJob == false) {
      if (0x5a < dev->temp_top1[0]) {
        uVar28 = 2;
        goto LAB_0003a28c;
      }
LAB_0003a59e:
      global_stop = false;
      if (once_error == false) {
        status_error = once_error;
        local_140 = 0;
      }
      else {
        local_140 = 0;
      }
    }
    else {
      cgtime(&tv_send);
      iVar31 = tv_send.tv_sec - tv_send_job.tv_sec;
      if (tv_send.tv_usec - tv_send_job.tv_usec < 0) {
        iVar31 = iVar31 + -1;
      }
      uVar28 = (uint)dev->fan_num;
      if (iVar31 < 0x79) {
        if ((dev->temp_top1[0] < 0x5b) && (1 < uVar28)) goto LAB_0003a59e;
      }
      else {
        builtin_strncpy(logstr,"Fatal Error: network connection lost",0x24);
        logstr[0x24] = '!';
        logstr[0x25] = '\n';
        logstr[0x26] = '\0';
        writeInitLogFile(logstr);
      }
LAB_0003a28c:
      local_140 = local_140 + 1;
      if (local_140 < 3) {
        global_stop = false;
        if (once_error == false) {
          status_error = once_error;
        }
      }
      else {
        global_stop = true;
        if (dev->temp_top1[0] < 0x5b) {
          if (uVar28 < 2) {
            FatalErrorValue = 2;
            goto LAB_0003a5c0;
          }
          if (dev->fan_speed_top1 < uVar28 * 0x28) {
            FatalErrorValue = 3;
          }
          else {
            FatalErrorValue = 4;
          }
        }
        else {
          FatalErrorValue = 1;
LAB_0003a5c0:
          iVar31 = 0;
          status_error = true;
          once_error = true;
          do {
            if (dev->chain_exist[iVar31] == 1) {
              pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
              disable_pic_dac((uchar)iVar31);
              pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            }
            iVar31 = iVar31 + 1;
          } while (iVar31 != 0x10);
        }
        uVar28 = get_dhash_acc_control();
        set_dhash_acc_control(uVar28 & 0xffffffbf);
      }
    }
    if (stop_mining == false) {
      if (status_error != false) goto LAB_0003a30c;
      goto LAB_0003a35e;
    }
    status_error = true;
LAB_0003a30c:
    switch(FatalErrorValue) {
    case 1:
      pcVar19 = "Fatal Error: Temperature is too high!\n";
      goto LAB_0003a33e;
    case 2:
      builtin_strncpy(logstr,"Fatal Error: Fan lost!\n",0x18);
      break;
    case 3:
      builtin_strncpy(logstr,"Fatal Error: Fan speed too low!\n",0x20);
      logstr._32_4_ = logstr._32_4_ & 0xffffff00;
      break;
    case 4:
      pcVar19 = "Fatal Error: network connection lost!\n";
LAB_0003a33e:
      logstr._0_4_ = *(undefined4 *)pcVar19;
      logstr._4_4_ = *(undefined4 *)(pcVar19 + 4);
      logstr._8_4_ = *(undefined4 *)(pcVar19 + 8);
      logstr._12_4_ = *(undefined4 *)(pcVar19 + 0xc);
      logstr._16_4_ = *(undefined4 *)(pcVar19 + 0x10);
      logstr._20_4_ = *(undefined4 *)(pcVar19 + 0x14);
      logstr._24_4_ = *(undefined4 *)(pcVar19 + 0x18);
      logstr._28_4_ = *(undefined4 *)(pcVar19 + 0x1c);
      logstr._32_4_ = *(undefined4 *)(pcVar19 + 0x20);
      logstr._36_2_ = (undefined2)*(undefined4 *)(pcVar19 + 0x24);
      logstr[0x26] = (char)((uint)*(undefined4 *)(pcVar19 + 0x24) >> 0x10);
      break;
    default:
      logstr[0] = 'F';
      logstr[1] = 'a';
      logstr[2] = 't';
      logstr[3] = 'a';
      logstr[4] = 'l';
      logstr[5] = ' ';
      logstr[6] = 'E';
      logstr[7] = 'r';
      logstr[8] = 'r';
      logstr[9] = 'o';
      logstr[10] = 'r';
      logstr[0xb] = ':';
      logstr[0xc] = ' ';
      logstr[0xd] = 'u';
      logstr[0xe] = 'n';
      logstr[0xf] = 'k';
      logstr[0x10] = 'o';
      logstr[0x11] = 'w';
      logstr[0x12] = 'n';
      logstr[0x13] = ' ';
      logstr[0x14] = 's';
      logstr[0x15] = 't';
      logstr[0x16] = 'a';
      logstr[0x17] = 't';
      logstr[0x18] = 'u';
      logstr[0x19] = 's';
      logstr[0x1a] = '.';
      logstr[0x1b] = '\n';
      logstr._28_4_ = logstr._28_4_ & 0xffffff00;
    }
    writeInitLogFile(logstr);
LAB_0003a35e:
    processTEST();
    sprintf(logstr,"FAN PWM: %d\n",(uint)dev->fan_pwm);
    writeLogFile(logstr);
    pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
    uVar13 = logstr._20_4_;
    builtin_strncpy(logstr,"read_temp_func Done!\n",0x16);
    logstr._22_2_ = SUB42(uVar13,2);
    writeLogFile(logstr);
    sprintf(logstr,"CRC error counter=%d\n",(uint)(ushort)axi_fpga_addr[0x3e]);
    writeLogFile(logstr);
    updateLogFile();
    if (doTestPatten == false) {
      sleep(1);
    }
    else {
      sleep(3);
    }
  } while( true );
}

