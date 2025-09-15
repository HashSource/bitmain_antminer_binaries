
void _applog(int prio,char *str,_Bool force)

{
  tm *ptVar1;
  int iVar2;
  _Bool force_local;
  char *str_local;
  int prio_local;
  char datetime [64];
  time_t tmp_time;
  timeval tv;
  tm *tm;
  int ms;
  
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  tmp_time = tv.tv_sec;
  iVar2 = tv.tv_usec / 1000;
  ptVar1 = localtime(&tmp_time);
  snprintf(datetime,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar1->tm_year + 0x76c,
           ptVar1->tm_mon + 1,ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,iVar2);
  if (app_conf->dbg_fp != (FILE *)0x0) {
    iVar2 = fileno((FILE *)app_conf->dbg_fp);
    iVar2 = isatty(iVar2);
    if (iVar2 == 0) {
      fprintf((FILE *)app_conf->dbg_fp,"%s%s",datetime,str);
      fflush((FILE *)app_conf->dbg_fp);
    }
  }
  if (app_conf->work_mode != 1) {
    my_log_curses(prio,datetime,str,force);
  }
  return;
}

