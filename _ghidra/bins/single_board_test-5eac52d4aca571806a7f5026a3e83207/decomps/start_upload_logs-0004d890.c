
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_upload_logs(void)

{
  pthread_t log_thread;
  
  log_thread = 0;
  clear_cache_file();
  pthread_create(&log_thread,(pthread_attr_t *)0x0,(__start_routine *)0x4d6bd,(void *)0x0);
  return;
}

