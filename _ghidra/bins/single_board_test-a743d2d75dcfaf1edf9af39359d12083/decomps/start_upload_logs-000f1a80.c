
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_upload_logs(void)

{
  char tmp42 [2048];
  pthread_t log_thread;
  
  log_thread = 0;
  clear_cache_file();
  pthread_create(&log_thread,(pthread_attr_t *)0x0,(__start_routine *)0xf1819,(void *)0x0);
  snprintf(tmp42,0x800,"log_thread:%lu\n",log_thread);
  _applog(5,tmp42,false);
  return;
}

