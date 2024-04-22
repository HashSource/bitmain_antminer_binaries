
/* WARNING: Unknown calling convention */

void StartHttpThread(void)

{
  char tmp42 [2048];
  pthread_attr_t tattr_ctrl;
  pthread_t tid_ctrl;
  int stacksize_ctrl;
  int ret;
  
  ret = pthread_attr_init((pthread_attr_t *)&tattr_ctrl);
  stacksize_ctrl = 0x200000;
  ret = pthread_attr_setstacksize((pthread_attr_t *)&tattr_ctrl,0x200000);
  ret = pthread_create(&tid_ctrl,(pthread_attr_t *)&tattr_ctrl,httpListenThread + 1,(void *)0x0);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"httpListenThread start ret=%d",ret);
    _applog(5,tmp42,false);
  }
  return;
}

