
undefined4 uart_get_readable_byte_num(uint param_1)

{
  undefined4 uVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
  uVar1 = check_how_many_uart_data_in_fpga(param_1 & 0xff);
  pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + param_1 * 0x18));
  return uVar1;
}

