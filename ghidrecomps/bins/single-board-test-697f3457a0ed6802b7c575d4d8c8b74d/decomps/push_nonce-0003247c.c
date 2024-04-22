
void push_nonce(nonce_rb_format *nonce_item)

{
  nonce_rb_format *nonce_item_local;
  char tmp42 [1024];
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  memcpy(nonce_fifo.nonce_buffer + nonce_fifo.p_wr,nonce_item,0x54d);
  if (nonce_fifo.p_wr < 0x1fe) {
    nonce_fifo.p_wr = nonce_fifo.p_wr + 1;
  }
  else {
    nonce_fifo.p_wr = 0;
  }
  if (nonce_fifo.nonce_num < 0x1ff) {
    nonce_fifo.nonce_num = nonce_fifo.nonce_num + 1;
  }
  else {
    nonce_fifo.nonce_num = 0x1ff;
    if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: nonce fifo full!!!\n","push_nonce");
      _applog(1,tmp42,false);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}

