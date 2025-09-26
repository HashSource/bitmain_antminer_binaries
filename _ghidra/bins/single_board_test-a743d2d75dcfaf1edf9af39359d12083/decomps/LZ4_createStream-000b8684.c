
/* WARNING: Unknown calling convention */

LZ4_stream_t * LZ4_createStream(void)

{
  LZ4_stream_t *buffer;
  LZ4_stream_t *lz4s;
  
  buffer = (LZ4_stream_t *)malloc(0x4020);
  if (buffer == (LZ4_stream_t *)0x0) {
    buffer = (LZ4_stream_t *)0x0;
  }
  else {
    LZ4_initStream(buffer,0x4020);
  }
  return buffer;
}

