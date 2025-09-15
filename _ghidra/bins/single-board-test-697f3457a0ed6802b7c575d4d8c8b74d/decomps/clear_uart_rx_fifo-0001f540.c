
uint clear_uart_rx_fifo(uchar which_chain)

{
  uint uVar1;
  uchar *buf_00;
  uint uVar2;
  uchar which_chain_local;
  char tmp42 [1024];
  uchar *buf;
  uint nbytes;
  uint len;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","clear_uart_rx_fifo");
    _applog(2,tmp42,false);
  }
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
  uVar1 = check_how_many_uart_data_in_fpga(which_chain);
  if (uVar1 == 0) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
    uVar1 = 0;
  }
  else {
    buf_00 = (uchar *)malloc(uVar1);
    if (buf_00 == (uchar *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"%s: uart%d malloc buffer error\n","clear_uart_rx_fifo",
                 (uint)which_chain);
        _applog(2,tmp42,false);
      }
      usleep(500000);
      pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
      uVar1 = 1;
    }
    else {
      uVar2 = read_uart_data_in_fpga(which_chain,buf_00,uVar1);
      if (uVar2 == uVar1) {
        free(buf_00);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
        uVar1 = 1;
      }
      else {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n",
                   "clear_uart_rx_fifo",(uint)which_chain,uVar1,uVar2);
          _applog(2,tmp42,false);
        }
        free(buf_00);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

