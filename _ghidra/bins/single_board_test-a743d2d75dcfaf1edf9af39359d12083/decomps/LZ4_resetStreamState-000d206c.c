
int LZ4_resetStreamState(void *state,char *inputBuffer)

{
  char *inputBuffer_local;
  void *state_local;
  
  LZ4_resetStream((LZ4_stream_t *)state);
  return 0;
}

