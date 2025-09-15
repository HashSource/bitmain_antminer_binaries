
void clear_nonce_fifo(void)

{
  pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
  nonce_fifo._0_4_ = 0;
  nonce_fifo._4_4_ = 0;
  nonce_fifo._8_4_ = 0;
  pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
  return;
}

