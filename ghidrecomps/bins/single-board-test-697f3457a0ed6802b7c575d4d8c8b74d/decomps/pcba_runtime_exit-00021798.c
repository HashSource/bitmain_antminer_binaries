
void pcba_runtime_exit(runtime_base_t *runtime)

{
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  
  runtime->start_recv = 0;
  usleep(1000000);
  pthread_cancel(runtime->p_scanhash);
  pthread_join(runtime->p_scanhash,(void **)0x0);
  pthread_cancel(runtime->chain_status[runtime->chain_id].p_dispatch);
  pthread_join(runtime->chain_status[runtime->chain_id].p_dispatch,(void **)0x0);
  uart_exit(runtime->chain_status[runtime->chain_id].fd);
  reg_list_exit();
  work_list_exit();
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","pcba_runtime_exit");
    _applog(2,tmp42,false);
  }
  return;
}

