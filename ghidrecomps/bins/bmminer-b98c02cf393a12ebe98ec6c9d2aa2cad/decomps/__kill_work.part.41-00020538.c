
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __kill_work_part_41(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined4 local_810;
  undefined4 local_80c;
  undefined4 uStack_808;
  undefined local_804;
  
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
    if (opt_debug == '\0') goto LAB_000205c4;
LAB_00020746:
    if (opt_log_level < 7) goto LAB_000205c4;
  }
  else {
    local_820 = s_Received_kill_message_0005d2c4._0_4_;
    uStack_81c = s_Received_kill_message_0005d2c4._4_4_;
    uStack_818 = s_Received_kill_message_0005d2c4._8_4_;
    uStack_814 = s_Received_kill_message_0005d2c4._12_4_;
    local_810 = s_Received_kill_message_0005d2c4._16_4_;
    local_80c._0_2_ = (short)ram0x0005d2d8;
    _applog(6,&local_820,1);
    if (opt_debug == '\0') goto LAB_000205c4;
    if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_00020746;
  }
  local_820._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[0];
  local_820._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[1];
  local_820._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[2];
  local_820._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[3];
  uStack_81c._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[4];
  uStack_81c._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[5];
  uStack_81c._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[6];
  uStack_81c._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[7];
  uStack_818._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[8];
  uStack_818._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[9];
  uStack_818._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[10];
  uStack_818._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[11];
  uStack_814._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[12];
  uStack_814._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[13];
  uStack_814._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[14];
  uStack_814._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[15];
  local_810._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[16];
  local_810._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[17];
  local_810._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[18];
  local_810._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[19];
  local_80c._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[20];
  local_80c._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[21];
  local_80c._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[22];
  local_80c._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[23];
  uStack_808._0_1_ = s_Killing_off_watchpool_thread_0005d2dc[24];
  uStack_808._1_1_ = s_Killing_off_watchpool_thread_0005d2dc[25];
  uStack_808._2_1_ = s_Killing_off_watchpool_thread_0005d2dc[26];
  uStack_808._3_1_ = s_Killing_off_watchpool_thread_0005d2dc[27];
  local_804 = (undefined)ram0x0005d2f8;
  _applog(7,&local_820,1);
