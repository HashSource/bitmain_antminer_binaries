
uint clear_uart_send_fifo(byte param_1)

{
  int iVar1;
  uint uVar2;
  uint local_14;
  int local_10;
  undefined4 local_c;
  
  printf("--- %s\n","clear_uart_send_fifo");
  pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  switch(param_1) {
  case 0:
    local_10 = 0x18;
    local_c = 0x400;
    break;
  case 1:
    local_10 = 0x10;
    local_c = 0x400;
    break;
  case 2:
    local_10 = 8;
    local_c = 0x400;
    break;
  case 3:
    local_10 = 0;
    local_c = 0x400;
    break;
  case 4:
    local_10 = 0x18;
    local_c = 0x401;
    break;
  case 5:
    local_10 = 0x10;
    local_c = 0x401;
    break;
  case 6:
    local_10 = 8;
    local_c = 0x401;
    break;
  case 7:
    local_10 = 0;
    local_c = 0x401;
    break;
  case 8:
    local_10 = 0x18;
    local_c = 0x402;
    break;
  case 9:
    local_10 = 0x10;
    local_c = 0x402;
    break;
  default:
    printf("%s: The uart%d is not supported!!!\n","clear_uart_send_fifo",(uint)param_1);
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
    return 1;
  }
  local_14 = 0;
  do {
    iVar1 = read_axi_fpga(local_c);
    uVar2 = iVar1 >> local_10 & 0xff;
    if (uVar2 == 0xff) {
      pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
      return 0;
    }
    printf("%s: waiting fpga uart%d clear send fifo space ...\n","clear_uart_send_fifo",
           (uint)param_1);
    usleep(3000);
    local_14 = local_14 + 1;
  } while (local_14 < 0x15);
  printf("%s: uart%d always dose not has enough send fifo space, break\n","clear_uart_send_fifo",
         (uint)param_1);
  pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  return uVar2;
}

