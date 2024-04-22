
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void get_api_stats_stub(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  FILE *pFVar7;
  size_t sVar8;
  uint uVar9;
  char *pcVar10;
  int *piVar11;
  short sVar12;
  uint *puVar13;
  byte *pbVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  bool bVar20;
  int *local_874;
  undefined4 local_860;
  undefined4 uStack_85c;
  char acStack_858 [16];
  undefined8 local_848;
  undefined4 local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_830;
  undefined4 uStack_82c;
  undefined4 local_828;
  undefined4 local_824;
  
  if (6 < log_level) {
    pFVar7 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar7 != (FILE *)0x0) {
      fprintf(pFVar7,"%s:%d:%s: get_api_stats_stub enter\n","driver-btm-c5.c",0x428b,DAT_0003e790);
    }
    fclose(pFVar7);
  }
  iVar15 = dev;
  uVar5 = DAT_00064fa0;
  *(undefined *)(dev + 0x53fe) = 2;
  *(undefined4 *)(iVar15 + 0x5445) = uVar5;
  uVar5 = api_add_uint8(*param_1,"miner_count",iVar15 + 0x53fd,1);
  *param_1 = uVar5;
  uVar5 = api_add_string(uVar5,"frequency",dev + 0x5445,1);
  *param_1 = uVar5;
  uVar5 = api_add_uint8(uVar5,"fan_num",dev + 0x53fe,1);
  *param_1 = uVar5;
  iVar15 = dev;
  *(undefined4 *)(dev + 0x5394) = 0x7e4;
  *(undefined4 *)(iVar15 + 0x53a0) = 0x7f8;
  iVar15 = 0;
  do {
    iVar16 = iVar15 + 1;
    sprintf((char *)&local_830,"fan%d",iVar16);
    uVar5 = api_add_uint(*param_1,&local_830,dev + (iVar15 + 0x14e2) * 4 + 4,1);
    *param_1 = uVar5;
    iVar15 = iVar16;
  } while (iVar16 != 8);
  uVar5 = api_add_uint8(uVar5,"temp_num",dev + 0x53fd,1);
  *param_1 = uVar5;
  iVar15 = 0;
  do {
    iVar17 = iVar15 + 1;
    sprintf((char *)&local_830,"temp%d",iVar17);
    iVar16 = dev;
    uVar5 = *param_1;
    *(undefined2 *)(dev + (iVar15 + 0x12d) * 8) = 0;
    uVar5 = api_add_int16(uVar5,&local_830,iVar16 + (iVar15 + 0x12d) * 8,1);
    *param_1 = uVar5;
    iVar15 = iVar17;
  } while (iVar17 != 0x10);
  iVar15 = 0;
  do {
    iVar17 = iVar15 + 1;
    sprintf((char *)&local_830,"temp2_%d",iVar17);
    uVar5 = *param_1;
    iVar16 = dev + iVar15 * 0x40 + 0x56a;
    *(undefined2 *)(iVar15 * 0x40 + dev + 0x56a) = 0x53;
    uVar5 = api_add_int16(uVar5,&local_830,iVar16,1);
    *param_1 = uVar5;
    iVar15 = iVar17;
  } while (iVar17 != 0x10);
  iVar15 = 0;
  do {
    iVar17 = iVar15 + 1;
    sprintf((char *)&local_830,"temp3_%d",iVar17);
    uVar5 = *param_1;
    iVar16 = dev + iVar15 * 0x40 + 0x572;
    *(undefined2 *)(iVar15 * 0x40 + dev + 0x572) = 0x34;
    uVar5 = api_add_int16(uVar5,&local_830,iVar16,1);
    *param_1 = uVar5;
    iVar15 = iVar17;
  } while (iVar17 != 0x10);
  uVar3 = CONCAT44(DAT_0003e398._4_4_,(undefined4)DAT_0003e398);
  iVar15 = 0;
  do {
    while( true ) {
      iVar16 = iVar15 + 1;
      local_848 = 0;
      sprintf((char *)&local_830,"freq_avg%d",iVar16);
      if (*(int *)(dev + (iVar15 + 2) * 4) != 1) break;
      local_848 = uVar3;
      uVar5 = api_add_mhs(*param_1,&local_830,&local_848,1);
      *param_1 = uVar5;
      iVar15 = iVar16;
      if (iVar16 == 0x10) goto LAB_0003e0ea;
    }
    local_848 = 0;
    uVar5 = api_add_mhs(*param_1,&local_830,&local_848);
    *param_1 = uVar5;
    iVar15 = iVar16;
  } while (iVar16 != 0x10);
