
/* WARNING: Unknown calling convention */

api_data * bitmain_api_stats(cgpu_info *cgpu)

{
  longlong lVar1;
  uint *puVar2;
  byte bVar3;
  _Bool *p_Var4;
  long *plVar5;
  undefined4 uVar6;
  api_data *paVar7;
  int iVar8;
  long lVar9;
  char (*__nptr) [32];
  int iVar10;
  size_t sVar11;
  undefined1 *puVar12;
  undefined1 *extraout_r1;
  char *pcVar13;
  all_parameters *paVar14;
  uint uVar15;
  int iVar16;
  uint64_t *puVar17;
  int iVar18;
  int iVar19;
  undefined1 *puVar20;
  int iVar21;
  int (*paiVar22) [256];
  undefined1 *puVar23;
  int *piVar24;
  undefined2 uVar25;
  bool bVar26;
  double dVar27;
  undefined1 in_stack_fffff764;
  undefined1 *local_890;
  undefined1 *local_88c;
  undefined1 *local_888;
  undefined1 *local_884;
  api_data *local_880;
  api_data *local_87c;
  int16_t asic_num_total;
  double dev_sum_freq;
  char chain_xtime [16];
  char tmp [20];
  char fan_name [12];
  
  paVar7 = api_add_uint8((api_data *)0x0,"miner_count",&dev->chain_num,true);
  paVar7 = api_add_string(paVar7,"frequency",dev->frequency_t,true);
  paVar7 = api_add_uint8(paVar7,"fan_num",&dev->fan_num,true);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"fan%d",iVar18);
    paVar7 = api_add_uint(paVar7,fan_name,dev->fan_speed_value + iVar19,true);
    iVar19 = iVar18;
  } while (iVar18 != 8);
  local_880 = api_add_uint8(paVar7,"temp_num",&dev->chain_num,true);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"temp%d",iVar18);
    local_880 = api_add_int16(local_880,fan_name,(uint16_t *)(dev->chain_asic_maxtemp + iVar19),true
                             );
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"temp2_%d",iVar18);
    local_880 = api_add_int16(local_880,fan_name,(uint16_t *)(dev->chain_asic_temp[iVar19][0] + 1),
                              true);
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"temp3_%d",iVar18);
    local_880 = api_add_int16(local_880,fan_name,(uint16_t *)(dev->chain_asic_temp[iVar19][1] + 1),
                              true);
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  puVar20 = CSWTCH_825;
  local_888 = CSWTCH_824;
  local_884 = CSWTCH_825;
  local_890 = CSWTCH_824;
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    dev_sum_freq = 0.0;
    sprintf(fan_name,"freq_avg%d",iVar18);
    paVar14 = dev;
    if (dev->chain_exist[iVar19] == 1) {
      iVar8 = getChainPICMagicNumber(iVar19);
      if (iVar8 == 0x7d) {
        if (paVar14->chain_asic_num[iVar19] != '\0') {
          iVar8 = 0;
          puVar23 = (undefined1 *)((iVar19 % 3) * 0x1f);
          puVar12 = puVar23;
          do {
            if (fpga_version < 0xe) {
              bVar3 = chain_pic_buf[(iVar19 / 3) * 3][(int)(puVar23 + iVar8 + 0xb)];
            }
            else {
              iVar21 = 0xb;
              if (iVar19 - 1U < 0xd) {
                puVar12 = local_890;
              }
              iVar10 = 0;
              if (iVar19 - 1U < 0xd) {
                iVar10 = *(int *)(puVar12 + -4);
                iVar21 = *(int *)(puVar20 + -4) * 0x1f + 0xb;
              }
              bVar3 = chain_pic_buf[iVar10][iVar21 + iVar8];
            }
            iVar8 = iVar8 + 1;
            lVar9 = strtol(freq_pll_1385[bVar3].freq,(char **)0x0,10);
            dev_sum_freq = (double)(longlong)lVar9 + dev_sum_freq;
            uVar15 = (uint)dev->chain_asic_num[iVar19];
            puVar12 = extraout_r1;
          } while (iVar8 < (int)uVar15);
          if (uVar15 != 0) {
            dev_sum_freq = dev_sum_freq / (double)(longlong)(int)uVar15;
          }
        }
        dVar27 = dev_sum_freq * 100.0;
      }
      else {
        dVar27 = dev_sum_freq * 100.0;
      }
    }
    else {
      dVar27 = dev_sum_freq * 100.0;
    }
    puVar20 = puVar20 + 4;
    dev_sum_freq = (double)(longlong)(int)(longlong)dVar27 / 100.0;
    local_880 = api_add_mhs(local_880,fan_name,&dev_sum_freq,true);
    local_890 = local_890 + 4;
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  puVar20 = CSWTCH_825;
  iVar19 = 0;
  local_88c = CSWTCH_824;
  paiVar22 = chain_badcore_num;
  dev_sum_freq = 0.0;
  builtin_strncpy(fan_name,"total_rateid",0xc);
  do {
    paVar14 = dev;
    if (((dev->chain_exist[iVar19] == 1) &&
        (iVar18 = getChainPICMagicNumber(iVar19), iVar18 == 0x7d)) &&
       (paVar14->chain_asic_num[iVar19] != '\0')) {
      iVar8 = 0;
      iVar18 = 0;
      do {
        if (fpga_version < 0xe) {
          bVar3 = *(byte *)((int)chain_pic_buf + iVar19 * 0x1f + (iVar19 / 3) * 0x123 + iVar18 + 0xb
                           );
        }
        else {
          iVar10 = 0xb;
          iVar21 = 0;
          if (iVar19 - 1U < 0xd) {
            iVar21 = *(int *)(local_88c + -4);
            iVar10 = *(int *)(puVar20 + -4) * 0x1f + 0xb;
          }
          bVar3 = chain_pic_buf[iVar21][iVar10 + iVar18];
        }
        iVar18 = iVar18 + 1;
        lVar9 = strtol(freq_pll_1385[bVar3].freq,(char **)0x0,10);
        piVar24 = (int *)((int)*paiVar22 + iVar8);
        iVar8 = iVar8 + 4;
        dev_sum_freq = (double)(longlong)(lVar9 * (0x72 - *piVar24)) + dev_sum_freq;
      } while (iVar18 < (int)(uint)dev->chain_asic_num[iVar19]);
    }
    iVar19 = iVar19 + 1;
    paiVar22 = paiVar22 + 1;
    puVar20 = puVar20 + 4;
    local_88c = local_88c + 4;
  } while (iVar19 != 0x10);
  iVar18 = 0;
  iVar19 = 0;
  puVar20 = CSWTCH_824;
  dev_sum_freq = (double)(longlong)(int)(longlong)((dev_sum_freq / 1000.0) * 100.0) / 100.0;
  paVar7 = api_add_mhs(local_880,fan_name,&dev_sum_freq,true);
  local_87c = (api_data *)chain_badcore_num;
  puVar23 = CSWTCH_825;
  dev_sum_freq = 0.0;
  builtin_strncpy(fan_name,"total_freqav",0xc);
  do {
    while (((paVar14 = dev, dev->chain_exist[iVar19] == 1 &&
            (iVar8 = getChainPICMagicNumber(iVar19), iVar8 == 0x7d)) &&
           (paVar14->chain_asic_num[iVar19] != '\0'))) {
      iVar8 = 0;
      do {
        if (fpga_version < 0xe) {
          bVar3 = *(byte *)((int)chain_pic_buf + iVar19 * 0x1f + (iVar19 / 3) * 0x123 + iVar8 + 0xb)
          ;
        }
        else {
          iVar10 = 0xb;
          iVar21 = 0;
          if (iVar19 - 1U < 0xd) {
            iVar21 = *(int *)(puVar20 + -4);
            iVar10 = *(int *)(puVar23 + -4) * 0x1f + 0xb;
          }
          bVar3 = chain_pic_buf[iVar21][iVar10 + iVar8];
        }
        iVar8 = iVar8 + 1;
        iVar18 = iVar18 + 1;
        lVar9 = strtol(freq_pll_1385[bVar3].freq,(char **)0x0,10);
        dev_sum_freq = (double)(longlong)lVar9 + dev_sum_freq;
      } while (iVar8 < (int)(uint)dev->chain_asic_num[iVar19]);
      iVar19 = iVar19 + 1;
      puVar20 = puVar20 + 4;
      puVar23 = puVar23 + 4;
      if (iVar19 == 0x10) goto LAB_0002c5e4;
    }
    iVar19 = iVar19 + 1;
    puVar20 = puVar20 + 4;
    puVar23 = puVar23 + 4;
  } while (iVar19 != 0x10);
