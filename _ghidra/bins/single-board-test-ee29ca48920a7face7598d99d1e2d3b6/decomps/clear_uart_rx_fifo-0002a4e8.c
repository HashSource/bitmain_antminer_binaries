
undefined4 clear_uart_rx_fifo(byte param_1)

{
  undefined4 uVar1;
  char acStack_414 [1024];
  void *local_14;
  size_t local_10;
  size_t local_c;
  
  local_c = 0;
  local_10 = 0;
  local_14 = (void *)0x0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_414,0x400,"--- %s\n","clear_uart_rx_fifo");
    _applog(2,acStack_414,0);
  }
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  local_10 = check_how_many_uart_data_in_fpga(param_1);
  if (local_10 == 0) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
    uVar1 = 0;
  }
  else {
    local_14 = malloc(local_10);
    if (local_14 == (void *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_414,0x400,"%s: uart%d malloc buffer error\n","clear_uart_rx_fifo",
                 (uint)param_1);
        _applog(2,acStack_414,0);
      }
      local_14 = (void *)0x0;
      usleep(500000);
      pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
      uVar1 = 1;
    }
    else {
      local_c = read_uart_data_in_fpga(param_1,local_14,local_10);
      if (local_c == local_10) {
        free(local_14);
        local_14 = (void *)0x0;
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
        uVar1 = 1;
      }
      else {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_414,0x400,"%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n",
                   "clear_uart_rx_fifo",(uint)param_1,local_10,local_c);
          _applog(2,acStack_414,0);
        }
        free(local_14);
        local_14 = (void *)0x0;
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