LAB_0003e0ea:
  uVar4 = DAT_0003e398._4_4_;
  uVar5 = (undefined4)DAT_0003e398;
  local_848 = CONCAT44(DAT_0003e3b4,DAT_0003e3b0);
  local_830._0_1_ = s_total_rateideal_00064ff8[0];
  local_830._1_1_ = s_total_rateideal_00064ff8[1];
  local_830._2_1_ = s_total_rateideal_00064ff8[2];
  local_830._3_1_ = s_total_rateideal_00064ff8[3];
  uStack_82c._0_1_ = s_total_rateideal_00064ff8[4];
  uStack_82c._1_1_ = s_total_rateideal_00064ff8[5];
  uStack_82c._2_1_ = s_total_rateideal_00064ff8[6];
  uStack_82c._3_1_ = s_total_rateideal_00064ff8[7];
  local_828._0_1_ = s_total_rateideal_00064ff8[8];
  local_828._1_1_ = s_total_rateideal_00064ff8[9];
  local_828._2_1_ = s_total_rateideal_00064ff8[10];
  local_828._3_1_ = s_total_rateideal_00064ff8[11];
  local_824._0_1_ = s_total_rateideal_00064ff8[12];
  local_824._1_1_ = s_total_rateideal_00064ff8[13];
  local_824._2_1_ = s_total_rateideal_00064ff8[14];
  local_824._3_1_ = s_total_rateideal_00064ff8[15];
  uVar6 = api_add_mhs(*param_1,&local_830,&local_848,1);
  *param_1 = uVar6;
  local_848 = CONCAT44(uVar4,uVar5);
  local_830._0_1_ = s_total_freqavg_00065008[0];
  local_830._1_1_ = s_total_freqavg_00065008[1];
  local_830._2_1_ = s_total_freqavg_00065008[2];
  local_830._3_1_ = s_total_freqavg_00065008[3];
  uStack_82c._0_1_ = s_total_freqavg_00065008[4];
  uStack_82c._1_1_ = s_total_freqavg_00065008[5];
  uStack_82c._2_1_ = s_total_freqavg_00065008[6];
  uStack_82c._3_1_ = s_total_freqavg_00065008[7];
  local_828._0_1_ = s_total_freqavg_00065008[8];
  local_828._1_1_ = s_total_freqavg_00065008[9];
  local_828._2_1_ = s_total_freqavg_00065008[10];
  local_828._3_1_ = s_total_freqavg_00065008[11];
  local_824 = CONCAT22(local_824._2_2_,(short)ram0x00065014);
  uVar5 = api_add_mhs(uVar6,&local_830,&local_848,1);
  *param_1 = uVar5;
  sVar12 = 0;
  pbVar14 = (byte *)(dev + 0x53eb);
  local_830._0_1_ = s_total_acn_00065018[0];
  local_830._1_1_ = s_total_acn_00065018[1];
  local_830._2_1_ = s_total_acn_00065018[2];
  local_830._3_1_ = s_total_acn_00065018[3];
  uStack_82c._0_1_ = s_total_acn_00065018[4];
  uStack_82c._1_1_ = s_total_acn_00065018[5];
  uStack_82c._2_1_ = s_total_acn_00065018[6];
  uStack_82c._3_1_ = s_total_acn_00065018[7];
  do {
    pbVar14 = pbVar14 + 1;
    sVar12 = sVar12 + (ushort)*pbVar14;
  } while (pbVar14 != (byte *)(dev + 0x53fb));
  local_848 = CONCAT62((int6)((ulonglong)local_848 >> 0x10),sVar12);
  local_828._0_2_ = (short)ram0x00065020;
  if (3 < log_level) {
    pFVar7 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar7 != (FILE *)0x0) {
      fprintf(pFVar7,"%s:%d:%s: asic_num_total = %d\n","driver-btm-c5.c",0x42df,DAT_0003e790,
              (int)(short)local_848);
    }
    fclose(pFVar7);
    uVar5 = *param_1;
  }
  uVar6 = api_add_int16(uVar5,&local_830,&local_848,1);
  *param_1 = uVar6;
  uVar4 = DAT_0003e3bc;
  uVar5 = DAT_0003e3b8;
  iVar15 = 0;
  local_830._0_1_ = s_total_rate_00065044[0];
  local_830._1_1_ = s_total_rate_00065044[1];
  local_830._2_1_ = s_total_rate_00065044[2];
  local_830._3_1_ = s_total_rate_00065044[3];
  uStack_82c._0_1_ = s_total_rate_00065044[4];
  uStack_82c._1_1_ = s_total_rate_00065044[5];
  uStack_82c._2_1_ = s_total_rate_00065044[6];
  uStack_82c._3_1_ = s_total_rate_00065044[7];
  local_848 = DAT_0003e3a0;
  uVar6 = api_add_mhs(uVar6,&local_830,&local_848,1);
  *param_1 = uVar6;
  do {
    iVar15 = iVar15 + 1;
    local_848 = CONCAT44(uVar4,uVar5);
    sprintf((char *)&local_830,"chain_rateideal%d",iVar15);
    uVar6 = api_add_mhs(*param_1,&local_830,&local_848,1);
    *param_1 = uVar6;
    iVar16 = dev;
  } while (iVar15 != 0x10);
  *(undefined4 *)(dev + 0x5408) = 0;
  uVar5 = api_add_int(uVar6,"temp_max",iVar16 + 0x5408,1);
  local_860 = 0;
  uStack_85c = 0;
  *param_1 = uVar5;
  hw_errors = 0;
  uVar5 = api_add_percent(uVar5,"Device Hardware%",&local_860,1);
  *param_1 = uVar5;
  uVar5 = api_add_int(uVar5,"no_matching_work",&hw_errors,1);
  *param_1 = uVar5;
  iVar15 = 0;
  do {
    iVar16 = iVar15 + 1;
    sprintf((char *)&local_830,"chain_acn%d",iVar16);
    if (5 < log_level) {
      pFVar7 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar7 != (FILE *)0x0) {
        fprintf(pFVar7,"%s:%d:%s: chain_asic_num[%d]=%d\n","driver-btm-c5.c",0x4302,DAT_0003e3c0,
                iVar15,(uint)*(byte *)(dev + iVar15 + 0x53ec));
      }
      fclose(pFVar7);
    }
    uVar5 = api_add_uint8(*param_1,&local_830,dev + iVar15 + 0x53ec,1);
    *param_1 = uVar5;
    iVar15 = iVar16;
  } while (iVar16 != 0x10);
  iVar15 = 0;
  do {
    iVar16 = iVar15 + 1;
    sprintf((char *)&local_830,"chain_acs%d",iVar16);
    uVar5 = api_add_string(*param_1,&local_830,dev + iVar15 * 0x88 + 0x4afc,1);
    *param_1 = uVar5;
    iVar15 = iVar16;
  } while (iVar16 != 0x10);
  iVar15 = 0;
  do {
    iVar16 = iVar15 + 1;
    sprintf((char *)&local_830,"chain_hw%d",iVar16);
    uVar5 = *param_1;
    puVar1 = (undefined4 *)(dev + (iVar15 + 0x2ae) * 4 + 4);
    *puVar1 = 0;
    uVar5 = api_add_uint32(uVar5,&local_830,puVar1,1);
    *param_1 = uVar5;
    iVar15 = iVar16;
  } while (iVar16 != 0x10);
  iVar15 = 0;
  pcVar10 = displayed_rate;
  do {
    iVar16 = iVar15 + 1;
    sprintf((char *)&local_830,"chain_rate%d",iVar16);
    snprintf(pcVar10,0x20,"%.2f");
    if (5 < log_level) {
      pFVar7 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar7 != (FILE *)0x0) {
        fprintf(pFVar7,"%s:%d:%s: %d  %s\n","driver-btm-c5.c",0x431d,DAT_0003e6f0,iVar15,pcVar10);
      }
      fclose(pFVar7);
    }
    uVar5 = api_add_string(*param_1,&local_830,pcVar10,1);
    *param_1 = uVar5;
    iVar15 = iVar16;
    pcVar10 = pcVar10 + 0x20;
  } while (iVar16 != 0x10);
  local_874 = DAT_0003e6f4;
  iVar15 = dev;
  iVar16 = 1;
  do {
    iVar17 = iVar16 + 1;
    if (*(int *)(iVar15 + iVar17 * 4) == 1) {
      local_830._0_1_ = '{';
      local_830._1_1_ = '\0';
      local_830._2_1_ = '\0';
      local_830._3_1_ = '\0';
      memset(&uStack_82c,0,0x7fc);
      local_848 = 0;
      local_840 = 0;
      local_83c = 0;
      local_838 = 0;
      sprintf(acStack_858,"chain_xtime%d",iVar16);
      iVar15 = *local_874;
      if (iVar15 != 0) {
        sprintf((char *)&local_848,"X%d=%d",0);
        strcat((char *)&local_830,(char *)&local_848);
      }
      bVar20 = iVar15 == 0;
      if (1 < *(byte *)(dev + iVar16 + -1 + 0x53ec)) {
        iVar15 = 1;
        piVar11 = local_874;
        do {
          piVar11 = piVar11 + 1;
          if (*piVar11 != 0) {
            pcVar10 = "X%d=%d";
            if (!bVar20) {
              pcVar10 = ",X%d=%d";
            }
            sprintf((char *)&local_848,pcVar10,iVar15,*piVar11);
            strcat((char *)&local_830,(char *)&local_848);
            bVar20 = false;
          }
          iVar15 = iVar15 + 1;
        } while (iVar15 < (int)(uint)*(byte *)(dev + iVar16 + -1 + 0x53ec));
      }
      sVar8 = strlen((char *)&local_830);
      *(undefined2 *)((int)&local_830 + sVar8) = s___id____d___method____mining_sub_00067a84._68_2_;
      if (5 < log_level) {
        pFVar7 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar7 != (FILE *)0x0) {
          fprintf(pFVar7,"%s:%d:%s: %s\n","driver-btm-c5.c",0x4345,DAT_0003e6f0,&local_830);
        }
        fclose(pFVar7);
      }
      uVar5 = api_add_string(*param_1,acStack_858,&local_830,1);
      *param_1 = uVar5;
      iVar15 = dev;
    }
    iVar18 = DAT_0003e6fc;
    local_874 = local_874 + 0x100;
    iVar16 = iVar17;
  } while (iVar17 != 0x11);
  iVar17 = 1;
  iVar16 = 0;
  do {
    while (*(int *)(iVar15 + (iVar16 + 2) * 4) != 1) {
      iVar16 = iVar16 + 1;
      iVar17 = iVar17 + 1;
      if (iVar16 == 0x10) goto LAB_0003e5a2;
    }
    sprintf((char *)&local_848,"chain_offside_%d",iVar17);
    iVar15 = iVar16 * 4;
    iVar16 = iVar16 + 1;
    sprintf((char *)&local_830,"%d",*(undefined4 *)(iVar18 + iVar15));
    uVar5 = api_add_string(*param_1,&local_848,&local_830,1);
    *param_1 = uVar5;
    iVar17 = iVar17 + 1;
    iVar15 = dev;
  } while (iVar16 != 0x10);
