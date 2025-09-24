
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_register_stage_1(void)

{
  set_chain_core_srst((uint8_t)(g_rt.config)->chain,false);
  set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0xffffffff);
  uart_flush_rx((g_rt.config)->chain);
  usleep(50000);
  return;
}

