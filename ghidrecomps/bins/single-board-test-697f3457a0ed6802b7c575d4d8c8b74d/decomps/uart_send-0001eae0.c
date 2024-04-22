
uint uart_send(uchar which_uart,uchar *buf,uint length)

{
  uint uVar1;
  uint length_local;
  uchar *buf_local;
  uchar which_uart_local;
  char tmp42 [1024];
  uchar send_buf [512];
  uint max_fpga_can_send_uart_data_len;
  uint send_data_len;
  int send_loop;
  uint bit_shift_num;
  uint chain_send_buffer_addr;
  uint chain_send_ready_addr;
  uint chain_send_fifo_status_addr;
  uint send_data;
  int i;
  int send_counter;
  
  memset(send_buf,0,0x200);
  send_data = 0;
  pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + which_uart));
  switch(which_uart) {
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
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 2)) {
      return 0;
    }
    snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","uart_send",(uint)which_uart);
    _applog(2,tmp42,false);
    return 0;
  }
  send_counter = 0;
  do {
    uVar1 = read_axi_fpga(chain_send_fifo_status_addr);
    if (length <= (uVar1 >> bit_shift_num & 0xff)) {
      send_counter = 0;
      while( true ) {
        uVar1 = read_axi_fpga(chain_send_ready_addr);
        if (-1 < (int)uVar1) {
          memcpy(send_buf,buf,length);
          for (i = 0; i < (int)(length >> 2); i = i + 1) {
            send_data = (uint)send_buf[i * 4 + 2] << 8 |
                        (uint)send_buf[i * 4] << 0x18 | (uint)send_buf[i * 4 + 1] << 0x10 |
                        (uint)send_buf[i * 4 + 3];
            write_axi_fpga(chain_send_buffer_addr,send_data);
          }
          uVar1 = length & 3;
          if (uVar1 != 0) {
            if (uVar1 == 2) {
              send_data = (uint)send_buf[i * 4 + 1] << 0x10 | (uint)send_buf[i * 4] << 0x18;
            }
            else if (uVar1 == 3) {
              send_data = (uint)send_buf[i * 4 + 2] << 8 |
                          (uint)send_buf[i * 4] << 0x18 | (uint)send_buf[i * 4 + 1] << 0x10;
            }
            else if (uVar1 == 1) {
              send_data = (uint)send_buf[i * 4] << 0x18;
            }
            else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"%s: the uart%d send left data is 4*N length, error!!!\n",
                       "uart_send",(uint)which_uart);
              _applog(2,tmp42,false);
            }
            write_axi_fpga(chain_send_buffer_addr,send_data);
          }
          write_axi_fpga(chain_send_ready_addr,length | 0x80000000);
          pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_uart));
          return length;
        }
        if (0x14 < send_counter) break;
        send_counter = send_counter + 1;
        usleep(3000);
      }
      pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_uart));
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"%s: uart%d always busy, break\n","uart_send",(uint)which_uart);
        _applog(2,tmp42,false);
      }
      return 0;
    }
    usleep(3000);
    send_counter = send_counter + 1;
  } while (send_counter < 0x15);
  pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_uart));
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: uart%d always dose not has enough send fifo space, break\n",
             "uart_send",(uint)which_uart);
    _applog(2,tmp42,false);
  }
  return 0;
}

