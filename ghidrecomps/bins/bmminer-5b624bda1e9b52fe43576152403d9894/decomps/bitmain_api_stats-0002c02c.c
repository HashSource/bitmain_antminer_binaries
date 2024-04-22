
/* WARNING: Unknown calling convention */

api_data * bitmain_api_stats(cgpu_info *cgpu)

{
  int *piVar1;
  byte bVar2;
  int *piVar3;
  uint *puVar4;
  api_data *paVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  char (*__nptr) [32];
  size_t sVar9;
  char *pcVar10;
  int extraout_r1;
  size_t bufsiz;
  int iVar11;
  int new_T9_PLUS_chainIndex;
  uint uVar12;
  int new_T9_PLUS_chainIndex_1;
  int new_T9_PLUS_chainIndex_2;
  int new_T9_PLUS_chainIndex_3;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  undefined2 uVar24;
  bool bVar25;
  double dVar26;
  double dVar27;
  undefined8 uVar28;
  undefined4 in_stack_fffff764;
  int local_890;
  int local_88c;
  int local_888;
  int local_884;
  api_data *local_880;
  api_data *local_87c;
  int16_t asic_num_total;
  double dev_sum_freq_1;
  char chain_xtime [16];
  char tmp [20];
  char fan_name [12];
  
  piVar1 = DAT_0002c2e8;
  paVar5 = api_add_uint8((api_data *)0x0,DAT_0002c2ec,(uchar *)(*DAT_0002c2e8 + 0x2fbc),true);
  paVar5 = api_add_string(paVar5,DAT_0002c2f0,(char *)(*piVar1 + 0x2ff0),true);
  paVar5 = api_add_uint8(paVar5,DAT_0002c2f4,(uchar *)(*piVar1 + 0x2fbd),true);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002c2f8,iVar20);
    piVar23 = DAT_0002c2e8;
    paVar5 = api_add_uint(paVar5,fan_name,(uint *)(*piVar1 + iVar22 * 4 + 0x2f4a),true);
    iVar22 = iVar20;
  } while (iVar20 != 8);
  local_880 = api_add_uint8(paVar5,DAT_0002c2fc,(uchar *)(*piVar23 + 0x2fbc),true);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002c300,iVar20);
    local_880 = api_add_int16(local_880,fan_name,(uint16_t *)(*piVar1 + (iVar22 + 0x12d) * 8),true);
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002c304,iVar20);
    local_880 = api_add_int16(local_880,fan_name,(uint16_t *)(*piVar1 + iVar22 * 0x40 + 0x56a),true)
    ;
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002c308,iVar20);
    local_880 = api_add_int16(local_880,fan_name,(uint16_t *)(*piVar1 + iVar22 * 0x40 + 0x572),true)
    ;
    dVar26 = DAT_0002c2e0;
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  local_884 = DAT_0002c30c + 0x34;
  local_888 = DAT_0002c30c;
  local_890 = DAT_0002c30c;
  iVar22 = 0;
  iVar20 = local_884;
  do {
    iVar17 = iVar22 + 1;
    dev_sum_freq_1 = 0.0;
    sprintf(fan_name,DAT_0002c310,iVar17);
    iVar13 = *piVar1;
    if (*(int *)(iVar13 + (iVar22 + 2) * 4) == 1) {
      iVar6 = getChainPICMagicNumber(iVar22);
      iVar8 = DAT_0002c324;
      iVar18 = DAT_0002c314;
      if (iVar6 == 0x7d) {
        if (*(char *)(iVar13 + iVar22 + 0x2faa) != '\0') {
          uVar14 = iVar22 - 1;
          iVar21 = 0;
          iVar13 = (iVar22 % 3) * 0x1f;
          iVar6 = iVar13 + (iVar22 / 3) * 0x180 + DAT_0002c314;
          do {
            if (fpga_version < 0xe) {
              bVar2 = *(byte *)(iVar6 + iVar21 + 0xdf);
            }
            else {
              iVar15 = 0xb;
              if (uVar14 < 0xd) {
                iVar13 = local_890;
              }
              iVar11 = 0;
              if (uVar14 < 0xd) {
                iVar11 = *(int *)(iVar13 + -4);
                iVar15 = *(int *)(iVar20 + -4) * 0x1f;
              }
              if (uVar14 < 0xd) {
                iVar15 = iVar15 + 0xb;
              }
              bVar2 = *(byte *)(iVar18 + iVar11 * 0x80 + iVar21 + iVar15 + 0xd4);
            }
            iVar21 = iVar21 + 1;
            lVar7 = strtol(*(char **)(iVar8 + (uint)bVar2 * 0x10 + 0x38),(char **)0x0,10);
            dev_sum_freq_1 = (double)(longlong)lVar7 + dev_sum_freq_1;
            uVar12 = (uint)*(byte *)(*piVar1 + iVar22 + 0x2faa);
            iVar13 = extraout_r1;
          } while (iVar21 < (int)uVar12);
          if (uVar12 != 0) {
            dev_sum_freq_1 = dev_sum_freq_1 / (double)(longlong)(int)uVar12;
          }
        }
        dVar27 = dev_sum_freq_1 * dVar26;
      }
      else {
        dVar27 = dev_sum_freq_1 * dVar26;
      }
    }
    else {
      dVar27 = dev_sum_freq_1 * dVar26;
    }
    iVar20 = iVar20 + 4;
    dev_sum_freq_1 = (double)(longlong)(int)(longlong)dVar27 / dVar26;
    local_880 = api_add_mhs(local_880,fan_name,&dev_sum_freq_1,true);
    iVar13 = DAT_0002c328;
    piVar23 = DAT_0002c320;
    local_890 = local_890 + 4;
    iVar22 = iVar17;
  } while (iVar17 != 0x10);
  fan_name._0_4_ = *DAT_0002c318;
  fan_name._4_4_ = DAT_0002c318[1];
  fan_name._8_4_ = DAT_0002c318[2];
  local_88c = DAT_0002c31c + -0x34;
  iVar17 = 0;
  dev_sum_freq_1 = 0.0;
  iVar22 = DAT_0002c31c;
  iVar20 = DAT_0002c328;
  do {
    iVar18 = *piVar1;
    if (((*(int *)(iVar18 + (iVar17 + 2) * 4) == 1) &&
        (iVar8 = getChainPICMagicNumber(iVar17), iVar8 == 0x7d)) &&
       (*(char *)(iVar18 + iVar17 + 0x2faa) != '\0')) {
      iVar6 = 0;
      iVar8 = 0;
      iVar18 = iVar17 * 0x1f + (iVar17 / 3) * 0x123 + DAT_0002c7b0;
      do {
        if (*piVar23 < 0xe) {
          bVar2 = *(byte *)(iVar18 + iVar8 + 0xb);
        }
        else {
          iVar15 = 0xb;
          iVar21 = 0;
          if (iVar17 - 1U < 0xd) {
            iVar21 = *(int *)(local_88c + -4);
            iVar15 = *(int *)(iVar22 + -4) * 0x1f + 0xb;
          }
          bVar2 = chain_pic_buf[iVar21][iVar15 + iVar8];
        }
        iVar8 = iVar8 + 1;
        lVar7 = strtol(freq_pll_1385[bVar2].freq,(char **)0x0,10);
        piVar3 = (int *)(iVar20 + iVar6);
        iVar6 = iVar6 + 4;
        dev_sum_freq_1 = (double)(longlong)(lVar7 * (0x72 - *piVar3)) + dev_sum_freq_1;
      } while (iVar8 < (int)(uint)*(byte *)(*piVar1 + iVar17 + 0x2faa));
    }
    iVar18 = DAT_0002c798;
    iVar17 = iVar17 + 1;
    iVar20 = iVar20 + 0x400;
    iVar22 = iVar22 + 4;
    local_88c = local_88c + 4;
  } while (iVar17 != 0x10);
  iVar20 = 0;
  iVar22 = 0;
  iVar17 = DAT_0002c798 + -0x34;
  dev_sum_freq_1 =
       (double)(longlong)(int)(longlong)((dev_sum_freq_1 / DAT_0002c788) * DAT_0002c790) /
       DAT_0002c790;
  paVar5 = api_add_mhs(local_880,fan_name,&dev_sum_freq_1,true);
  fan_name._0_4_ = *DAT_0002c79c;
  fan_name._4_4_ = DAT_0002c79c[1];
  fan_name._8_4_ = DAT_0002c79c[2];
  dev_sum_freq_1 = 0.0;
  do {
    while (((iVar8 = *piVar1, *(int *)(iVar8 + (iVar22 + 2) * 4) == 1 &&
            (iVar6 = getChainPICMagicNumber(iVar22), iVar6 == 0x7d)) &&
           (*(char *)(iVar8 + iVar22 + 0x2faa) != '\0'))) {
      iVar6 = 0;
      iVar8 = iVar22 * 0x1f + (iVar22 / 3) * 0x123 + DAT_0002c7b0;
      do {
        if (fpga_version < 0xe) {
          bVar2 = *(byte *)(iVar8 + iVar6 + 0xb);
        }
        else {
          iVar15 = 0xb;
          iVar21 = 0;
          if (iVar22 - 1U < 0xd) {
            iVar21 = *(int *)(iVar17 + -4);
            iVar15 = *(int *)(iVar18 + -4) * 0x1f + 0xb;
          }
          bVar2 = chain_pic_buf[iVar21][iVar15 + iVar6];
        }
        iVar6 = iVar6 + 1;
        iVar20 = iVar20 + 1;
        lVar7 = strtol(freq_pll_1385[bVar2].freq,(char **)0x0,10);
        dev_sum_freq_1 = (double)(longlong)lVar7 + dev_sum_freq_1;
      } while (iVar6 < (int)(uint)*(byte *)(*piVar1 + iVar22 + 0x2faa));
      iVar22 = iVar22 + 1;
      iVar17 = iVar17 + 4;
      iVar18 = iVar18 + 4;
      if (iVar22 == 0x10) goto LAB_0002c5e4;
    }
    iVar22 = iVar22 + 1;
    iVar17 = iVar17 + 4;
    iVar18 = iVar18 + 4;
  } while (iVar22 != 0x10);
