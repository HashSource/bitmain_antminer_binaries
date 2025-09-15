
void cglock_destroy(cglock_t *lock)

{
  cglock_t *lock_local;
  
  rwlock_destroy(&lock->rwlock);
  mutex_destroy(&lock->mutex);
  return;
}

