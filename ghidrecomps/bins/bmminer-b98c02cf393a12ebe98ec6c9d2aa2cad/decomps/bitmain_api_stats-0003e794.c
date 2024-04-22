
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 bitmain_api_stats(int param_1)

{
  longlong lVar1;
  uint *puVar2;
  double dVar3;
  double dVar4;
  long lVar5;
  char *pcVar6;
  undefined4 uVar7;
  size_t sVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  char *pcVar15;
  short sVar16;
  int iVar17;
  byte *pbVar18;
  int iVar19;
  byte *pbVar20;
  char *pcVar21;
  int iVar22;
  undefined1 *__nptr;
  byte *pbVar23;
  bool bVar24;
  double dVar25;
  undefined4 in_stack_fffff760;
  undefined4 in_stack_fffff764;
  int *local_894;
  byte *local_890;
  int *local_88c;
  int *local_888;
  undefined1 *local_884;
  undefined4 local_874;
  double local_870;
  char local_868;
  undefined local_867;
  undefined8 local_858;
  undefined4 local_850;
  undefined4 local_84c;
  undefined4 local_848;
  undefined4 local_840;
  undefined4 uStack_83c;
  undefined4 local_838;
  undefined4 local_834;
  
  local_874 = 0;
  if (is_certification != '\0') {
    get_api_stats_stub(&local_874,*(undefined4 *)(param_1 + 0x14));
    return local_874;
  }
  local_874 = api_add_uint8(0,"miner_count",dev + 0x53fd,1);
  local_874 = api_add_string(local_874,"frequency",dev + 0x5445,1);
  local_874 = api_add_uint8(local_874,"fan_num",dev + 0x53fe,1);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"fan%d",iVar19);
    local_874 = api_add_uint(local_874,&local_840,dev + (iVar17 + 0x14e2) * 4 + 4,1);
    iVar17 = iVar19;
  } while (iVar19 != 8);
  local_874 = api_add_uint8(local_874,"temp_num",dev + 0x53fd,1);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"temp%d",iVar19);
    local_874 = api_add_int16(local_874,&local_840,dev + (iVar17 + 0x12d) * 8,1);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"temp2_%d",iVar19);
    local_874 = api_add_int16(local_874,&local_840,iVar17 * 0x40 + 0x56a + dev,1);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"temp3_%d",iVar19);
    local_874 = api_add_int16(local_874,&local_840,iVar17 * 0x40 + 0x572 + dev,1);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  iVar17 = 0;
  do {
    local_867 = 0;
    iVar22 = 0;
    local_868 = '-';
    uVar9 = (uint)*(char *)(dev + iVar17 + 0x458);
    iVar19 = 0;
    while( true ) {
      iVar13 = iVar19 + 1;
      if ((int)uVar9 <= iVar19) break;
      iVar19 = sprintf((char *)((int)&local_840 + iVar22),"%d",
                       (int)*(short *)(dev + (iVar17 * 8 + iVar19 + 0xad) * 8));
      iVar22 = iVar22 + iVar19;
      uVar12 = (uint)*(char *)(dev + iVar17 + 0x458);
      uVar9 = uVar12;
      if (iVar13 < (int)uVar12) {
        uVar9 = (uint)(ushort)s__s_s__00057b64._4_2_;
        *(undefined2 *)((int)&local_840 + iVar22) = s__s_s__00057b64._4_2_;
        iVar22 = iVar22 + 1;
      }
      iVar19 = iVar13;
      if (iVar13 < (int)uVar12) {
        uVar9 = (uint)*(char *)(dev + iVar17 + 0x458);
      }
    }
    iVar17 = iVar17 + 1;
    sprintf((char *)&local_858,"temp_pcb_%d",iVar17);
    local_874 = api_add_string(local_874,&local_858);
  } while (iVar17 != 0x10);
  iVar17 = 0;
  do {
    local_867 = 0;
    iVar22 = 0;
    local_868 = '-';
    uVar9 = (uint)*(char *)(dev + iVar17 + 0x458);
    iVar19 = 0;
    while( true ) {
      iVar13 = iVar19 + 1;
      if ((int)uVar9 <= iVar19) break;
      iVar19 = sprintf((char *)((int)&local_840 + iVar22),"%d",
                       (int)*(short *)(dev + (iVar17 * 8 + iVar19) * 8 + 0x56a));
      iVar22 = iVar22 + iVar19;
      uVar12 = (uint)*(char *)(dev + iVar17 + 0x458);
      uVar9 = uVar12;
      if (iVar13 < (int)uVar12) {
        uVar9 = (uint)(ushort)s__s_s__00057b64._4_2_;
        *(undefined2 *)((int)&local_840 + iVar22) = s__s_s__00057b64._4_2_;
        iVar22 = iVar22 + 1;
      }
      iVar19 = iVar13;
      if (iVar13 < (int)uVar12) {
        uVar9 = (uint)*(char *)(dev + iVar17 + 0x458);
      }
    }
    iVar17 = iVar17 + 1;
    sprintf((char *)&local_858,"temp_chip_%d",iVar17);
    local_874 = api_add_string(local_874,&local_858);
    pbVar23 = DAT_0003ed60;
    dVar3 = DAT_0003ed50;
    dVar25 = DAT_0003ed48;
  } while (iVar17 != 0x10);
  local_890 = DAT_0003ed60;
  local_894 = (int *)DAT_0003ed60;
  local_884 = (undefined1 *)DAT_0003ed64;
  local_88c = DAT_0003ed64;
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    local_858 = dVar25;
    sprintf((char *)&local_840,"freq_avg%d",iVar19);
    if (((*(int *)(dev + (iVar17 + 2) * 4) == 1) && (*(byte *)((int)local_894 + -2) == 0x7d)) &&
       (*(char *)(dev + iVar17 + 0x53ec) != '\0')) {
      iVar22 = 0;
      pbVar20 = (byte *)local_894;
      piVar10 = local_88c;
      do {
        piVar10 = piVar10 + 1;
        iVar22 = iVar22 + 1;
        pcVar6 = "200";
        if (*piVar10 < 0xf) {
          pcVar6 = *(char **)(freq_pll_1385 + (uint)*pbVar20 * 0x10);
        }
        lVar5 = strtol(pcVar6,(char **)0x0,10);
        local_858 = local_858 + (double)(longlong)lVar5;
        uVar9 = (uint)*(byte *)(dev + iVar17 + 0x53ec);
        pbVar20 = pbVar20 + 1;
      } while (iVar22 < (int)uVar9);
      if (uVar9 != 0) {
        local_858 = local_858 / (double)(longlong)(int)uVar9;
      }
    }
    local_858 = (double)(longlong)(int)(longlong)(local_858 * dVar3) / dVar3;
    local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
    local_88c = local_88c + 0x100;
    local_894 = (int *)((int)local_894 + 0x80);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  local_888 = DAT_0003ed68;
  iVar17 = 0;
  local_858 = 0.0;
  local_840._0_1_ = s_total_rateideal_00064ff8[0];
  local_840._1_1_ = s_total_rateideal_00064ff8[1];
  local_840._2_1_ = s_total_rateideal_00064ff8[2];
  local_840._3_1_ = s_total_rateideal_00064ff8[3];
  uStack_83c._0_1_ = s_total_rateideal_00064ff8[4];
  uStack_83c._1_1_ = s_total_rateideal_00064ff8[5];
  uStack_83c._2_1_ = s_total_rateideal_00064ff8[6];
  uStack_83c._3_1_ = s_total_rateideal_00064ff8[7];
  local_838._0_1_ = s_total_rateideal_00064ff8[8];
  local_838._1_1_ = s_total_rateideal_00064ff8[9];
  local_838._2_1_ = s_total_rateideal_00064ff8[10];
  local_838._3_1_ = s_total_rateideal_00064ff8[11];
  local_834._0_1_ = s_total_rateideal_00064ff8[12];
  local_834._1_1_ = s_total_rateideal_00064ff8[13];
  local_834._2_1_ = s_total_rateideal_00064ff8[14];
  local_834._3_1_ = s_total_rateideal_00064ff8[15];
  pbVar20 = pbVar23;
  piVar10 = DAT_0003ed68;
  do {
    if (*(int *)(dev + (iVar17 + 2) * 4) == 1) {
      if (opt_fixed_freq == '\0') {
        local_858 = (double)(longlong)(ideal_total_hash_rate * 1000);
      }
      else if ((pbVar20[-2] == 0x7d) && (*(char *)(dev + iVar17 + 0x53ec) != '\0')) {
        iVar19 = 0;
        piVar14 = piVar10;
        pbVar18 = pbVar20;
        do {
          iVar19 = iVar19 + 1;
          if (*piVar14 < 0xf) {
            lVar5 = strtol(*(char **)(freq_pll_1385 + (uint)*pbVar18 * 0x10),(char **)0x0,10);
            local_858 = (double)(longlong)(lVar5 * (0x72 - *piVar14)) + local_858;
          }
          piVar14 = piVar14 + 1;
          pbVar18 = pbVar18 + 1;
        } while (iVar19 < (int)(uint)*(byte *)(dev + iVar17 + 0x53ec));
      }
    }
    iVar17 = iVar17 + 1;
    piVar10 = piVar10 + 0x100;
    pbVar20 = pbVar20 + 0x80;
  } while (iVar17 != 0x10);
  local_88c = (int *)pbVar23;
  iVar19 = 0;
  local_858 = (double)(longlong)(int)(longlong)((local_858 / DAT_0003ed58) * DAT_0003ed50) /
              DAT_0003ed50;
  local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
  local_840._0_1_ = s_total_freqavg_00065008[0];
  local_840._1_1_ = s_total_freqavg_00065008[1];
  local_840._2_1_ = s_total_freqavg_00065008[2];
  local_840._3_1_ = s_total_freqavg_00065008[3];
  uStack_83c._0_1_ = s_total_freqavg_00065008[4];
  uStack_83c._1_1_ = s_total_freqavg_00065008[5];
  uStack_83c._2_1_ = s_total_freqavg_00065008[6];
  uStack_83c._3_1_ = s_total_freqavg_00065008[7];
  local_838._0_1_ = s_total_freqavg_00065008[8];
  local_838._1_1_ = s_total_freqavg_00065008[9];
  local_838._2_1_ = s_total_freqavg_00065008[10];
  local_838._3_1_ = s_total_freqavg_00065008[11];
  local_834 = CONCAT22(local_834._2_2_,(short)ram0x00065014);
  local_858 = 0.0;
  iVar17 = 0;
  do {
    iVar22 = iVar17;
    if (((*(int *)(dev + (iVar19 + 2) * 4) == 1) && (*(byte *)((int)local_88c + -2) == 0x7d)) &&
       (pbVar23 = (byte *)local_88c, piVar10 = (int *)local_884,
       *(char *)(dev + iVar19 + 0x53ec) != '\0')) {
      do {
        iVar22 = iVar22 + 1;
        pcVar6 = "200";
        if (piVar10[1] < 0xf) {
          pcVar6 = *(char **)(freq_pll_1385 + (uint)*pbVar23 * 0x10);
        }
        lVar5 = strtol(pcVar6,(char **)0x0,10);
        local_858 = local_858 + (double)(longlong)lVar5;
        pbVar23 = pbVar23 + 1;
        piVar10 = piVar10 + 1;
      } while (iVar22 - iVar17 < (int)(uint)*(byte *)(dev + iVar19 + 0x53ec));
    }
    iVar19 = iVar19 + 1;
    local_884 = (undefined1 *)((int)local_884 + 0x400);
    local_88c = (int *)((int)local_88c + 0x80);
    iVar17 = iVar22;
  } while (iVar19 != 0x10);
  sVar16 = 0;
  local_858 = (double)(longlong)
                      (int)(longlong)((local_858 / (double)(longlong)iVar22) * DAT_0003ef60) /
              DAT_0003ef60;
  local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
  dVar25 = local_858;
  piVar10 = (int *)(dev + 4);
  local_840._0_1_ = s_total_acn_00065018[0];
  local_840._1_1_ = s_total_acn_00065018[1];
  local_840._2_1_ = s_total_acn_00065018[2];
  local_840._3_1_ = s_total_acn_00065018[3];
  uStack_83c._0_1_ = s_total_acn_00065018[4];
  uStack_83c._1_1_ = s_total_acn_00065018[5];
  uStack_83c._2_1_ = s_total_acn_00065018[6];
  uStack_83c._3_1_ = s_total_acn_00065018[7];
  local_858 = (double)((ulonglong)local_858 & 0xffffffffffff0000);
  bVar24 = false;
  pbVar23 = (byte *)(dev + 0x53ec);
  do {
    piVar10 = piVar10 + 1;
    if (*piVar10 == 1) {
      sVar16 = sVar16 + (ushort)*pbVar23;
      bVar24 = true;
    }
    pbVar23 = pbVar23 + 1;
  } while ((int *)(dev + 0x44) != piVar10);
  if (bVar24) {
    local_858 = (double)CONCAT62(SUB86(dVar25,2),sVar16);
  }
  local_838._0_2_ = (short)ram0x00065020;
  local_874 = api_add_int16(local_874,&local_840,&local_858,1);
  __nptr = displayed_rate;
  iVar17 = 0;
  local_858 = 0.0;
  local_840._0_1_ = s_total_rate_00065044[0];
  local_840._1_1_ = s_total_rate_00065044[1];
  local_840._2_1_ = s_total_rate_00065044[2];
  local_840._3_1_ = s_total_rate_00065044[3];
  uStack_83c._0_1_ = s_total_rate_00065044[4];
  uStack_83c._1_1_ = s_total_rate_00065044[5];
  uStack_83c._2_1_ = s_total_rate_00065044[6];
  uStack_83c._3_1_ = s_total_rate_00065044[7];
  do {
    while ((iVar19 = iVar17 + 2, iVar17 = iVar17 + 1, *(int *)(dev + iVar19 * 4) != 1 ||
           (*__nptr == '\0'))) {
      __nptr = __nptr + 0x20;
      if (iVar17 == 0x10) goto LAB_0003ee68;
    }
    dVar25 = strtod(__nptr,(char **)0x0);
    __nptr = __nptr + 0x20;
    local_858 = local_858 + dVar25;
  } while (iVar17 != 0x10);
