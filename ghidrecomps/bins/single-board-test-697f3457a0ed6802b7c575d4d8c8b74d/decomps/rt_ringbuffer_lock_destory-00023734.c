
void rt_ringbuffer_lock_destory(rt_ringbuffer *rb)

{
  rt_ringbuffer *rb_local;
  
  pthread_mutex_destroy((pthread_mutex_t *)&rb->ringbuf_lock);
  if (rb->ringbuffer_type == BLOCK_TYPE) {
    pthread_cond_destroy((pthread_cond_t *)&rb->notfull);
    pthread_cond_destroy((pthread_cond_t *)&rb->notempty);
  }
  return;
}

