
void clear_uart_tx_fifo(int param_1)

{
  int iVar1;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_c = 0;
  pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  iVar1 = get_send_address_info(param_1,&local_20,&local_10,&local_14,&local_18);
  if (iVar1 == 0) {
    local_c = 0;
    do {
      fpga_read(local_10,&local_1c);
      local_1c = local_1c >> (local_20 & 0xff) & 0xff;
      if (local_1c == 0xff) {
        pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
        return;
      }
      printf("%s: waiting fpga uart%d clear send fifo space ...\n","clear_uart_tx_fifo",param_1);
      usleep(3000);
      local_c = local_c + 1;
    } while (local_c < 0x15);
    printf("%s:%d","clear_uart_tx_fifo",0x323);
    printf("%s: uart%d always dose not has enough send fifo space, break\n","clear_uart_tx_fifo",
           param_1);
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  }
  else {
    printf("%s:%d","clear_uart_tx_fifo",0x30f);
    printf("get_send_address_info error, chain_id = %d\n",param_1);
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  }
  return;
}

