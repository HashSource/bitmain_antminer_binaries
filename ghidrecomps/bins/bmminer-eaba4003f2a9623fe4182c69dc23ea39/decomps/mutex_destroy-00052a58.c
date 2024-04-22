
void mutex_destroy(pthread_mutex_t *lock)

{
  pthread_mutex_t *lock_local;
  
  pthread_mutex_destroy((pthread_mutex_t *)lock);
  return;
}

