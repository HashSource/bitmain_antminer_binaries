
int LZ4_freeStreamDecode(LZ4_streamDecode_t *LZ4_stream)

{
  LZ4_streamDecode_t *LZ4_stream_local;
  
  if (LZ4_stream != (LZ4_streamDecode_t *)0x0) {
    free(LZ4_stream);
  }
  return 0;
}

