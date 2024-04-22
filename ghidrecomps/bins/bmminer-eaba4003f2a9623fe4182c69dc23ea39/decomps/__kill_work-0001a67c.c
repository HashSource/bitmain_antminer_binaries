
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void __kill_work(void)

{
  thr_info *ptVar1;
  char tmp42 [2048];
  cgpu_info *cgpu;
  thr_info *thr;
  int i;
  
  if (successful_connect) {
    if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
      tmp42._0_4_ = s_Received_kill_message_00072e24._0_4_;
      tmp42._4_4_ = s_Received_kill_message_00072e24._4_4_;
      tmp42._8_4_ = s_Received_kill_message_00072e24._8_4_;
      tmp42._12_4_ = s_Received_kill_message_00072e24._12_4_;
      tmp42._16_4_ = s_Received_kill_message_00072e24._16_4_;
      tmp42[20] = (char)(short)ram0x00072e38;
      tmp42[21] = (char)((ushort)(short)ram0x00072e38 >> 8);
      _applog(6,tmp42,true);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_watchpool_thread_00072e3c[0];
      tmp42[1] = s_Killing_off_watchpool_thread_00072e3c[1];
      tmp42[2] = s_Killing_off_watchpool_thread_00072e3c[2];
      tmp42[3] = s_Killing_off_watchpool_thread_00072e3c[3];
      tmp42[4] = s_Killing_off_watchpool_thread_00072e3c[4];
      tmp42[5] = s_Killing_off_watchpool_thread_00072e3c[5];
      tmp42[6] = s_Killing_off_watchpool_thread_00072e3c[6];
      tmp42[7] = s_Killing_off_watchpool_thread_00072e3c[7];
      tmp42[8] = s_Killing_off_watchpool_thread_00072e3c[8];
      tmp42[9] = s_Killing_off_watchpool_thread_00072e3c[9];
      tmp42[10] = s_Killing_off_watchpool_thread_00072e3c[10];
      tmp42[11] = s_Killing_off_watchpool_thread_00072e3c[11];
      tmp42[12] = s_Killing_off_watchpool_thread_00072e3c[12];
      tmp42[13] = s_Killing_off_watchpool_thread_00072e3c[13];
      tmp42[14] = s_Killing_off_watchpool_thread_00072e3c[14];
      tmp42[15] = s_Killing_off_watchpool_thread_00072e3c[15];
      tmp42[16] = s_Killing_off_watchpool_thread_00072e3c[16];
      tmp42[17] = s_Killing_off_watchpool_thread_00072e3c[17];
      tmp42[18] = s_Killing_off_watchpool_thread_00072e3c[18];
      tmp42[19] = s_Killing_off_watchpool_thread_00072e3c[19];
      tmp42[20] = s_Killing_off_watchpool_thread_00072e3c[20];
      tmp42[21] = s_Killing_off_watchpool_thread_00072e3c[21];
      tmp42[22] = s_Killing_off_watchpool_thread_00072e3c[22];
      tmp42[23] = s_Killing_off_watchpool_thread_00072e3c[23];
      tmp42[24] = s_Killing_off_watchpool_thread_00072e3c[24];
      tmp42[25] = s_Killing_off_watchpool_thread_00072e3c[25];
      tmp42[26] = s_Killing_off_watchpool_thread_00072e3c[26];
      tmp42[27] = s_Killing_off_watchpool_thread_00072e3c[27];
      tmp42[28] = (char)ram0x00072e58;
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchpool_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_watchdog_thread_00072e5c[0];
      tmp42[1] = s_Killing_off_watchdog_thread_00072e5c[1];
      tmp42[2] = s_Killing_off_watchdog_thread_00072e5c[2];
      tmp42[3] = s_Killing_off_watchdog_thread_00072e5c[3];
      tmp42[4] = s_Killing_off_watchdog_thread_00072e5c[4];
      tmp42[5] = s_Killing_off_watchdog_thread_00072e5c[5];
      tmp42[6] = s_Killing_off_watchdog_thread_00072e5c[6];
      tmp42[7] = s_Killing_off_watchdog_thread_00072e5c[7];
      tmp42[8] = s_Killing_off_watchdog_thread_00072e5c[8];
      tmp42[9] = s_Killing_off_watchdog_thread_00072e5c[9];
      tmp42[10] = s_Killing_off_watchdog_thread_00072e5c[10];
      tmp42[11] = s_Killing_off_watchdog_thread_00072e5c[11];
      tmp42[12] = s_Killing_off_watchdog_thread_00072e5c[12];
      tmp42[13] = s_Killing_off_watchdog_thread_00072e5c[13];
      tmp42[14] = s_Killing_off_watchdog_thread_00072e5c[14];
      tmp42[15] = s_Killing_off_watchdog_thread_00072e5c[15];
      tmp42[16] = s_Killing_off_watchdog_thread_00072e5c[16];
      tmp42[17] = s_Killing_off_watchdog_thread_00072e5c[17];
      tmp42[18] = s_Killing_off_watchdog_thread_00072e5c[18];
      tmp42[19] = s_Killing_off_watchdog_thread_00072e5c[19];
      tmp42[20] = s_Killing_off_watchdog_thread_00072e5c[20];
      tmp42[21] = s_Killing_off_watchdog_thread_00072e5c[21];
      tmp42[22] = s_Killing_off_watchdog_thread_00072e5c[22];
      tmp42[23] = s_Killing_off_watchdog_thread_00072e5c[23];
      tmp42[24] = s_Killing_off_watchdog_thread_00072e5c[24];
      tmp42[25] = s_Killing_off_watchdog_thread_00072e5c[25];
      tmp42[26] = s_Killing_off_watchdog_thread_00072e5c[26];
      tmp42[27] = s_Killing_off_watchdog_thread_00072e5c[27];
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchdog_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Shutting_down_mining_threads_00072e78[0];
      tmp42[1] = s_Shutting_down_mining_threads_00072e78[1];
      tmp42[2] = s_Shutting_down_mining_threads_00072e78[2];
      tmp42[3] = s_Shutting_down_mining_threads_00072e78[3];
      tmp42[4] = s_Shutting_down_mining_threads_00072e78[4];
      tmp42[5] = s_Shutting_down_mining_threads_00072e78[5];
      tmp42[6] = s_Shutting_down_mining_threads_00072e78[6];
      tmp42[7] = s_Shutting_down_mining_threads_00072e78[7];
      tmp42[8] = s_Shutting_down_mining_threads_00072e78[8];
      tmp42[9] = s_Shutting_down_mining_threads_00072e78[9];
      tmp42[10] = s_Shutting_down_mining_threads_00072e78[10];
      tmp42[11] = s_Shutting_down_mining_threads_00072e78[11];
      tmp42[12] = s_Shutting_down_mining_threads_00072e78[12];
      tmp42[13] = s_Shutting_down_mining_threads_00072e78[13];
      tmp42[14] = s_Shutting_down_mining_threads_00072e78[14];
      tmp42[15] = s_Shutting_down_mining_threads_00072e78[15];
      tmp42[16] = s_Shutting_down_mining_threads_00072e78[16];
      tmp42[17] = s_Shutting_down_mining_threads_00072e78[17];
      tmp42[18] = s_Shutting_down_mining_threads_00072e78[18];
      tmp42[19] = s_Shutting_down_mining_threads_00072e78[19];
      tmp42[20] = s_Shutting_down_mining_threads_00072e78[20];
      tmp42[21] = s_Shutting_down_mining_threads_00072e78[21];
      tmp42[22] = s_Shutting_down_mining_threads_00072e78[22];
      tmp42[23] = s_Shutting_down_mining_threads_00072e78[23];
      tmp42[24] = s_Shutting_down_mining_threads_00072e78[24];
      tmp42[25] = s_Shutting_down_mining_threads_00072e78[25];
      tmp42[26] = s_Shutting_down_mining_threads_00072e78[26];
      tmp42[27] = s_Shutting_down_mining_threads_00072e78[27];
      tmp42[28] = (char)ram0x00072e94;
      _applog(7,tmp42,true);
    }
    for (i = 0; i < mining_threads; i = i + 1) {
      ptVar1 = get_thread(i);
      if ((ptVar1 != (thr_info *)0x0) && (ptVar1->cgpu != (cgpu_info *)0x0)) {
        ptVar1->cgpu->shutdown = true;
      }
    }
    sleep(1);
    cg_completion_timeout(kill_mining + 1,(void *)0x0,3000);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_API_thread_00072e98[0];
      tmp42[1] = s_Killing_off_API_thread_00072e98[1];
      tmp42[2] = s_Killing_off_API_thread_00072e98[2];
      tmp42[3] = s_Killing_off_API_thread_00072e98[3];
      tmp42[4] = s_Killing_off_API_thread_00072e98[4];
      tmp42[5] = s_Killing_off_API_thread_00072e98[5];
      tmp42[6] = s_Killing_off_API_thread_00072e98[6];
      tmp42[7] = s_Killing_off_API_thread_00072e98[7];
      tmp42[8] = s_Killing_off_API_thread_00072e98[8];
      tmp42[9] = s_Killing_off_API_thread_00072e98[9];
      tmp42[10] = s_Killing_off_API_thread_00072e98[10];
      tmp42[11] = s_Killing_off_API_thread_00072e98[11];
      tmp42[12] = s_Killing_off_API_thread_00072e98[12];
      tmp42[13] = s_Killing_off_API_thread_00072e98[13];
      tmp42[14] = s_Killing_off_API_thread_00072e98[14];
      tmp42[15] = s_Killing_off_API_thread_00072e98[15];
      tmp42[16] = s_Killing_off_API_thread_00072e98[16];
      tmp42[17] = s_Killing_off_API_thread_00072e98[17];
      tmp42[18] = s_Killing_off_API_thread_00072e98[18];
      tmp42[19] = s_Killing_off_API_thread_00072e98[19];
      tmp42._20_3_ = (undefined3)ram0x00072eac;
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + api_thr_id);
  }
  return;
}

