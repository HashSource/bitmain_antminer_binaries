
void print_summary(void)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  uint local_960;
  int iStack_95c;
  int local_958;
  undefined1 auStack_940 [256];
  undefined4 local_840;
  char acStack_83c [28];
  ushort local_820;
  undefined1 local_81e;
  
  dVar12 = total_secs;
  iVar6 = (int)total_tv_end - (int)total_tv_start;
  if (total_tv_end._4_4_ - total_tv_start._4_4_ < 0) {
    iVar6 = iVar6 + -1;
  }
  dVar9 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_,
                              (iVar6 % 0xe10) * -0x77777777);
  dVar10 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) {
    if ((int)opt_log_level < 4) goto LAB_00020046;
LAB_0001f4d0:
    snprintf((char *)&local_840,0x800,"Started at %s",datestamp);
    _applog(4,&local_840,0);
    if (total_pools == 1) {
      if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020058;
      goto LAB_00020062;
    }
LAB_0001f504:
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000200be;
LAB_0001f51a:
    snprintf((char *)&local_840,0x800,"Runtime: %d hrs : %d mins : %d secs",iVar6 / 0xe10,
             (iVar6 % 0xe10) / 0x3c,iVar6 % 0x3c);
    _applog(4,&local_840,0);
    dVar11 = total_mhashes_done / total_secs;
    puVar5 = &total_mhashes_done;
    if ((use_syslog == 0) &&
       (puVar5 = (undefined8 *)(uint)opt_log_output,
       (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_000200da;
LAB_0001f56a:
    snprintf((char *)&local_840,0x800,"Average hashrate: %.1f Mhash/s",puVar5,dVar11);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020238;
LAB_0001f5a0:
    snprintf((char *)&local_840,0x800,"Solved blocks: %d",found_blocks);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020244;
LAB_0001f5dc:
    snprintf((char *)&local_840,0x800,"Best share difficulty: %s",&best_share);
    _applog(4,&local_840,0);
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020250;
LAB_0001f610:
    snprintf((char *)&local_840,0x800,"Share submissions: %lld",&total_rejected,
             (uint)total_accepted + (uint)total_rejected,
             total_accepted._4_4_ +
             total_rejected._4_4_ + (uint)CARRY4((uint)total_accepted,(uint)total_rejected));
    _applog(4,&local_840,0);
    puVar5 = (undefined8 *)(uint)use_syslog;
    if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
       (puVar5 = (undefined8 *)(uint)opt_log_output,
       (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_000201d4;
LAB_0001f662:
    snprintf((char *)&local_840,0x800,"Accepted shares: %lld",puVar5,(uint)total_accepted,
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
    uVar7 = (uint)total_accepted;
    iVar6 = total_accepted._4_4_;
    if ((uint)total_accepted != 0 || total_accepted._4_4_ != 0) {
joined_r0x0001f778:
      if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_00020210;
      goto LAB_0001f78a;
    }
LAB_0001fcd8:
    if (total_rejected._4_4_ != 0 || (uint)total_rejected != 0) {
      uVar7 = 0;
      iVar6 = 0;
      goto joined_r0x0001f778;
    }
LAB_0001f7fc:
    if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_000200f0;
LAB_0001f812:
    snprintf((char *)&local_840,0x800,"Hardware errors: %d",hw_errors);
    _applog(4,&local_840,0);
    puVar5 = (undefined8 *)(uint)use_syslog;
    if ((((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
        (puVar5 = (undefined8 *)(uint)opt_log_output,
        (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) &&
       (puVar5 = opt_log_level, (int)opt_log_level < 4)) goto LAB_00020104;
LAB_0001f850:
    snprintf((char *)&local_840,0x800,"Utility (accepted shares / min): %.2f/min",puVar5,
             (dVar9 / dVar12) * 60.0);
    _applog(4,&local_840,0);
    puVar5 = (undefined8 *)(uint)use_syslog;
    if ((((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
        (puVar5 = (undefined8 *)(uint)opt_log_output,
        (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) &&
       (puVar5 = opt_log_level, (int)opt_log_level < 4)) goto LAB_00020110;
LAB_0001f886:
    snprintf((char *)&local_840,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",puVar5,
             (dVar10 / dVar12) * 60.0);
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
    local_840._0_1_ = 'S';
    local_840._1_1_ = 'u';
    local_840._2_1_ = 'm';
    local_840._3_1_ = 'm';
    builtin_strncpy(acStack_83c,"ary of per device statistics",0x1c);
    local_820 = 0xa3a;
    local_81e = 0;
    _applog(4,&local_840,0);
  }
  else {
    local_840._0_1_ = '\n';
    local_840._1_1_ = 'S';
    local_840._2_1_ = 'u';
    local_840._3_1_ = 'm';
    builtin_strncpy(acStack_83c,"mary of runtime statistics:\n",0x1c);
    local_820 = local_820 & 0xff00;
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
    dVar11 = total_mhashes_done / total_secs;
LAB_000200da:
    puVar5 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f56a;
LAB_00020238:
    if (3 < (int)opt_log_level) goto LAB_0001f5a0;
LAB_00020244:
    if (3 < (int)opt_log_level) goto LAB_0001f5dc;
LAB_00020250:
    if (3 < (int)opt_log_level) goto LAB_0001f610;
LAB_000201d4:
    puVar5 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f662;
LAB_000201e0:
    if (3 < (int)opt_log_level) goto LAB_0001f69c;
LAB_000201ec:
    if (3 < (int)opt_log_level) goto LAB_0001f6de;
LAB_000201f8:
    if (3 < (int)opt_log_level) goto LAB_0001f73c;
    uVar7 = (uint)total_accepted;
    iVar6 = total_accepted._4_4_;
    if ((uint)total_accepted == 0 && total_accepted._4_4_ == 0) goto LAB_0001fcd8;
LAB_00020210:
    if (3 < (int)opt_log_level) {
LAB_0001f78a:
      iVar3 = total_rejected._4_4_;
      uVar1 = (uint)total_rejected;
      iVar8 = total_rejected._4_4_ * 3 + (uint)CARRY4((uint)total_rejected,(uint)total_rejected) +
              (uint)CARRY4((uint)total_rejected * 2,(uint)total_rejected);
      __aeabi_l2d((uint)total_rejected * 100,
                  (iVar8 * 0x20 | (uint)total_rejected * 3 >> 0x1b) +
                  iVar8 + (uint)CARRY4((uint)total_rejected * 0x60,(uint)total_rejected * 3) +
                  total_rejected._4_4_ +
                  (uint)CARRY4((uint)total_rejected * 99,(uint)total_rejected));
      __aeabi_l2d(uVar1 + uVar7,iVar3 + iVar6 + (uint)CARRY4(uVar1,uVar7));
      snprintf((char *)&local_840,0x800,"Reject ratio: %.1f%%");
      _applog(4,&local_840,0);
      goto LAB_0001f7fc;
    }
LAB_000200f0:
    if (3 < (int)opt_log_level) goto LAB_0001f812;
    puVar5 = opt_log_level;
    if (3 < (int)opt_log_level) goto LAB_0001f850;
LAB_00020104:
    puVar5 = opt_log_level;
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
        iVar6 = pools[local_958];
        if (((use_syslog == 0) && (opt_log_output == 0)) && ((int)opt_log_level < 4)) {
          iVar3 = *(int *)(iVar6 + 0x20);
          if (iVar3 == 0) goto LAB_0001fd6c;
joined_r0x00020020:
          if (3 < (int)opt_log_level) goto LAB_0001fd32;
LAB_0001fa50:
          puVar5 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fd7a;
LAB_0001fa58:
          puVar5 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fdba;
LAB_0001fa66:
          puVar5 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fdee;
LAB_0001fa74:
          puVar5 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fe22;
LAB_0001fa82:
          puVar5 = opt_log_level;
          if (3 < (int)opt_log_level) goto LAB_0001fe56;
          local_960 = *(uint *)(iVar6 + 8);
          iStack_95c = *(int *)(iVar6 + 0xc);
          if (local_960 == 0 && iStack_95c == 0) goto LAB_0001fe86;
LAB_0001fa9e:
          if (3 < (int)opt_log_level) {
LAB_0001fea6:
            uVar7 = *(uint *)(iVar6 + 0x10);
            iVar3 = *(int *)(iVar6 + 0x14);
            iVar8 = iVar3 * 3 + (uint)CARRY4(uVar7,uVar7) + (uint)CARRY4(uVar7 * 2,uVar7);
            __aeabi_l2d(uVar7 * 100,
                        (iVar8 * 0x20 | uVar7 * 3 >> 0x1b) + iVar8 +
                        (uint)CARRY4(uVar7 * 0x60,uVar7 * 3) + iVar3 +
                        (uint)CARRY4(uVar7 * 99,uVar7));
            __aeabi_l2d(local_960 + uVar7,iStack_95c + iVar3 + (uint)CARRY4(local_960,uVar7));
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
          snprintf((char *)&local_840,0x800,"Pool: %s",*(undefined4 *)(iVar6 + 0xa4));
          _applog(4,&local_840,0);
          iVar3 = *(int *)(iVar6 + 0x20);
          if (iVar3 != 0) {
            if ((use_syslog == 0) && (opt_log_output == 0)) goto joined_r0x00020020;
LAB_0001fd32:
            pcVar2 = "S";
            if (iVar3 < 2) {
              pcVar2 = "";
            }
            snprintf((char *)&local_840,0x800,"SOLVED %d BLOCK%s!",iVar3,pcVar2);
            _applog(4,&local_840,0);
          }
          puVar5 = (undefined8 *)(uint)use_syslog;
          if ((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) {
LAB_0001fd6c:
            puVar5 = (undefined8 *)(uint)opt_log_output;
            if (puVar5 == (undefined8 *)0x0) goto LAB_0001fa50;
          }
LAB_0001fd7a:
          snprintf((char *)&local_840,0x800," Share submissions: %lld",puVar5,
                   *(int *)(iVar6 + 8) + *(int *)(iVar6 + 0x10));
          _applog(4,&local_840,0);
          puVar5 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar5 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa58;
LAB_0001fdba:
          snprintf((char *)&local_840,0x800," Accepted shares: %lld",puVar5,
                   *(undefined4 *)(iVar6 + 8));
          _applog(4,&local_840,0);
          puVar5 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar5 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa66;
LAB_0001fdee:
          snprintf((char *)&local_840,0x800," Rejected shares: %lld",puVar5,
                   *(undefined4 *)(iVar6 + 0x10));
          _applog(4,&local_840,0);
          puVar5 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar5 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa74;
LAB_0001fe22:
          snprintf((char *)&local_840,0x800," Accepted difficulty shares: %1.f",puVar5,
                   *(undefined4 *)(iVar6 + 0x48));
          _applog(4,&local_840,0);
          puVar5 = (undefined8 *)(uint)use_syslog;
          if (((undefined8 *)(uint)use_syslog == (undefined8 *)0x0) &&
             (puVar5 = (undefined8 *)(uint)opt_log_output,
             (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_0001fa82;
LAB_0001fe56:
          snprintf((char *)&local_840,0x800," Rejected difficulty shares: %1.f",puVar5,
                   *(undefined4 *)(iVar6 + 0x50));
          _applog(4,&local_840,0);
          local_960 = *(uint *)(iVar6 + 8);
          iStack_95c = *(int *)(iVar6 + 0xc);
          if (local_960 != 0 || iStack_95c != 0) {
LAB_0001fe96:
            if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001fa9e;
            goto LAB_0001fea6;
          }
LAB_0001fe86:
          if (*(int *)(iVar6 + 0x14) != 0 || *(int *)(iVar6 + 0x10) != 0) {
            local_960 = 0;
            iStack_95c = 0;
            goto LAB_0001fe96;
          }
LAB_0001ff0e:
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001faa6;
LAB_0001ff1c:
          snprintf((char *)&local_840,0x800," Items worked on: %d",*(undefined4 *)(iVar6 + 0x44));
          _applog(4,&local_840,0);
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001faae;
LAB_0001ff4c:
          snprintf((char *)&local_840,0x800," Stale submissions discarded due to new blocks: %d",
                   *(undefined4 *)(iVar6 + 0x78));
          _applog(4,&local_840,0);
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001fabc;
LAB_0001ff78:
          snprintf((char *)&local_840,0x800," Unable to get work from server occasions: %d",
                   *(undefined4 *)(iVar6 + 0x80));
          _applog(4,&local_840,0);
          if ((use_syslog == 0) && (opt_log_output == 0)) goto LAB_0001faca;
LAB_0001fad6:
          snprintf((char *)&local_840,0x800," Submitting work remotely delay occasions: %d\n",
                   *(undefined4 *)(iVar6 + 0x84));
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
    iVar6 = 0;
    do {
      iVar3 = get_devices(iVar6);
      iVar3 = *(int *)(iVar3 + 4);
      iVar6 = iVar6 + 1;
      *(undefined4 *)(iVar3 + 0x14) = 0x1c7b5;
      *(undefined4 *)(iVar3 + 0x18) = 0x1b3fd;
      get_statline(auStack_940,0xff);
      if (((use_syslog != 0) || (opt_log_output != 0)) || (3 < (int)opt_log_level)) {
        snprintf((char *)&local_840,0x800,"%s",auStack_940);
        _applog(4,&local_840,0);
      }
    } while (iVar6 < total_devices);
  }
  if (opt_shares == 0) {
LAB_0001fc8a:
    puVar5 = (undefined8 *)(uint)use_syslog;
LAB_0001fc8e:
    if (puVar5 == (undefined8 *)0x0) {
LAB_0001fc98:
      if (opt_log_output == 0) goto LAB_0002009a;
    }
  }
  else {
    puVar4 = (undefined1 *)(uint)use_syslog;
    if (((puVar4 != (undefined1 *)0x0) || (puVar4 = &opt_log_output, opt_log_output != 0)) ||
       (3 < (int)opt_log_level)) {
      snprintf((char *)&local_840,0x800,"Mined %.0f accepted shares of %d requested\n",puVar4,
               (undefined4)total_diff_accepted,total_diff_accepted._4_4_,opt_shares);
      _applog(4,&local_840,0);
      dVar12 = (double)CONCAT44(total_diff_accepted._4_4_,(undefined4)total_diff_accepted);
      puVar5 = (undefined8 *)(uint)use_syslog;
      if (dVar12 < (double)(longlong)opt_shares) {
        if ((puVar5 == (undefined8 *)0x0) &&
           (puVar5 = (undefined8 *)(uint)opt_log_output,
           (undefined8 *)(uint)opt_log_output == (undefined8 *)0x0)) goto LAB_000201aa;
LAB_0001fc68:
        snprintf((char *)&local_840,0x800,"WARNING - Mined only %.0f shares of %d requested.",puVar5
                 ,dVar12,opt_shares);
        _applog(4,&local_840,0);
        goto LAB_0001fc8a;
      }
      goto LAB_0001fc8e;
    }
    dVar12 = (double)CONCAT44(total_diff_accepted._4_4_,(undefined4)total_diff_accepted);
    if ((double)(longlong)opt_shares <= dVar12) goto LAB_0001fc98;
LAB_000201aa:
    puVar5 = opt_log_level;
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

