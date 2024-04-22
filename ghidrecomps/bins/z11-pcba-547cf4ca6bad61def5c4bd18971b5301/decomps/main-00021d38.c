
undefined4 main(void)

{
  char acStack_428 [1024];
  char acStack_28 [32];
  
  app_config_handle("/mnt/card/app_config.ini");
  memset(acStack_28,0,0x20);
  sprintf(acStack_28,"%s.log",DAT_00021e0c);
  app_conf._0_4_ = fopen(acStack_28,"w+");
  if ((FILE *)app_conf._0_4_ == (FILE *)0x0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_428,0x400,"open %s file error\n",acStack_28);
      _applog(2,acStack_428,0);
    }
  }
  else {
    start_pcba_test();
    fclose((FILE *)app_conf._0_4_);
  }
  return 0;
}

