
int32_t pt_send_work(uint32_t chain,void *args)

{
  int iVar1;
  int32_t iVar2;
  void *args_local;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  pattern_runtime_ctx *ctx;
  int ret;
  
  (**(code **)((int)args + 0x218d4))();
  iVar1 = pthread_create(&g_send_handle,(pthread_attr_t *)0x0,(__start_routine *)0x505d9,args);
  if (iVar1 == 0) {
    pthread_join(g_send_handle,(void **)0x0);
    usleep(200000);
    iVar2 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : create send work thread failed\n","pt_send_work");
    builtin_strncpy(tmp1,"create send work thread fail",0x1c);
    tmp1[0x1c] = 'e';
    tmp1[0x1d] = 'd';
    tmp1[0x1e] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar2 = -1;
  }
  return iVar2;
}

