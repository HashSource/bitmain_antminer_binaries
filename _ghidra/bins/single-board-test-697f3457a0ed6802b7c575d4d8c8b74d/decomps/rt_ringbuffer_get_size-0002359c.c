
uint16_t rt_ringbuffer_get_size(rt_ringbuffer *rb)

{
  rt_ringbuffer *rb_local;
  
  return rb->buffer_size;
}

