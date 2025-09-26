
/* WARNING: Unknown calling convention */

int32_t uart_flush_rx(uint32_t chain_id)

{
  clear_uart_rx_fifo(chain_id);
  return 0;
}

