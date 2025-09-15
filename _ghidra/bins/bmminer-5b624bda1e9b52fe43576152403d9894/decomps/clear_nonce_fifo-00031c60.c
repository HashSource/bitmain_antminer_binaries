
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_nonce_fifo(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  nonce_read_out.p_wr = 0;
  nonce_read_out.p_rd = 0;
  nonce_read_out.nonce_num = 0;
  (*(code *)(undefined *)0x0)(&nonce_mutex);
  return;
}

