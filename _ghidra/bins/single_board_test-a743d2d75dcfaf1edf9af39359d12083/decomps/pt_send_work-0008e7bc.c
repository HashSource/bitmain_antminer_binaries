
int32_t pt_send_work(uint32_t chain,void *args)

{
  int iVar1;
  int32_t iVar2;
  void *args_local;
  uint32_t chain_local;
  char tmp42 [256];
  pattern_runtime_ctx *ctx;
  int ret;
  
  (**(code **)((int)args + 0x55518))();
  iVar1 = pthread_create(&g_send_handle,(pthread_attr_t *)0x0,(__start_routine *)0x8e241,args);
  if (iVar1 == 0) {
    pthread_join(g_send_handle,(void **)0x0);
    usleep(100000);
    iVar2 = 0;
  }
  else {
    builtin_strncpy(tmp42,"create send work thread failed\n",0x20);
    puts(tmp42);
    iVar2 = -1;
  }
  return iVar2;
}

