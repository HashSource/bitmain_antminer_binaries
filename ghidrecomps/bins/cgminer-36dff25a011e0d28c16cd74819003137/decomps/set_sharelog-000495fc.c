
char * set_sharelog(char *arg)

{
  int iVar1;
  char *arg_local;
  char tmp42 [2048];
  char *r;
  long i;
  
  r = "";
  i = strtol(arg,&r,10);
  if ((*r == '\0') && (-1 < i)) {
    sharelog_file = (FILE *)fdopen(i,"a");
    if ((sharelog_file == (FILE *)0x0) &&
       (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Failed to open fd %u for share log",i);
      _applog(3,tmp42,false);
    }
  }
  else {
    iVar1 = strcmp(arg,"-");
    if (iVar1 == 0) {
      sharelog_file = stdout;
      if ((stdout == (FILE *)0x0) &&
         (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Standard output missing for share lo",0x24);
        tmp42[0x24] = 'g';
        tmp42[0x25] = '\0';
        _applog(3,tmp42,false);
      }
    }
    else {
      sharelog_file = (FILE *)fopen(arg,"a");
      if ((sharelog_file == (FILE *)0x0) &&
         (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Failed to open %s for share log",arg);
        _applog(3,tmp42,false);
      }
    }
  }
  return (char *)0x0;
}