LAB_0002c5e4:
  dev_sum_freq_1 =
       (double)(longlong)(int)(longlong)((dev_sum_freq_1 / (double)(longlong)iVar20) * DAT_0002c790)
       / DAT_0002c790;
  paVar5 = api_add_mhs(paVar5,fan_name,&dev_sum_freq_1,true);
  asic_num_total = 0;
  iVar20 = 0;
  fan_name._0_4_ = *DAT_0002c7a0;
  fan_name._4_4_ = DAT_0002c7a0[1];
  iVar22 = *piVar1;
  do {
    iVar17 = *(int *)(iVar22 + 8);
    iVar22 = iVar22 + 4;
    bVar25 = iVar17 == 1;
    if (bVar25) {
      iVar17 = *piVar1 + iVar20;
    }
    iVar20 = iVar20 + 1;
    if (bVar25) {
      asic_num_total = (ushort)*(byte *)(iVar17 + 0x2faa) + asic_num_total;
    }
  } while (iVar20 != 0x10);
  iVar22 = 0;
  fan_name._8_2_ = (short)DAT_0002c7a0[2];
  paVar5 = api_add_int16(paVar5,fan_name,(uint16_t *)&asic_num_total,true);
  fan_name._0_4_ = *DAT_0002c7a4;
  fan_name._4_4_ = DAT_0002c7a4[1];
  dev_sum_freq_1 = 0.0;
  fan_name._8_3_ = (undefined3)DAT_0002c7a4[2];
  do {
    while ((*(int *)(*piVar1 + (iVar22 + 2) * 4) == 1 &&
           (__nptr = displayed_rate + iVar22, displayed_rate[iVar22][0] != '\0'))) {
      iVar22 = iVar22 + 1;
      dVar26 = strtod(*__nptr,(char **)0x0);
      dev_sum_freq_1 = dev_sum_freq_1 + dVar26;
      if (iVar22 == 0x10) goto LAB_0002c6cc;
    }
    iVar22 = iVar22 + 1;
  } while (iVar22 != 0x10);
