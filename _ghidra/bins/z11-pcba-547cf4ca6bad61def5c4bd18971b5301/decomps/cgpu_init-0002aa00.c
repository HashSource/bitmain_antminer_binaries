
undefined4 cgpu_init(void)

{
  char acStack_40c [1024];
  int local_c;
  
  local_c = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_40c,0x400,"--- %s\n","cgpu_init");
    _applog(2,acStack_40c,0);
  }
  memset(cgpu,0,0x5c);
  local_c = open_lcd();
  if (local_c < 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_40c,0x400,"!!! %s: open lcd driver error\n","cgpu_init");
      _applog(2,acStack_40c,0);
    }
  }
  else {
    memset(lcd_buffer + 0x20,0x20,0x40);
    write(cgpu._36_4_,lcd_buffer + 0x20,0x40);
    local_c = open_key();
    if (local_c < 1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_40c,0x400,"!!! %s: open start key error\n","cgpu_init");
        _applog(2,acStack_40c,0);
      }
    }
    else {
      local_c = open_red_led();
      if (local_c < 1) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_40c,0x400,"!!! %s: open red led error\n","cgpu_init");
          _applog(2,acStack_40c,0);
        }
      }
      else {
        local_c = open_green_led();
        if (local_c < 1) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
            snprintf(acStack_40c,0x400,"!!! %s: open green led error\n","cgpu_init");
            _applog(2,acStack_40c,0);
          }
        }
        else {
          local_c = bitmain_axi_init();
          if (-1 < local_c) {
            patten_info_init();
            patten_load();
            return 0;
          }
          bitmain_axi_close();
        }
        close_green_led();
      }
      close_red_led();
    }
    close_key();
  }
  close_lcd();
  return 0xffffffff;
}