LAB_0003ee68:
  dVar4 = DAT_0003ef70;
  dVar3 = DAT_0003ef68;
  dVar25 = DAT_0003ef60;
  local_858 = (double)(longlong)(int)(longlong)(local_858 * DAT_0003ef60) / DAT_0003ef60;
  local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
  local_884 = displayed_rate;
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    local_858 = dVar4;
    sprintf((char *)&local_840,"chain_rateideal%d",iVar19);
    if ((*(int *)(dev + (iVar17 + 2) * 4) == 1) && (local_890[-2] == 0x7d)) {
      if (opt_economic_mode == '\0') {
        local_858 = (double)(longlong)*(int *)(local_890 + 0x54);
      }
      else {
        if (*(char *)(dev + iVar17 + 0x53ec) != '\0') {
          iVar22 = 0;
          piVar10 = local_888;
          pbVar23 = local_890;
          do {
            iVar22 = iVar22 + 1;
            if (*piVar10 < 0xf) {
              lVar5 = strtol(*(char **)(freq_pll_1385 + (uint)*pbVar23 * 0x10),(char **)0x0,10);
              local_858 = (double)(longlong)(lVar5 * (0x72 - *piVar10)) + local_858;
            }
            piVar10 = piVar10 + 1;
            pbVar23 = pbVar23 + 1;
          } while (iVar22 < (int)(uint)*(byte *)(dev + iVar17 + 0x53ec));
        }
        local_858 = (double)(longlong)(int)(longlong)((local_858 / dVar3) * dVar25) / dVar25;
      }
      local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
    }
    else {
      local_858 = (double)(longlong)(int)(longlong)((local_858 / dVar3) * dVar25) / dVar25;
      local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
    }
    local_888 = local_888 + 0x100;
    local_890 = local_890 + 0x80;
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  uVar7 = api_add_int(local_874,"temp_max",dev + 0x5408,1);
  local_874 = uVar7;
  total_diff1 = __fixdfdi((DFtype)CONCAT44(in_stack_fffff764,in_stack_fffff760));
  local_870 = DAT_0003ef70;
  if (((uint)total_diff1 + hw_errors |
      (int)((ulonglong)total_diff1 >> 0x20) +
      ((int)hw_errors >> 0x1f) + (uint)CARRY4((uint)total_diff1,hw_errors)) != 0) {
    lVar1 = (longlong)(int)hw_errors;
    dVar25 = (double)__aeabi_l2d();
    local_870 = (double)lVar1 / dVar25;
  }
  local_874 = api_add_percent(uVar7,"Device Hardware%",&local_870,1);
  local_874 = api_add_int(local_874,"no_matching_work",&hw_errors,1);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"chain_acn%d",iVar19);
    local_874 = api_add_uint8(local_874,&local_840,dev + iVar17 + 0x53ec,1);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"chain_acs%d",iVar19);
    local_874 = api_add_string(local_874,&local_840,dev + iVar17 * 0x88 + 0x4afc,1);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  iVar17 = 0;
  do {
    iVar19 = iVar17 + 1;
    sprintf((char *)&local_840,"chain_hw%d",iVar19);
    local_874 = api_add_uint32(local_874,&local_840,dev + (iVar17 + 0x2ae) * 4 + 4,1);
    iVar17 = iVar19;
  } while (iVar19 != 0x10);
  iVar17 = 0;
  do {
    iVar17 = iVar17 + 1;
    sprintf((char *)&local_840,"chain_rate%d",iVar17);
    local_874 = api_add_string(local_874,&local_840,local_884,1);
    local_884 = local_884 + 0x20;
  } while (iVar17 != 0x10);
  local_894 = DAT_0003f410;
  iVar17 = dev;
  iVar19 = 1;
  do {
    iVar22 = iVar19 + 1;
    if (*(int *)(iVar17 + iVar22 * 4) == 1) {
      local_840._0_1_ = '{';
      local_840._1_1_ = '\0';
      local_840._2_1_ = '\0';
      local_840._3_1_ = '\0';
      memset(&uStack_83c,0,0x7fc);
      local_858 = 0.0;
      local_850 = 0;
      local_84c = 0;
      local_848 = 0;
      sprintf(&local_868,"chain_xtime%d",iVar19);
      iVar17 = *local_894;
      if (iVar17 != 0) {
        sprintf((char *)&local_858,"X%d=%d",0);
        strcat((char *)&local_840,(char *)&local_858);
      }
      bVar24 = iVar17 == 0;
      if (1 < *(byte *)(dev + iVar19 + -1 + 0x53ec)) {
        iVar17 = 1;
        piVar10 = local_894;
        do {
          piVar10 = piVar10 + 1;
          if (*piVar10 != 0) {
            pcVar6 = "X%d=%d";
            if (!bVar24) {
              pcVar6 = ",X%d=%d";
            }
            sprintf((char *)&local_858,pcVar6,iVar17,*piVar10);
            strcat((char *)&local_840,(char *)&local_858);
            bVar24 = false;
          }
          iVar17 = iVar17 + 1;
        } while (iVar17 < (int)(uint)*(byte *)(dev + iVar19 + -1 + 0x53ec));
      }
      sVar8 = strlen((char *)&local_840);
      *(undefined2 *)((int)&local_840 + sVar8) = s___id____d___method____mining_sub_00067a84._68_2_;
      local_874 = api_add_string(local_874,&local_868,&local_840,1);
      iVar17 = dev;
    }
    iVar13 = DAT_0003f41c;
    local_894 = local_894 + 0x100;
    iVar19 = iVar22;
  } while (iVar22 != 0x11);
  iVar22 = 0;
  iVar19 = 1;
  do {
    while (*(int *)(iVar17 + (iVar22 + 2) * 4) == 1) {
      sprintf((char *)&local_858,"chain_offside_%d",iVar19);
      iVar17 = iVar22 * 4;
      iVar22 = iVar22 + 1;
      sprintf((char *)&local_840,"%d",*(undefined4 *)(iVar13 + iVar17));
      local_874 = api_add_string(local_874,&local_858,&local_840,1);
      iVar17 = dev;
      iVar19 = iVar19 + 1;
      if (iVar22 == 0x10) goto LAB_0003f2e2;
    }
    iVar22 = iVar22 + 1;
    iVar19 = iVar19 + 1;
  } while (iVar22 != 0x10);
