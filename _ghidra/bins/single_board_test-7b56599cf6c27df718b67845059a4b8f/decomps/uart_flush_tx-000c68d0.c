
/* WARNING: Unknown calling convention */

int32_t uart_flush_tx(uint32_t chain_id)

{
  clear_uart_tx_fifo(chain_id);
  return 0;
}

