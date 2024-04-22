
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void kill_mining(void)

{
  thr_info *thr_00;
  char tmp42 [2048];
  thr_info *thr;
  pthread_t *pth;
  int i;
  
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    tmp42._0_4_ = s_Killing_off_mining_threads_0008c624._0_4_;
    tmp42._4_4_ = s_Killing_off_mining_threads_0008c624._4_4_;
    tmp42._8_4_ = s_Killing_off_mining_threads_0008c624._8_4_;
    tmp42._12_4_ = s_Killing_off_mining_threads_0008c624._12_4_;
    tmp42._16_4_ = s_Killing_off_mining_threads_0008c624._16_4_;
    tmp42._20_4_ = s_Killing_off_mining_threads_0008c624._20_4_;
    tmp42._24_2_ = (undefined2)ram0x0008c63c;
    tmp42[26] = (char)((uint)ram0x0008c63c >> 0x10);
    _applog(7,tmp42,true);
  }
  for (i = 0; i < mining_threads; i = i + 1) {
    pth = (pthread_t *)0x0;
    thr_00 = get_thread(i);
    if ((thr_00 != (thr_info *)0x0) && (thr_00->pth != 0)) {
      pth = &thr_00->pth;
    }
    thr_info_cancel(thr_00);
    if ((pth != (pthread_t *)0x0) && (*pth != 0)) {
      pthread_join(*pth,(void **)0x0);
    }
  }
  return;
}

