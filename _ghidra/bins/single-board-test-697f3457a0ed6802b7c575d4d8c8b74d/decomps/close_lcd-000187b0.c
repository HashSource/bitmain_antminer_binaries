
/* WARNING: Unknown calling convention */

int close_lcd(void)

{
  int iVar1;
  char tmp42 [1024];
  int ret;
  
  iVar1 = close(cgpu.lcd_fd);
  if (iVar1 == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"lcd closed!!",0xc);
      tmp42[0xc] = '!';
      tmp42[0xd] = '\n';
      tmp42[0xe] = '\0';
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"lcd close failed!!!\n",0x14);
    tmp42[0x14] = '\0';
    _applog(2,tmp42,false);
  }
  return iVar1;
}

