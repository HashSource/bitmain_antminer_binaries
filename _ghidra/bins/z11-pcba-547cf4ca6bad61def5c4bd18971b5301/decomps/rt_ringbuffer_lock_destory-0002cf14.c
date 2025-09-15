
void rt_ringbuffer_lock_destory(int param_1)

{
  pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 0x10));
  if (*(int *)(param_1 + 0x88) == 0) {
    pthread_cond_destroy((pthread_cond_t *)(param_1 + 0x28));
    pthread_cond_destroy((pthread_cond_t *)(param_1 + 0x58));
  }
  return;
}

