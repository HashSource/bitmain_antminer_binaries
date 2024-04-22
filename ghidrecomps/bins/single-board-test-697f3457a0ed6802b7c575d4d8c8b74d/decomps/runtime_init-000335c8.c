
void runtime_init(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  
  work_list_init((runtime->nonce_verify_info).work_len);
  reg_list_init();
  iVar1 = runtime->chain_id;
  sleep(1);
  pthread_create(&runtime->chain_status[iVar1].p_dispatch,(pthread_attr_t *)0x0,
                 handle_asic_response + 1,runtime);
  pthread_create(&runtime->p_scanhash,(pthread_attr_t *)0x0,nonce_scanhash_loop + 1,runtime);
  runtime->start_recv = 1;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","runtime_init");
    _applog(2,tmp42,false);
  }
  return;
}

