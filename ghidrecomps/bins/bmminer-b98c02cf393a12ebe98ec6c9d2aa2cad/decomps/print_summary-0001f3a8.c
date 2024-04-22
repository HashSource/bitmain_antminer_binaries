
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void print_summary(void)

{
  double *pdVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  uint local_960;
  uint uStack_95c;
  int local_958;
  undefined auStack_940 [256];
  undefined4 local_840;
  undefined4 uStack_83c;
  undefined4 uStack_838;
  undefined4 uStack_834;
  undefined4 local_830;
  undefined4 uStack_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined2 local_820;
  undefined local_81e;
  
  pdVar1 = DAT_0001f738;
  dVar15 = DAT_0001f728;
  iVar8 = (int)total_tv_end - (int)total_tv_start;
  if (total_tv_end._4_4_ - total_tv_start._4_4_ < 0) {
    iVar8 = iVar8 + -1;
  }
  dVar16 = *DAT_0001f738;
  dVar12 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_,
                               (iVar8 % 0xe10) * -0x77777777);
  dVar13 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) {
    if ((int)opt_log_level < 4) goto LAB_00020046;
LAB_0001f4d0:
    snprintf((char *)&local_840,0x800,"Started at %s",DAT_0001f730);
    _applog(4,&local_840,0);
    if (total_pools == 1) {
      if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020058;
      goto LAB_00020062;
    }
LAB_0001f504:
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000200be;
LAB_0001f51a:
    snprintf((char *)&local_840,0x800,"Runtime: %d hrs : %d mins : %d secs",iVar8 / 0xe10,
             (iVar8 % 0xe10) / 0x3c,iVar8 % 0x3c);
    _applog(4,&local_840,0);
    dVar14 = total_mhashes_done / *pdVar1;
    puVar7 = &total_mhashes_done;
    if ((use_syslog == 0) &&
       (puVar7 = (undefined8 *)(uint)opt_log_output,
       (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_000200da;
LAB_0001f56a:
    snprintf((char *)&local_840,0x800,"Average hashrate: %.1f Mhash/s",puVar7,dVar14);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020238;
LAB_0001f5a0:
    snprintf((char *)&local_840,0x800,"Solved blocks: %d",found_blocks);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020244;
LAB_0001f5dc:
    snprintf((char *)&local_840,0x800,"Best share difficulty: %s",DAT_0001f734);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020250;
LAB_0001f610:
    snprintf((char *)&local_840,0x800,"Share submissions: %lld",&total_rejected,
             (uint)total_accepted + (uint)total_rejected,
             total_accepted._4_4_ +
             total_rejected._4_4_ + CARRY4((uint)total_accepted,(uint)total_rejected));
    _applog(4,&local_840,0);
    puVar7 = (undefined8 *)(uint)use_syslog;
    if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
       (puVar7 = (undefined8 *)(uint)opt_log_output,
       (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_000201d4;
LAB_0001f662:
    snprintf((char *)&local_840,0x800,"Accepted shares: %lld",puVar7,(uint)total_accepted,
             total_accepted._4_4_);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000201e0;
LAB_0001f69c:
    snprintf((char *)&local_840,0x800,"Rejected shares: %lld",&total_rejected,(uint)total_rejected,
             total_rejected._4_4_);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000201ec;
LAB_0001f6de:
    snprintf((char *)&local_840,0x800,"Accepted difficulty shares: %1.f",&total_diff_accepted,
             (undefined4)total_diff_accepted,total_diff_accepted._4_4_);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000201f8;
LAB_0001f73c:
    snprintf((char *)&local_840,0x800,"Rejected difficulty shares: %1.f",&total_diff_rejected,
             (undefined4)total_diff_rejected,total_diff_rejected._4_4_);
    _applog(4,&local_840,0);
    uVar9 = (uint)total_accepted;
    uVar11 = total_accepted._4_4_;
    if (((uint)total_accepted | total_accepted._4_4_) != 0) {
joined_r0x0001f778:
      if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020210;
      goto LAB_0001f78a;
    }
LAB_0001fcd8:
    if ((total_rejected._4_4_ | (uint)total_rejected) != 0) {
      uVar9 = 0;
      uVar11 = 0;
      goto joined_r0x0001f778;
    }
LAB_0001f7fc:
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000200f0;
LAB_0001f812:
    snprintf((char *)&local_840,0x800,"Hardware errors: %d",hw_errors);
    _applog(4,&local_840,0);
    puVar7 = (undefined8 *)(uint)use_syslog;
    if ((((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
        (puVar7 = (undefined8 *)(uint)opt_log_output,
        (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) &&
       (puVar7 = opt_log_level, (int)opt_log_level < 4)) goto LAB_00020104;
LAB_0001f850:
    snprintf((char *)&local_840,0x800,"Utility (accepted shares / min): %.2f/min",puVar7,
             (dVar12 / dVar16) * dVar15);
    _applog(4,&local_840,0);
    puVar7 = (undefined8 *)(uint)use_syslog;
    if ((((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
        (puVar7 = (undefined8 *)(uint)opt_log_output,
        (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) &&
       (puVar7 = opt_log_level, (int)opt_log_level < 4)) goto LAB_00020110;
LAB_0001f886:
    snprintf((char *)&local_840,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",puVar7,
             (dVar13 / dVar16) * dVar15);
    _applog(4,&local_840,0);
    if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) goto LAB_0002011c;
LAB_0001f8bc:
    snprintf((char *)&local_840,0x800,"Stale submissions discarded due to new blocks: %lld",
             &total_stale,(undefined4)total_stale,total_stale._4_4_);
    _applog(4,&local_840,0);
    if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) goto LAB_00020128;
LAB_0001f8fe:
    snprintf((char *)&local_840,0x800,"Unable to get work from server occasions: %d",total_go);
    _applog(4,&local_840,0);
    if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) goto LAB_00020134;
LAB_0001f93a:
    snprintf((char *)&local_840,0x800,"Work items generated locally: %d",local_work);
    _applog(4,&local_840,0);
    if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) goto LAB_00020140;
LAB_0001f976:
    snprintf((char *)&local_840,0x800,"Submitting work remotely delay occasions: %d",total_ro);
    _applog(4,&local_840,0);
    if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) goto LAB_0002014c;
LAB_0001f9b2:
    snprintf((char *)&local_840,0x800,"New blocks detected on network: %d\n",new_blocks);
    _applog(4,&local_840,0);
    if (1 < total_pools) goto LAB_0001f9e2;
LAB_0001fb02:
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000200ac;
LAB_0001fb18:
    local_840._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[0];
    local_840._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[1];
    local_840._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[2];
    local_840._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[3];
    uStack_83c._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[4];
    uStack_83c._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[5];
    uStack_83c._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[6];
    uStack_83c._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[7];
    uStack_838._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[8];
    uStack_838._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[9];
    uStack_838._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[10];
    uStack_838._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[11];
    uStack_834._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[12];
    uStack_834._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[13];
    uStack_834._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[14];
    uStack_834._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[15];
    local_830._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[16];
    local_830._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[17];
    local_830._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[18];
    local_830._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[19];
    uStack_82c._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[20];
    uStack_82c._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[21];
    uStack_82c._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[22];
    uStack_82c._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[23];
    uStack_828._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[24];
    uStack_828._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[25];
    uStack_828._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[26];
    uStack_828._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[27];
    uStack_824._0_1_ = s_Summary_of_per_device_statistics_0005d1d8[28];
    uStack_824._1_1_ = s_Summary_of_per_device_statistics_0005d1d8[29];
    uStack_824._2_1_ = s_Summary_of_per_device_statistics_0005d1d8[30];
    uStack_824._3_1_ = s_Summary_of_per_device_statistics_0005d1d8[31];
    local_820 = (undefined2)ram0x0005d1f8;
    local_81e = (undefined)((uint)ram0x0005d1f8 >> 0x10);
    _applog(4,&local_840,0);
  }
  else {
    local_840._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[0];
    local_840._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[1];
    local_840._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[2];
    local_840._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[3];
    uStack_83c._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[4];
    uStack_83c._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[5];
    uStack_83c._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[6];
    uStack_83c._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[7];
    uStack_838._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[8];
    uStack_838._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[9];
    uStack_838._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[10];
    uStack_838._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[11];
    uStack_834._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[12];
    uStack_834._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[13];
    uStack_834._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[14];
    uStack_834._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[15];
    local_830._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[16];
    local_830._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[17];
    local_830._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[18];
    local_830._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[19];
    uStack_82c._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[20];
    uStack_82c._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[21];
    uStack_82c._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[22];
    uStack_82c._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[23];
    uStack_828._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[24];
    uStack_828._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[25];
    uStack_828._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[26];
    uStack_828._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[27];
    uStack_824._0_1_ = s__Summary_of_runtime_statistics__0005cdc0[28];
    uStack_824._1_1_ = s__Summary_of_runtime_statistics__0005cdc0[29];
    uStack_824._2_1_ = s__Summary_of_runtime_statistics__0005cdc0[30];
    uStack_824._3_1_ = s__Summary_of_runtime_statistics__0005cdc0[31];
    local_820 = CONCAT11(local_820._1_1_,(char)ram0x0005cde0);
    _applog(4,&local_840,0);
    if (((use_syslog != 0) || (opt_log_output != 0)) || (3 < (int)opt_log_level)) goto LAB_0001f4d0;
LAB_00020046:
    if (total_pools != 1) goto LAB_0001f504;
LAB_00020058:
    if (3 < (int)opt_log_level) {
LAB_00020062:
      snprintf((char *)&local_840,0x800,"Pool: %s",*(undefined4 *)(*pools + 0xa4));
      _applog(4,&local_840,0);
      goto LAB_0001f504;
    }
LAB_000200be:
    if (3 < (int)opt_log_level) goto LAB_0001f51a;
    dVar14 = total_mhashes_done / *pdVar1;
LAB_000200da:
    puVar7 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f56a;
LAB_00020238:
    if (3 < (int)opt_log_level) goto LAB_0001f5a0;
LAB_00020244:
    if (3 < (int)opt_log_level) goto LAB_0001f5dc;
LAB_00020250:
    if (3 < (int)opt_log_level) goto LAB_0001f610;
LAB_000201d4:
    puVar7 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f662;
LAB_000201e0:
    if (3 < (int)opt_log_level) goto LAB_0001f69c;
LAB_000201ec:
    if (3 < (int)opt_log_level) goto LAB_0001f6de;
LAB_000201f8:
    if (3 < (int)opt_log_level) goto LAB_0001f73c;
    uVar9 = (uint)total_accepted;
    uVar11 = total_accepted._4_4_;
    if (((uint)total_accepted | total_accepted._4_4_) == 0) goto LAB_0001fcd8;
LAB_00020210:
    if (3 < (int)opt_log_level) {
LAB_0001f78a:
      uVar3 = total_rejected._4_4_;
      uVar2 = (uint)total_rejected;
      iVar8 = total_rejected._4_4_ * 3 + (uint)CARRY4((uint)total_rejected,(uint)total_rejected) +
              (uint)CARRY4((uint)total_rejected * 2,(uint)total_rejected);
      __aeabi_l2d((uint)total_rejected * 100,
                  (iVar8 * 0x20 | (uint)total_rejected * 3 >> 0x1b) +
                  iVar8 + (uint)CARRY4((uint)total_rejected * 0x60,(uint)total_rejected * 3) +
                  total_rejected._4_4_ + CARRY4((uint)total_rejected * 99,(uint)total_rejected));
      __aeabi_l2d(uVar2 + uVar9,uVar3 + uVar11 + CARRY4(uVar2,uVar9));
      snprintf((char *)&local_840,0x800,"Reject ratio: %.1f%%");
      _applog(4,&local_840,0);
      goto LAB_0001f7fc;
    }
LAB_000200f0:
    if (3 < (int)opt_log_level) goto LAB_0001f812;
    puVar7 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f850;
LAB_00020104:
    puVar7 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f886;
LAB_00020110:
    if (3 < (int)opt_log_level) goto LAB_0001f8bc;
LAB_0002011c:
    if (3 < (int)opt_log_level) goto LAB_0001f8fe;
LAB_00020128:
    if (3 < (int)opt_log_level) goto LAB_0001f93a;
LAB_00020134:
    if (3 < (int)opt_log_level) goto LAB_0001f976;
LAB_00020140:
    if (3 < (int)opt_log_level) goto LAB_0001f9b2;
LAB_0002014c:
    if (1 < total_pools) {
LAB_0001f9e2:
      local_958 = 0;
      do {
        iVar8 = pools[local_958];
        if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) {
          iVar5 = *(int *)(iVar8 + 0x20);
          if (iVar5 == 0) goto LAB_0001fd6c;
joined_r0x00020020:
          if (3 < (int)opt_log_level) goto LAB_0001fd32;
LAB_0001fa50:
          puVar7 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fd7a;
LAB_0001fa58:
          puVar7 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fdba;
LAB_0001fa66:
          puVar7 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fdee;
LAB_0001fa74:
          puVar7 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fe22;
LAB_0001fa82:
          puVar7 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fe56;
          local_960 = *(uint *)(iVar8 + 8);
          uStack_95c = *(uint *)(iVar8 + 0xc);
          if ((local_960 | uStack_95c) == 0) goto LAB_0001fe86;
LAB_0001fa9e:
          if (3 < (int)opt_log_level) {
LAB_0001fea6:
            uVar9 = *(uint *)(iVar8 + 0x10);
            iVar5 = *(int *)(iVar8 + 0x14);
            iVar10 = iVar5 * 3 + (uint)CARRY4(uVar9,uVar9) + (uint)CARRY4(uVar9 * 2,uVar9);
            __aeabi_l2d(uVar9 * 100,
                        (iVar10 * 0x20 | uVar9 * 3 >> 0x1b) + iVar10 +
                        (uint)CARRY4(uVar9 * 0x60,uVar9 * 3) + iVar5 +
                        (uint)CARRY4(uVar9 * 99,uVar9));
            __aeabi_l2d(local_960 + uVar9,uStack_95c + iVar5 + (uint)CARRY4(local_960,uVar9));
            snprintf((char *)&local_840,0x800," Reject ratio: %.1f%%");
            _applog(4,&local_840,0);
            goto LAB_0001ff0e;
          }
LAB_0001faa6:
          if (3 < (int)opt_log_level) goto LAB_0001ff1c;
LAB_0001faae:
          if (3 < (int)opt_log_level) goto LAB_0001ff4c;
LAB_0001fabc:
          if (3 < (int)opt_log_level) goto LAB_0001ff78;
LAB_0001faca:
          if (3 < (int)opt_log_level) goto LAB_0001fad6;
        }
        else {
          snprintf((char *)&local_840,0x800,"Pool: %s",*(undefined4 *)(iVar8 + 0xa4));
          _applog(4,&local_840,0);
          iVar5 = *(int *)(iVar8 + 0x20);
          if (iVar5 != 0) {
            if ((use_syslog == 0) && (opt_log_output == 0)) goto joined_r0x00020020;
LAB_0001fd32:
            pcVar4 = "S";
            if (iVar5 < 2) {
              pcVar4 = "";
            }
            snprintf((char *)&local_840,0x800,"SOLVED %d BLOCK%s!",iVar5,pcVar4);
            _applog(4,&local_840,0);
          }
          puVar7 = (undefined8 *)(uint)use_syslog;
          if ((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) {
LAB_0001fd6c:
            puVar7 = (undefined8 *)(uint)opt_log_output;
            if (puVar7 == (undefined8 *)0x0) goto LAB_0001fa50;
          }
LAB_0001fd7a:
          snprintf((char *)&local_840,0x800," Share submissions: %lld",puVar7,
                   *(int *)(iVar8 + 8) + *(int *)(iVar8 + 0x10));
          _applog(4,&local_840,0);
          puVar7 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar7 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa58;
LAB_0001fdba:
          snprintf((char *)&local_840,0x800," Accepted shares: %lld",puVar7,
                   *(undefined4 *)(iVar8 + 8));
          _applog(4,&local_840,0);
          puVar7 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar7 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa66;
LAB_0001fdee:
          snprintf((char *)&local_840,0x800," Rejected shares: %lld",puVar7,
                   *(undefined4 *)(iVar8 + 0x10));
          _applog(4,&local_840,0);
          puVar7 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar7 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa74;
LAB_0001fe22:
          snprintf((char *)&local_840,0x800," Accepted difficulty shares: %1.f",puVar7,
                   *(undefined4 *)(iVar8 + 0x48));
          _applog(4,&local_840,0);
          puVar7 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar7 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa82;
LAB_0001fe56:
          snprintf((char *)&local_840,0x800," Rejected difficulty shares: %1.f",puVar7,
                   *(undefined4 *)(iVar8 + 0x50));
          _applog(4,&local_840,0);
          local_960 = *(uint *)(iVar8 + 8);
          uStack_95c = *(uint *)(iVar8 + 0xc);
          if ((local_960 | uStack_95c) != 0) {
LAB_0001fe96:
            if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001fa9e;
            goto LAB_0001fea6;
          }
LAB_0001fe86:
          if ((*(uint *)(iVar8 + 0x14) | *(uint *)(iVar8 + 0x10)) != 0) {
            local_960 = 0;
            uStack_95c = 0;
            goto LAB_0001fe96;
          }
LAB_0001ff0e:
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001faa6;
LAB_0001ff1c:
          snprintf((char *)&local_840,0x800," Items worked on: %d",*(undefined4 *)(iVar8 + 0x44));
          _applog(4,&local_840,0);
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001faae;
LAB_0001ff4c:
          snprintf((char *)&local_840,0x800," Stale submissions discarded due to new blocks: %d",
                   *(undefined4 *)(iVar8 + 0x78));
          _applog(4,&local_840,0);
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001fabc;
LAB_0001ff78:
          snprintf((char *)&local_840,0x800," Unable to get work from server occasions: %d",
                   *(undefined4 *)(iVar8 + 0x80));
          _applog(4,&local_840,0);
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001faca;
LAB_0001fad6:
          snprintf((char *)&local_840,0x800," Submitting work remotely delay occasions: %d\n",
                   *(undefined4 *)(iVar8 + 0x84));
          _applog(4,&local_840,0);
        }
        local_958 = local_958 + 1;
      } while (local_958 < total_pools);
      goto LAB_0001fb02;
    }
LAB_000200ac:
    if (3 < (int)opt_log_level) goto LAB_0001fb18;
  }
  if (0 < total_devices) {
    iVar8 = 0;
    do {
      iVar5 = get_devices(iVar8);
      iVar5 = *(int *)(iVar5 + 4);
      iVar8 = iVar8 + 1;
      *(undefined4 *)(iVar5 + 0x14) = 0x1c7b5;
      *(undefined4 *)(iVar5 + 0x18) = 0x1b3fd;
      get_statline(auStack_940,0xff);
      if (((use_syslog != 0) || (opt_log_output != 0)) || (3 < (int)opt_log_level)) {
        snprintf((char *)&local_840,0x800,"%s",auStack_940);
        _applog(4,&local_840,0);
      }
    } while (iVar8 < total_devices);
  }
  if (opt_shares == 0) {
LAB_0001fc8a:
    puVar7 = (undefined8 *)(uint)use_syslog;
LAB_0001fc8e:
    if (puVar7 == (undefined8 *)0x0) {
LAB_0001fc98:
      if (opt_log_output == 0) goto LAB_0002009a;
    }
  }
  else {
    puVar6 = (undefined1 *)(uint)use_syslog;
    if (((puVar6 != (undefined1 *)0x0) || (puVar6 = &opt_log_output, opt_log_output != 0)) ||
       (3 < (int)opt_log_level)) {
      snprintf((char *)&local_840,0x800,"Mined %.0f accepted shares of %d requested\n",puVar6,
               (undefined4)total_diff_accepted,total_diff_accepted._4_4_,opt_shares);
      _applog(4,&local_840,0);
      dVar15 = (double)CONCAT44(total_diff_accepted._4_4_,(undefined4)total_diff_accepted);
      puVar7 = (undefined8 *)(uint)use_syslog;
      dVar12 = (double)(longlong)opt_shares;
      if (dVar12 != dVar15 && dVar12 < dVar15 == (NAN(dVar12) || NAN(dVar15))) {
        if ((puVar7 == (undefined8 *)0x0) &&
           (puVar7 = (undefined8 *)(uint)opt_log_output,
           (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_000201aa;
LAB_0001fc68:
        snprintf((char *)&local_840,0x800,"WARNING - Mined only %.0f shares of %d requested.",puVar7
                 ,dVar15,opt_shares);
        _applog(4,&local_840,0);
        goto LAB_0001fc8a;
      }
      goto LAB_0001fc8e;
    }
    dVar15 = (double)CONCAT44(total_diff_accepted._4_4_,(undefined4)total_diff_accepted);
    dVar12 = (double)(longlong)opt_shares;
    if (dVar12 == dVar15 || dVar12 < dVar15 != (NAN(dVar12) || NAN(dVar15))) goto LAB_0001fc98;
LAB_000201aa:
    puVar7 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001fc68;
LAB_0002009a:
    if ((int)opt_log_level < 4) goto LAB_0001fcb0;
  }
  local_840._0_2_ = 0x20;
  _applog(4,&local_840,0);
LAB_0001fcb0:
  fflush(stderr);
  fflush(stdout);
  return;
}