LAB_0003f2e2:
  pcVar6 = DAT_0003f414;
  iVar19 = 1;
  pcVar21 = DAT_0003f414 + 0x10;
  pcVar15 = DAT_0003f414;
  do {
    while (*(int *)(iVar17 + (int)(pcVar15 + (2 - (int)pcVar6)) * 4) == 1) {
      sprintf((char *)&local_858,"chain_opencore_%d",iVar19);
      if (*pcVar15 == '\0') {
        local_840._0_2_ = 0x30;
      }
      else {
        local_840._0_2_ = 0x31;
      }
      pcVar15 = pcVar15 + 1;
      iVar19 = iVar19 + 1;
      local_874 = api_add_string(local_874,&local_858,&local_840,1);
      iVar17 = dev;
      if (pcVar21 == pcVar15) goto LAB_0003f33c;
    }
    pcVar15 = pcVar15 + 1;
    iVar19 = iVar19 + 1;
  } while (pcVar21 != pcVar15);
LAB_0003f33c:
  piVar10 = (int *)(iVar17 + 4);
  uVar9 = 0;
  iVar17 = 0;
  puVar11 = DAT_0003f418;
  do {
    while (piVar10 = piVar10 + 1, *piVar10 != 1) {
      puVar11 = puVar11 + 2;
      if (DAT_0003f418 + 0x20 == puVar11) goto LAB_0003f366;
    }
    uVar12 = *puVar11;
    puVar2 = puVar11 + 1;
    puVar11 = puVar11 + 2;
    bVar24 = CARRY4(uVar9,uVar12);
    uVar9 = uVar9 + uVar12;
    iVar17 = iVar17 + *puVar2 + (uint)bVar24;
  } while (DAT_0003f418 + 0x20 != puVar11);
