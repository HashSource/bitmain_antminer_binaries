
uint16_t rt_ringbuffer_data_len(rt_ringbuffer *rb)

{
  RINGBUFFER_STATE RVar1;
  uint16_t uVar2;
  rt_ringbuffer *rb_local;
  
  RVar1 = rt_ringbuffer_status(rb);
  if (RVar1 == RT_RINGBUFFER_EMPTY) {
    uVar2 = 0;
  }
  else if (RVar1 == RT_RINGBUFFER_FULL) {
    uVar2 = rb->buffer_size;
  }
  else if (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11 <
           ((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) {
    uVar2 = (*(ushort *)&rb->field_0x6 >> 1) - (*(ushort *)&rb->field_0x4 >> 1);
  }
  else {
    uVar2 = ((*(ushort *)&rb->field_0x6 >> 1) - (*(ushort *)&rb->field_0x4 >> 1)) + rb->buffer_size;
  }
  return uVar2;
}

