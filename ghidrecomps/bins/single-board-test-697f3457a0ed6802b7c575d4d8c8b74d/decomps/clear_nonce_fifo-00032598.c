
/* WARNING: Unknown calling convention */

void clear_nonce_fifo(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  nonce_fifo.p_wr = 0;
  nonce_fifo.p_rd = 0;
  nonce_fifo.nonce_num = 0;
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}

