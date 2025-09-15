
void _applog(int prio,char *str,_Bool force)

{
  tm *ptVar1;
  int iVar2;
  size_t sVar3;
  _Bool force_local;
  char *str_local;
  int prio_local;
  char datetime [64];
  time_t tmp_time;
  timeval tv;
  tm *tm;
  int ms;
  
  if (use_syslog) {
    syslog(prio | 0x80,"%s\n",str);
  }
  else {
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    cgtime(&tv);
    tmp_time = tv.tv_sec;
    iVar2 = tv.tv_usec / 1000;
    ptVar1 = localtime(&tmp_time);
    snprintf(datetime,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar1->tm_year + 0x76c,
             ptVar1->tm_mon + 1,ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,iVar2)
    ;
    iVar2 = fileno(stderr);
    iVar2 = isatty(iVar2);
    if (iVar2 == 0) {
      if (g_logfile_no_datetime == false) {
        fprintf(stderr,"%s%s\n",datetime,str);
        fflush(stderr);
      }
      else {
        fputs(str,stderr);
        fflush(stderr);
      }
    }
    if (g_logfile_enable != false) {
      if (g_log_file == (FILE *)0x0) {
        g_log_file = (FILE *)fopen(g_logfile_path,g_logfile_openflag);
      }
      if (g_log_file != (FILE *)0x0) {
        if (g_logfile_no_datetime != true) {
          sVar3 = strlen(datetime);
          fwrite(datetime,sVar3,1,(FILE *)g_log_file);
        }
        sVar3 = strlen(str);
        fwrite(str,sVar3,1,(FILE *)g_log_file);
        if (g_logfile_no_datetime != true) {
          fwrite(&DAT_0007a67c,1,1,(FILE *)g_log_file);
        }
        fflush((FILE *)g_log_file);
      }
    }
    my_log_curses(prio,datetime,str,force);
  }
  return;
}

