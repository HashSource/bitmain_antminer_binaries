
int stream_get(stream_t *stream,json_error_t *error)

{
  byte byte;
  int iVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  json_error_t *error_local;
  stream_t *stream_local;
  size_t count;
  int c;
  size_t i;
  
  if (stream->state != 0) {
    return stream->state;
  }
  if (stream->buffer[stream->buffer_pos] == '\0') {
    iVar1 = (*stream->get)(stream->data);
    if (iVar1 == -1) {
      stream->state = -1;
      return -1;
    }
    stream->buffer[0] = (char)iVar1;
    stream->buffer_pos = 0;
    if ((0x7f < iVar1) && (iVar1 < 0x100)) {
      sVar2 = utf8_check_first((char)iVar1);
      if (sVar2 != 0) {
        if (sVar2 < 2) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("count >= 2","compat/jansson-2.9/src/load.c",0xbc,"stream_get");
        }
        for (i = 1; i < sVar2; i = i + 1) {
          iVar3 = (*stream->get)(stream->data);
          stream->buffer[i] = (char)iVar3;
        }
        sVar4 = utf8_check_full(stream->buffer,sVar2,(int32_t *)0x0);
        if (sVar4 != 0) {
          stream->buffer[sVar2] = '\0';
          goto LAB_0007b82c;
        }
      }
      stream->state = -2;
      error_set(error,(lex_t *)stream,"unable to decode byte 0x%x",iVar1);
      return -2;
    }
    stream->buffer[1] = '\0';
  }
LAB_0007b82c:
  sVar2 = stream->buffer_pos;
  stream->buffer_pos = sVar2 + 1;
  byte = stream->buffer[sVar2];
  stream->position = stream->position + 1;
  if (byte == 10) {
    stream->line = stream->line + 1;
    stream->last_column = stream->column;
    stream->column = 0;
  }
  else {
    sVar2 = utf8_check_first(byte);
    if (sVar2 != 0) {
      stream->column = stream->column + 1;
    }
  }
  return (uint)byte;
}

