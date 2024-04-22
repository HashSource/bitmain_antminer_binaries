
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void print_summary(void)

{
  cgpu_info *cgpu_00;
  int iVar1;
  pool *ppVar2;
  uint uVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
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
  dVar5 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_);
  dVar7 = (dVar5 / total_secs) * DAT_00060698;
  dVar5 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  dVar5 = (dVar5 / total_secs) * DAT_00060698;
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = s__Summary_of_runtime_statistics__000a51d0[0];
    tmp42[1] = s__Summary_of_runtime_statistics__000a51d0[1];
    tmp42[2] = s__Summary_of_runtime_statistics__000a51d0[2];
    tmp42[3] = s__Summary_of_runtime_statistics__000a51d0[3];
    tmp42[4] = s__Summary_of_runtime_statistics__000a51d0[4];
    tmp42[5] = s__Summary_of_runtime_statistics__000a51d0[5];
    tmp42[6] = s__Summary_of_runtime_statistics__000a51d0[6];
    tmp42[7] = s__Summary_of_runtime_statistics__000a51d0[7];
    tmp42[8] = s__Summary_of_runtime_statistics__000a51d0[8];
    tmp42[9] = s__Summary_of_runtime_statistics__000a51d0[9];
    tmp42[10] = s__Summary_of_runtime_statistics__000a51d0[10];
    tmp42[11] = s__Summary_of_runtime_statistics__000a51d0[11];
    tmp42[12] = s__Summary_of_runtime_statistics__000a51d0[12];
    tmp42[13] = s__Summary_of_runtime_statistics__000a51d0[13];
    tmp42[14] = s__Summary_of_runtime_statistics__000a51d0[14];
    tmp42[15] = s__Summary_of_runtime_statistics__000a51d0[15];
    tmp42[16] = s__Summary_of_runtime_statistics__000a51d0[16];
    tmp42[17] = s__Summary_of_runtime_statistics__000a51d0[17];
    tmp42[18] = s__Summary_of_runtime_statistics__000a51d0[18];
    tmp42[19] = s__Summary_of_runtime_statistics__000a51d0[19];
    tmp42[20] = s__Summary_of_runtime_statistics__000a51d0[20];
    tmp42[21] = s__Summary_of_runtime_statistics__000a51d0[21];
    tmp42[22] = s__Summary_of_runtime_statistics__000a51d0[22];
    tmp42[23] = s__Summary_of_runtime_statistics__000a51d0[23];
    tmp42[24] = s__Summary_of_runtime_statistics__000a51d0[24];
    tmp42[25] = s__Summary_of_runtime_statistics__000a51d0[25];
    tmp42[26] = s__Summary_of_runtime_statistics__000a51d0[26];
    tmp42[27] = s__Summary_of_runtime_statistics__000a51d0[27];
    tmp42[28] = s__Summary_of_runtime_statistics__000a51d0[28];
    tmp42[29] = s__Summary_of_runtime_statistics__000a51d0[29];
    tmp42[30] = s__Summary_of_runtime_statistics__000a51d0[30];
    tmp42[31] = s__Summary_of_runtime_statistics__000a51d0[31];
    tmp42[32] = (char)ram0x000a51f0;
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
    displayed_hashes._4_4_ = (undefined4)((ulonglong)(total_mhashes_done / total_secs) >> 0x20);
    snprintf(tmp42,0x800,"Average hashrate: %.1f Mhash/s",displayed_hashes._4_4_,
             SUB84(total_mhashes_done / total_secs,0),displayed_hashes._4_4_);
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
             ,total_accepted._4_4_ + total_rejected._4_4_ +
              (uint)CARRY4((uint)total_accepted,(uint)total_rejected));
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Accepted shares: %lld",total_accepted._4_4_,(uint)total_accepted,
             total_accepted._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Rejected shares: %lld",total_rejected._4_4_,(uint)total_rejected,
             total_rejected._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Accepted difficulty shares: %1.f",total_diff_accepted._4_4_,
             total_diff_accepted._0_4_,total_diff_accepted._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Rejected difficulty shares: %1.f",total_diff_rejected._4_4_,
             total_diff_rejected._0_4_,total_diff_rejected._4_4_);
    _applog(4,tmp42,false);
  }
  if (((((uint)total_accepted | total_accepted._4_4_) != 0) ||
      (((uint)total_rejected | total_rejected._4_4_) != 0)) &&
     ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
    iVar1 = total_rejected._4_4_ * 3 + (uint)CARRY4((uint)total_rejected,(uint)total_rejected) +
            (uint)CARRY4((uint)total_rejected * 2,(uint)total_rejected);
    dVar8 = (double)__aeabi_l2d((uint)total_rejected * 100,
                                iVar1 + (iVar1 * 0x20 | (uint)total_rejected * 3 >> 0x1b) +
                                (uint)CARRY4((uint)total_rejected * 3,(uint)total_rejected * 0x60) +
                                total_rejected._4_4_ +
                                (uint)CARRY4((uint)total_rejected * 99,(uint)total_rejected));
    dVar6 = (double)__aeabi_l2d((uint)total_accepted + (uint)total_rejected,
                                total_accepted._4_4_ + total_rejected._4_4_ +
                                (uint)CARRY4((uint)total_accepted,(uint)total_rejected));
    snprintf(tmp42,0x800,"Reject ratio: %.1f%%",tmp42,dVar8 / dVar6);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Hardware errors: %d",hw_errors);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    utility._4_4_ = (undefined4)((ulonglong)dVar7 >> 0x20);
    snprintf(tmp42,0x800,"Utility (accepted shares / min): %.2f/min",tmp42,SUB84(dVar7,0),
             utility._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    work_util._4_4_ = (undefined4)((ulonglong)dVar5 >> 0x20);
    snprintf(tmp42,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",tmp42,SUB84(dVar5,0)
             ,work_util._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Stale submissions discarded due to new blocks: %lld",tmp42,
             (undefined4)total_stale,total_stale._4_4_);
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
          uVar3 = 0x1bd4;
        }
        else {
          uVar3 = 0x547c;
        }
        snprintf(tmp42,0x800,"SOLVED %d BLOCK%s!",ppVar2->solved,uVar3 | 0xa0000);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Share submissions: %lld",tmp42,
                 *(int *)&ppVar2->accepted + *(int *)&ppVar2->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted shares: %lld",tmp42,*(undefined4 *)&ppVar2->accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected shares: %lld",tmp42,*(undefined4 *)&ppVar2->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted difficulty shares: %1.f",tmp42,
                 *(undefined4 *)&ppVar2->diff_accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected difficulty shares: %1.f",tmp42,
                 *(undefined4 *)&ppVar2->diff_rejected);
        _applog(4,tmp42,false);
      }
      if ((((*(uint *)&ppVar2->accepted | *(uint *)((int)&ppVar2->accepted + 4)) != 0) ||
          ((*(uint *)&ppVar2->rejected | *(uint *)((int)&ppVar2->rejected + 4)) != 0)) &&
         ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
        uVar3 = *(uint *)&ppVar2->rejected;
        iVar4 = *(int *)((int)&ppVar2->rejected + 4);
        iVar1 = iVar4 * 3 + (uint)CARRY4(uVar3,uVar3) + (uint)CARRY4(uVar3 * 2,uVar3);
        dVar7 = (double)__aeabi_l2d(uVar3 * 100,
                                    iVar1 + (iVar1 * 0x20 | uVar3 * 3 >> 0x1b) +
                                    (uint)CARRY4(uVar3 * 3,uVar3 * 0x60) + iVar4 +
                                    (uint)CARRY4(uVar3 * 99,uVar3));
        dVar5 = (double)__aeabi_l2d(*(uint *)&ppVar2->accepted + *(uint *)&ppVar2->rejected,
                                    *(int *)((int)&ppVar2->accepted + 4) +
                                    *(int *)((int)&ppVar2->rejected + 4) +
                                    (uint)CARRY4(*(uint *)&ppVar2->accepted,
                                                 *(uint *)&ppVar2->rejected));
        snprintf(tmp42,0x800," Reject ratio: %.1f%%",tmp42,dVar7 / dVar5);
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
    tmp42[0] = s_Summary_of_per_device_statistics_000a55ec[0];
    tmp42[1] = s_Summary_of_per_device_statistics_000a55ec[1];
    tmp42[2] = s_Summary_of_per_device_statistics_000a55ec[2];
    tmp42[3] = s_Summary_of_per_device_statistics_000a55ec[3];
    tmp42[4] = s_Summary_of_per_device_statistics_000a55ec[4];
    tmp42[5] = s_Summary_of_per_device_statistics_000a55ec[5];
    tmp42[6] = s_Summary_of_per_device_statistics_000a55ec[6];
    tmp42[7] = s_Summary_of_per_device_statistics_000a55ec[7];
    tmp42[8] = s_Summary_of_per_device_statistics_000a55ec[8];
    tmp42[9] = s_Summary_of_per_device_statistics_000a55ec[9];
    tmp42[10] = s_Summary_of_per_device_statistics_000a55ec[10];
    tmp42[11] = s_Summary_of_per_device_statistics_000a55ec[11];
    tmp42[12] = s_Summary_of_per_device_statistics_000a55ec[12];
    tmp42[13] = s_Summary_of_per_device_statistics_000a55ec[13];
    tmp42[14] = s_Summary_of_per_device_statistics_000a55ec[14];
    tmp42[15] = s_Summary_of_per_device_statistics_000a55ec[15];
    tmp42[16] = s_Summary_of_per_device_statistics_000a55ec[16];
    tmp42[17] = s_Summary_of_per_device_statistics_000a55ec[17];
    tmp42[18] = s_Summary_of_per_device_statistics_000a55ec[18];
    tmp42[19] = s_Summary_of_per_device_statistics_000a55ec[19];
    tmp42[20] = s_Summary_of_per_device_statistics_000a55ec[20];
    tmp42[21] = s_Summary_of_per_device_statistics_000a55ec[21];
    tmp42[22] = s_Summary_of_per_device_statistics_000a55ec[22];
    tmp42[23] = s_Summary_of_per_device_statistics_000a55ec[23];
    tmp42[24] = s_Summary_of_per_device_statistics_000a55ec[24];
    tmp42[25] = s_Summary_of_per_device_statistics_000a55ec[25];
    tmp42[26] = s_Summary_of_per_device_statistics_000a55ec[26];
    tmp42[27] = s_Summary_of_per_device_statistics_000a55ec[27];
    tmp42[28] = s_Summary_of_per_device_statistics_000a55ec[28];
    tmp42[29] = s_Summary_of_per_device_statistics_000a55ec[29];
    tmp42[30] = s_Summary_of_per_device_statistics_000a55ec[30];
    tmp42[31] = s_Summary_of_per_device_statistics_000a55ec[31];
    tmp42._32_2_ = (undefined2)ram0x000a560c;
    tmp42[34] = (char)((uint)ram0x000a560c >> 0x10);
    _applog(4,tmp42,false);
  }
  for (i = 0; i < total_devices; i = i + 1) {
    cgpu_00 = get_devices(i);
    cgpu_00->drv->get_statline_before = blank_get_statline_before;
    cgpu_00->drv->get_statline = noop_get_statline;
    log_print_status(cgpu_00);
  }
  if (opt_shares != 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Mined %.0f accepted shares of %d requested\n",tmp42,
               total_diff_accepted._0_4_,total_diff_accepted._4_4_,opt_shares);
      _applog(4,tmp42,false);
    }
    dVar7 = (double)(longlong)opt_shares;
    dVar5 = (double)CONCAT44(total_diff_accepted._4_4_,total_diff_accepted._0_4_);
    if ((dVar7 != dVar5 && dVar7 < dVar5 == (NAN(dVar7) || NAN(dVar5))) &&
       (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
      snprintf(tmp42,0x800,"WARNING - Mined only %.0f shares of %d requested.",tmp42,
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

