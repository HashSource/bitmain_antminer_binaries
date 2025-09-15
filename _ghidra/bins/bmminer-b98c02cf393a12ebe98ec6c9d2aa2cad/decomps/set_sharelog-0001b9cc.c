
undefined4 set_sharelog(char *param_1)

{
  char *__fd;
  char *__format;
  bool bVar1;
  char *local_814;
  char local_810 [36];
  undefined2 local_7ec;
  
  local_814 = "";
  __fd = (char *)strtol(param_1,&local_814,10);
  bVar1 = __fd == (char *)0x0;
  if (-1 < (int)__fd) {
    bVar1 = *local_814 == '\0';
  }
  if (bVar1) {
    sharelog_file = fdopen((int)__fd,"a");
    if (sharelog_file != (FILE *)0x0) {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return 0;
    }
    __format = "Failed to open fd %u for share log";
    param_1 = __fd;
  }
  else {
    if ((*param_1 == '-') && (param_1[1] == '\0')) {
      sharelog_file = (FILE *)stdout;
      if (stdout != 0) {
        sharelog_file = (FILE *)stdout;
        return 0;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        sharelog_file = (FILE *)stdout;
        return 0;
      }
      builtin_strncpy(local_810,"Standard output missing for share lo",0x24);
      local_7ec = 0x67;
      _applog(3,local_810,0);
      return 0;
    }
    sharelog_file = fopen(param_1,"a");
    if (sharelog_file != (FILE *)0x0) {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return 0;
    }
    __format = "Failed to open %s for share log";
  }
  sharelog_file = (FILE *)0x0;
  snprintf(local_810,0x800,__format,param_1);
  _applog(3,local_810,0);
  return 0;
}

