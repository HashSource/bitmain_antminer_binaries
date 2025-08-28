
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void kill_mining(void)

{
  thr_info *thr;
  int thr_id;
  char tmp42 [2048];
  
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Killing off mining threa",0x18);
    tmp42[0x18] = 'd';
    tmp42[0x19] = 's';
    tmp42[0x1a] = '\0';
    _applog(7,tmp42,true);
  }
  if (0 < mining_threads) {
    thr_id = 0;
    do {
      while ((thr = get_thread(thr_id), thr != (thr_info *)0x0 && (thr->pth != 0))) {
        thr_info_cancel(thr);
        if (thr->pth != 0) {
          pthread_join(thr->pth,(void **)0x0);
        }
        thr_id = thr_id + 1;
        if (mining_threads <= thr_id) {
          return;
        }
      }
      thr_id = thr_id + 1;
      thr_info_cancel(thr);
    } while (thr_id < mining_threads);
  }
  return;
}