LAB_0002c5e4:
  dev_sum_freq = (double)(longlong)
                         (int)(longlong)((dev_sum_freq / (double)(longlong)iVar18) * 100.0) / 100.0;
  paVar7 = api_add_mhs(paVar7,fan_name,&dev_sum_freq,true);
  uVar6 = fan_name._8_4_;
  asic_num_total = 0;
  iVar19 = 0;
  builtin_strncpy(fan_name,"total_acn",10);
  fan_name._10_2_ = SUB42(uVar6,2);
  paVar14 = dev;
  do {
    uVar15 = paVar14->chain_exist[0];
    paVar14 = (all_parameters *)&paVar14->pwm_value;
    bVar26 = uVar15 == 1;
    if (bVar26) {
      uVar15 = (int)dev->chain_exist + iVar19 + -8;
    }
    iVar19 = iVar19 + 1;
    if (bVar26) {
      asic_num_total = (ushort)*(byte *)(uVar15 + 0x2faa) + asic_num_total;
    }
  } while (iVar19 != 0x10);
  iVar19 = 0;
  paVar7 = api_add_int16(paVar7,fan_name,(uint16_t *)&asic_num_total,true);
  dev_sum_freq = 0.0;
  builtin_strncpy(fan_name,"total_ra",8);
  fan_name[8] = 't';
  fan_name[9] = 'e';
  fan_name[10] = '\0';
  do {
    while ((dev->chain_exist[iVar19] == 1 &&
           (__nptr = displayed_rate + iVar19, displayed_rate[iVar19][0] != '\0'))) {
      iVar19 = iVar19 + 1;
      dVar27 = strtod(*__nptr,(char **)0x0);
      dev_sum_freq = dev_sum_freq + dVar27;
      if (iVar19 == 0x10) goto LAB_0002c6cc;
    }
    iVar19 = iVar19 + 1;
  } while (iVar19 != 0x10);
