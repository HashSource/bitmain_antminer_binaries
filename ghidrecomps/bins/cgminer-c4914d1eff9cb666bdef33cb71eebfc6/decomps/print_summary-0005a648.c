
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void print_summary(void)

{
  int iVar1;
  cgpu_info *cgpu_00;
  pool *ppVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  char tmp42 [2048];
  timeval diff;
  cgpu_info *cgpu;
  pool *pool;
  double displayed_hashes;
  double work_util;
  double utility;
  int secs;
  int mins;
  int hours;
  int i;
  
  diff.tv_sec = total_tv_end.tv_sec - total_tv_start.tv_sec;
  if (total_tv_end.tv_usec - total_tv_start.tv_usec < 0) {
    diff.tv_sec = diff.tv_sec + -1;
  }
  dVar6 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_);
  dVar8 = (dVar6 / total_secs) * DAT_0005aa58;
  dVar6 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  dVar6 = (dVar6 / total_secs) * DAT_0005aa58;
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = s__Summary_of_runtime_statistics__0008de18[0];
    tmp42[1] = s__Summary_of_runtime_statistics__0008de18[1];
    tmp42[2] = s__Summary_of_runtime_statistics__0008de18[2];
    tmp42[3] = s__Summary_of_runtime_statistics__0008de18[3];
    tmp42[4] = s__Summary_of_runtime_statistics__0008de18[4];
    tmp42[5] = s__Summary_of_runtime_statistics__0008de18[5];
    tmp42[6] = s__Summary_of_runtime_statistics__0008de18[6];
    tmp42[7] = s__Summary_of_runtime_statistics__0008de18[7];
    tmp42[8] = s__Summary_of_runtime_statistics__0008de18[8];
    tmp42[9] = s__Summary_of_runtime_statistics__0008de18[9];
    tmp42[10] = s__Summary_of_runtime_statistics__0008de18[10];
    tmp42[11] = s__Summary_of_runtime_statistics__0008de18[11];
    tmp42[12] = s__Summary_of_runtime_statistics__0008de18[12];
    tmp42[13] = s__Summary_of_runtime_statistics__0008de18[13];
    tmp42[14] = s__Summary_of_runtime_statistics__0008de18[14];
    tmp42[15] = s__Summary_of_runtime_statistics__0008de18[15];
    tmp42[16] = s__Summary_of_runtime_statistics__0008de18[16];
    tmp42[17] = s__Summary_of_runtime_statistics__0008de18[17];
    tmp42[18] = s__Summary_of_runtime_statistics__0008de18[18];
    tmp42[19] = s__Summary_of_runtime_statistics__0008de18[19];
    tmp42[20] = s__Summary_of_runtime_statistics__0008de18[20];
    tmp42[21] = s__Summary_of_runtime_statistics__0008de18[21];
    tmp42[22] = s__Summary_of_runtime_statistics__0008de18[22];
    tmp42[23] = s__Summary_of_runtime_statistics__0008de18[23];
    tmp42[24] = s__Summary_of_runtime_statistics__0008de18[24];
    tmp42[25] = s__Summary_of_runtime_statistics__0008de18[25];
    tmp42[26] = s__Summary_of_runtime_statistics__0008de18[26];
    tmp42[27] = s__Summary_of_runtime_statistics__0008de18[27];
    tmp42[28] = s__Summary_of_runtime_statistics__0008de18[28];
    tmp42[29] = s__Summary_of_runtime_statistics__0008de18[29];
    tmp42[30] = s__Summary_of_runtime_statistics__0008de18[30];
    tmp42[31] = s__Summary_of_runtime_statistics__0008de18[31];
    tmp42[32] = (char)ram0x0008de38;
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Started at %s",datestamp);
    _applog(4,tmp42,false);
  }
  if ((total_pools == 1) &&
     (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Pool: %s",(*pools)->rpc_url);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Runtime: %d hrs : %d mins : %d secs",diff.tv_sec / 0xe10,
             (diff.tv_sec % 0xe10) / 0x3c,diff.tv_sec % 0x3c);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    displayed_hashes._0_4_ = SUB84(total_mhashes_done / total_secs,0);
    displayed_hashes._4_4_ = (undefined4)((ulonglong)(total_mhashes_done / total_secs) >> 0x20);
    snprintf(tmp42,0x800,"Average hashrate: %.1f Mhash/s",displayed_hashes._0_4_,
             displayed_hashes._0_4_,displayed_hashes._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Solved blocks: %d",found_blocks);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Best share difficulty: %s",best_share);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Share submissions: %lld",tmp42,(uint)total_accepted + (uint)total_rejected
             ,total_accepted._4_4_ +
              total_rejected._4_4_ + CARRY4((uint)total_accepted,(uint)total_rejected));
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Accepted shares: %lld",(uint)total_accepted,(uint)total_accepted,
             total_accepted._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Rejected shares: %lld",(uint)total_rejected,(uint)total_rejected,
             total_rejected._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Accepted difficulty shares: %1.f",total_diff_accepted._0_4_,
             total_diff_accepted._0_4_,total_diff_accepted._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Rejected difficulty shares: %1.f",total_diff_rejected._0_4_,
             total_diff_rejected._0_4_,total_diff_rejected._4_4_);
    _applog(4,tmp42,false);
  }
  if (((((uint)total_accepted | total_accepted._4_4_) != 0) ||
      (((uint)total_rejected | total_rejected._4_4_) != 0)) &&
     ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
    iVar1 = total_rejected._4_4_ * 3 + (uint)CARRY4((uint)total_rejected,(uint)total_rejected) +
            (uint)CARRY4((uint)total_rejected * 2,(uint)total_rejected);
    dVar9 = (double)__aeabi_l2d((uint)total_rejected * 100,
                                (iVar1 * 0x20 | (uint)total_rejected * 3 >> 0x1b) +
                                iVar1 + (uint)CARRY4((uint)total_rejected * 3,
                                                     (uint)total_rejected * 0x60) +
                                total_rejected._4_4_ +
                                CARRY4((uint)total_rejected * 99,(uint)total_rejected));
    dVar7 = (double)__aeabi_l2d((uint)total_accepted + (uint)total_rejected,
                                total_accepted._4_4_ +
                                total_rejected._4_4_ +
                                CARRY4((uint)total_accepted,(uint)total_rejected));
    snprintf(tmp42,0x800,"Reject ratio: %.1f%%",tmp42,dVar9 / dVar7);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Hardware errors: %d",hw_errors);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    utility._0_4_ = SUB84(dVar8,0);
    utility._4_4_ = (undefined4)((ulonglong)dVar8 >> 0x20);
    snprintf(tmp42,0x800,"Utility (accepted shares / min): %.2f/min",utility._0_4_,utility._0_4_,
             utility._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    work_util._0_4_ = SUB84(dVar6,0);
    work_util._4_4_ = (undefined4)((ulonglong)dVar6 >> 0x20);
    snprintf(tmp42,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",work_util._0_4_,
             work_util._0_4_,work_util._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Stale submissions discarded due to new blocks: %lld",
             (undefined4)total_stale,(undefined4)total_stale,total_stale._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Unable to get work from server occasions: %d",total_go);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Work items generated locally: %d",local_work);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Submitting work remotely delay occasions: %d",total_ro);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"New blocks detected on network: %d\n",new_blocks);
    _applog(4,tmp42,false);
  }
  if (1 < total_pools) {
    for (i = 0; i < total_pools; i = i + 1) {
      ppVar2 = pools[i];
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool: %s",ppVar2->rpc_url);
        _applog(4,tmp42,false);
      }
      if ((ppVar2->solved != 0) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        if (ppVar2->solved < 2) {
          puVar3 = &DAT_0008a828;
        }
        else {
          puVar3 = &DAT_0008e0c4;
        }
        snprintf(tmp42,0x800,"SOLVED %d BLOCK%s!",ppVar2->solved,puVar3);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Share submissions: %lld",tmp42,
                 *(int *)&ppVar2->accepted + *(int *)&ppVar2->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted shares: %lld",*(undefined4 *)&ppVar2->accepted,
                 *(undefined4 *)&ppVar2->accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected shares: %lld",*(undefined4 *)&ppVar2->rejected,
                 *(undefined4 *)&ppVar2->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted difficulty shares: %1.f",
                 *(undefined4 *)&ppVar2->diff_accepted,*(undefined4 *)&ppVar2->diff_accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected difficulty shares: %1.f",
                 *(undefined4 *)&ppVar2->diff_rejected,*(undefined4 *)&ppVar2->diff_rejected);
        _applog(4,tmp42,false);
      }
      if ((((*(uint *)&ppVar2->accepted | *(uint *)((int)&ppVar2->accepted + 4)) != 0) ||
          ((*(uint *)&ppVar2->rejected | *(uint *)((int)&ppVar2->rejected + 4)) != 0)) &&
         ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
        uVar4 = *(uint *)&ppVar2->rejected;
        iVar5 = *(int *)((int)&ppVar2->rejected + 4);
        iVar1 = iVar5 * 3 + (uint)CARRY4(uVar4,uVar4) + (uint)CARRY4(uVar4 * 2,uVar4);
        dVar8 = (double)__aeabi_l2d(uVar4 * 100,
                                    (iVar1 * 0x20 | uVar4 * 3 >> 0x1b) +
                                    iVar1 + (uint)CARRY4(uVar4 * 3,uVar4 * 0x60) +
                                    iVar5 + (uint)CARRY4(uVar4 * 99,uVar4));
        dVar6 = (double)__aeabi_l2d(*(uint *)&ppVar2->accepted + *(uint *)&ppVar2->rejected,
                                    *(int *)((int)&ppVar2->accepted + 4) +
                                    *(int *)((int)&ppVar2->rejected + 4) +
                                    (uint)CARRY4(*(uint *)&ppVar2->accepted,
                                                 *(uint *)&ppVar2->rejected));
        snprintf(tmp42,0x800," Reject ratio: %.1f%%",tmp42,dVar8 / dVar6);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Items worked on: %d",ppVar2->works);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Stale submissions discarded due to new blocks: %d",
                 ppVar2->stale_shares);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Unable to get work from server occasions: %d",
                 ppVar2->getfail_occasions);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Submitting work remotely delay occasions: %d\n",
                 ppVar2->remotefail_occasions);
        _applog(4,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = s_Summary_of_per_device_statistics_0008e234[0];
    tmp42[1] = s_Summary_of_per_device_statistics_0008e234[1];
    tmp42[2] = s_Summary_of_per_device_statistics_0008e234[2];
    tmp42[3] = s_Summary_of_per_device_statistics_0008e234[3];
    tmp42[4] = s_Summary_of_per_device_statistics_0008e234[4];
    tmp42[5] = s_Summary_of_per_device_statistics_0008e234[5];
    tmp42[6] = s_Summary_of_per_device_statistics_0008e234[6];
    tmp42[7] = s_Summary_of_per_device_statistics_0008e234[7];
    tmp42[8] = s_Summary_of_per_device_statistics_0008e234[8];
    tmp42[9] = s_Summary_of_per_device_statistics_0008e234[9];
    tmp42[10] = s_Summary_of_per_device_statistics_0008e234[10];
    tmp42[11] = s_Summary_of_per_device_statistics_0008e234[11];
    tmp42[12] = s_Summary_of_per_device_statistics_0008e234[12];
    tmp42[13] = s_Summary_of_per_device_statistics_0008e234[13];
    tmp42[14] = s_Summary_of_per_device_statistics_0008e234[14];
    tmp42[15] = s_Summary_of_per_device_statistics_0008e234[15];
    tmp42[16] = s_Summary_of_per_device_statistics_0008e234[16];
    tmp42[17] = s_Summary_of_per_device_statistics_0008e234[17];
    tmp42[18] = s_Summary_of_per_device_statistics_0008e234[18];
    tmp42[19] = s_Summary_of_per_device_statistics_0008e234[19];
    tmp42[20] = s_Summary_of_per_device_statistics_0008e234[20];
    tmp42[21] = s_Summary_of_per_device_statistics_0008e234[21];
    tmp42[22] = s_Summary_of_per_device_statistics_0008e234[22];
    tmp42[23] = s_Summary_of_per_device_statistics_0008e234[23];
    tmp42[24] = s_Summary_of_per_device_statistics_0008e234[24];
    tmp42[25] = s_Summary_of_per_device_statistics_0008e234[25];
    tmp42[26] = s_Summary_of_per_device_statistics_0008e234[26];
    tmp42[27] = s_Summary_of_per_device_statistics_0008e234[27];
    tmp42[28] = s_Summary_of_per_device_statistics_0008e234[28];
    tmp42[29] = s_Summary_of_per_device_statistics_0008e234[29];
    tmp42[30] = s_Summary_of_per_device_statistics_0008e234[30];
    tmp42[31] = s_Summary_of_per_device_statistics_0008e234[31];
    tmp42._32_2_ = (undefined2)ram0x0008e254;
    tmp42[34] = (char)((uint)ram0x0008e254 >> 0x10);
    _applog(4,tmp42,false);
  }
  for (i = 0; i < total_devices; i = i + 1) {
    cgpu_00 = get_devices(i);
    cgpu_00->drv->get_statline_before = blank_get_statline_before + 1;
    cgpu_00->drv->get_statline = noop_get_statline + 1;
    log_print_status(cgpu_00);
  }
  if (opt_shares != 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Mined %.0f accepted shares of %d requested\n",opt_shares,
               total_diff_accepted._0_4_,total_diff_accepted._4_4_,opt_shares);
      _applog(4,tmp42,false);
    }
    dVar8 = (double)(longlong)opt_shares;
    dVar6 = (double)CONCAT44(total_diff_accepted._4_4_,total_diff_accepted._0_4_);
    if ((dVar8 != dVar6 && dVar8 < dVar6 == (NAN(dVar8) || NAN(dVar6))) &&
       (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
      snprintf(tmp42,0x800,"WARNING - Mined only %.0f shares of %d requested.",opt_shares,
               total_diff_accepted._0_4_,total_diff_accepted._4_4_,opt_shares);
      _applog(4,tmp42,false);
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = ' ';
    tmp42[1] = '\0';
    _applog(4,tmp42,false);
  }
  fflush(stderr);
  fflush(stdout);
  return;
}

