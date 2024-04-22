
uint32_t rt_ringbuffer_prefetch(rt_ringbuffer *rb,uint8_t *ptr,uint16_t length)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint16_t length_local;
  uint8_t *ptr_local;
  rt_ringbuffer *rb_local;
  uint32_t size;
  
  uVar1 = rt_ringbuffer_data_len(rb);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    length_local = length;
    if (uVar1 < length) {
      length_local = uVar1;
    }
    if ((int)(uint)length_local <
        (int)((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11))) {
      memcpy(ptr,rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11),
             (uint)length_local);
      uVar2 = (uint32_t)length_local;
    }
    else {
      memcpy(ptr,rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11),
             (uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11));
      memcpy(ptr + ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11)),
             rb->buffer_ptr,
             (uint)length_local -
             ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11)));
      uVar2 = (uint32_t)length_local;
    }
  }
  return uVar2;
}

