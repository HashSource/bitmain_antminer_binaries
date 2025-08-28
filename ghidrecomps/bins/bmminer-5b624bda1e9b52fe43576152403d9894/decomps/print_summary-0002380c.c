
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_summary(void)

{
  double dVar1;
  cgpu_info *cgpu;
  int iVar2;
  device_drv *pdVar3;
  _Bool *p_Var4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  pool *ppVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  char logline [255];
  char tmp42 [2048];
  
  dVar1 = total_secs;
  iVar2 = total_tv_end.tv_sec - total_tv_start.tv_sec;
  if (total_tv_end.tv_usec - total_tv_start.tv_usec < 0) {
    iVar2 = iVar2 + -1;
  }
  dVar11 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_);
  dVar12 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
    if (total_pools != 1) goto LAB_00023938;
LAB_00024276:
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Pool: %s",(*pools)->rpc_url);
      _applog(4,tmp42,false);
      goto LAB_00023938;
    }
  }
  else {
    builtin_strncpy(tmp42,"\nSummary of runtime statistics:\n",0x20);
    tmp42._32_2_ = tmp42._32_2_ & 0xff00;
    _applog(4,tmp42,false);
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Started at %s",datestamp);
      _applog(4,tmp42,false);
    }
    if (total_pools == 1) goto LAB_00024276;
