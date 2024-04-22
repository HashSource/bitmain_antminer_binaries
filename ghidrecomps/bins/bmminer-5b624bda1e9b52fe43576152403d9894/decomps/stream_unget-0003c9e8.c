
/* WARNING: Unknown calling convention */

void stream_unget(stream_t *stream,int c)

{
  int iVar1;
  size_t sVar2;
  
  if (1 < c + 2U) {
    stream->position = stream->position - 1;
    if (c == 10) {
      stream->line = stream->line + -1;
      stream->column = stream->last_column;
    }
    else {
      iVar1 = utf8_check_first((char)c);
      if (iVar1 != 0) {
        stream->column = stream->column + -1;
      }
    }
    sVar2 = stream->buffer_pos;
    if (sVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail(DAT_0003ca50,DAT_0003ca48,0xe0,DAT_0003ca4c);
    }
    stream->buffer_pos = sVar2 - 1;
    if ((uint)(byte)stream->buffer[sVar2 - 1] != c) {
                    /* WARNING: Subroutine does not return */
      __assert_fail(DAT_0003ca44,DAT_0003ca48,0xe2,DAT_0003ca4c);
    }
  }
  return;
}

