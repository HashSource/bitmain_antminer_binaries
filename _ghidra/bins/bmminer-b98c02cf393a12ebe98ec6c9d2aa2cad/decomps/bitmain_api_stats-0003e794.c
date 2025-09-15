
undefined4 bitmain_api_stats(int param_1)

{
  longlong lVar1;
  uint *puVar2;
  long lVar3;
  char *pcVar4;
  undefined4 uVar5;
  size_t sVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  short sVar13;
  int iVar14;
  byte *pbVar15;
  int iVar16;
  byte *pbVar17;
  int iVar18;
  undefined1 *puVar19;
  bool bVar20;
  undefined4 extraout_s0;
  double dVar21;
  undefined4 extraout_s1;
  byte *local_894;
  byte *local_890;
  byte *local_88c;
  int *local_888;
  int *local_884;
  undefined4 local_874;
  double local_870;
  char local_868 [16];
  double local_858;
  undefined4 local_850;
  undefined4 local_84c;
  undefined4 local_848;
  undefined4 local_840;
  char acStack_83c [4];
  uint local_838;
  undefined4 local_834 [510];
  
  local_874 = 0;
  if (is_certification != '\0') {
    get_api_stats_stub(&local_874,*(undefined4 *)(param_1 + 0x14));
    return local_874;
  }
  local_874 = api_add_uint8(0,"miner_count",dev + 0x53fd,1);
  local_874 = api_add_string(local_874,"frequency",dev + 0x5445,1);
  local_874 = api_add_uint8(local_874,"fan_num",dev + 0x53fe,1);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"fan%d",iVar16);
    local_874 = api_add_uint(local_874,&local_840,dev + (iVar14 + 0x14e2) * 4 + 4,1);
    iVar14 = iVar16;
  } while (iVar16 != 8);
  local_874 = api_add_uint8(local_874,"temp_num",dev + 0x53fd,1);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"temp%d",iVar16);
    local_874 = api_add_int16(local_874,&local_840,dev + (iVar14 + 0x12d) * 8,1);
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"temp2_%d",iVar16);
    local_874 = api_add_int16(local_874,&local_840,iVar14 * 0x40 + 0x56a + dev,1);
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"temp3_%d",iVar16);
    local_874 = api_add_int16(local_874,&local_840,iVar14 * 0x40 + 0x572 + dev,1);
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  iVar14 = 0;
  do {
    local_868[1] = 0;
    iVar18 = 0;
    local_868[0] = '-';
    iVar16 = (int)*(char *)(dev + iVar14 + 0x458);
    iVar12 = 0;
    while( true ) {
      iVar11 = iVar12 + 1;
      if (iVar16 <= iVar12) break;
      iVar16 = sprintf((char *)((int)&local_840 + iVar18),"%d",
                       (int)*(short *)(dev + (iVar14 * 8 + iVar12 + 0xad) * 8));
      iVar18 = iVar18 + iVar16;
      iVar7 = (int)*(char *)(dev + iVar14 + 0x458);
      iVar16 = iVar7;
      if (iVar11 < iVar7) {
        iVar16 = 0x2d;
        pcVar4 = (char *)((int)&local_840 + iVar18);
        pcVar4[0] = '-';
        pcVar4[1] = '\0';
        iVar18 = iVar18 + 1;
      }
      iVar12 = iVar11;
      if (iVar11 < iVar7) {
        iVar16 = (int)*(char *)(dev + iVar14 + 0x458);
      }
    }
    iVar14 = iVar14 + 1;
    sprintf((char *)&local_858,"temp_pcb_%d",iVar14);
    local_874 = api_add_string(local_874,&local_858);
  } while (iVar14 != 0x10);
  iVar14 = 0;
  do {
    local_868[1] = 0;
    iVar18 = 0;
    local_868[0] = '-';
    iVar16 = (int)*(char *)(dev + iVar14 + 0x458);
    iVar12 = 0;
    while( true ) {
      iVar11 = iVar12 + 1;
      if (iVar16 <= iVar12) break;
      iVar16 = sprintf((char *)((int)&local_840 + iVar18),"%d",
                       (int)*(short *)(dev + (iVar14 * 8 + iVar12) * 8 + 0x56a));
      iVar18 = iVar18 + iVar16;
      iVar7 = (int)*(char *)(dev + iVar14 + 0x458);
      iVar16 = iVar7;
      if (iVar11 < iVar7) {
        iVar16 = 0x2d;
        pcVar4 = (char *)((int)&local_840 + iVar18);
        pcVar4[0] = '-';
        pcVar4[1] = '\0';
        iVar18 = iVar18 + 1;
      }
      iVar12 = iVar11;
      if (iVar11 < iVar7) {
        iVar16 = (int)*(char *)(dev + iVar14 + 0x458);
      }
    }
    iVar14 = iVar14 + 1;
    sprintf((char *)&local_858,"temp_chip_%d",iVar14);
    local_874 = api_add_string(local_874,&local_858);
  } while (iVar14 != 0x10);
  local_890 = chain_pic_buf + 2;
  local_894 = chain_pic_buf + 2;
  local_884 = (int *)(iic_mutex + 0x14);
  local_88c = iic_mutex + 0x14;
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    local_858 = 0.0;
    sprintf((char *)&local_840,"freq_avg%d",iVar16);
    if (((*(int *)(dev + (iVar14 + 2) * 4) == 1) && (local_894[-2] == 0x7d)) &&
       (*(char *)(dev + iVar14 + 0x53ec) != '\0')) {
      iVar12 = 0;
      pbVar15 = local_894;
      pbVar17 = local_88c;
      do {
        pbVar17 = (byte *)((int)pbVar17 + 4);
        iVar12 = iVar12 + 1;
        pcVar4 = "200";
        if (*(int *)pbVar17 < 0xf) {
          pcVar4 = *(char **)(freq_pll_1385 + (uint)*pbVar15 * 0x10);
        }
        lVar3 = strtol(pcVar4,(char **)0x0,10);
        local_858 = local_858 + (double)(longlong)lVar3;
        uVar8 = (uint)*(byte *)(dev + iVar14 + 0x53ec);
        pbVar15 = pbVar15 + 1;
      } while (iVar12 < (int)uVar8);
      if (uVar8 != 0) {
        local_858 = local_858 / (double)(longlong)(int)uVar8;
      }
    }
    local_858 = (double)(longlong)(int)(longlong)(local_858 * 100.0) / 100.0;
    local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
    local_88c = (byte *)((int)local_88c + 0x400);
    local_894 = local_894 + 0x80;
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  local_888 = (int *)chain_badcore_num;
  puVar19 = chain_badcore_num;
  iVar14 = 0;
  local_858 = 0.0;
  local_840._0_1_ = 't';
  local_840._1_1_ = 'o';
  local_840._2_1_ = 't';
  local_840._3_1_ = 'a';
  builtin_strncpy(acStack_83c,"l_ra",4);
  local_838._0_1_ = 't';
  local_838._1_1_ = 'e';
  local_838._2_1_ = 'i';
  local_838._3_1_ = 'd';
  local_834[0]._0_1_ = 'e';
  local_834[0]._1_1_ = 'a';
  local_834[0]._2_1_ = 'l';
  local_834[0]._3_1_ = '\0';
  pbVar17 = local_890;
  do {
    if (*(int *)(dev + (iVar14 + 2) * 4) == 1) {
      if (opt_fixed_freq == '\0') {
        local_858 = (double)(longlong)(ideal_total_hash_rate * 1000);
      }
      else if ((pbVar17[-2] == 0x7d) && (*(char *)(dev + iVar14 + 0x53ec) != '\0')) {
        iVar16 = 0;
        piVar9 = (int *)puVar19;
        pbVar15 = pbVar17;
        do {
          iVar16 = iVar16 + 1;
          if (*piVar9 < 0xf) {
            lVar3 = strtol(*(char **)(freq_pll_1385 + (uint)*pbVar15 * 0x10),(char **)0x0,10);
            local_858 = (double)(longlong)(lVar3 * (0x72 - *piVar9)) + local_858;
          }
          piVar9 = piVar9 + 1;
          pbVar15 = pbVar15 + 1;
        } while (iVar16 < (int)(uint)*(byte *)(dev + iVar14 + 0x53ec));
      }
    }
    iVar14 = iVar14 + 1;
    puVar19 = (undefined1 *)((int)puVar19 + 0x400);
    pbVar17 = pbVar17 + 0x80;
  } while (iVar14 != 0x10);
  local_88c = chain_pic_buf + 2;
  iVar16 = 0;
  local_858 = (double)(longlong)(int)(longlong)((local_858 / 1000.0) * 100.0) / 100.0;
  local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
  local_840._0_1_ = 't';
  local_840._1_1_ = 'o';
  local_840._2_1_ = 't';
  local_840._3_1_ = 'a';
  builtin_strncpy(acStack_83c,"l_fr",4);
  local_838._0_1_ = 'e';
  local_838._1_1_ = 'q';
  local_838._2_1_ = 'a';
  local_838._3_1_ = 'v';
  local_834[0] = CONCAT22(local_834[0]._2_2_,0x67);
  local_858 = 0.0;
  iVar14 = 0;
  do {
    iVar12 = iVar14;
    if (((*(int *)(dev + (iVar16 + 2) * 4) == 1) && (local_88c[-2] == 0x7d)) &&
       (pbVar17 = local_88c, piVar9 = local_884, *(char *)(dev + iVar16 + 0x53ec) != '\0')) {
      do {
        iVar12 = iVar12 + 1;
        pcVar4 = "200";
        if (piVar9[1] < 0xf) {
          pcVar4 = *(char **)(freq_pll_1385 + (uint)*pbVar17 * 0x10);
        }
        lVar3 = strtol(pcVar4,(char **)0x0,10);
        local_858 = local_858 + (double)(longlong)lVar3;
        pbVar17 = pbVar17 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar12 - iVar14 < (int)(uint)*(byte *)(dev + iVar16 + 0x53ec));
    }
    iVar16 = iVar16 + 1;
    local_884 = local_884 + 0x100;
    local_88c = local_88c + 0x80;
    iVar14 = iVar12;
  } while (iVar16 != 0x10);
  sVar13 = 0;
  local_858 = (double)(longlong)(int)(longlong)((local_858 / (double)(longlong)iVar12) * 100.0) /
              100.0;
  local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
  dVar21 = local_858;
  piVar9 = (int *)(dev + 4);
  local_840._0_1_ = 't';
  local_840._1_1_ = 'o';
  local_840._2_1_ = 't';
  local_840._3_1_ = 'a';
  builtin_strncpy(acStack_83c,"l_ac",4);
  local_838._0_2_ = 0x6e;
  local_858 = (double)((ulonglong)local_858 & 0xffffffffffff0000);
  bVar20 = false;
  pbVar17 = (byte *)(dev + 0x53ec);
  do {
    piVar9 = piVar9 + 1;
    if (*piVar9 == 1) {
      sVar13 = sVar13 + (ushort)*pbVar17;
      bVar20 = true;
    }
    pbVar17 = pbVar17 + 1;
  } while ((int *)(dev + 0x44) != piVar9);
  if (bVar20) {
    local_858 = (double)CONCAT62(SUB86(dVar21,2),sVar13);
  }
  local_874 = api_add_int16(local_874,&local_840,&local_858,1);
  puVar19 = displayed_rate;
  iVar14 = 0;
  local_858 = 0.0;
  local_840._0_1_ = 't';
  local_840._1_1_ = 'o';
  local_840._2_1_ = 't';
  local_840._3_1_ = 'a';
  builtin_strncpy(acStack_83c,"l_ra",4);
  local_838 = CONCAT13(local_838._3_1_,0x6574);
  do {
    while ((iVar16 = iVar14 + 2, iVar14 = iVar14 + 1, *(int *)(dev + iVar16 * 4) == 1 &&
           (*puVar19 != '\0'))) {
      dVar21 = strtod(puVar19,(char **)0x0);
      puVar19 = puVar19 + 0x20;
      local_858 = local_858 + dVar21;
      if (iVar14 == 0x10) goto LAB_0003ee68;
    }
    puVar19 = puVar19 + 0x20;
  } while (iVar14 != 0x10);
