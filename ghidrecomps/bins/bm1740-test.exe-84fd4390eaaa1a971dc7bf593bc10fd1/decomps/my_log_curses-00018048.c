
void my_log_curses(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  if ((opt_quiet == '\0') || (param_1 == 0)) {
    if (param_4 != '\0') {
      pthread_mutex_trylock((pthread_mutex_t *)console_lock);
      pthread_mutex_unlock((pthread_mutex_t *)console_lock);
    }
    pthread_mutex_lock((pthread_mutex_t *)console_lock);
    fprintf(stderr,"%s%s",param_2,param_3);
    pthread_mutex_unlock((pthread_mutex_t *)console_lock);
  }
  return;
}

