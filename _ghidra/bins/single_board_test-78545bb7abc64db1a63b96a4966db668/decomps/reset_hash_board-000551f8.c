
int reset_hash_board(uint32_t chain)

{
  uint32_t chain_local;
  
  chain_reset_low(chain);
  usleep(10000);
  chain_reset_high(chain);
  usleep(100000);
  chain_reset_low(chain);
  usleep(10000);
  chain_reset_high(chain);
  usleep(100000);
  set_chain_ticketmask((uint8_t)chain,0xffff);
  uart_flush_rx(chain);
  usleep(50000);
  return 0;
}

