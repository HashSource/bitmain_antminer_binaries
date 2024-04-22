
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void print_summary(void)

{
  longlong lVar1;
  cgpu_info *cgpu_00;
  int iVar2;
  pool *ppVar3;
  undefined1 *puVar4;
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
  dVar6 = (dVar5 / total_secs) * DAT_0002a888;
  dVar5 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  dVar5 = (dVar5 / total_secs) * DAT_0002a888;
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = s__Summary_of_runtime_statistics__00074590[0];
    tmp42[1] = s__Summary_of_runtime_statistics__00074590[1];
    tmp42[2] = s__Summary_of_runtime_statistics__00074590[2];
    tmp42[3] = s__Summary_of_runtime_statistics__00074590[3];
    tmp42[4] = s__Summary_of_runtime_statistics__00074590[4];
    tmp42[5] = s__Summary_of_runtime_statistics__00074590[5];
    tmp42[6] = s__Summary_of_runtime_statistics__00074590[6];
    tmp42[7] = s__Summary_of_runtime_statistics__00074590[7];
    tmp42[8] = s__Summary_of_runtime_statistics__00074590[8];
    tmp42[9] = s__Summary_of_runtime_statistics__00074590[9];
    tmp42[10] = s__Summary_of_runtime_statistics__00074590[10];
    tmp42[11] = s__Summary_of_runtime_statistics__00074590[11];
    tmp42[12] = s__Summary_of_runtime_statistics__00074590[12];
    tmp42[13] = s__Summary_of_runtime_statistics__00074590[13];
    tmp42[14] = s__Summary_of_runtime_statistics__00074590[14];
    tmp42[15] = s__Summary_of_runtime_statistics__00074590[15];
    tmp42[16] = s__Summary_of_runtime_statistics__00074590[16];
    tmp42[17] = s__Summary_of_runtime_statistics__00074590[17];
    tmp42[18] = s__Summary_of_runtime_statistics__00074590[18];
    tmp42[19] = s__Summary_of_runtime_statistics__00074590[19];
    tmp42[20] = s__Summary_of_runtime_statistics__00074590[20];
    tmp42[21] = s__Summary_of_runtime_statistics__00074590[21];
    tmp42[22] = s__Summary_of_runtime_statistics__00074590[22];
    tmp42[23] = s__Summary_of_runtime_statistics__00074590[23];
    tmp42[24] = s__Summary_of_runtime_statistics__00074590[24];
    tmp42[25] = s__Summary_of_runtime_statistics__00074590[25];
    tmp42[26] = s__Summary_of_runtime_statistics__00074590[26];
    tmp42[27] = s__Summary_of_runtime_statistics__00074590[27];
    tmp42[28] = s__Summary_of_runtime_statistics__00074590[28];
    tmp42[29] = s__Summary_of_runtime_statistics__00074590[29];
    tmp42[30] = s__Summary_of_runtime_statistics__00074590[30];
    tmp42[31] = s__Summary_of_runtime_statistics__00074590[31];
    tmp42[32] = (char)ram0x000745b0;
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
    iVar2 = total_rejected._4_4_ +
            total_accepted._4_4_ + CARRY4((uint)total_rejected,(uint)total_accepted);
    snprintf(tmp42,0x800,"Share submissions: %lld",iVar2,(uint)total_rejected + (uint)total_accepted
             ,iVar2);
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
    dVar8 = (double)__aeabi_l2d((int)((ulonglong)(uint)total_rejected * 100),
                                total_rejected._4_4_ * 100 +
                                (int)((ulonglong)(uint)total_rejected * 100 >> 0x20));
    dVar7 = (double)__aeabi_l2d((uint)total_rejected + (uint)total_accepted,
                                total_rejected._4_4_ +
                                total_accepted._4_4_ +
                                CARRY4((uint)total_rejected,(uint)total_accepted));
    snprintf(tmp42,0x800,"Reject ratio: %.1f%%",tmp42,dVar8 / dVar7);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Hardware errors: %d",hw_errors);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    utility._4_4_ = (undefined4)((ulonglong)dVar6 >> 0x20);
    snprintf(tmp42,0x800,"Utility (accepted shares / min): %.2f/min",utility._4_4_,SUB84(dVar6,0),
             utility._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    work_util._4_4_ = (undefined4)((ulonglong)dVar5 >> 0x20);
    snprintf(tmp42,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",work_util._4_4_,
             SUB84(dVar5,0),work_util._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Stale submissions discarded due to new blocks: %lld",total_stale._4_4_,
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
      ppVar3 = pools[i];
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool: %s",ppVar3->rpc_url);
        _applog(4,tmp42,false);
      }
      if ((ppVar3->solved != 0) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        if (ppVar3->solved < 2) {
          puVar4 = &DAT_00071100;
        }
        else {
          puVar4 = &DAT_0007483c;
        }
        snprintf(tmp42,0x800,"SOLVED %d BLOCK%s!",ppVar3->solved,puVar4);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Share submissions: %lld",
                 *(int *)((int)&ppVar3->rejected + 4) +
                 *(int *)((int)&ppVar3->accepted + 4) +
                 (uint)CARRY4(*(uint *)&ppVar3->rejected,*(uint *)&ppVar3->accepted),
                 *(uint *)&ppVar3->rejected + *(uint *)&ppVar3->accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted shares: %lld",*(undefined4 *)((int)&ppVar3->accepted + 4),
                 *(undefined4 *)&ppVar3->accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected shares: %lld",*(undefined4 *)((int)&ppVar3->rejected + 4),
                 *(undefined4 *)&ppVar3->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted difficulty shares: %1.f",
                 *(undefined4 *)((int)&ppVar3->diff_accepted + 4),
                 *(undefined4 *)&ppVar3->diff_accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected difficulty shares: %1.f",
                 *(undefined4 *)((int)&ppVar3->diff_rejected + 4),
                 *(undefined4 *)&ppVar3->diff_rejected);
        _applog(4,tmp42,false);
      }
      if ((((*(uint *)&ppVar3->accepted | *(uint *)((int)&ppVar3->accepted + 4)) != 0) ||
          ((*(uint *)&ppVar3->rejected | *(uint *)((int)&ppVar3->rejected + 4)) != 0)) &&
         ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
        lVar1 = (ulonglong)*(uint *)&ppVar3->rejected * 100;
        dVar6 = (double)__aeabi_l2d((int)lVar1,
                                    *(int *)((int)&ppVar3->rejected + 4) * 100 +
                                    (int)((ulonglong)lVar1 >> 0x20));
        dVar5 = (double)__aeabi_l2d(*(uint *)&ppVar3->rejected + *(uint *)&ppVar3->accepted,
                                    *(int *)((int)&ppVar3->rejected + 4) +
                                    *(int *)((int)&ppVar3->accepted + 4) +
                                    (uint)CARRY4(*(uint *)&ppVar3->rejected,
                                                 *(uint *)&ppVar3->accepted));
        snprintf(tmp42,0x800," Reject ratio: %.1f%%",tmp42,dVar6 / dVar5);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Items worked on: %d",ppVar3->works);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Stale submissions discarded due to new blocks: %d",
                 ppVar3->stale_shares);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Unable to get work from server occasions: %d",
                 ppVar3->getfail_occasions);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Submitting work remotely delay occasions: %d\n",
                 ppVar3->remotefail_occasions);
        _applog(4,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = s_Summary_of_per_device_statistics_000749ac[0];
    tmp42[1] = s_Summary_of_per_device_statistics_000749ac[1];
    tmp42[2] = s_Summary_of_per_device_statistics_000749ac[2];
    tmp42[3] = s_Summary_of_per_device_statistics_000749ac[3];
    tmp42[4] = s_Summary_of_per_device_statistics_000749ac[4];
    tmp42[5] = s_Summary_of_per_device_statistics_000749ac[5];
    tmp42[6] = s_Summary_of_per_device_statistics_000749ac[6];
    tmp42[7] = s_Summary_of_per_device_statistics_000749ac[7];
    tmp42[8] = s_Summary_of_per_device_statistics_000749ac[8];
    tmp42[9] = s_Summary_of_per_device_statistics_000749ac[9];
    tmp42[10] = s_Summary_of_per_device_statistics_000749ac[10];
    tmp42[11] = s_Summary_of_per_device_statistics_000749ac[11];
    tmp42[12] = s_Summary_of_per_device_statistics_000749ac[12];
    tmp42[13] = s_Summary_of_per_device_statistics_000749ac[13];
    tmp42[14] = s_Summary_of_per_device_statistics_000749ac[14];
    tmp42[15] = s_Summary_of_per_device_statistics_000749ac[15];
    tmp42[16] = s_Summary_of_per_device_statistics_000749ac[16];
    tmp42[17] = s_Summary_of_per_device_statistics_000749ac[17];
    tmp42[18] = s_Summary_of_per_device_statistics_000749ac[18];
    tmp42[19] = s_Summary_of_per_device_statistics_000749ac[19];
    tmp42[20] = s_Summary_of_per_device_statistics_000749ac[20];
    tmp42[21] = s_Summary_of_per_device_statistics_000749ac[21];
    tmp42[22] = s_Summary_of_per_device_statistics_000749ac[22];
    tmp42[23] = s_Summary_of_per_device_statistics_000749ac[23];
    tmp42[24] = s_Summary_of_per_device_statistics_000749ac[24];
    tmp42[25] = s_Summary_of_per_device_statistics_000749ac[25];
    tmp42[26] = s_Summary_of_per_device_statistics_000749ac[26];
    tmp42[27] = s_Summary_of_per_device_statistics_000749ac[27];
    tmp42[28] = s_Summary_of_per_device_statistics_000749ac[28];
    tmp42[29] = s_Summary_of_per_device_statistics_000749ac[29];
    tmp42[30] = s_Summary_of_per_device_statistics_000749ac[30];
    tmp42[31] = s_Summary_of_per_device_statistics_000749ac[31];
    tmp42._32_2_ = (undefined2)ram0x000749cc;
    tmp42[34] = (char)((uint)ram0x000749cc >> 0x10);
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
      snprintf(tmp42,0x800,"Mined %.0f accepted shares of %d requested\n",tmp42,
               total_diff_accepted._0_4_,total_diff_accepted._4_4_,opt_shares);
      _applog(4,tmp42,false);
    }
    dVar6 = (double)(longlong)opt_shares;
    dVar5 = (double)CONCAT44(total_diff_accepted._4_4_,total_diff_accepted._0_4_);
    if ((dVar6 != dVar5 && dVar6 < dVar5 == (NAN(dVar6) || NAN(dVar5))) &&
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

