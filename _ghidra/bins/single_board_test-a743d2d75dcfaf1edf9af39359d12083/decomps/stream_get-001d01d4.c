
/* WARNING: Unknown calling convention */

int stream_get(stream_t *stream,json_error_t *error)

{
  uint uVar1;
  size_t sVar2;
  uint uVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  stream_t *psVar8;
  
  uVar5 = stream->buffer_pos + 1;
  uVar1 = (uint)(byte)stream->buffer[stream->buffer_pos];
  if (uVar1 == 0) {
    uVar3 = (*stream->get)(stream->data);
    if (uVar3 == 0xffffffff) {
      stream->state = -1;
      return -1;
    }
    uVar7 = uVar3 - 0x80;
    uVar1 = uVar3 & 0xff;
    stream->buffer[0] = (char)uVar3;
    stream->buffer_pos = 0;
    uVar5 = uVar7;
    if (0x7f < uVar7) {
      uVar5 = 1;
    }
    if (uVar7 < 0x80) {
      sVar2 = utf8_check_first((char)uVar3);
      if (sVar2 != 0) {
        if (sVar2 < 2) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("count >= 2","load.c",0xaf,"stream_get");
        }
        psVar8 = stream;
        do {
          iVar6 = (*stream->get)(stream->data);
          psVar8->buffer[1] = (char)iVar6;
          psVar8 = (stream_t *)((int)&psVar8->get + 1);
        } while (psVar8 != (stream_t *)(stream->buffer + (sVar2 - 9)));
        sVar4 = utf8_check_full(stream->buffer,sVar2,(int32_t *)0x0);
        if (sVar4 != 0) {
          sVar4 = stream->buffer_pos;
          stream->buffer[sVar2] = '\0';
          uVar5 = sVar4 + 1;
          uVar1 = (uint)(byte)stream->buffer[sVar4];
          goto LAB_001d01e8;
        }
      }
      stream->state = -2;
      error_set(error,(lex_t *)stream,json_error_invalid_utf8,"unable to decode byte 0x%x",uVar3);
      return -2;
    }
    stream->buffer[1] = '\0';
  }
LAB_001d01e8:
  stream->buffer_pos = uVar5;
  stream->position = stream->position + 1;
  if (uVar1 == 10) {
    iVar6 = stream->column;
    stream->column = 0;
    stream->line = stream->line + 1;
    stream->last_column = iVar6;
  }
  else {
    sVar2 = utf8_check_first((char)uVar1);
    if (sVar2 != 0) {
      stream->column = stream->column + 1;
    }
  }
  return uVar1;
}

