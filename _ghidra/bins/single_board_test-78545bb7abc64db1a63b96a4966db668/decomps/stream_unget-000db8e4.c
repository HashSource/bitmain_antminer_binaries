
/* WARNING: Unknown calling convention */

void stream_unget(stream_t *stream,int c)

{
  size_t sVar1;
  
  if (1 < c + 2U) {
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
    sVar1 = stream->buffer_pos;
    if (sVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer_pos > 0","load.c",0xdd,"stream_unget");
    }
    stream->buffer_pos = sVar1 - 1;
    if ((uint)(byte)stream->buffer[sVar1 - 1] != c) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer[stream->buffer_pos] == c","load.c",0xdf,"stream_unget");
    }
  }
  return;
}

