
undefined4 uart_receive(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
  local_c = check_how_many_uart_data_in_fpga(param_1 & 0xff);
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if (local_c == 0) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
    uVar1 = 0;
  }
  else {
    uVar1 = __udivsi3(local_c,1,local_c,1,param_4);
    uVar1 = read_uart_data_in_fpga(param_1,param_2,uVar1);
    __udivsi3(local_c,1);
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
  }
  return uVar1;
}

