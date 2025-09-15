
void close_key(void)

{
  char local_410 [12];
  undefined2 local_404;
  undefined1 local_402;
  
  close(cgpu._44_4_);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    builtin_strncpy(local_410,"key closed!!",0xc);
    local_404 = 0xa21;
    local_402 = 0;
    _applog(2,local_410,0);
  }
  return;
}

