
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void kill_mining(void)

{
  thr_info *thr_00;
  char tmp42 [2048];
  thr_info *thr;
  pthread_t *pth;
  int i;
  
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Killing off mining threa",0x18);
    tmp42[0x18] = 'd';
    tmp42[0x19] = 's';
    tmp42[0x1a] = '\0';
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

