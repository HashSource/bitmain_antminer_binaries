
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
      tmp42._0_4_ = s_Received_kill_message_0008c640._0_4_;
      tmp42._4_4_ = s_Received_kill_message_0008c640._4_4_;
      tmp42._8_4_ = s_Received_kill_message_0008c640._8_4_;
      tmp42._12_4_ = s_Received_kill_message_0008c640._12_4_;
      tmp42._16_4_ = s_Received_kill_message_0008c640._16_4_;
      tmp42[20] = (char)(short)ram0x0008c654;
      tmp42[21] = (char)((ushort)(short)ram0x0008c654 >> 8);
      _applog(6,tmp42,true);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_watchpool_thread_0008c658[0];
      tmp42[1] = s_Killing_off_watchpool_thread_0008c658[1];
      tmp42[2] = s_Killing_off_watchpool_thread_0008c658[2];
      tmp42[3] = s_Killing_off_watchpool_thread_0008c658[3];
      tmp42[4] = s_Killing_off_watchpool_thread_0008c658[4];
      tmp42[5] = s_Killing_off_watchpool_thread_0008c658[5];
      tmp42[6] = s_Killing_off_watchpool_thread_0008c658[6];
      tmp42[7] = s_Killing_off_watchpool_thread_0008c658[7];
      tmp42[8] = s_Killing_off_watchpool_thread_0008c658[8];
      tmp42[9] = s_Killing_off_watchpool_thread_0008c658[9];
      tmp42[10] = s_Killing_off_watchpool_thread_0008c658[10];
      tmp42[11] = s_Killing_off_watchpool_thread_0008c658[11];
      tmp42[12] = s_Killing_off_watchpool_thread_0008c658[12];
      tmp42[13] = s_Killing_off_watchpool_thread_0008c658[13];
      tmp42[14] = s_Killing_off_watchpool_thread_0008c658[14];
      tmp42[15] = s_Killing_off_watchpool_thread_0008c658[15];
      tmp42[16] = s_Killing_off_watchpool_thread_0008c658[16];
      tmp42[17] = s_Killing_off_watchpool_thread_0008c658[17];
      tmp42[18] = s_Killing_off_watchpool_thread_0008c658[18];
      tmp42[19] = s_Killing_off_watchpool_thread_0008c658[19];
      tmp42[20] = s_Killing_off_watchpool_thread_0008c658[20];
      tmp42[21] = s_Killing_off_watchpool_thread_0008c658[21];
      tmp42[22] = s_Killing_off_watchpool_thread_0008c658[22];
      tmp42[23] = s_Killing_off_watchpool_thread_0008c658[23];
      tmp42[24] = s_Killing_off_watchpool_thread_0008c658[24];
      tmp42[25] = s_Killing_off_watchpool_thread_0008c658[25];
      tmp42[26] = s_Killing_off_watchpool_thread_0008c658[26];
      tmp42[27] = s_Killing_off_watchpool_thread_0008c658[27];
      tmp42[28] = (char)ram0x0008c674;
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchpool_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_watchdog_thread_0008c678[0];
      tmp42[1] = s_Killing_off_watchdog_thread_0008c678[1];
      tmp42[2] = s_Killing_off_watchdog_thread_0008c678[2];
      tmp42[3] = s_Killing_off_watchdog_thread_0008c678[3];
      tmp42[4] = s_Killing_off_watchdog_thread_0008c678[4];
      tmp42[5] = s_Killing_off_watchdog_thread_0008c678[5];
      tmp42[6] = s_Killing_off_watchdog_thread_0008c678[6];
      tmp42[7] = s_Killing_off_watchdog_thread_0008c678[7];
      tmp42[8] = s_Killing_off_watchdog_thread_0008c678[8];
      tmp42[9] = s_Killing_off_watchdog_thread_0008c678[9];
      tmp42[10] = s_Killing_off_watchdog_thread_0008c678[10];
      tmp42[11] = s_Killing_off_watchdog_thread_0008c678[11];
      tmp42[12] = s_Killing_off_watchdog_thread_0008c678[12];
      tmp42[13] = s_Killing_off_watchdog_thread_0008c678[13];
      tmp42[14] = s_Killing_off_watchdog_thread_0008c678[14];
      tmp42[15] = s_Killing_off_watchdog_thread_0008c678[15];
      tmp42[16] = s_Killing_off_watchdog_thread_0008c678[16];
      tmp42[17] = s_Killing_off_watchdog_thread_0008c678[17];
      tmp42[18] = s_Killing_off_watchdog_thread_0008c678[18];
      tmp42[19] = s_Killing_off_watchdog_thread_0008c678[19];
      tmp42[20] = s_Killing_off_watchdog_thread_0008c678[20];
      tmp42[21] = s_Killing_off_watchdog_thread_0008c678[21];
      tmp42[22] = s_Killing_off_watchdog_thread_0008c678[22];
      tmp42[23] = s_Killing_off_watchdog_thread_0008c678[23];
      tmp42[24] = s_Killing_off_watchdog_thread_0008c678[24];
      tmp42[25] = s_Killing_off_watchdog_thread_0008c678[25];
      tmp42[26] = s_Killing_off_watchdog_thread_0008c678[26];
      tmp42[27] = s_Killing_off_watchdog_thread_0008c678[27];
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchdog_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Shutting_down_mining_threads_0008c694[0];
      tmp42[1] = s_Shutting_down_mining_threads_0008c694[1];
      tmp42[2] = s_Shutting_down_mining_threads_0008c694[2];
      tmp42[3] = s_Shutting_down_mining_threads_0008c694[3];
      tmp42[4] = s_Shutting_down_mining_threads_0008c694[4];
      tmp42[5] = s_Shutting_down_mining_threads_0008c694[5];
      tmp42[6] = s_Shutting_down_mining_threads_0008c694[6];
      tmp42[7] = s_Shutting_down_mining_threads_0008c694[7];
      tmp42[8] = s_Shutting_down_mining_threads_0008c694[8];
      tmp42[9] = s_Shutting_down_mining_threads_0008c694[9];
      tmp42[10] = s_Shutting_down_mining_threads_0008c694[10];
      tmp42[11] = s_Shutting_down_mining_threads_0008c694[11];
      tmp42[12] = s_Shutting_down_mining_threads_0008c694[12];
      tmp42[13] = s_Shutting_down_mining_threads_0008c694[13];
      tmp42[14] = s_Shutting_down_mining_threads_0008c694[14];
      tmp42[15] = s_Shutting_down_mining_threads_0008c694[15];
      tmp42[16] = s_Shutting_down_mining_threads_0008c694[16];
      tmp42[17] = s_Shutting_down_mining_threads_0008c694[17];
      tmp42[18] = s_Shutting_down_mining_threads_0008c694[18];
      tmp42[19] = s_Shutting_down_mining_threads_0008c694[19];
      tmp42[20] = s_Shutting_down_mining_threads_0008c694[20];
      tmp42[21] = s_Shutting_down_mining_threads_0008c694[21];
      tmp42[22] = s_Shutting_down_mining_threads_0008c694[22];
      tmp42[23] = s_Shutting_down_mining_threads_0008c694[23];
      tmp42[24] = s_Shutting_down_mining_threads_0008c694[24];
      tmp42[25] = s_Shutting_down_mining_threads_0008c694[25];
      tmp42[26] = s_Shutting_down_mining_threads_0008c694[26];
      tmp42[27] = s_Shutting_down_mining_threads_0008c694[27];
      tmp42[28] = (char)ram0x0008c6b0;
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
      tmp42[0] = s_Killing_off_API_thread_0008c6b4[0];
      tmp42[1] = s_Killing_off_API_thread_0008c6b4[1];
      tmp42[2] = s_Killing_off_API_thread_0008c6b4[2];
      tmp42[3] = s_Killing_off_API_thread_0008c6b4[3];
      tmp42[4] = s_Killing_off_API_thread_0008c6b4[4];
      tmp42[5] = s_Killing_off_API_thread_0008c6b4[5];
      tmp42[6] = s_Killing_off_API_thread_0008c6b4[6];
      tmp42[7] = s_Killing_off_API_thread_0008c6b4[7];
      tmp42[8] = s_Killing_off_API_thread_0008c6b4[8];
      tmp42[9] = s_Killing_off_API_thread_0008c6b4[9];
      tmp42[10] = s_Killing_off_API_thread_0008c6b4[10];
      tmp42[11] = s_Killing_off_API_thread_0008c6b4[11];
      tmp42[12] = s_Killing_off_API_thread_0008c6b4[12];
      tmp42[13] = s_Killing_off_API_thread_0008c6b4[13];
      tmp42[14] = s_Killing_off_API_thread_0008c6b4[14];
      tmp42[15] = s_Killing_off_API_thread_0008c6b4[15];
      tmp42[16] = s_Killing_off_API_thread_0008c6b4[16];
      tmp42[17] = s_Killing_off_API_thread_0008c6b4[17];
      tmp42[18] = s_Killing_off_API_thread_0008c6b4[18];
      tmp42[19] = s_Killing_off_API_thread_0008c6b4[19];
      tmp42._20_3_ = (undefined3)ram0x0008c6c8;
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + api_thr_id);
  }
  return;
}

