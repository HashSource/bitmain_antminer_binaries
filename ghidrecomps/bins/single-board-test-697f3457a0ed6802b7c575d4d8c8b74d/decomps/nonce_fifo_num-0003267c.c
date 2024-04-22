
void nonce_fifo_num(int *num)

{
  int *num_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  *num = nonce_fifo.nonce_num;
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}

