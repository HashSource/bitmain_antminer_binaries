
/* WARNING: Unknown calling convention */

int stream_get(stream_t *stream,json_error_t *error)

{
  uint uVar1;
  int c_1;
  int iVar2;
  uint uVar3;
  int count;
  int iVar4;
  uint uVar5;
  uint uVar6;
  size_t sVar7;
  int c;
  stream_t *psVar8;
  
  if (stream->state != 0) {
    return stream->state;
  }
  uVar5 = stream->buffer_pos + 1;
  uVar1 = (uint)(byte)stream->buffer[stream->buffer_pos];
  if (uVar1 == 0) {
    uVar3 = (*stream->get)(stream->data);
    if (uVar3 == 0xffffffff) {
      stream->state = -1;
      return -1;
    }
    uVar6 = uVar3 - 0x80;
    uVar1 = uVar3 & 0xff;
    stream->buffer_pos = 0;
    stream->buffer[0] = (char)uVar3;
    uVar5 = uVar6;
    if (0x7f < uVar6) {
      uVar5 = 1;
    }
    if (uVar6 < 0x80) {
      iVar2 = utf8_check_first((char)uVar3);
      if (iVar2 != 0) {
        if (iVar2 < 2) {
                    /* WARNING: Subroutine does not return */
          __assert_fail(DAT_0003cb30,DAT_0003cb34,0xaf,DAT_0003cb38);
        }
        psVar8 = stream;
        do {
          iVar4 = (*stream->get)(stream->data);
          psVar8->buffer[1] = (char)iVar4;
          psVar8 = (stream_t *)((int)&psVar8->get + 1);
        } while (psVar8 != (stream_t *)(stream->buffer + iVar2 + -9));
        iVar4 = utf8_check_full(stream->buffer,iVar2,(int32_t *)0x0);
        if (iVar4 != 0) {
          sVar7 = stream->buffer_pos;
          stream->buffer[iVar2] = '\0';
          uVar5 = sVar7 + 1;
          uVar1 = (uint)(byte)stream->buffer[sVar7];
          goto LAB_0003ca6a;
        }
      }
      stream->state = -2;
      error_set(error,(lex_t *)stream,DAT_0003cb2c,uVar3);
      return -2;
    }
    stream->buffer[1] = '\0';
  }
LAB_0003ca6a:
  stream->buffer_pos = uVar5;
  stream->position = stream->position + 1;
  if (uVar1 != 10) {
    iVar2 = utf8_check_first((char)uVar1);
    if (iVar2 != 0) {
      stream->column = stream->column + 1;
    }
    return uVar1;
  }
  iVar2 = stream->column;
  stream->column = 0;
  stream->line = stream->line + 1;
  stream->last_column = iVar2;
  return 10;
}

