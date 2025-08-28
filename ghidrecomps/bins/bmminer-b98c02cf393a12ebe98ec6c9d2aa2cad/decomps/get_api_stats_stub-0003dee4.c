
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void get_api_stats_stub(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  FILE *pFVar4;
  size_t sVar5;
  uint uVar6;
  char *pcVar7;
  int *piVar8;
  short sVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  int *local_874;
  undefined4 local_860;
  undefined4 uStack_85c;
  char acStack_858 [16];
  undefined8 local_848;
  undefined4 local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_830;
  char acStack_82c [4];
  uint local_828;
  undefined4 local_824 [510];
  
  if (6 < log_level) {
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: get_api_stats_stub enter\n","driver-btm-c5.c",0x428b,
              "get_api_stats_stub");
    }
    fclose(pFVar4);
  }
  iVar12 = dev;
  *(undefined1 *)(dev + 0x53fe) = 2;
  *(undefined4 *)(iVar12 + 0x5445) = 0x303036;
  uVar3 = api_add_uint8(*param_1,"miner_count",iVar12 + 0x53fd,1);
  *param_1 = uVar3;
  uVar3 = api_add_string(uVar3,"frequency",dev + 0x5445,1);
  *param_1 = uVar3;
  uVar3 = api_add_uint8(uVar3,"fan_num",dev + 0x53fe,1);
  *param_1 = uVar3;
  iVar12 = dev;
  *(undefined4 *)(dev + 0x5394) = 0x7e4;
  *(undefined4 *)(iVar12 + 0x53a0) = 0x7f8;
  iVar12 = 0;
  do {
    iVar13 = iVar12 + 1;
    sprintf((char *)&local_830,"fan%d",iVar13);
    uVar3 = api_add_uint(*param_1,&local_830,dev + (iVar12 + 0x14e2) * 4 + 4,1);
    *param_1 = uVar3;
    iVar12 = iVar13;
  } while (iVar13 != 8);
  uVar3 = api_add_uint8(uVar3,"temp_num",dev + 0x53fd,1);
  *param_1 = uVar3;
  iVar12 = 0;
  do {
    iVar14 = iVar12 + 1;
    sprintf((char *)&local_830,"temp%d",iVar14);
    iVar13 = dev;
    uVar3 = *param_1;
    *(undefined2 *)(dev + (iVar12 + 0x12d) * 8) = 0;
    uVar3 = api_add_int16(uVar3,&local_830,iVar13 + (iVar12 + 0x12d) * 8,1);
    *param_1 = uVar3;
    iVar12 = iVar14;
  } while (iVar14 != 0x10);
  iVar12 = 0;
  do {
    iVar14 = iVar12 + 1;
    sprintf((char *)&local_830,"temp2_%d",iVar14);
    uVar3 = *param_1;
    iVar13 = dev + iVar12 * 0x40 + 0x56a;
    *(undefined2 *)(iVar12 * 0x40 + dev + 0x56a) = 0x53;
    uVar3 = api_add_int16(uVar3,&local_830,iVar13,1);
    *param_1 = uVar3;
    iVar12 = iVar14;
  } while (iVar14 != 0x10);
  iVar12 = 0;
  do {
    iVar14 = iVar12 + 1;
    sprintf((char *)&local_830,"temp3_%d",iVar14);
    uVar3 = *param_1;
    iVar13 = dev + iVar12 * 0x40 + 0x572;
    *(undefined2 *)(iVar12 * 0x40 + dev + 0x572) = 0x34;
    uVar3 = api_add_int16(uVar3,&local_830,iVar13,1);
    *param_1 = uVar3;
    iVar12 = iVar14;
  } while (iVar14 != 0x10);
  iVar12 = 0;
  do {
    while( true ) {
      iVar13 = iVar12 + 1;
      local_848 = 0;
      sprintf((char *)&local_830,"freq_avg%d",iVar13);
      if (*(int *)(dev + (iVar12 + 2) * 4) != 1) break;
      local_848 = 0x408498f5c28f5c29;
      uVar3 = api_add_mhs(*param_1,&local_830,&local_848,1);
      *param_1 = uVar3;
      iVar12 = iVar13;
      if (iVar13 == 0x10) goto LAB_0003e0ea;
    }
    local_848 = 0;
    uVar3 = api_add_mhs(*param_1,&local_830,&local_848);
    *param_1 = uVar3;
    iVar12 = iVar13;
  } while (iVar13 != 0x10);
