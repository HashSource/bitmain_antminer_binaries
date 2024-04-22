
uint clear_uart_send_fifo(uchar which_chain)

{
  uint uVar1;
  uchar which_chain_local;
  char tmp42 [1024];
  uint max_fpga_can_send_uart_data_len;
  uint chain_send_buffer_addr;
  uint send_counter;
  uint bit_shift_num;
  uint chain_send_ready_addr;
  uint chain_send_fifo_status_addr;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","clear_uart_send_fifo");
    _applog(2,tmp42,false);
  }
  pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + which_chain));
  switch(which_chain) {
  case '\0':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x404;
    chain_send_buffer_addr = 0x405;
    break;
  case '\x01':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x406;
    chain_send_buffer_addr = 0x407;
    break;
  case '\x02':
    bit_shift_num = 8;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x408;
    chain_send_buffer_addr = 0x409;
    break;
  case '\x03':
    bit_shift_num = 0;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x40a;
    chain_send_buffer_addr = 0x40b;
    break;
  case '\x04':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x40c;
    chain_send_buffer_addr = 0x40d;
    break;
  case '\x05':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x40e;
    chain_send_buffer_addr = 0x40f;
    break;
  case '\x06':
    bit_shift_num = 8;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x410;
    chain_send_buffer_addr = 0x411;
    break;
  case '\a':
    bit_shift_num = 0;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x412;
    chain_send_buffer_addr = 0x413;
    break;
  case '\b':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x402;
    chain_send_ready_addr = 0x414;
    chain_send_buffer_addr = 0x415;
    break;
  case '\t':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x402;
    chain_send_ready_addr = 0x416;
    chain_send_buffer_addr = 0x417;
    break;
  default:
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","clear_uart_send_fifo",
               (uint)which_chain);
      _applog(2,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_chain));
    return 1;
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x400,"chain_send_ready_addr: 0x%08x, chain_send_buffer_addr: 0x%08x",
             chain_send_ready_addr,chain_send_buffer_addr);
    _applog(4,tmp42,false);
  }
  send_counter = 0;
  do {
    uVar1 = read_axi_fpga(chain_send_fifo_status_addr);
    uVar1 = uVar1 >> bit_shift_num & 0xff;
    if (uVar1 == 0xff) {
      pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_chain));
      return 0;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: waiting fpga uart%d clear send fifo space ...\n",
               "clear_uart_send_fifo",(uint)which_chain);
      _applog(2,tmp42,false);
    }
    usleep(3000);
    send_counter = send_counter + 1;
  } while (send_counter < 0x15);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: uart%d always dose not has enough send fifo space, break\n",
             "clear_uart_send_fifo",(uint)which_chain);
    _applog(2,tmp42,false);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_chain));
  return uVar1;
}

