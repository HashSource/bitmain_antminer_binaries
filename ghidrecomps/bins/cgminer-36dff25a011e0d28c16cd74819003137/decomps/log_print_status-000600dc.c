
void log_print_status(cgpu_info *cgpu)

{
  cgpu_info *cgpu_local;
  char tmp42 [2048];
  char logline [255];
  
  get_statline(logline,0xff,cgpu);
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s",logline);
    _applog(4,tmp42,false);
  }
  return;
}

