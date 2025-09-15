
undefined4 uart_flush_tx(undefined4 param_1)

{
  clear_uart_tx_fifo(param_1);
  return 0;
}