LAB_0003e5a2:
  iVar16 = DAT_0003e700;
  iVar18 = 1;
  iVar17 = 0;
  do {
    while (*(int *)(iVar15 + (iVar17 + 2) * 4) != 1) {
      iVar17 = iVar17 + 1;
      iVar18 = iVar18 + 1;
      if (iVar17 == 0x10) goto LAB_0003e5fc;
    }
    sprintf((char *)&local_848,"chain_opencore_%d",iVar18);
    if (*(char *)(iVar17 + iVar16) == '\0') {
      local_830._0_2_ = 0x30;
    }
    else {
      local_830._0_2_ = 0x31;
    }
    iVar17 = iVar17 + 1;
    iVar18 = iVar18 + 1;
    uVar5 = api_add_string(*param_1,&local_848,&local_830,1);
    *param_1 = uVar5;
    iVar15 = dev;
  } while (iVar17 != 0x10);
LAB_0003e5fc:
  piVar11 = (int *)(iVar15 + 4);
  uVar9 = 0;
  iVar15 = 0;
  puVar13 = DAT_0003e6f8;
  do {
    while (piVar11 = piVar11 + 1, *piVar11 != 1) {
      puVar13 = puVar13 + 2;
      if (puVar13 == DAT_0003e6f8 + 0x20) goto LAB_0003e62a;
    }
    uVar19 = *puVar13;
    puVar2 = puVar13 + 1;
    puVar13 = puVar13 + 2;
    bVar20 = CARRY4(uVar9,uVar19);
    uVar9 = uVar9 + uVar19;
    iVar15 = iVar15 + *puVar2 + (uint)bVar20;
  } while (puVar13 != DAT_0003e6f8 + 0x20);
