
void _applog(undefined4 param_1,undefined4 param_2,undefined param_3)

{
  int iVar1;
  char acStack_6c [64];
  __time_t local_2c;
  timeval local_28;
  tm *local_20;
  int local_1c;
  
  local_28.tv_sec = 0;
  local_28.tv_usec = 0;
  gettimeofday(&local_28,(__timezone_ptr_t)0x0);
  local_2c = local_28.tv_sec;
  local_1c = local_28.tv_usec / 1000;
  local_20 = localtime(&local_2c);
  snprintf(acStack_6c,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",local_20->tm_year + 0x76c,
           local_20->tm_mon + 1,local_20->tm_mday,local_20->tm_hour,local_20->tm_min,
           local_20->tm_sec,local_1c);
  if (app_conf._0_4_ != 0) {
    iVar1 = fileno((FILE *)app_conf._0_4_);
    iVar1 = isatty(iVar1);
    if (iVar1 == 0) {
      fprintf((FILE *)app_conf._0_4_,"%s%s",acStack_6c,param_2);
      fflush((FILE *)app_conf._0_4_);
    }
  }
  if (app_conf._44_4_ != 1) {
    my_log_curses(param_1,acStack_6c,param_2,param_3);
  }
  return;
}

