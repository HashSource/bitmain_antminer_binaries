
void pcba_runtime_init(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int bt8d;
  int chainid;
  
  iVar2 = runtime->chain_id;
  runtime->chain_status[iVar2].design_asic_num = app_conf->asic_num;
  reg_list_init();
  work_list_init((runtime->nonce_verify_info).work_len);
  iVar1 = uart_init(runtime->chain_status[iVar2].comport,0x1c200);
  runtime->chain_status[iVar2].fd = iVar1;
  sleep(1);
  if (runtime->baudrate != 0x1c200) {
    iVar1 = baud2bt8d(runtime->baudrate);
    if (iVar1 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Don\'t support current baudrate, set to 11520",0x2c);
        tmp42[0x2c] = '0';
        tmp42[0x2d] = '\n';
        tmp42[0x2e] = '\0';
        _applog(2,tmp42,false);
      }
    }
    else {
      (*runtime->set_baud)(runtime->chain_status[iVar2].fd,runtime->baudrate);
      usleep(200000);
      set_fpga_baud((uchar)iVar1);
      sleep(1);
    }
  }
  pthread_create(&runtime->chain_status[iVar2].p_dispatch,(pthread_attr_t *)0x0,
                 (__start_routine *)0x330a5,runtime);
  sleep(1);
  pthread_create(&runtime->p_scanhash,(pthread_attr_t *)0x0,(__start_routine *)0x213c5,runtime);
  runtime->start_recv = 1;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","pcba_runtime_init");
    _applog(2,tmp42,false);
  }
  return;
}

