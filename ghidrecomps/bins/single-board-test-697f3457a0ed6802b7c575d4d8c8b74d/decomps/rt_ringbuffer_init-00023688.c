
void rt_ringbuffer_init(rt_ringbuffer *rb,uint8_t *pool,int16_t size,
                       ringbuffer_type_t ringbuffer_type)

{
  ringbuffer_type_t ringbuffer_type_local;
  int16_t size_local;
  uint8_t *pool_local;
  rt_ringbuffer *rb_local;
  
  *(ushort *)&rb->field_0x4 = *(ushort *)&rb->field_0x4 & 1;
  rb->field_0x4 =
       rb->field_0x4 & 0xfe | (byte)(((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11) & 1;
  *(ushort *)&rb->field_0x6 = *(ushort *)&rb->field_0x6 & 1;
  rb->field_0x6 =
       rb->field_0x6 & 0xfe | (byte)(((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) & 1;
  rb->buffer_ptr = pool;
  rb->buffer_size = size & 0xfffc;
  rb->ringbuffer_type = ringbuffer_type;
  pthread_mutex_init((pthread_mutex_t *)&rb->ringbuf_lock,(pthread_mutexattr_t *)0x0);
  if (rb->ringbuffer_type == BLOCK_TYPE) {
    pthread_cond_init((pthread_cond_t *)&rb->notfull,(pthread_condattr_t *)0x0);
    pthread_cond_init((pthread_cond_t *)&rb->notempty,(pthread_condattr_t *)0x0);
  }
  return;
}

