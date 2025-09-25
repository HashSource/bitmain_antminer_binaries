
/* WARNING: Unknown calling convention */

void clear_uart_tx_fifo(uint32_t chain_id)

{
  int32_t iVar1;
  int iVar2;
  uint chain_send_fifo_status_addr;
  uint chain_send_ready_addr;
  uint chain_send_buffer_addr;
  uint max_fpga_can_send_uart_data_len;
  uint bit_shift_num;
  char tmp42 [2048];
  
  chain_send_fifo_status_addr = 0;
  chain_send_ready_addr = 0;
  chain_send_buffer_addr = 0;
  max_fpga_can_send_uart_data_len = 0;
  bit_shift_num = 0;
  pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + chain_id));
  iVar1 = get_send_address_info
                    (chain_id,&bit_shift_num,&chain_send_fifo_status_addr,&chain_send_ready_addr,
                     &chain_send_buffer_addr);
  if (iVar1 == 0) {
    iVar2 = 0x15;
    do {
      fpga_read(chain_send_fifo_status_addr,&max_fpga_can_send_uart_data_len);
      max_fpga_can_send_uart_data_len =
           max_fpga_can_send_uart_data_len >> (bit_shift_num & 0xff) & 0xff;
      if (max_fpga_can_send_uart_data_len == 0xff) goto LAB_000c0944;
      printf("%s: waiting fpga uart%d clear send fifo space ...\n","clear_uart_tx_fifo",chain_id);
      fpga_write(chain_send_ready_addr,max_fpga_can_send_uart_data_len | 0x80000000);
      usleep(3000);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    snprintf(tmp42,0x800,"%s: uart%d always dose not has enough send fifo space, break\n",
             "clear_uart_tx_fifo",chain_id);
  }
  else {
    snprintf(tmp42,0x800,"get_send_address_info error, chain_id = %d\n",chain_id);
  }
  _applog(0,tmp42,false);
LAB_000c0944:
  pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + chain_id));
  return;
}