LAB_00023938:
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Runtime: %d hrs : %d mins : %d secs",iVar2 / 0xe10,
               (iVar2 % 0xe10) / 0x3c,iVar2 % 0x3c);
      _applog(4,tmp42,false);
      dVar13 = total_mhashes_done / total_secs;
      uVar5 = (uint)use_syslog;
      if (((use_syslog != 0) || (uVar5 = (uint)opt_log_output, opt_log_output != 0)) ||
         (uVar5 = opt_log_level, 3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Average hashrate: %.1f Mhash/s",uVar5,dVar13);
        _applog(4,tmp42,false);
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800,"Solved blocks: %d",found_blocks,dVar13);
          _applog(4,tmp42,false);
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Best share difficulty: %s",best_share,dVar13);
            _applog(4,tmp42,false);
            uVar5 = (uint)use_syslog;
            if (((use_syslog != 0) || (uVar5 = (uint)opt_log_output, opt_log_output != 0)) ||
               (uVar5 = opt_log_level, 3 < opt_log_level)) {
              snprintf(tmp42,0x800,"Share submissions: %lld",uVar5,
                       (uint)total_rejected + (uint)total_accepted,
                       total_rejected._4_4_ +
                       total_accepted._4_4_ +
                       (uint)CARRY4((uint)total_rejected,(uint)total_accepted));
              _applog(4,tmp42,false);
              uVar5 = (uint)use_syslog;
              if (((use_syslog != 0) || (uVar5 = (uint)opt_log_output, opt_log_output != 0)) ||
                 (uVar5 = opt_log_level, 3 < opt_log_level)) {
                snprintf(tmp42,0x800,"Accepted shares: %lld",uVar5,(uint)total_accepted,
                         total_accepted._4_4_);
                _applog(4,tmp42,false);
                uVar5 = (uint)use_syslog;
                if (((use_syslog != 0) || (uVar5 = (uint)opt_log_output, opt_log_output != 0)) ||
                   (uVar5 = opt_log_level, 3 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Rejected shares: %lld",uVar5,(uint)total_rejected,
                           total_rejected._4_4_);
                  _applog(4,tmp42,false);
                  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                    snprintf(tmp42,0x800,"Accepted difficulty shares: %1.f",&total_diff_accepted,
                             total_diff_accepted);
                    _applog(4,tmp42,false);
                    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level))
                    {
                      snprintf(tmp42,0x800,"Rejected difficulty shares: %1.f",&total_diff_rejected,
                               total_diff_rejected);
                      _applog(4,tmp42,false);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar6 = total_rejected._4_4_;
  uVar7 = (uint)total_rejected;
  iVar2 = total_accepted._4_4_;
  uVar5 = (uint)total_accepted;
  if (((uint)total_accepted == 0 && total_accepted._4_4_ == 0) &&
     ((uint)total_rejected == 0 && total_rejected._4_4_ == 0)) {
LAB_00023bc4:
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Hardware errors: %d",hw_errors);
      _applog(4,tmp42,false);
      uVar5 = (uint)use_syslog;
      if (((use_syslog != 0) || (uVar5 = (uint)opt_log_output, opt_log_output != 0)) ||
         (uVar5 = opt_log_level, 3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Utility (accepted shares / min): %.2f/min",uVar5,
                 (dVar11 / dVar1) * 60.0);
        _applog(4,tmp42,false);
        uVar5 = (uint)use_syslog;
        if (((use_syslog != 0) || (uVar5 = (uint)opt_log_output, opt_log_output != 0)) ||
           (uVar5 = opt_log_level, 3 < opt_log_level)) {
          snprintf(tmp42,0x800,"Work Utility (diff1 shares solved / min): %.2f/min\n",uVar5,
                   (dVar12 / dVar1) * 60.0);
          _applog(4,tmp42,false);
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Stale submissions discarded due to new blocks: %lld",&total_stale,
                     (undefined4)total_stale,total_stale._4_4_);
            _applog(4,tmp42,false);
            if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
              snprintf(tmp42,0x800,"Unable to get work from server occasions: %d",total_go);
              _applog(4,tmp42,false);
              if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                snprintf(tmp42,0x800,"Work items generated locally: %d",local_work);
                _applog(4,tmp42,false);
                if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Submitting work remotely delay occasions: %d",total_ro);
                  _applog(4,tmp42,false);
                  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                    snprintf(tmp42,0x800,"New blocks detected on network: %d\n",new_blocks);
                    _applog(4,tmp42,false);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
    __aeabi_l2d((int)((ulonglong)(uint)total_rejected * 100),
                total_rejected._4_4_ * 100 + (int)((ulonglong)(uint)total_rejected * 100 >> 0x20));
    __aeabi_l2d(uVar5 + uVar7,iVar2 + iVar6 + (uint)CARRY4(uVar5,uVar7));
    snprintf(tmp42,0x800,"Reject ratio: %.1f%%");
    _applog(4,tmp42,false);
    goto LAB_00023bc4;
  }
  if (1 < total_pools) {
    iVar2 = 0;
    do {
      ppVar10 = pools[iVar2];
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
        iVar6 = ppVar10->solved;
        if (iVar6 == 0) goto LAB_0002410e;
LAB_00023de0:
        if ((opt_log_output != false) || (3 < opt_log_level)) goto LAB_000240e0;
      }
      else {
        snprintf(tmp42,0x800,"Pool: %s",ppVar10->rpc_url);
        _applog(4,tmp42,false);
        iVar6 = ppVar10->solved;
        if (iVar6 != 0) {
          if (use_syslog == false) goto LAB_00023de0;
LAB_000240e0:
          if (iVar6 < 2) {
            pcVar8 = "";
          }
          else {
            pcVar8 = "S";
          }
          snprintf(tmp42,0x800,"SOLVED %d BLOCK%s!",iVar6,pcVar8);
          _applog(4,tmp42,false);
        }
        if (use_syslog == false) {
LAB_0002410e:
          if ((opt_log_output == false) && (opt_log_level < 4)) goto LAB_00023df2;
        }
        snprintf(tmp42,0x800," Share submissions: %lld",*(undefined4 *)((int)&ppVar10->rejected + 4)
                 ,(int)ppVar10->accepted + (int)ppVar10->rejected);
        _applog(4,tmp42,false);
        uVar5 = (uint)use_syslog;
        if ((use_syslog != 0) ||
           ((uVar5 = (uint)opt_log_output, opt_log_output != 0 ||
            (uVar5 = opt_log_level, 3 < opt_log_level)))) {
          snprintf(tmp42,0x800," Accepted shares: %lld",uVar5,(int)ppVar10->accepted);
          _applog(4,tmp42,false);
          uVar5 = (uint)use_syslog;
          if ((use_syslog != 0) ||
             ((uVar5 = (uint)opt_log_output, opt_log_output != 0 ||
              (uVar5 = opt_log_level, 3 < opt_log_level)))) {
            snprintf(tmp42,0x800," Rejected shares: %lld",uVar5,(int)ppVar10->rejected);
            _applog(4,tmp42,false);
            uVar5 = (uint)use_syslog;
            if ((use_syslog != 0) ||
               ((uVar5 = (uint)opt_log_output, opt_log_output != 0 ||
                (uVar5 = opt_log_level, 3 < opt_log_level)))) {
              snprintf(tmp42,0x800," Accepted difficulty shares: %1.f",uVar5,ppVar10->diff_accepted)
              ;
              _applog(4,tmp42,false);
              uVar5 = (uint)use_syslog;
              if ((use_syslog != 0) ||
                 ((uVar5 = (uint)opt_log_output, opt_log_output != 0 ||
                  (uVar5 = opt_log_level, 3 < opt_log_level)))) {
                snprintf(tmp42,0x800," Rejected difficulty shares: %1.f",uVar5,
                         ppVar10->diff_rejected);
                _applog(4,tmp42,false);
              }
            }
          }
        }
      }
LAB_00023df2:
      uVar5 = (uint)ppVar10->accepted;
      iVar6 = *(int *)((int)&ppVar10->accepted + 4);
      if ((uVar5 == 0 && iVar6 == 0) &&
         ((int)ppVar10->rejected == 0 && *(int *)((int)&ppVar10->rejected + 4) == 0)) {
LAB_00023e68:
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800," Items worked on: %d",ppVar10->works);
          _applog(4,tmp42,false);
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800," Stale submissions discarded due to new blocks: %d",
                     ppVar10->stale_shares);
            _applog(4,tmp42,false);
            if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
              snprintf(tmp42,0x800," Unable to get work from server occasions: %d",
                       ppVar10->getfail_occasions);
              _applog(4,tmp42,false);
              if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                snprintf(tmp42,0x800," Submitting work remotely delay occasions: %d\n",
                         ppVar10->remotefail_occasions);
                _applog(4,tmp42,false);
              }
            }
          }
        }
      }
      else if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
        uVar7 = (uint)ppVar10->rejected;
        iVar9 = *(int *)((int)&ppVar10->rejected + 4);
        __aeabi_l2d((int)((ulonglong)uVar7 * 100),
                    iVar9 * 100 + (int)((ulonglong)uVar7 * 100 >> 0x20));
        __aeabi_l2d(uVar5 + uVar7,iVar6 + iVar9 + (uint)CARRY4(uVar5,uVar7));
        snprintf(tmp42,0x800," Reject ratio: %.1f%%");
        _applog(4,tmp42,false);
        goto LAB_00023e68;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < total_pools);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    builtin_strncpy(tmp42,"Summary of per device statistics",0x20);
    tmp42[0x20] = ':';
    tmp42[0x21] = '\n';
    tmp42[0x22] = '\0';
    _applog(4,tmp42,false);
  }
  if (0 < total_devices) {
    iVar2 = 0;
    do {
      iVar6 = iVar2 + 1;
      cgpu = get_devices(iVar2);
      pdVar3 = cgpu->drv;
      pdVar3->get_statline_before = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x1d8ed;
      pdVar3->get_statline = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x1d8f1;
      get_statline(logline,0xff,cgpu);
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s",logline);
        _applog(4,tmp42,false);
      }
      iVar2 = iVar6;
    } while (iVar6 < total_devices);
  }
  if (opt_shares == 0) {
LAB_00024056:
    uVar5 = (uint)use_syslog;
LAB_0002405a:
    if (uVar5 == 0) goto LAB_0002405e;
  }
  else {
    p_Var4 = (_Bool *)(uint)use_syslog;
    if (((p_Var4 != (_Bool *)0x0) || (p_Var4 = &opt_log_output, opt_log_output != false)) ||
       (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Mined %.0f accepted shares of %d requested\n",p_Var4,total_diff_accepted
               ,opt_shares);
      _applog(4,tmp42,false);
      uVar5 = (uint)use_syslog;
      if (total_diff_accepted < (double)(longlong)opt_shares) {
        if (uVar5 == 0) goto LAB_0002402a;
        goto LAB_0002403a;
      }
      goto LAB_0002405a;
    }
    if (total_diff_accepted < (double)(longlong)opt_shares) {
LAB_0002402a:
      uVar5 = (uint)opt_log_output;
      if ((opt_log_output == 0) && (uVar5 = opt_log_level, opt_log_level < 4)) goto LAB_00024076;
LAB_0002403a:
      snprintf(tmp42,0x800,"WARNING - Mined only %.0f shares of %d requested.",uVar5,
               total_diff_accepted,opt_shares);
      _applog(4,tmp42,false);
      goto LAB_00024056;
    }
LAB_0002405e:
    if ((opt_log_output == false) && (opt_log_level < 4)) goto LAB_00024076;
  }
  tmp42[0] = ' ';
  tmp42[1] = '\0';
  _applog(4,tmp42,false);
LAB_00024076:
  fflush(stderr);
  fflush(stdout);
  return;
}

