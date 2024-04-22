
RINGBUFFER_STATE rt_ringbuffer_status(rt_ringbuffer *rb)

{
  RINGBUFFER_STATE RVar1;
  rt_ringbuffer *rb_local;
  
  if (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11 ==
      ((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) {
    if ((rb->field_0x4 & 1) == (rb->field_0x6 & 1)) {
      RVar1 = RT_RINGBUFFER_EMPTY;
    }
    else {
      RVar1 = RT_RINGBUFFER_FULL;
    }
  }
  else {
    RVar1 = RT_RINGBUFFER_HALFFULL;
  }
  return RVar1;
}

