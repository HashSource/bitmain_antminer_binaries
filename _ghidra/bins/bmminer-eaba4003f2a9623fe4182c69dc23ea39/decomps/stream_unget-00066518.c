
void stream_unget(stream_t *stream,int c)

{
  size_t sVar1;
  int c_local;
  stream_t *stream_local;
  
  if ((c != -1) && (c != -2)) {
    stream->position = stream->position - 1;
    if (c == 10) {
      stream->line = stream->line + -1;
      stream->column = stream->last_column;
    }
    else {
      sVar1 = utf8_check_first((char)c);
      if (sVar1 != 0) {
        stream->column = stream->column + -1;
      }
    }
    if (stream->buffer_pos == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer_pos > 0","compat/jansson-2.9/src/load.c",0xf0,"stream_unget");
    }
    stream->buffer_pos = stream->buffer_pos - 1;
    if ((uint)(byte)stream->buffer[stream->buffer_pos] != c) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer[stream->buffer_pos] == c","compat/jansson-2.9/src/load.c",0xf2,
                    "stream_unget");
    }
  }
  return;
}

