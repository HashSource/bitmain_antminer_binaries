
void stream_unget(int param_1,uint param_2)

{
  int iVar1;
  
  if (1 < param_2 + 2) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    if (param_2 == 10) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      iVar1 = utf8_check_first(param_2 & 0xff);
      if (iVar1 != 0) {
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      }
    }
    if (*(int *)(param_1 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer_pos > 0","compat/jansson-2.9/src/load.c",0xf0,DAT_0004fe80);
    }
    iVar1 = *(int *)(param_1 + 0x10) + -1;
    *(int *)(param_1 + 0x10) = iVar1;
    if (param_2 != *(byte *)(param_1 + iVar1 + 8)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer[stream->buffer_pos] == c","compat/jansson-2.9/src/load.c",0xf2,
                    DAT_0004fe80);
    }
  }
  return;
}

