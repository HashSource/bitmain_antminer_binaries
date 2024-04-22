
void stream_unget(int param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 != 0xffffffff) && (param_2 != 0xfffffffe)) {
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
      __assert_fail("stream->buffer_pos > 0","3rdparty/jansson-2.6/src/load.c",0xe0,"stream_unget");
    }
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    if (*(byte *)(param_1 + *(int *)(param_1 + 0x10) + 8) != param_2) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("stream->buffer[stream->buffer_pos] == c","3rdparty/jansson-2.6/src/load.c",0xe2
                    ,"stream_unget");
    }
  }
  return;
}

