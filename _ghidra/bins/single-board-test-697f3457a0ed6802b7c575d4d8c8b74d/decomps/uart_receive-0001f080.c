
uint uart_receive(uchar which_uart,uchar *buf,uint buf_length)

{
  uint length;
  uint buf_length_local;
  uchar *buf_local;
  uchar which_uart_local;
  uint nbytes;
  uint len;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + which_uart));
  length = check_how_many_uart_data_in_fpga(which_uart);
  if (length < buf_length) {
    if (length == 0) {
      len = 0;
    }
    else {
      len = read_uart_data_in_fpga(which_uart,buf,length);
    }
  }
  else {
    len = read_uart_data_in_fpga(which_uart,buf,buf_length);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_uart));
  return len;
}

