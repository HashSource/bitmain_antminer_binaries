
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
      tmp42._0_4_ = s_Received_kill_message_000a39fc._0_4_;
      tmp42._4_4_ = s_Received_kill_message_000a39fc._4_4_;
      tmp42._8_4_ = s_Received_kill_message_000a39fc._8_4_;
      tmp42._12_4_ = s_Received_kill_message_000a39fc._12_4_;
      tmp42._16_4_ = s_Received_kill_message_000a39fc._16_4_;
      tmp42[20] = (char)(short)ram0x000a3a10;
      tmp42[21] = (char)((ushort)(short)ram0x000a3a10 >> 8);
      _applog(6,tmp42,true);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_watchpool_thread_000a3a14[0];
      tmp42[1] = s_Killing_off_watchpool_thread_000a3a14[1];
      tmp42[2] = s_Killing_off_watchpool_thread_000a3a14[2];
      tmp42[3] = s_Killing_off_watchpool_thread_000a3a14[3];
      tmp42[4] = s_Killing_off_watchpool_thread_000a3a14[4];
      tmp42[5] = s_Killing_off_watchpool_thread_000a3a14[5];
      tmp42[6] = s_Killing_off_watchpool_thread_000a3a14[6];
      tmp42[7] = s_Killing_off_watchpool_thread_000a3a14[7];
      tmp42[8] = s_Killing_off_watchpool_thread_000a3a14[8];
      tmp42[9] = s_Killing_off_watchpool_thread_000a3a14[9];
      tmp42[10] = s_Killing_off_watchpool_thread_000a3a14[10];
      tmp42[11] = s_Killing_off_watchpool_thread_000a3a14[11];
      tmp42[12] = s_Killing_off_watchpool_thread_000a3a14[12];
      tmp42[13] = s_Killing_off_watchpool_thread_000a3a14[13];
      tmp42[14] = s_Killing_off_watchpool_thread_000a3a14[14];
      tmp42[15] = s_Killing_off_watchpool_thread_000a3a14[15];
      tmp42[16] = s_Killing_off_watchpool_thread_000a3a14[16];
      tmp42[17] = s_Killing_off_watchpool_thread_000a3a14[17];
      tmp42[18] = s_Killing_off_watchpool_thread_000a3a14[18];
      tmp42[19] = s_Killing_off_watchpool_thread_000a3a14[19];
      tmp42[20] = s_Killing_off_watchpool_thread_000a3a14[20];
      tmp42[21] = s_Killing_off_watchpool_thread_000a3a14[21];
      tmp42[22] = s_Killing_off_watchpool_thread_000a3a14[22];
      tmp42[23] = s_Killing_off_watchpool_thread_000a3a14[23];
      tmp42[24] = s_Killing_off_watchpool_thread_000a3a14[24];
      tmp42[25] = s_Killing_off_watchpool_thread_000a3a14[25];
      tmp42[26] = s_Killing_off_watchpool_thread_000a3a14[26];
      tmp42[27] = s_Killing_off_watchpool_thread_000a3a14[27];
      tmp42[28] = (char)ram0x000a3a30;
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchpool_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_watchdog_thread_000a3a34[0];
      tmp42[1] = s_Killing_off_watchdog_thread_000a3a34[1];
      tmp42[2] = s_Killing_off_watchdog_thread_000a3a34[2];
      tmp42[3] = s_Killing_off_watchdog_thread_000a3a34[3];
      tmp42[4] = s_Killing_off_watchdog_thread_000a3a34[4];
      tmp42[5] = s_Killing_off_watchdog_thread_000a3a34[5];
      tmp42[6] = s_Killing_off_watchdog_thread_000a3a34[6];
      tmp42[7] = s_Killing_off_watchdog_thread_000a3a34[7];
      tmp42[8] = s_Killing_off_watchdog_thread_000a3a34[8];
      tmp42[9] = s_Killing_off_watchdog_thread_000a3a34[9];
      tmp42[10] = s_Killing_off_watchdog_thread_000a3a34[10];
      tmp42[11] = s_Killing_off_watchdog_thread_000a3a34[11];
      tmp42[12] = s_Killing_off_watchdog_thread_000a3a34[12];
      tmp42[13] = s_Killing_off_watchdog_thread_000a3a34[13];
      tmp42[14] = s_Killing_off_watchdog_thread_000a3a34[14];
      tmp42[15] = s_Killing_off_watchdog_thread_000a3a34[15];
      tmp42[16] = s_Killing_off_watchdog_thread_000a3a34[16];
      tmp42[17] = s_Killing_off_watchdog_thread_000a3a34[17];
      tmp42[18] = s_Killing_off_watchdog_thread_000a3a34[18];
      tmp42[19] = s_Killing_off_watchdog_thread_000a3a34[19];
      tmp42[20] = s_Killing_off_watchdog_thread_000a3a34[20];
      tmp42[21] = s_Killing_off_watchdog_thread_000a3a34[21];
      tmp42[22] = s_Killing_off_watchdog_thread_000a3a34[22];
      tmp42[23] = s_Killing_off_watchdog_thread_000a3a34[23];
      tmp42[24] = s_Killing_off_watchdog_thread_000a3a34[24];
      tmp42[25] = s_Killing_off_watchdog_thread_000a3a34[25];
      tmp42[26] = s_Killing_off_watchdog_thread_000a3a34[26];
      tmp42[27] = s_Killing_off_watchdog_thread_000a3a34[27];
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + watchdog_thr_id);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Shutting_down_mining_threads_000a3a50[0];
      tmp42[1] = s_Shutting_down_mining_threads_000a3a50[1];
      tmp42[2] = s_Shutting_down_mining_threads_000a3a50[2];
      tmp42[3] = s_Shutting_down_mining_threads_000a3a50[3];
      tmp42[4] = s_Shutting_down_mining_threads_000a3a50[4];
      tmp42[5] = s_Shutting_down_mining_threads_000a3a50[5];
      tmp42[6] = s_Shutting_down_mining_threads_000a3a50[6];
      tmp42[7] = s_Shutting_down_mining_threads_000a3a50[7];
      tmp42[8] = s_Shutting_down_mining_threads_000a3a50[8];
      tmp42[9] = s_Shutting_down_mining_threads_000a3a50[9];
      tmp42[10] = s_Shutting_down_mining_threads_000a3a50[10];
      tmp42[11] = s_Shutting_down_mining_threads_000a3a50[11];
      tmp42[12] = s_Shutting_down_mining_threads_000a3a50[12];
      tmp42[13] = s_Shutting_down_mining_threads_000a3a50[13];
      tmp42[14] = s_Shutting_down_mining_threads_000a3a50[14];
      tmp42[15] = s_Shutting_down_mining_threads_000a3a50[15];
      tmp42[16] = s_Shutting_down_mining_threads_000a3a50[16];
      tmp42[17] = s_Shutting_down_mining_threads_000a3a50[17];
      tmp42[18] = s_Shutting_down_mining_threads_000a3a50[18];
      tmp42[19] = s_Shutting_down_mining_threads_000a3a50[19];
      tmp42[20] = s_Shutting_down_mining_threads_000a3a50[20];
      tmp42[21] = s_Shutting_down_mining_threads_000a3a50[21];
      tmp42[22] = s_Shutting_down_mining_threads_000a3a50[22];
      tmp42[23] = s_Shutting_down_mining_threads_000a3a50[23];
      tmp42[24] = s_Shutting_down_mining_threads_000a3a50[24];
      tmp42[25] = s_Shutting_down_mining_threads_000a3a50[25];
      tmp42[26] = s_Shutting_down_mining_threads_000a3a50[26];
      tmp42[27] = s_Shutting_down_mining_threads_000a3a50[27];
      tmp42[28] = (char)ram0x000a3a6c;
      _applog(7,tmp42,true);
    }
    for (i = 0; i < mining_threads; i = i + 1) {
      ptVar1 = get_thread(i);
      if ((ptVar1 != (thr_info *)0x0) && (ptVar1->cgpu != (cgpu_info *)0x0)) {
        ptVar1->cgpu->shutdown = true;
      }
    }
    sleep(1);
    cg_completion_timeout(kill_mining,(void *)0x0,3000);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Killing_off_API_thread_000a3a70[0];
      tmp42[1] = s_Killing_off_API_thread_000a3a70[1];
      tmp42[2] = s_Killing_off_API_thread_000a3a70[2];
      tmp42[3] = s_Killing_off_API_thread_000a3a70[3];
      tmp42[4] = s_Killing_off_API_thread_000a3a70[4];
      tmp42[5] = s_Killing_off_API_thread_000a3a70[5];
      tmp42[6] = s_Killing_off_API_thread_000a3a70[6];
      tmp42[7] = s_Killing_off_API_thread_000a3a70[7];
      tmp42[8] = s_Killing_off_API_thread_000a3a70[8];
      tmp42[9] = s_Killing_off_API_thread_000a3a70[9];
      tmp42[10] = s_Killing_off_API_thread_000a3a70[10];
      tmp42[11] = s_Killing_off_API_thread_000a3a70[11];
      tmp42[12] = s_Killing_off_API_thread_000a3a70[12];
      tmp42[13] = s_Killing_off_API_thread_000a3a70[13];
      tmp42[14] = s_Killing_off_API_thread_000a3a70[14];
      tmp42[15] = s_Killing_off_API_thread_000a3a70[15];
      tmp42[16] = s_Killing_off_API_thread_000a3a70[16];
      tmp42[17] = s_Killing_off_API_thread_000a3a70[17];
      tmp42[18] = s_Killing_off_API_thread_000a3a70[18];
      tmp42[19] = s_Killing_off_API_thread_000a3a70[19];
      tmp42._20_3_ = (undefined3)ram0x000a3a84;
      _applog(7,tmp42,true);
    }
    kill_timeout(control_thr + api_thr_id);
  }
  return;
}