LAB_0002c6cc:
  dVar27 = DAT_0002c790;
  dVar26 = DAT_0002c788;
  dev_sum_freq_1 = (double)(longlong)(int)(longlong)(dev_sum_freq_1 * DAT_0002c790) / DAT_0002c790;
  local_87c = api_add_mhs(paVar5,fan_name,&dev_sum_freq_1,true);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    dev_sum_freq_1 = 0.0;
    sprintf(fan_name,DAT_0002c7a8,iVar20);
    iVar17 = *piVar1;
    if (((*(int *)(iVar17 + (iVar22 + 2) * 4) == 1) &&
        (iVar8 = getChainPICMagicNumber(iVar22), piVar23 = DAT_0002c7b4, iVar18 = DAT_0002c7ac,
        iVar8 == 0x7d)) && (*(char *)(iVar17 + iVar22 + 0x2faa) != '\0')) {
      iVar6 = 0;
      iVar8 = 0;
      iVar17 = iVar22 * 0x1f + (iVar22 / 3) * 0x123 + DAT_0002c7b0;
      do {
        if (*piVar23 < 0xe) {
          bVar2 = *(byte *)(iVar17 + iVar8 + 0xb);
        }
        else {
          iVar21 = 0xb;
          new_T9_PLUS_chainIndex_3 = 0;
          if (iVar22 - 1U < 0xd) {
            new_T9_PLUS_chainIndex_3 = *(int *)(local_888 + -4);
            iVar21 = *(int *)(local_884 + -4) * 0x1f + 0xb;
          }
          bVar2 = chain_pic_buf[new_T9_PLUS_chainIndex_3][iVar21 + iVar8];
        }
        iVar8 = iVar8 + 1;
        lVar7 = strtol(*(char **)(iVar18 + (uint)bVar2 * 0x10 + 0x38),(char **)0x0,10);
        piVar3 = (int *)(iVar13 + iVar6);
        iVar6 = iVar6 + 4;
        dev_sum_freq_1 = (double)(longlong)(lVar7 * (0x72 - *piVar3)) + dev_sum_freq_1;
      } while (iVar8 < (int)(uint)*(byte *)(*piVar1 + iVar22 + 0x2faa));
    }
    iVar13 = iVar13 + 0x400;
    dev_sum_freq_1 = (double)(longlong)(int)(longlong)((dev_sum_freq_1 / dVar26) * dVar27) / dVar27;
    local_87c = api_add_mhs(local_87c,fan_name,&dev_sum_freq_1,true);
    local_888 = local_888 + 4;
    local_884 = local_884 + 4;
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  paVar5 = api_add_int(local_87c,DAT_0002cb54,(int *)(*piVar1 + 0x2fc7),true);
  dVar26 = *DAT_0002cb5c + *DAT_0002cb58 + *DAT_0002cb60;
  uVar28 = __aeabi_d2lz(SUB84(dVar26,0),(int)((ulonglong)dVar26 >> 0x20));
  uVar14 = *DAT_0002cb64;
  *DAT_0002cb68 = uVar28;
  uVar12 = (uint)uVar28 + uVar14;
  uVar16 = (int)((ulonglong)uVar28 >> 0x20) +
           ((int)uVar14 >> 0x1f) + (uint)CARRY4((uint)uVar28,uVar14);
  dVar26 = DAT_0002cc28;
  if ((uVar12 | uVar16) != 0) {
    dVar26 = (double)__aeabi_l2d(uVar12,uVar16);
    dVar26 = (double)(longlong)(int)uVar14 / dVar26;
  }
  dev_sum_freq_1 = dVar26;
  paVar5 = api_add_percent(paVar5,DAT_0002cb6c,&dev_sum_freq_1,true);
  paVar5 = api_add_int(paVar5,DAT_0002cb70,(int *)DAT_0002cb64,true);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002cb74,iVar20);
    paVar5 = api_add_uint8(paVar5,fan_name,(uchar *)(*piVar1 + iVar22 + 0x2faa),true);
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002cb78,iVar20);
    paVar5 = api_add_string(paVar5,fan_name,(char *)(*piVar1 + iVar22 * 0x48 + 0x2aba),true);
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002cb7c,iVar20);
    paVar5 = api_add_uint32(paVar5,fan_name,(uint *)(*piVar1 + iVar22 * 4 + 0xa7a),true);
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  iVar22 = 0;
  do {
    iVar20 = iVar22 + 1;
    sprintf(fan_name,DAT_0002cb80,iVar20);
    paVar5 = api_add_string(paVar5,fan_name,displayed_rate[iVar22],true);
    iVar22 = iVar20;
  } while (iVar20 != 0x10);
  iVar20 = *piVar1;
  iVar22 = 1;
  do {
    while( true ) {
      iVar17 = iVar22 + 1;
      iVar13 = iVar22 + -1;
      if (*(int *)(iVar20 + iVar17 * 4) != 1) break;
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
      tmp[11] = '\0';
      tmp[12] = '\0';
      tmp[13] = '\0';
      tmp[14] = '\0';
      tmp[15] = '\0';
      tmp[16] = '\0';
      tmp[17] = '\0';
      tmp[18] = '\0';
      tmp[19] = '\0';
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      sprintf(chain_xtime,DAT_0002cb84,iVar22);
      bVar25 = *(int *)(DAT_0002cb88 + iVar22 * 0x400 + -0x400) != 0;
      if (bVar25) {
        sprintf(tmp,DAT_0002cc3c,0);
        strcat(fan_name,tmp);
      }
      bVar25 = !bVar25;
      if (1 < *(byte *)(*piVar1 + iVar13 + 0x2faa)) {
        iVar22 = 1;
        piVar23 = (int *)(DAT_0002cb88 + iVar13 * 0x400);
        do {
          piVar23 = piVar23 + 1;
          if (*piVar23 != 0) {
            pcVar10 = DAT_0002cb8c;
            if (!bVar25) {
              pcVar10 = DAT_0002cb90;
            }
            sprintf(tmp,pcVar10,iVar22,*piVar23);
            strcat(fan_name,tmp);
            bVar25 = false;
          }
          iVar22 = iVar22 + 1;
        } while (iVar22 < (int)(uint)*(byte *)(*piVar1 + iVar13 + 0x2faa));
      }
      sVar9 = strlen(fan_name);
      *(undefined2 *)(fan_name + sVar9) = s___id____d___method____mining_sub_00045a48._68_2_;
      paVar5 = api_add_string(paVar5,chain_xtime,fan_name,true);
      iVar20 = *piVar1;
      iVar22 = iVar17;
      if (iVar17 == 0x11) goto LAB_0002caa0;
    }
    iVar22 = iVar17;
  } while (iVar17 != 0x11);
