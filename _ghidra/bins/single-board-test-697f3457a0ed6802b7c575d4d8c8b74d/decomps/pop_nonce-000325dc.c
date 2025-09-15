
void pop_nonce(nonce_rb_format *nonce_tmp)

{
  nonce_rb_format *nonce_tmp_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  nonce_fifo.nonce_num = nonce_fifo.nonce_num - 1;
  memcpy(nonce_tmp,nonce_fifo.nonce_buffer + nonce_fifo.p_rd,0x54d);
  if (nonce_fifo.p_rd < 0x1fe) {
    nonce_fifo.p_rd = nonce_fifo.p_rd + 1;
  }
  else {
    nonce_fifo.p_rd = 0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}

