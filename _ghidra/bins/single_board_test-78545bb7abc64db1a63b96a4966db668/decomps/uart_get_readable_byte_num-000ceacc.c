
/* WARNING: Unknown calling convention */

int32_t uart_get_readable_byte_num(uint32_t chain_id)

{
  uint32_t uVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + chain_id));
  uVar1 = check_how_many_uart_data_in_fpga((uchar)chain_id);
  pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + chain_id));
  return uVar1;
}

