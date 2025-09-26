
int LZ4_freeStream(LZ4_stream_t *LZ4_stream)

{
  LZ4_stream_t *LZ4_stream_local;
  
  if (LZ4_stream != (LZ4_stream_t *)0x0) {
    free(LZ4_stream);
  }
  return 0;
}

