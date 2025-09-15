
uint32_t rt_ringbuffer_put(rt_ringbuffer *rb,uint8_t *ptr,uint16_t length)

{
  ushort uVar1;
  uint16_t uVar2;
  uint16_t length_local;
  uint8_t *ptr_local;
  rt_ringbuffer *rb_local;
  uint16_t size;
  
  pthread_mutex_lock((pthread_mutex_t *)&rb->ringbuf_lock);
  uVar1 = rb->buffer_size;
  uVar2 = rt_ringbuffer_data_len(rb);
  size = uVar1 - uVar2;
  if (rb->ringbuffer_type == POLL_TYPE) {
    if (size == 0) {
      pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
      return 0;
    }
    length_local = length;
    if (size < length) {
      length_local = size;
    }
  }
  else {
    length_local = length;
    if (rb->ringbuffer_type == BLOCK_TYPE) {
      while (size < length) {
        pthread_cond_wait((pthread_cond_t *)&rb->notfull,(pthread_mutex_t *)&rb->ringbuf_lock);
        uVar1 = rb->buffer_size;
        uVar2 = rt_ringbuffer_data_len(rb);
        size = uVar1 - uVar2;
      }
    }
  }
  if ((int)(uint)length_local <
      (int)((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11))) {
    memcpy(rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11),ptr,
           (uint)length_local);
    *(ushort *)&rb->field_0x6 =
         *(ushort *)&rb->field_0x6 & 1 |
         (ushort)(((uint)length_local + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) & 0x7fff
                  ) << 1);
    pthread_cond_signal((pthread_cond_t *)&rb->notempty);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  else {
    memcpy(rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11),ptr,
           (uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11));
    memcpy(rb->buffer_ptr,
           ptr + ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11)),
           (uint)length_local -
           ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11)));
    rb->field_0x6 = rb->field_0x6 & 0xfe | ~(byte)(((uint)(byte)rb->field_0x6 << 0x1f) >> 0x1f) & 1;
    *(ushort *)&rb->field_0x6 =
         *(ushort *)&rb->field_0x6 & 1 |
         (ushort)(((uint)length_local +
                   ((((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) - (uint)rb->buffer_size &
                   0xffff) & 0x7fff) << 1);
    pthread_cond_signal((pthread_cond_t *)&rb->notempty);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  return (uint)length_local;
}

