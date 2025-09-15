
void runtime_exit(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  
  runtime->start_recv = 0;
  iVar1 = runtime->chain_id;
  usleep(300000);
  pthread_cancel(runtime->p_scanhash);
  pthread_join(runtime->p_scanhash,(void **)0x0);
  pthread_cancel(runtime->chain_status[iVar1].p_dispatch);
  pthread_join(runtime->chain_status[iVar1].p_dispatch,(void **)0x0);
  reg_list_exit();
  work_list_exit();
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","runtime_exit");
    _applog(2,tmp42,false);
  }
  return;
}

