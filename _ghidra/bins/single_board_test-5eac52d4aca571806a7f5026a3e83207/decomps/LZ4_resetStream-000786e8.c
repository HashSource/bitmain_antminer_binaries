
void LZ4_resetStream(LZ4_stream_t *LZ4_stream)

{
  LZ4_stream_t *LZ4_stream_local;
  
  memset(LZ4_stream,0,0x4014);
  return;
}

