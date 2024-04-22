
undefined4 uart_receive(byte param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  uVar1 = check_how_many_uart_data_in_fpga(param_1);
  if (uVar1 < param_3) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
    uVar2 = 0;
  }
  else {
    uVar2 = __udivsi3(uVar1,1);
    uVar2 = read_uart_data_in_fpga(param_1,param_2,uVar2);
    __udivsi3(uVar1,1);
    local_c = 0;
    while( true ) {
      if (uVar1 <= local_c) break;
      printf("%02x",(uint)*(byte *)(param_2 + local_c));
      local_c = local_c + 1;
    }
    printf(" --- len = %d\n",uVar2);
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  }
  return uVar2;
}

