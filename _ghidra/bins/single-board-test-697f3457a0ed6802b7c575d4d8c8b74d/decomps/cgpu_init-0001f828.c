
int cgpu_init(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","cgpu_init");
    _applog(2,tmp42,false);
  }
  memset(&cgpu,0,0x60);
  iVar1 = open_lcd();
  if (iVar1 < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"!!! %s: open lcd driver error\n","cgpu_init");
      _applog(2,tmp42,false);
    }
  }
  else {
    memset(lcd_output,0x20,0x40);
    write(cgpu.lcd_fd,lcd_output,0x40);
    iVar1 = open_key();
    if (iVar1 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"!!! %s: open start key error\n","cgpu_init");
        _applog(2,tmp42,false);
      }
    }
    else {
      iVar1 = open_red_led();
      if (iVar1 < 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"!!! %s: open red led error\n","cgpu_init");
          _applog(2,tmp42,false);
        }
      }
      else {
        iVar1 = open_green_led();
        if (iVar1 < 1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            snprintf(tmp42,0x400,"!!! %s: open green led error\n","cgpu_init");
            _applog(2,tmp42,false);
          }
        }
        else {
          iVar1 = bitmain_axi_init();
          if (-1 < iVar1) {
            cgpu.runtime = runtime;
            patten_info_init();
            patten_load("/mnt/card/");
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
  return -1;
}

