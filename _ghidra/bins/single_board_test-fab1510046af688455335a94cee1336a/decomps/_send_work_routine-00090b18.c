
void * _send_work_routine(void *args)

{
  pthread_t __th;
  void *args_local;
  pattern_runtime_ctx *ctx;
  
  (**(code **)((int)args + 0x55728))((g_rt.config)->chain,args);
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

