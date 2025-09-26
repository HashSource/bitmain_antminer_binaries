
/* WARNING: Unknown calling convention */

void clear_uart_rx_fifo(uint32_t chain_id)

{
  uint32_t __size;
  uint8_t *buf;
  uint32_t uVar1;
  pthread_mutex_t *__mutex;
  char tmp42 [2048];
  
  __mutex = (pthread_mutex_t *)(uart_receive_mutex + chain_id);
  pthread_mutex_lock(__mutex);
  __size = check_how_many_uart_data_in_fpga((uchar)chain_id);
  if (__size != 0) {
    buf = (uint8_t *)malloc(__size);
    if (buf == (uint8_t *)0x0) {
      snprintf(tmp42,0x800,"%s: uart%d malloc buffer error\n","clear_uart_rx_fifo",chain_id);
      _applog(0,tmp42,false);
      usleep(500000);
      pthread_mutex_unlock(__mutex);
      return;
    }
    uVar1 = read_uart_data_in_fpga(chain_id,buf,__size);
    if (uVar1 != __size) {
      snprintf(tmp42,0x800,"%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n",
               "clear_uart_rx_fifo",chain_id,__size,uVar1);
      _applog(0,tmp42,false);
    }
    free(buf);
    usleep(10000);
  }
  pthread_mutex_unlock(__mutex);
  return;
}

