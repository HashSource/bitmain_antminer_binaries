
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __kill_work(void)

{
  int iVar1;
  undefined4 uVar2;
  thr_info *ptVar3;
  int thr_id;
  int iVar4;
  char tmp42 [2048];
  
  uVar2 = tmp42._20_4_;
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    builtin_strncpy(tmp42,"Received kill message",0x16);
    tmp42._22_2_ = SUB42(uVar2,2);
    _applog(6,tmp42,true);
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Killing off watchpool thread",0x1c);
    tmp42[0x1c] = '\0';
    _applog(7,tmp42,true);
  }
  cg_completion_timeout((void *)0x11599,control_thr + watchpool_thr_id,1000);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Killing off watchdog thread",0x1c);
    _applog(7,tmp42,true);
  }
  cg_completion_timeout((void *)0x11599,control_thr + watchdog_thr_id,1000);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Shutting down mining threads",0x1c);
    tmp42[0x1c] = '\0';
    _applog(7,tmp42,true);
  }
  if (0 < mining_threads) {
    thr_id = 0;
    do {
      iVar4 = thr_id + 1;
      ptVar3 = get_thread(thr_id);
      iVar1 = mining_threads;
      if ((ptVar3 != (thr_info *)0x0) && (ptVar3->cgpu != (cgpu_info *)0x0)) {
        ptVar3->cgpu->shutdown = true;
      }
      thr_id = iVar4;
    } while (iVar4 < iVar1);
  }
  sleep(1);
  cg_completion_timeout((void *)0x22981,(void *)0x0,3000);
  uVar2 = tmp42._20_4_;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Killing off API thread",0x17);
    tmp42[0x17] = SUB41(uVar2,3);
    _applog(7,tmp42,true);
  }
  cg_completion_timeout((void *)0x11599,control_thr + api_thr_id,1000);
  return;
}

