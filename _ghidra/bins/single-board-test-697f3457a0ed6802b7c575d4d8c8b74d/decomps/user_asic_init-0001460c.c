
int user_asic_init(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  int check_times;
  
  iVar2 = runtime->chain_id;
  check_times = 3;
  do {
    check_asic_num(runtime);
    if (0 < runtime->chain_status[iVar2].real_asic_num) break;
    sleep(1);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"check again check_times = %d\n",check_times);
      _applog(2,tmp42,false);
    }
    check_times = check_times + -1;
  } while (0 < check_times);
  if (check_times < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"check asic faile",0x10);
      tmp42[0x10] = 'd';
      tmp42[0x11] = '\n';
      tmp42[0x12] = '\0';
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    runtime->start_recv = 0;
    if (runtime->baudrate != 0x1c200) {
      sleep(1);
      (*runtime->set_baud)(runtime->chain_status[iVar2].fd,runtime->baudrate);
      sleep(1);
      uart_exit(runtime->chain_status[iVar2].fd);
      sleep(1);
      iVar1 = uart_init(runtime->chain_status[iVar2].comport,runtime->baudrate);
      runtime->chain_status[iVar2].fd = iVar1;
      sleep(1);
    }
    runtime->start_recv = 1;
    iVar2 = 0;
  }
  return iVar2;
}

