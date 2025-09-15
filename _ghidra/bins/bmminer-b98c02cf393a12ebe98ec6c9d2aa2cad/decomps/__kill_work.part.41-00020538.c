
void __kill_work_part_41(void)

{
  int iVar1;
  int iVar2;
  char local_820 [20];
  undefined4 local_80c;
  char acStack_808 [2024];
  
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
    if (opt_debug == '\0') goto LAB_000205c4;
LAB_00020746:
    if (opt_log_level < 7) goto LAB_000205c4;
  }
  else {
    builtin_strncpy(local_820,"Received kill messag",0x14);
    local_80c._0_2_ = 0x65;
    _applog(6,local_820,1);
    if (opt_debug == '\0') goto LAB_000205c4;
    if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_00020746;
  }
  builtin_strncpy(local_820,"Killing off watchpoo",0x14);
  local_80c._0_1_ = 'l';
  local_80c._1_1_ = ' ';
  local_80c._2_1_ = 't';
  local_80c._3_1_ = 'h';
  builtin_strncpy(acStack_808,"read",5);
  _applog(7,local_820,1);
LAB_000205c4:
  cg_completion_timeout(0x464a5,control_thr + watchpool_thr_id * 0x40,1000);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_820,"Killing off watchdog",0x14);
    local_80c._0_1_ = ' ';
    local_80c._1_1_ = 't';
    local_80c._2_1_ = 'h';
    local_80c._3_1_ = 'r';
    builtin_strncpy(acStack_808,"ead",4);
    _applog(7,local_820,1);
  }
  cg_completion_timeout(0x464a5,control_thr + watchdog_thr_id * 0x40,1000);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_820,"Shutting down mining",0x14);
    local_80c._0_1_ = ' ';
    local_80c._1_1_ = 't';
    local_80c._2_1_ = 'h';
    local_80c._3_1_ = 'r';
    builtin_strncpy(acStack_808,"eads",4);
    acStack_808[4] = 0;
    _applog(7,local_820,1);
  }
  if (0 < mining_threads) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      iVar1 = get_thread(iVar1);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x24) != 0)) {
        *(undefined1 *)(*(int *)(iVar1 + 0x24) + 0x16c) = 1;
      }
      iVar1 = iVar2;
    } while (iVar2 < mining_threads);
  }
  sleep(1);
  cg_completion_timeout(0x207a5,0,3000);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_820,"Killing off API thre",0x14);
    local_80c._0_3_ = 0x6461;
    _applog(7,local_820,1);
  }
  cg_completion_timeout(0x464a5,control_thr + api_thr_id * 0x40,1000);
  return;
}

