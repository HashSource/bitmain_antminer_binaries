
void _simplelog(int prio,char *str,_Bool force)

{
  int iVar1;
  _Bool force_local;
  char *str_local;
  int prio_local;
  
  if (use_syslog) {
    syslog(prio | 0x80,"%s",str);
  }
  else {
    iVar1 = fileno(stderr);
    iVar1 = isatty(iVar1);
    if (iVar1 == 0) {
      fprintf(stderr,"%s\n",str);
      fflush(stderr);
    }
    my_log_curses(prio,"",str,force);
  }
  return;
}

