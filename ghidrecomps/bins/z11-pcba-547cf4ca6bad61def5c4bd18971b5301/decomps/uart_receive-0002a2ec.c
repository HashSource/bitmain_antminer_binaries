
uint uart_receive(byte param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint local_10;
  uint local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  uVar1 = check_how_many_uart_data_in_fpga(param_1);
  if (uVar1 < param_3) {
    if (uVar1 == 0) {
      local_c = 0;
    }
    else {
      local_c = read_uart_data_in_fpga(param_1,param_2,uVar1);
    }
  }
  else {
    local_c = read_uart_data_in_fpga(param_1,param_2,param_3);
  }
  if (local_c != 0) {
    for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
      fprintf(stderr,"%02x",(uint)*(byte *)(local_10 + param_2));
    }
    fprintf(stderr,"   len=%d fd=%d\n",local_c,(uint)param_1);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + (uint)param_1 * 0x18));
  return local_c;
}

