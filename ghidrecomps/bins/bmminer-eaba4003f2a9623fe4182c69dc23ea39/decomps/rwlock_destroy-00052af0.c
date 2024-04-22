
void rwlock_destroy(pthread_rwlock_t *lock)

{
  pthread_rwlock_t *lock_local;
  
  pthread_rwlock_destroy((pthread_rwlock_t *)lock);
  return;
}

