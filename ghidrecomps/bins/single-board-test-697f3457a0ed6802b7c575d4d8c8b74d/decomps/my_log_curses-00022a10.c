
void my_log_curses(int prio,char *datetime,char *str,_Bool force)

{
  _Bool force_local;
  char *str_local;
  char *datetime_local;
  int prio_local;
  
  if ((!opt_quiet) || (prio == 0)) {
    if (force) {
      pthread_mutex_trylock((pthread_mutex_t *)&console_lock);
      pthread_mutex_unlock((pthread_mutex_t *)&console_lock);
    }
    pthread_mutex_lock((pthread_mutex_t *)&console_lock);
    if (prio == 0) {
      fprintf(stderr,"\x1b[0;31m%s%s\x1b[0m",datetime,str);
    }
    else if (prio == 1) {
      fprintf(stderr,"\x1b[1;34m%s%s\x1b[0m",datetime,str);
    }
    else {
      fprintf(stderr,"%s%s",datetime,str);
    }
    fflush(stderr);
    pthread_mutex_unlock((pthread_mutex_t *)&console_lock);
  }
  return;
}

