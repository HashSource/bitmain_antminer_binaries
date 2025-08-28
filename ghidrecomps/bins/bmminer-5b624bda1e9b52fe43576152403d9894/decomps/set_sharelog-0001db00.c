
/* WARNING: Unknown calling convention */

char * set_sharelog(char *arg)

{
  char *__fd;
  char *__format;
  char *r;
  char tmp42 [2048];
  
  r = "";
  __fd = (char *)strtol(arg,&r,10);
  if ((*r == '\0') && (-1 < (int)__fd)) {
    sharelog_file = (FILE *)fdopen((int)__fd,"a");
    if (sharelog_file != (FILE *)0x0) {
      return (char *)0x0;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
      return (char *)0x0;
    }
    __format = "Failed to open fd %u for share log";
    arg = __fd;
  }
  else {
    if ((*arg == '-') && (arg[1] == '\0')) {
      sharelog_file = stdout;
      if (stdout != (FILE *)0x0) {
        sharelog_file = stdout;
        return (char *)0x0;
      }
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
        sharelog_file = stdout;
        return (char *)0x0;
      }
      builtin_strncpy(tmp42,"Standard output missing for share lo",0x24);
      tmp42[0x24] = 'g';
      tmp42[0x25] = '\0';
      _applog(3,tmp42,false);
      return (char *)0x0;
    }
    sharelog_file = (FILE *)fopen(arg,"a");
    if (sharelog_file != (FILE *)0x0) {
      return (char *)0x0;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
      return (char *)0x0;
    }
    __format = "Failed to open %s for share log";
  }
  sharelog_file = (FILE *)0x0;
  snprintf(tmp42,0x800,__format,arg);
  _applog(3,tmp42,false);
  return (char *)0x0;
}