LAB_0003e0ea:
  local_848 = 0x40cbbcae147ae148;
  local_830._0_1_ = 't';
  local_830._1_1_ = 'o';
  local_830._2_1_ = 't';
  local_830._3_1_ = 'a';
  builtin_strncpy(acStack_82c,"l_ra",4);
  local_828._0_1_ = 't';
  local_828._1_1_ = 'e';
  local_828._2_1_ = 'i';
  local_828._3_1_ = 'd';
  local_824[0]._0_1_ = 'e';
  local_824[0]._1_1_ = 'a';
  local_824[0]._2_1_ = 'l';
  local_824[0]._3_1_ = '\0';
  uVar3 = api_add_mhs(*param_1,&local_830,&local_848,1);
  *param_1 = uVar3;
  local_848 = 0x408498f5c28f5c29;
  local_830._0_1_ = 't';
  local_830._1_1_ = 'o';
  local_830._2_1_ = 't';
  local_830._3_1_ = 'a';
  builtin_strncpy(acStack_82c,"l_fr",4);
  local_828._0_1_ = 'e';
  local_828._1_1_ = 'q';
  local_828._2_1_ = 'a';
  local_828._3_1_ = 'v';
  local_824[0] = CONCAT22(local_824[0]._2_2_,0x67);
  uVar3 = api_add_mhs(uVar3,&local_830,&local_848,1);
  *param_1 = uVar3;
  sVar9 = 0;
  pbVar11 = (byte *)(dev + 0x53eb);
  local_830._0_1_ = 't';
  local_830._1_1_ = 'o';
  local_830._2_1_ = 't';
  local_830._3_1_ = 'a';
  builtin_strncpy(acStack_82c,"l_ac",4);
  local_828._0_2_ = 0x6e;
  do {
    pbVar11 = pbVar11 + 1;
    sVar9 = sVar9 + (ushort)*pbVar11;
  } while (pbVar11 != (byte *)(dev + 0x53fb));
  local_848 = CONCAT62((int6)((ulonglong)local_848 >> 0x10),sVar9);
  if (3 < log_level) {
    local_828._0_2_ = 0x6e;
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: asic_num_total = %d\n","driver-btm-c5.c",0x42df,"get_api_stats_stub"
              ,(int)(short)local_848);
    }
    fclose(pFVar4);
    uVar3 = *param_1;
  }
  uVar3 = api_add_int16(uVar3,&local_830,&local_848,1);
  *param_1 = uVar3;
  iVar12 = 0;
  local_830._0_1_ = 't';
  local_830._1_1_ = 'o';
  local_830._2_1_ = 't';
  local_830._3_1_ = 'a';
  builtin_strncpy(acStack_82c,"l_ra",4);
  local_848 = 0x40cbb69ae147ae14;
  local_828 = CONCAT13(local_828._3_1_,0x6574);
  uVar3 = api_add_mhs(uVar3,&local_830,&local_848,1);
  *param_1 = uVar3;
  do {
    iVar12 = iVar12 + 1;
    local_848 = 0x40b27dab851eb852;
    sprintf((char *)&local_830,"chain_rateideal%d",iVar12);
    uVar3 = api_add_mhs(*param_1,&local_830,&local_848,1);
    *param_1 = uVar3;
    iVar13 = dev;
  } while (iVar12 != 0x10);
  *(undefined4 *)(dev + 0x5408) = 0;
  uVar3 = api_add_int(uVar3,"temp_max",iVar13 + 0x5408,1);
  local_860 = 0;
  uStack_85c = 0;
  *param_1 = uVar3;
  hw_errors = 0;
  uVar3 = api_add_percent(uVar3,"Device Hardware%",&local_860,1);
  *param_1 = uVar3;
  uVar3 = api_add_int(uVar3,"no_matching_work",&hw_errors,1);
  *param_1 = uVar3;
  iVar12 = 0;
  do {
    iVar13 = iVar12 + 1;
    sprintf((char *)&local_830,"chain_acn%d",iVar13);
    if (5 < log_level) {
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: chain_asic_num[%d]=%d\n","driver-btm-c5.c",0x4302,
                "get_api_stats_stub",iVar12,(uint)*(byte *)(dev + iVar12 + 0x53ec));
      }
      fclose(pFVar4);
    }
    uVar3 = api_add_uint8(*param_1,&local_830,dev + iVar12 + 0x53ec,1);
    *param_1 = uVar3;
    iVar12 = iVar13;
  } while (iVar13 != 0x10);
  iVar12 = 0;
  do {
    iVar13 = iVar12 + 1;
    sprintf((char *)&local_830,"chain_acs%d",iVar13);
    uVar3 = api_add_string(*param_1,&local_830,dev + iVar12 * 0x88 + 0x4afc,1);
    *param_1 = uVar3;
    iVar12 = iVar13;
  } while (iVar13 != 0x10);
  iVar12 = 0;
  do {
    iVar13 = iVar12 + 1;
    sprintf((char *)&local_830,"chain_hw%d",iVar13);
    uVar3 = *param_1;
    puVar1 = (undefined4 *)(dev + (iVar12 + 0x2ae) * 4 + 4);
    *puVar1 = 0;
    uVar3 = api_add_uint32(uVar3,&local_830,puVar1,1);
    *param_1 = uVar3;
    iVar12 = iVar13;
  } while (iVar13 != 0x10);
  iVar12 = 0;
  pcVar7 = displayed_rate;
  do {
    iVar13 = iVar12 + 1;
    sprintf((char *)&local_830,"chain_rate%d",iVar13);
    snprintf(pcVar7,0x20,"%.2f");
    if (5 < log_level) {
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: %d  %s\n","driver-btm-c5.c",0x431d,"get_api_stats_stub",iVar12,
                pcVar7);
      }
      fclose(pFVar4);
    }
    uVar3 = api_add_string(*param_1,&local_830,pcVar7,1);
    *param_1 = uVar3;
    iVar12 = iVar13;
    pcVar7 = pcVar7 + 0x20;
  } while (iVar13 != 0x10);
  local_874 = (int *)x_time;
  iVar12 = dev;
  iVar13 = 1;
  do {
    iVar14 = iVar13 + 1;
    if (*(int *)(iVar12 + iVar14 * 4) == 1) {
      local_830._0_1_ = '{';
      local_830._1_1_ = '\0';
      local_830._2_1_ = '\0';
      local_830._3_1_ = '\0';
      memset(acStack_82c,0,0x7fc);
      local_848 = 0;
      local_840 = 0;
      local_83c = 0;
      local_838 = 0;
      sprintf(acStack_858,"chain_xtime%d",iVar13);
      iVar12 = *local_874;
      if (iVar12 != 0) {
        sprintf((char *)&local_848,"X%d=%d",0);
        strcat((char *)&local_830,(char *)&local_848);
      }
      bVar16 = iVar12 == 0;
      if (1 < *(byte *)(dev + iVar13 + -1 + 0x53ec)) {
        iVar12 = 1;
        piVar8 = local_874;
        do {
          piVar8 = piVar8 + 1;
          if (*piVar8 != 0) {
            pcVar7 = "X%d=%d";
            if (!bVar16) {
              pcVar7 = ",X%d=%d";
            }
            sprintf((char *)&local_848,pcVar7,iVar12,*piVar8);
            strcat((char *)&local_830,(char *)&local_848);
            bVar16 = false;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)(uint)*(byte *)(dev + iVar13 + -1 + 0x53ec));
      }
      sVar5 = strlen((char *)&local_830);
      pcVar7 = (char *)((int)&local_830 + sVar5);
      pcVar7[0] = '}';
      pcVar7[1] = '\0';
      if (5 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: %s\n","driver-btm-c5.c",0x4345,"get_api_stats_stub",&local_830);
        }
        fclose(pFVar4);
      }
      uVar3 = api_add_string(*param_1,acStack_858,&local_830,1);
      *param_1 = uVar3;
      iVar12 = dev;
    }
    local_874 = local_874 + 0x100;
    iVar13 = iVar14;
  } while (iVar14 != 0x11);
  iVar14 = 1;
  iVar13 = 0;
  do {
    while (*(int *)(iVar12 + (iVar13 + 2) * 4) != 1) {
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + 1;
      if (iVar13 == 0x10) goto LAB_0003e5a2;
    }
    sprintf((char *)&local_848,"chain_offside_%d",iVar14);
    iVar12 = iVar13 * 4;
    iVar13 = iVar13 + 1;
    sprintf((char *)&local_830,"%d",*(undefined4 *)(temp_offside + iVar12));
    uVar3 = api_add_string(*param_1,&local_848,&local_830,1);
    *param_1 = uVar3;
    iVar14 = iVar14 + 1;
    iVar12 = dev;
  } while (iVar13 != 0x10);
