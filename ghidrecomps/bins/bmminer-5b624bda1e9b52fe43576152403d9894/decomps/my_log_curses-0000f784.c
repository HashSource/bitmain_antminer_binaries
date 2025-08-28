
void my_log_curses(int prio,char *datetime,char *str,_Bool force)

{
  pthread_mutex_t *lock;
  char *file;
  char *file_00;
  char *file_01;
  char *extraout_r1;
  char *func;
  char *func_00;
  char *extraout_r2;
  uint line;
  int line_00;
  int line_01;
  uint extraout_r3;
  
  line = (uint)force;
  lock = (pthread_mutex_t *)prio;
  file = datetime;
  if (str != (char *)0x0) {
    pthread_mutex_trylock((pthread_mutex_t *)&console_lock);
    _mutex_unlock_noyield((pthread_mutex_t *)0x26,file_01,func_00,line_01);
    lock = (pthread_mutex_t *)(*selective_yield)();
    file = extraout_r1;
    str = extraout_r2;
    line = extraout_r3;
  }
  _mutex_lock(lock,file,str,line);
  printf("%s%s%s",prio,datetime,"                    \n");
  _mutex_unlock_noyield((pthread_mutex_t *)0x33,file_00,func,line_00);
  (*selective_yield)();
  return;
}