LAB_000205c4:
  cg_completion_timeout(0x464a5,control_thr + watchpool_thr_id * 0x40,1000);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_820._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[0];
    local_820._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[1];
    local_820._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[2];
    local_820._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[3];
    uStack_81c._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[4];
    uStack_81c._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[5];
    uStack_81c._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[6];
    uStack_81c._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[7];
    uStack_818._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[8];
    uStack_818._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[9];
    uStack_818._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[10];
    uStack_818._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[11];
    uStack_814._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[12];
    uStack_814._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[13];
    uStack_814._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[14];
    uStack_814._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[15];
    local_810._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[16];
    local_810._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[17];
    local_810._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[18];
    local_810._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[19];
    local_80c._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[20];
    local_80c._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[21];
    local_80c._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[22];
    local_80c._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[23];
    uStack_808._0_1_ = s_Killing_off_watchdog_thread_0005d2fc[24];
    uStack_808._1_1_ = s_Killing_off_watchdog_thread_0005d2fc[25];
    uStack_808._2_1_ = s_Killing_off_watchdog_thread_0005d2fc[26];
    uStack_808._3_1_ = s_Killing_off_watchdog_thread_0005d2fc[27];
    _applog(7,&local_820,1);
  }
  cg_completion_timeout(0x464a5,control_thr + watchdog_thr_id * 0x40,1000);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_820._0_1_ = s_Shutting_down_mining_threads_0005d318[0];
    local_820._1_1_ = s_Shutting_down_mining_threads_0005d318[1];
    local_820._2_1_ = s_Shutting_down_mining_threads_0005d318[2];
    local_820._3_1_ = s_Shutting_down_mining_threads_0005d318[3];
    uStack_81c._0_1_ = s_Shutting_down_mining_threads_0005d318[4];
    uStack_81c._1_1_ = s_Shutting_down_mining_threads_0005d318[5];
    uStack_81c._2_1_ = s_Shutting_down_mining_threads_0005d318[6];
    uStack_81c._3_1_ = s_Shutting_down_mining_threads_0005d318[7];
    uStack_818._0_1_ = s_Shutting_down_mining_threads_0005d318[8];
    uStack_818._1_1_ = s_Shutting_down_mining_threads_0005d318[9];
    uStack_818._2_1_ = s_Shutting_down_mining_threads_0005d318[10];
    uStack_818._3_1_ = s_Shutting_down_mining_threads_0005d318[11];
    uStack_814._0_1_ = s_Shutting_down_mining_threads_0005d318[12];
    uStack_814._1_1_ = s_Shutting_down_mining_threads_0005d318[13];
    uStack_814._2_1_ = s_Shutting_down_mining_threads_0005d318[14];
    uStack_814._3_1_ = s_Shutting_down_mining_threads_0005d318[15];
    local_810._0_1_ = s_Shutting_down_mining_threads_0005d318[16];
    local_810._1_1_ = s_Shutting_down_mining_threads_0005d318[17];
    local_810._2_1_ = s_Shutting_down_mining_threads_0005d318[18];
    local_810._3_1_ = s_Shutting_down_mining_threads_0005d318[19];
    local_80c._0_1_ = s_Shutting_down_mining_threads_0005d318[20];
    local_80c._1_1_ = s_Shutting_down_mining_threads_0005d318[21];
    local_80c._2_1_ = s_Shutting_down_mining_threads_0005d318[22];
    local_80c._3_1_ = s_Shutting_down_mining_threads_0005d318[23];
    uStack_808._0_1_ = s_Shutting_down_mining_threads_0005d318[24];
    uStack_808._1_1_ = s_Shutting_down_mining_threads_0005d318[25];
    uStack_808._2_1_ = s_Shutting_down_mining_threads_0005d318[26];
    uStack_808._3_1_ = s_Shutting_down_mining_threads_0005d318[27];
    local_804 = (undefined)ram0x0005d334;
    _applog(7,&local_820,1);
  }
  if (0 < mining_threads) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      iVar1 = get_thread(iVar1);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x24) != 0)) {
        *(undefined *)(*(int *)(iVar1 + 0x24) + 0x16c) = 1;
      }
      iVar1 = iVar2;
    } while (iVar2 < mining_threads);
  }
  sleep(1);
  cg_completion_timeout(0x207a5,0,3000);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_820._0_1_ = s_Killing_off_API_thread_0005d338[0];
    local_820._1_1_ = s_Killing_off_API_thread_0005d338[1];
    local_820._2_1_ = s_Killing_off_API_thread_0005d338[2];
    local_820._3_1_ = s_Killing_off_API_thread_0005d338[3];
    uStack_81c._0_1_ = s_Killing_off_API_thread_0005d338[4];
    uStack_81c._1_1_ = s_Killing_off_API_thread_0005d338[5];
    uStack_81c._2_1_ = s_Killing_off_API_thread_0005d338[6];
    uStack_81c._3_1_ = s_Killing_off_API_thread_0005d338[7];
    uStack_818._0_1_ = s_Killing_off_API_thread_0005d338[8];
    uStack_818._1_1_ = s_Killing_off_API_thread_0005d338[9];
    uStack_818._2_1_ = s_Killing_off_API_thread_0005d338[10];
    uStack_818._3_1_ = s_Killing_off_API_thread_0005d338[11];
    uStack_814._0_1_ = s_Killing_off_API_thread_0005d338[12];
    uStack_814._1_1_ = s_Killing_off_API_thread_0005d338[13];
    uStack_814._2_1_ = s_Killing_off_API_thread_0005d338[14];
    uStack_814._3_1_ = s_Killing_off_API_thread_0005d338[15];
    local_810._0_1_ = s_Killing_off_API_thread_0005d338[16];
    local_810._1_1_ = s_Killing_off_API_thread_0005d338[17];
    local_810._2_1_ = s_Killing_off_API_thread_0005d338[18];
    local_810._3_1_ = s_Killing_off_API_thread_0005d338[19];
    local_80c._0_3_ = (undefined3)ram0x0005d34c;
    _applog(7,&local_820,1);
  }
  cg_completion_timeout(0x464a5,control_thr + api_thr_id * 0x40,1000);
  return;
}

