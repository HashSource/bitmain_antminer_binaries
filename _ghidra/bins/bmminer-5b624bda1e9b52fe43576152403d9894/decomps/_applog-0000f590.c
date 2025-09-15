
/* WARNING: Unknown calling convention */

void _applog(int prio,char *str,_Bool force)

{
  FILE *__s;
  tm *ptVar1;
  int iVar2;
  size_t sVar3;
  __time_t local_6c;
  timeval tv;
  char datetime [64];
  
  tv.tv_sec = (__time_t)use_syslog;
  if (tv.tv_sec == 0) {
    tv.tv_usec = tv.tv_sec;
    cgtime(&tv);
    local_6c = tv.tv_sec;
    iVar2 = tv.tv_usec / 1000;
    ptVar1 = localtime(&local_6c);
    snprintf(datetime,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar1->tm_year + 0x76c,
             ptVar1->tm_mon + 1,ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,iVar2)
    ;
    iVar2 = fileno(stderr);
    iVar2 = isatty(iVar2);
    if (iVar2 == 0) {
      fprintf(stderr,"%s%s\n",datetime,str);
      fflush(stderr);
    }
    if ((g_logfile_enable != false) &&
       ((g_log_file != (FILE *)0x0 ||
        (g_log_file = (FILE *)fopen(g_logfile_path,g_logfile_openflag), g_log_file != (FILE *)0x0)))
       ) {
      __s = g_log_file;
      sVar3 = strlen(datetime);
      fwrite(datetime,sVar3,1,(FILE *)__s);
      sVar3 = strlen(str);
      fwrite(str,sVar3,1,(FILE *)g_log_file);
      fwrite("\n",1,1,(FILE *)g_log_file);
      fflush((FILE *)g_log_file);
    }
    if ((opt_quiet == false) || (prio == 3)) {
      my_log_curses((int)datetime,str,(char *)(uint)force,opt_quiet);
    }
  }
  else {
    syslog(prio | 0x80,"%s",str);
  }
  return;
}