LAB_0002c6cc:
  dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * 100.0) / 100.0;
  paVar7 = api_add_mhs(paVar7,fan_name,&dev_sum_freq,true);
  iVar19 = 0;
  paiVar22 = (int (*) [256])local_87c;
  local_87c = paVar7;
  do {
    iVar18 = iVar19 + 1;
    dev_sum_freq = 0.0;
    sprintf(fan_name,"chain_rateideal%d",iVar18);
    paVar14 = dev;
    if (((dev->chain_exist[iVar19] == 1) && (iVar8 = getChainPICMagicNumber(iVar19), iVar8 == 0x7d))
       && (paVar14->chain_asic_num[iVar19] != '\0')) {
      iVar21 = 0;
      iVar8 = 0;
      do {
        if (fpga_version < 0xe) {
          bVar3 = *(byte *)((int)chain_pic_buf + iVar19 * 0x1f + (iVar19 / 3) * 0x123 + iVar8 + 0xb)
          ;
        }
        else {
          iVar10 = 0xb;
          iVar16 = 0;
          if (iVar19 - 1U < 0xd) {
            iVar16 = *(int *)(local_888 + -4);
            iVar10 = *(int *)(local_884 + -4) * 0x1f + 0xb;
          }
          bVar3 = chain_pic_buf[iVar16][iVar10 + iVar8];
        }
        iVar8 = iVar8 + 1;
        lVar9 = strtol(freq_pll_1385[bVar3].freq,(char **)0x0,10);
        piVar24 = (int *)((int)*paiVar22 + iVar21);
        iVar21 = iVar21 + 4;
        dev_sum_freq = (double)(longlong)(lVar9 * (0x72 - *piVar24)) + dev_sum_freq;
      } while (iVar8 < (int)(uint)dev->chain_asic_num[iVar19]);
    }
    paiVar22 = paiVar22 + 1;
    dev_sum_freq = (double)(longlong)(int)(longlong)((dev_sum_freq / 1000.0) * 100.0) / 100.0;
    local_87c = api_add_mhs(local_87c,fan_name,&dev_sum_freq,true);
    local_888 = local_888 + 4;
    local_884 = local_884 + 4;
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  paVar7 = api_add_int(local_87c,"temp_max",dev->temp_top1 + 1,true);
  dVar27 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  total_diff1 = __aeabi_d2lz(SUB84(dVar27,0),(int)((ulonglong)dVar27 >> 0x20));
  iVar19 = (uint)total_diff1 + hw_errors;
  iVar18 = (int)((ulonglong)total_diff1 >> 0x20) +
           (hw_errors >> 0x1f) + (uint)CARRY4((uint)total_diff1,hw_errors);
  if (iVar19 == 0 && iVar18 == 0) {
    dev_sum_freq = 0.0;
  }
  else {
    lVar1 = (longlong)hw_errors;
    dVar27 = (double)__aeabi_l2d(iVar19,iVar18);
    dev_sum_freq = (double)lVar1 / dVar27;
  }
  paVar7 = api_add_percent(paVar7,"Device Hardware%",&dev_sum_freq,true);
  paVar7 = api_add_int(paVar7,"no_matching_work",&hw_errors,true);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"chain_acn%d",iVar18);
    paVar7 = api_add_uint8(paVar7,fan_name,dev->chain_asic_num + iVar19,true);
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"chain_acs%d",iVar18);
    paVar7 = api_add_string(paVar7,fan_name,dev->chain_asic_status_string[iVar19],true);
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"chain_hw%d",iVar18);
    paVar7 = api_add_uint32(paVar7,fan_name,dev->chain_hw + iVar19,true);
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  iVar19 = 0;
  do {
    iVar18 = iVar19 + 1;
    sprintf(fan_name,"chain_rate%d",iVar18);
    paVar7 = api_add_string(paVar7,fan_name,displayed_rate[iVar19],true);
    iVar19 = iVar18;
  } while (iVar18 != 0x10);
  paVar14 = dev;
  iVar19 = 1;
  do {
    while( true ) {
      iVar18 = iVar19 + 1;
      if (paVar14->chain_exist[iVar19 + -1] != 1) break;
      fan_name[0] = '{';
      fan_name[1] = '\0';
      fan_name[2] = '\0';
      fan_name[3] = '\0';
      memset(fan_name + 4,0,0x7fc);
      tmp[4] = '\0';
      tmp[5] = '\0';
      tmp[6] = '\0';
      tmp[7] = '\0';
      tmp[8] = '\0';
      tmp[9] = '\0';
      tmp[10] = '\0';
      tmp[0xb] = '\0';
      tmp[0xc] = '\0';
      tmp[0xd] = '\0';
      tmp[0xe] = '\0';
      tmp[0xf] = '\0';
      tmp[0x10] = '\0';
      tmp[0x11] = '\0';
      tmp[0x12] = '\0';
      tmp[0x13] = '\0';
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      sprintf(chain_xtime,"chain_xtime%d",iVar19);
      bVar26 = chain_badcore_num[iVar19 + 0xf][0] != 0;
      if (bVar26) {
        sprintf(tmp,"X%d=%d",0);
        strcat(fan_name,tmp);
      }
      bVar26 = !bVar26;
      if (1 < *(byte *)((int)dev->temp + iVar19 + 0x3f)) {
        iVar8 = 1;
        piVar24 = x_time[iVar19 + -1];
        do {
          piVar24 = piVar24 + 1;
          if (*piVar24 != 0) {
            pcVar13 = "X%d=%d";
            if (!bVar26) {
              pcVar13 = ",X%d=%d";
            }
            sprintf(tmp,pcVar13,iVar8,*piVar24);
            strcat(fan_name,tmp);
            bVar26 = false;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)*(byte *)((int)dev->temp + iVar19 + 0x3f));
      }
      sVar11 = strlen(fan_name);
      pcVar13 = fan_name + sVar11;
      pcVar13[0] = '}';
      pcVar13[1] = '\0';
      paVar7 = api_add_string(paVar7,chain_xtime,fan_name,true);
      paVar14 = dev;
      iVar19 = iVar18;
      if (iVar18 == 0x11) goto LAB_0002caa0;
    }
    iVar19 = iVar18;
  } while (iVar18 != 0x11);
