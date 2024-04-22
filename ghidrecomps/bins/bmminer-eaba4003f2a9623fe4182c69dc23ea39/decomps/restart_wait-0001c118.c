
int restart_wait(thr_info *thr,uint mstime)

{
  uint mstime_local;
  thr_info *thr_local;
  timespec abstime;
  timeval now;
  timeval then;
  timeval tdiff;
  int rc;
  
  cgtime(&now);
  then.tv_sec = now.tv_sec + mstime / 1000;
  then.tv_usec = now.tv_usec + mstime * 1000 + (mstime / 1000) * -1000000;
  if (999999 < then.tv_usec) {
    then.tv_sec = then.tv_sec + 1;
    then.tv_usec = then.tv_usec + -1000000;
  }
  abstime.tv_sec = then.tv_sec;
  abstime.tv_nsec = then.tv_usec * 1000;
  _mutex_lock(&restart_lock,"cgminer.c","restart_wait",0x14d0);
  if (thr->work_restart == false) {
    rc = pthread_cond_timedwait
                   ((pthread_cond_t *)&restart_cond,(pthread_mutex_t *)&restart_lock,
                    (timespec *)&abstime);
  }
  else {
    rc = 0;
  }
  _mutex_unlock(&restart_lock,"cgminer.c","restart_wait",0x14da);
  return rc;
}