LAB_0003e62a:
  suffix_string_c5_constprop_16(uVar9,iVar15,displayed_hash_rate,0x10,7);
  local_830._0_1_ = s_miner_version_00065138[0];
  local_830._1_1_ = s_miner_version_00065138[1];
  local_830._2_1_ = s_miner_version_00065138[2];
  local_830._3_1_ = s_miner_version_00065138[3];
  uStack_82c._0_1_ = s_miner_version_00065138[4];
  uStack_82c._1_1_ = s_miner_version_00065138[5];
  uStack_82c._2_1_ = s_miner_version_00065138[6];
  uStack_82c._3_1_ = s_miner_version_00065138[7];
  local_828._0_1_ = s_miner_version_00065138[8];
  local_828._1_1_ = s_miner_version_00065138[9];
  local_828._2_1_ = s_miner_version_00065138[10];
  local_828._3_1_ = s_miner_version_00065138[11];
  local_824 = CONCAT22(local_824._2_2_,(short)ram0x00065144);
  uVar5 = api_add_string(*param_1,&local_830,g_miner_version,1);
  *param_1 = uVar5;
  local_830._0_1_ = s_miner_id_00065148[0];
  local_830._1_1_ = s_miner_id_00065148[1];
  local_830._2_1_ = s_miner_id_00065148[2];
  local_830._3_1_ = s_miner_id_00065148[3];
  uStack_82c._0_1_ = s_miner_id_00065148[4];
  uStack_82c._1_1_ = s_miner_id_00065148[5];
  uStack_82c._2_1_ = s_miner_id_00065148[6];
  uStack_82c._3_1_ = s_miner_id_00065148[7];
  local_828 = CONCAT31(local_828._1_3_,(char)ram0x00065150);
  uVar5 = api_add_string(uVar5,&local_830,FPGA_ID_str,1);
  *param_1 = uVar5;
  return;
}