LAB_0003f366:
  suffix_string_c5_constprop_16(uVar9,iVar17,displayed_hash_rate,0x10,7);
  local_840._0_1_ = s_miner_version_00065138[0];
  local_840._1_1_ = s_miner_version_00065138[1];
  local_840._2_1_ = s_miner_version_00065138[2];
  local_840._3_1_ = s_miner_version_00065138[3];
  uStack_83c._0_1_ = s_miner_version_00065138[4];
  uStack_83c._1_1_ = s_miner_version_00065138[5];
  uStack_83c._2_1_ = s_miner_version_00065138[6];
  uStack_83c._3_1_ = s_miner_version_00065138[7];
  local_838._0_1_ = s_miner_version_00065138[8];
  local_838._1_1_ = s_miner_version_00065138[9];
  local_838._2_1_ = s_miner_version_00065138[10];
  local_838._3_1_ = s_miner_version_00065138[11];
  local_834 = CONCAT22(local_834._2_2_,(short)ram0x00065144);
  local_874 = api_add_string(local_874,&local_840,g_miner_version,1);
  local_840._0_1_ = s_miner_id_00065148[0];
  local_840._1_1_ = s_miner_id_00065148[1];
  local_840._2_1_ = s_miner_id_00065148[2];
  local_840._3_1_ = s_miner_id_00065148[3];
  uStack_83c._0_1_ = s_miner_id_00065148[4];
  uStack_83c._1_1_ = s_miner_id_00065148[5];
  uStack_83c._2_1_ = s_miner_id_00065148[6];
  uStack_83c._3_1_ = s_miner_id_00065148[7];
  local_838 = CONCAT31(local_838._1_3_,(char)ram0x00065150);
  uVar7 = api_add_string(local_874,&local_840,FPGA_ID_str,1);
  return uVar7;
}