LAB_0003ee68:
  local_858 = (double)(longlong)(int)(longlong)(local_858 * 100.0) / 100.0;
  local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
  local_884 = (int *)displayed_rate;
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    local_858 = 0.0;
    sprintf((char *)&local_840,"chain_rateideal%d",iVar16);
    if ((*(int *)(dev + (iVar14 + 2) * 4) == 1) && (local_890[-2] == 0x7d)) {
      if (opt_economic_mode == '\0') {
        local_858 = (double)(longlong)*(int *)(local_890 + 0x54);
      }
      else {
        if (*(char *)(dev + iVar14 + 0x53ec) != '\0') {
          iVar12 = 0;
          piVar9 = local_888;
          pbVar17 = local_890;
          do {
            iVar12 = iVar12 + 1;
            if (*piVar9 < 0xf) {
              lVar3 = strtol(*(char **)(freq_pll_1385 + (uint)*pbVar17 * 0x10),(char **)0x0,10);
              local_858 = (double)(longlong)(lVar3 * (0x72 - *piVar9)) + local_858;
            }
            piVar9 = piVar9 + 1;
            pbVar17 = pbVar17 + 1;
          } while (iVar12 < (int)(uint)*(byte *)(dev + iVar14 + 0x53ec));
        }
        local_858 = (double)(longlong)(int)(longlong)((local_858 / 1000.0) * 100.0) / 100.0;
      }
      local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
    }
    else {
      local_858 = (double)(longlong)(int)(longlong)((local_858 / 1000.0) * 100.0) / 100.0;
      local_874 = api_add_mhs(local_874,&local_840,&local_858,1);
    }
    local_888 = local_888 + 0x100;
    local_890 = local_890 + 0x80;
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  uVar5 = api_add_int(local_874,"temp_max",dev + 0x5408,1);
  local_874 = uVar5;
  total_diff1 = __fixdfdi((DFtype)CONCAT44(extraout_s1,extraout_s0));
  if ((uint)total_diff1 + hw_errors == 0 &&
      (int)((ulonglong)total_diff1 >> 0x20) +
      ((int)hw_errors >> 0x1f) + (uint)CARRY4((uint)total_diff1,hw_errors) == 0) {
    local_870 = 0.0;
  }
  else {
    lVar1 = (longlong)(int)hw_errors;
    local_870 = (double)__aeabi_l2d();
    local_870 = (double)lVar1 / local_870;
  }
  local_874 = api_add_percent(uVar5,"Device Hardware%",&local_870,1);
  local_874 = api_add_int(local_874,"no_matching_work",&hw_errors,1);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"chain_acn%d",iVar16);
    local_874 = api_add_uint8(local_874,&local_840,dev + iVar14 + 0x53ec,1);
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"chain_acs%d",iVar16);
    local_874 = api_add_string(local_874,&local_840,dev + iVar14 * 0x88 + 0x4afc,1);
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  iVar14 = 0;
  do {
    iVar16 = iVar14 + 1;
    sprintf((char *)&local_840,"chain_hw%d",iVar16);
    local_874 = api_add_uint32(local_874,&local_840,dev + (iVar14 + 0x2ae) * 4 + 4,1);
    iVar14 = iVar16;
  } while (iVar16 != 0x10);
  iVar14 = 0;
  do {
    iVar14 = iVar14 + 1;
    sprintf((char *)&local_840,"chain_rate%d",iVar14);
    local_874 = api_add_string(local_874,&local_840,local_884,1);
    local_884 = (int *)((int)local_884 + 0x20);
  } while (iVar14 != 0x10);
  local_894 = x_time;
  iVar14 = dev;
  iVar16 = 1;
  do {
    iVar12 = iVar16 + 1;
    if (*(int *)(iVar14 + iVar12 * 4) == 1) {
      local_840._0_1_ = '{';
      local_840._1_1_ = '\0';
      local_840._2_1_ = '\0';
      local_840._3_1_ = '\0';
      memset(acStack_83c,0,0x7fc);
      local_858 = 0.0;
      local_850 = 0;
      local_84c = 0;
      local_848 = 0;
      sprintf(local_868,"chain_xtime%d",iVar16);
      iVar14 = *(int *)local_894;
      if (iVar14 != 0) {
        sprintf((char *)&local_858,"X%d=%d",0);
        strcat((char *)&local_840,(char *)&local_858);
      }
      bVar20 = iVar14 == 0;
      if (1 < *(byte *)(dev + iVar16 + -1 + 0x53ec)) {
        iVar14 = 1;
        pbVar17 = local_894;
        do {
          pbVar17 = (byte *)((int)pbVar17 + 4);
          if (*(int *)pbVar17 != 0) {
            pcVar4 = "X%d=%d";
            if (!bVar20) {
              pcVar4 = ",X%d=%d";
            }
            sprintf((char *)&local_858,pcVar4,iVar14,*(int *)pbVar17);
            strcat((char *)&local_840,(char *)&local_858);
            bVar20 = false;
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < (int)(uint)*(byte *)(dev + iVar16 + -1 + 0x53ec));
      }
      sVar6 = strlen((char *)&local_840);
      pcVar4 = (char *)((int)&local_840 + sVar6);
      pcVar4[0] = '}';
      pcVar4[1] = '\0';
      local_874 = api_add_string(local_874,local_868,&local_840,1);
      iVar14 = dev;
    }
    local_894 = (byte *)((int)local_894 + 0x400);
    iVar16 = iVar12;
  } while (iVar12 != 0x11);
  iVar12 = 0;
  iVar16 = 1;
  do {
    while (*(int *)(iVar14 + (iVar12 + 2) * 4) != 1) {
      iVar12 = iVar12 + 1;
      iVar16 = iVar16 + 1;
      if (iVar12 == 0x10) goto LAB_0003f2e2;
    }
    sprintf((char *)&local_858,"chain_offside_%d",iVar16);
    iVar14 = iVar12 * 4;
    iVar12 = iVar12 + 1;
    sprintf((char *)&local_840,"%d",*(undefined4 *)(temp_offside + iVar14));
    local_874 = api_add_string(local_874,&local_858,&local_840,1);
    iVar14 = dev;
    iVar16 = iVar16 + 1;
  } while (iVar12 != 0x10);
LAB_0003f2e2:
  iVar16 = 1;
  puVar19 = isChainAllCoresOpened;
  do {
    while (*(int *)(iVar14 + (int)(puVar19 + -0x80a0ea) * 4) == 1) {
      sprintf((char *)&local_858,"chain_opencore_%d",iVar16);
      if (*puVar19 == '\0') {
        local_840._0_2_ = 0x30;
      }
      else {
        local_840._0_2_ = 0x31;
      }
      puVar19 = puVar19 + 1;
      iVar16 = iVar16 + 1;
      local_874 = api_add_string(local_874,&local_858,&local_840,1);
      iVar14 = dev;
      if ((undefined4 *)puVar19 == &is_first_job) goto LAB_0003f33c;
    }
    puVar19 = puVar19 + 1;
    iVar16 = iVar16 + 1;
  } while ((undefined4 *)puVar19 != &is_first_job);
LAB_0003f33c:
  puVar19 = rate;
  piVar9 = (int *)(iVar14 + 4);
  uVar8 = 0;
  iVar14 = 0;
  do {
    while (piVar9 = piVar9 + 1, *piVar9 == 1) {
      uVar10 = *(uint *)puVar19;
      puVar2 = (uint *)((int)puVar19 + 4);
      puVar19 = (undefined1 *)((int)puVar19 + 8);
      bVar20 = CARRY4(uVar8,uVar10);
      uVar8 = uVar8 + uVar10;
      iVar14 = iVar14 + *puVar2 + (uint)bVar20;
      if (puVar19 == rate_error) goto LAB_0003f366;
    }
    puVar19 = (undefined1 *)((int)puVar19 + 8);
  } while (puVar19 != rate_error);
LAB_0003f366:
  suffix_string_c5_constprop_16(uVar8,iVar14,displayed_hash_rate,0x10,7);
  local_840._0_1_ = 'm';
  local_840._1_1_ = 'i';
  local_840._2_1_ = 'n';
  local_840._3_1_ = 'e';
  builtin_strncpy(acStack_83c,"r_ve",4);
  local_838._0_1_ = 'r';
  local_838._1_1_ = 's';
  local_838._2_1_ = 'i';
  local_838._3_1_ = 'o';
  local_834[0] = CONCAT22(local_834[0]._2_2_,0x6e);
  local_874 = api_add_string(local_874,&local_840,g_miner_version,1);
  local_840._0_1_ = 'm';
  local_840._1_1_ = 'i';
  local_840._2_1_ = 'n';
  local_840._3_1_ = 'e';
  builtin_strncpy(acStack_83c,"r_id",4);
  local_838 = local_838 & 0xffffff00;
  uVar5 = api_add_string(local_874,&local_840,FPGA_ID_str,1);
  return uVar5;
}