LAB_0002caa0:
  iVar22 = DAT_0002cba4;
  iVar17 = 0;
  iVar13 = 1;
  do {
    while (*(int *)(iVar20 + (iVar17 + 2) * 4) != 1) {
      iVar17 = iVar17 + 1;
      iVar13 = iVar13 + 1;
      if (iVar17 == 0x10) goto LAB_0002caea;
    }
    sprintf(tmp,DAT_0002cb94,iVar13);
    iVar20 = iVar17 * 4;
    iVar17 = iVar17 + 1;
    sprintf(fan_name,DAT_0002cb98,*(undefined4 *)(iVar22 + iVar20));
    paVar5 = api_add_string(paVar5,tmp,fan_name,true);
    iVar20 = *piVar1;
    iVar13 = iVar13 + 1;
  } while (iVar17 != 0x10);
LAB_0002caea:
  iVar22 = DAT_0002cba8;
  iVar17 = 0;
  iVar13 = 1;
  do {
    while (*(int *)(iVar20 + (iVar17 + 2) * 4) == 1) {
      sprintf(tmp,DAT_0002cb9c,iVar13);
      pcVar10 = (char *)(iVar17 + iVar22);
      iVar17 = iVar17 + 1;
      if (*pcVar10 == '\0') {
        uVar24 = 0x30;
      }
      else {
        uVar24 = 0x31;
      }
      fan_name[0] = (char)uVar24;
      fan_name[1] = (char)((ushort)uVar24 >> 8);
      paVar5 = api_add_string(paVar5,tmp,fan_name,true);
      iVar20 = *piVar1;
      iVar13 = iVar13 + 1;
      if (iVar17 == 0x10) goto LAB_0002cb44;
    }
    iVar17 = iVar17 + 1;
    iVar13 = iVar13 + 1;
  } while (iVar17 != 0x10);
LAB_0002cb44:
  pcVar10 = (char *)0x0;
  bufsiz = 0;
  puVar19 = DAT_0002cba0;
  do {
    while (piVar1 = (int *)(iVar20 + 8), iVar20 = iVar20 + 4, *piVar1 == 1) {
      uVar14 = *puVar19;
      puVar4 = puVar19 + 1;
      puVar19 = puVar19 + 2;
      bVar25 = CARRY4((uint)pcVar10,uVar14);
      pcVar10 = pcVar10 + uVar14;
      bufsiz = bufsiz + *puVar4 + (uint)bVar25;
      if (puVar19 == DAT_0002cba0 + 0x20) goto LAB_0002cbca;
    }
    puVar19 = puVar19 + 2;
  } while (puVar19 != DAT_0002cba0 + 0x20);
LAB_0002cbca:
  suffix_string_c5(CONCAT44(in_stack_fffff764,7),pcVar10,bufsiz,DAT_0002cc30,true);
  fan_name._0_4_ = *DAT_0002cc34;
  fan_name._4_4_ = DAT_0002cc34[1];
  fan_name._8_4_ = DAT_0002cc34[2];
  paVar5 = api_add_string(paVar5,fan_name,DAT_0002cc38,true);
  return paVar5;
}