LAB_0003e5a2:
  iVar14 = 1;
  iVar13 = 0;
  do {
    while (*(int *)(iVar12 + (iVar13 + 2) * 4) != 1) {
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + 1;
      if (iVar13 == 0x10) goto LAB_0003e5fc;
    }
    sprintf((char *)&local_848,"chain_opencore_%d",iVar14);
    if (isChainAllCoresOpened[iVar13] == '\0') {
      local_830._0_2_ = 0x30;
    }
    else {
      local_830._0_2_ = 0x31;
    }
    iVar13 = iVar13 + 1;
    iVar14 = iVar14 + 1;
    uVar3 = api_add_string(*param_1,&local_848,&local_830,1);
    *param_1 = uVar3;
    iVar12 = dev;
  } while (iVar13 != 0x10);
LAB_0003e5fc:
  puVar10 = rate;
  piVar8 = (int *)(iVar12 + 4);
  uVar6 = 0;
  iVar12 = 0;
  do {
    while (piVar8 = piVar8 + 1, *piVar8 != 1) {
      puVar10 = (undefined1 *)((int)puVar10 + 8);
      if (puVar10 == rate_error) goto LAB_0003e62a;
    }
    uVar15 = *(uint *)puVar10;
    puVar2 = (uint *)((int)puVar10 + 4);
    puVar10 = (undefined1 *)((int)puVar10 + 8);
    bVar16 = CARRY4(uVar6,uVar15);
    uVar6 = uVar6 + uVar15;
    iVar12 = iVar12 + *puVar2 + (uint)bVar16;
  } while (puVar10 != rate_error);
LAB_0003e62a:
  suffix_string_c5_constprop_16(uVar6,iVar12,displayed_hash_rate,0x10,7);
  local_830._0_1_ = 'm';
  local_830._1_1_ = 'i';
  local_830._2_1_ = 'n';
  local_830._3_1_ = 'e';
  builtin_strncpy(acStack_82c,"r_ve",4);
  local_828._0_1_ = 'r';
  local_828._1_1_ = 's';
  local_828._2_1_ = 'i';
  local_828._3_1_ = 'o';
  local_824[0] = CONCAT22(local_824[0]._2_2_,0x6e);
  uVar3 = api_add_string(*param_1,&local_830,g_miner_version,1);
  *param_1 = uVar3;
  local_830._0_1_ = 'm';
  local_830._1_1_ = 'i';
  local_830._2_1_ = 'n';
  local_830._3_1_ = 'e';
  builtin_strncpy(acStack_82c,"r_id",4);
  local_828 = local_828 & 0xffffff00;
  uVar3 = api_add_string(uVar3,&local_830,FPGA_ID_str,1);
  *param_1 = uVar3;
  return;
}

