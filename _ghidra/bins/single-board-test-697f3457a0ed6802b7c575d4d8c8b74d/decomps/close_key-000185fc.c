
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void close_key(void)

{
  char tmp42 [1024];
  
  close(cgpu.key_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"key closed!!",0xc);
    tmp42[0xc] = '!';
    tmp42[0xd] = '\n';
    tmp42[0xe] = '\0';
    _applog(2,tmp42,false);
  }
  return;
}

