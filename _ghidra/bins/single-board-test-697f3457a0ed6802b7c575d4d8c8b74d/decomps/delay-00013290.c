
void delay(int seconds)

{
  int seconds_local;
  char tmp42 [1024];
  int i;
  
  i = 0;
  while (i < seconds) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"remain %d seconds......\n",seconds - (i + 1));
      _applog(2,tmp42,false);
    }
    sleep(1);
    i = i + 1;
  }
  return;
}

