
LZ4_stream_t * LZ4_initStream(void *buffer,size_t size)

{
  size_t alignment;
  int iVar1;
  size_t size_local;
  void *buffer_local;
  
  if (buffer == (void *)0x0) {
    buffer = (LZ4_stream_t *)0x0;
  }
  else if (size < 0x4020) {
    buffer = (LZ4_stream_t *)0x0;
  }
  else {
    alignment = LZ4_stream_t_alignment();
    iVar1 = LZ4_isAligned(buffer,alignment);
    if (iVar1 == 0) {
      buffer = (LZ4_stream_t *)0x0;
    }
    else {
      memset(buffer,0,0x4014);
    }
  }
  return (LZ4_stream_t *)buffer;
}

