
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __kill_work(void)

{
  undefined4 uVar1;
  thr_info *ptVar2;
  char tmp42 [2048];
  cgpu_info *cgpu;
  thr_info *thr;
  int i;
  
  uVar1 = tmp42._20_4_;
  if (successful_connect) {
    if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
      builtin_strncpy(tmp42,"Received kill message",0x16);
      tmp42._22_2_ = SUB42(uVar1,2);
      _applog(6,tmp42,true);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Killing off watchpool thread",0x1c);
      tmp42[0x1c] = '\0';
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchpool_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Killing off watchdog thread",0x1c);
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchdog_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Shutting down mining threads",0x1c);
      tmp42[0x1c] = '\0';
      _applog(7,tmp42,true);
    }
    for (i = 0; i < mining_threads; i = i + 1) {
      ptVar2 = get_thread(i);
      if ((ptVar2 != (thr_info *)0x0) && (ptVar2->cgpu != (cgpu_info *)0x0)) {
        ptVar2->cgpu->shutdown = true;
      }
    }
    sleep(1);
    cg_completion_timeout((void *)0x1a58d,(void *)0x0,3000);
    uVar1 = tmp42._20_4_;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Killing off API thread",0x17);
      tmp42[0x17] = SUB41(uVar1,3);
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + api_thr_id);
  }
  return;
}

