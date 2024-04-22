
void my_log_curses(int prio,char *datetime,char *str,_Bool force)

{
  _Bool force_local;
  char *str_local;
  char *datetime_local;
  int prio_local;
  
  if ((!opt_quiet) || (prio == 3)) {
    if (force) {
      _mutex_trylock(&console_lock,"logging.c","my_log_curses",0x28);
      _mutex_unlock(&console_lock,"logging.c","my_log_curses",0x29);
    }
    _mutex_lock(&console_lock,"logging.c","my_log_curses",0x34);
    printf("%s%s%s",datetime,str,"                    \n");
    _mutex_unlock(&console_lock,"logging.c","my_log_curses",0x36);
  }
  return;
}