LAB_0002caa0:
  iVar18 = 0;
  iVar19 = 1;
  do {
    while (paVar14->chain_exist[iVar18] != 1) {
      iVar18 = iVar18 + 1;
      iVar19 = iVar19 + 1;
      if (iVar18 == 0x10) goto LAB_0002caea;
    }
    sprintf(tmp,"chain_offside_%d",iVar19);
    piVar24 = temp_offside + iVar18;
    iVar18 = iVar18 + 1;
    sprintf(fan_name,"%d",*piVar24);
    paVar7 = api_add_string(paVar7,tmp,fan_name,true);
    paVar14 = dev;
    iVar19 = iVar19 + 1;
  } while (iVar18 != 0x10);
LAB_0002caea:
  iVar18 = 0;
  iVar19 = 1;
  do {
    while (paVar14->chain_exist[iVar18] == 1) {
      sprintf(tmp,"chain_opencore_%d",iVar19);
      p_Var4 = isChainAllCoresOpened + iVar18;
      iVar18 = iVar18 + 1;
      if (*p_Var4 == false) {
        uVar25 = 0x30;
      }
      else {
        uVar25 = 0x31;
      }
      fan_name[0] = (char)uVar25;
      fan_name[1] = (char)((ushort)uVar25 >> 8);
      paVar7 = api_add_string(paVar7,tmp,fan_name,true);
      paVar14 = dev;
      iVar19 = iVar19 + 1;
      if (iVar18 == 0x10) goto LAB_0002cb44;
    }
    iVar18 = iVar18 + 1;
    iVar19 = iVar19 + 1;
  } while (iVar18 != 0x10);
