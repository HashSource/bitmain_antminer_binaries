
/* WARNING: Unknown calling convention */

int32_t uart_flush(uint32_t chain_id)

{
  clear_uart_rx_fifo(chain_id);
  usleep(10000);
  clear_uart_tx_fifo(chain_id);
  return 0;
}

