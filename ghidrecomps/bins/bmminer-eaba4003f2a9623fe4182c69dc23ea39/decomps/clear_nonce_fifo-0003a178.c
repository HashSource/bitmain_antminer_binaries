
/* WARNING: Unknown calling convention */

void clear_nonce_fifo(void)

{
  uint buf [2];
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  nonce_read_out.p_wr = 0;
  nonce_read_out.p_rd = 0;
  nonce_read_out.nonce_num = 0;
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}

