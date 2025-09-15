
void clear_uart_rx_fifo(uint param_1)

{
  size_t __size;
  void *__ptr;
  size_t sVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
  __size = check_how_many_uart_data_in_fpga(param_1 & 0xff);
  if (__size == 0) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
  }
  else {
    __ptr = malloc(__size);
    if (__ptr == (void *)0x0) {
      printf("%s:%d","clear_uart_rx_fifo",0x33f);
      printf("%s: uart%d malloc buffer error\n","clear_uart_rx_fifo",param_1);
      usleep(500000);
      pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
    }
    else {
      sVar1 = read_uart_data_in_fpga(param_1,__ptr,__size);
      if (sVar1 == __size) {
        free(__ptr);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
      }
      else {
        printf("%s:%d","clear_uart_rx_fifo",0x348);
        printf("%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n","clear_uart_rx_fifo",
               param_1,__size,sVar1);
        free(__ptr);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
      }
    }
  }
  return;
}

