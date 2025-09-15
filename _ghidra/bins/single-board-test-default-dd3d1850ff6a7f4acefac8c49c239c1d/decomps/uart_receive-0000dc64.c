
undefined4 uart_receive(byte param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  if (Conf._116_4_ == 0x569) {
    local_10 = 5;
  }
  local_c = check_how_many_uart_data_in_fpga(param_1);
  if (param_3 < local_c) {
    printf("%s: nbytes > buf_length\n","uart_receive");
    local_c = param_3;
  }
  if (local_c < local_10) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
    uVar2 = 0;
  }
  else {
    iVar1 = __udivsi3(local_c,local_10);
    uVar2 = read_uart_data_in_fpga(param_1,param_2,local_10 * iVar1);
    __udivsi3(local_c,local_10);
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  }
  return uVar2;
}

