
void bm1740_app_exit(void)

{
  int local_c;
  
  reg_scan_exit();
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    pthread_cancel(p_get_reg_back);
    pthread_cancel(p_get_nonce_back);
    pthread_cancel(*(pthread_t *)(g_chain + local_c * 0x28 + 0x18));
    pthread_cancel(*(pthread_t *)(g_chain + local_c * 0x28 + 0x1c));
  }
  rt_ringbuffer_lock_destory(bm_nonce_rb);
  rt_ringbuffer_lock_destory(bm_reg_rb);
  rt_ringbuffer_lock_destory(bm_comm_rb);
  free(rb_nonce);
  free(rb_reg);
  free(rb_comm);
  return;
}

