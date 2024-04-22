
void clear_nonce_fifo(void)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = DAT_000314bc;
  pthread_mutex_lock(DAT_000314bc);
  nonce_read_out._0_4_ = 0;
  nonce_read_out._4_4_ = 0;
  nonce_read_out._8_4_ = 0;
  (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(ppVar1);
  return;
}

