
/* WARNING: Unknown calling convention */

int32_t uart_receive(uint32_t chain_id,void *data,uint32_t size,int32_t timeout)

{
  uint32_t uVar1;
  pthread_mutex_t *__mutex;
  
  __mutex = (pthread_mutex_t *)(uart_receive_mutex + chain_id);
  pthread_mutex_lock(__mutex);
  uVar1 = check_how_many_uart_data_in_fpga((uchar)chain_id);
  if (uVar1 <= size) {
    size = uVar1;
  }
  if (size == 0) {
    pthread_mutex_unlock(__mutex);
    return 0;
  }
  uVar1 = read_uart_data_in_fpga(chain_id,(uint8_t *)data,size);
  pthread_mutex_unlock(__mutex);
  return uVar1;
}

