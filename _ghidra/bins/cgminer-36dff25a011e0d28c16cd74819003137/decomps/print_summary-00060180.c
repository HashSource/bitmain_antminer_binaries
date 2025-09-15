
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_summary(void)

{
  cgpu_info *cgpu_00;
  uint uVar1;
  int iVar2;
  pool *ppVar3;
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
  dVar8 = (dVar6 / total_secs) * 60.0;
  dVar6 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  dVar6 = (dVar6 / total_secs) * 60.0;
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    builtin_strncpy(tmp42,"\nSummary of runtime statistics:\n",0x20);
    tmp42._32_2_ = tmp42._32_2_ & 0xff00;
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
  if ((((uint)total_accepted != 0 || total_accepted._4_4_ != 0) ||
      ((uint)total_rejected != 0 || total_rejected._4_4_ != 0)) &&
     ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
    iVar2 = total_rejected._4_4_ * 3 + (uint)CARRY4((uint)total_rejected,(uint)total_rejected) +
            (uint)CARRY4((uint)total_rejected * 2,(uint)total_rejected);
    dVar9 = (double)__aeabi_l2d((uint)total_rejected * 100,
                                iVar2 + (iVar2 * 0x20 | (uint)total_rejected * 3 >> 0x1b) +
                                (uint)CARRY4((uint)total_rejected * 3,(uint)total_rejected * 0x60) +
                                total_rejected._4_4_ +
                                (uint)CARRY4((uint)total_rejected * 99,(uint)total_rejected));
    dVar7 = (double)__aeabi_l2d((uint)total_accepted + (uint)total_rejected,
                                total_accepted._4_4_ + total_rejected._4_4_ +
                                (uint)CARRY4((uint)total_accepted,(uint)total_rejected));
    snprintf(tmp42,0x800,"Reject ratio: %.1f%%",tmp42,dVar9 / dVar7);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Hardware errors: %d",hw_errors);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    utility._4_4_ = (undefined4)((ulonglong)dVar8 >> 0x20);
    snprintf(tmp42,0x800,"Utility (accepted shares / min): %.2f/min",tmp42,SUB84(dVar8,0),
             utility._4_4_);
    _applog(4,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    work_util._4_4_ = (undefined4)((ulonglong)dVar6 >> 0x20);
    snprintf(tmp42,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",tmp42,SUB84(dVar6,0)
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
      ppVar3 = pools[i];
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool: %s",ppVar3->rpc_url);
        _applog(4,tmp42,false);
      }
      if ((ppVar3->solved != 0) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        if (ppVar3->solved < 2) {
          uVar4 = 0x1bd4;
        }
        else {
          uVar4 = 0x547c;
        }
        snprintf(tmp42,0x800,"SOLVED %d BLOCK%s!",ppVar3->solved,uVar4 | 0xa0000);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Share submissions: %lld",tmp42,
                 (int)ppVar3->accepted + (int)ppVar3->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted shares: %lld",tmp42,(int)ppVar3->accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected shares: %lld",tmp42,(int)ppVar3->rejected);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Accepted difficulty shares: %1.f",tmp42,
                 *(undefined4 *)&ppVar3->diff_accepted);
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800," Rejected difficulty shares: %1.f",tmp42,
                 *(undefined4 *)&ppVar3->diff_rejected);
        _applog(4,tmp42,false);
      }
      if ((((int)ppVar3->accepted != 0 || *(int *)((int)&ppVar3->accepted + 4) != 0) ||
          ((int)ppVar3->rejected != 0 || *(int *)((int)&ppVar3->rejected + 4) != 0)) &&
         ((use_syslog != false || ((opt_log_output != false || (3 < opt_log_level)))))) {
        uVar4 = (uint)ppVar3->rejected;
        iVar5 = *(int *)((int)&ppVar3->rejected + 4);
        iVar2 = iVar5 * 3 + (uint)CARRY4(uVar4,uVar4) + (uint)CARRY4(uVar4 * 2,uVar4);
        dVar8 = (double)__aeabi_l2d(uVar4 * 100,
                                    iVar2 + (iVar2 * 0x20 | uVar4 * 3 >> 0x1b) +
                                    (uint)CARRY4(uVar4 * 3,uVar4 * 0x60) + iVar5 +
                                    (uint)CARRY4(uVar4 * 99,uVar4));
        uVar4 = (uint)ppVar3->accepted;
        uVar1 = (uint)ppVar3->rejected;
        dVar6 = (double)__aeabi_l2d(uVar4 + uVar1,
                                    *(int *)((int)&ppVar3->accepted + 4) +
                                    *(int *)((int)&ppVar3->rejected + 4) + (uint)CARRY4(uVar4,uVar1)
                                   );
        snprintf(tmp42,0x800," Reject ratio: %.1f%%",tmp42,dVar8 / dVar6);
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
    builtin_strncpy(tmp42,"Summary of per device statistics",0x20);
    tmp42[0x20] = ':';
    tmp42[0x21] = '\n';
    tmp42[0x22] = '\0';
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
    if (((double)CONCAT44(total_diff_accepted._4_4_,total_diff_accepted._0_4_) <
         (double)(longlong)opt_shares) &&
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