LAB_0002cb44:
  puVar17 = rate;
  uVar15 = 0;
  iVar19 = 0;
  do {
    while (puVar2 = paVar14->chain_exist, paVar14 = (all_parameters *)&paVar14->pwm_value,
          *puVar2 == 1) {
      piVar24 = &((__pthread_mutex_s *)puVar17)->__lock;
      plVar5 = (long *)((int)puVar17 + 4);
      puVar17 = (uint64_t *)((int)puVar17 + 8);
      bVar26 = CARRY4(uVar15,*piVar24);
      uVar15 = uVar15 + *piVar24;
      iVar19 = iVar19 + *plVar5 + (uint)bVar26;
      if ((pthread_mutex_t *)puVar17 == &iic_mutex) goto LAB_0002cbca;
    }
    puVar17 = (uint64_t *)((int)puVar17 + 8);
  } while ((pthread_mutex_t *)puVar17 != &iic_mutex);
LAB_0002cbca:
  suffix_string_c5(CONCAT44(iVar19,uVar15),displayed_hash_rate,0x10,7,(_Bool)in_stack_fffff764);
  builtin_strncpy(fan_name,"miner_versio",0xc);
  paVar7 = api_add_string(paVar7,fan_name,g_miner_version,true);
  return paVar7;
}

