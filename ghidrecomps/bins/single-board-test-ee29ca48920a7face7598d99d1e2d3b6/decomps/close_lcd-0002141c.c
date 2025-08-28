
int close_lcd(void)

{
  char local_414 [12];
  undefined4 local_408;
  char local_404 [1008];
  int local_14;
  
  local_14 = 0xffffffff;
  local_14 = close(cgpu._36_4_);
  if (local_14 == 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      builtin_strncpy(local_414,"lcd closed!!",0xc);
      local_408 = CONCAT13(local_408._3_1_,0xa21);
      _applog(2,local_414,0);
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    builtin_strncpy(local_414,"lcd close fa",0xc);
    local_408._0_1_ = 'i';
    local_408._1_1_ = 'l';
    local_408._2_1_ = 'e';
    local_408._3_1_ = 'd';
    builtin_strncpy(local_404,"!!!\n",4);
    local_404[4] = 0;
    _applog(2,local_414,0);
  }
  return local_14;
}

