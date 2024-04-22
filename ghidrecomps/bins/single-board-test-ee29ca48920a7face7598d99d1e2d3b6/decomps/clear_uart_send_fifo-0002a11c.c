
uint clear_uart_send_fifo(byte param_1)

{
  uint uVar1;
  char acStack_420 [1024];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_18 = 0;
  local_1c = 0;
  local_10 = 0;
  local_14 = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_420,0x400,"--- %s\n","clear_uart_send_fifo");
    _applog(2,acStack_420,0);
  }
  pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  switch(param_1) {
  case 0:
    local_10 = 0x18;
    local_c = 0x400;
    local_18 = 0x404;
    local_20 = 0x405;
    break;
  case 1:
    local_10 = 0x10;
    local_c = 0x400;
    local_18 = 0x406;
    local_20 = 0x407;
    break;
  case 2:
    local_10 = 8;
    local_c = 0x400;
    local_18 = 0x408;
    local_20 = 0x409;
    break;
  case 3:
    local_10 = 0;
    local_c = 0x400;
    local_18 = 0x40a;
    local_20 = 0x40b;
    break;
  case 4:
    local_10 = 0x18;
    local_c = 0x401;
    local_18 = 0x40c;
    local_20 = 0x40d;
    break;
  case 5:
    local_10 = 0x10;
    local_c = 0x401;
    local_18 = 0x40e;
    local_20 = 0x40f;
    break;
  case 6:
    local_10 = 8;
    local_c = 0x401;
    local_18 = 0x410;
    local_20 = 0x411;
    break;
  case 7:
    local_10 = 0;
    local_c = 0x401;
    local_18 = 0x412;
    local_20 = 0x413;
    break;
  case 8:
    local_10 = 0x18;
    local_c = 0x402;
    local_18 = 0x414;
    local_20 = 0x415;
    break;
  case 9:
    local_10 = 0x10;
    local_c = 0x402;
    local_18 = 0x416;
    local_20 = 0x417;
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_420,0x400,"%s: The uart%d is not supported!!!\n","clear_uart_send_fifo",
               (uint)param_1);
      _applog(2,acStack_420,0);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
    return 1;
  }
  local_14 = 0;
  do {
    uVar1 = read_axi_fpga(local_c);
    local_1c = uVar1 >> (local_10 & 0xff) & 0xff;
    if (local_1c == 0xff) {
      pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
      return 0;
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_420,0x400,"%s: waiting fpga uart%d clear send fifo space ...\n",
               "clear_uart_send_fifo",(uint)param_1);
      _applog(2,acStack_420,0);
    }
    usleep(3000);
    local_14 = local_14 + 1;
  } while (local_14 < 0x15);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_420,0x400,"%s: uart%d always dose not has enough send fifo space, break\n",
             "clear_uart_send_fifo",(uint)param_1);
    _applog(2,acStack_420,0);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  return local_1c;
}

