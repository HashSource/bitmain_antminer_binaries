
undefined4 uart_flush(undefined4 param_1)

{
  printf("%s:%d","uart_flush",0x35b);
  printf("flush uart %d\n",param_1);
  clear_uart_rx_fifo(param_1);
  usleep(10000);
  clear_uart_tx_fifo(param_1);
  return 0;
}

