
void lex_unget_unsave(int param_1,uint param_2)

{
  byte bVar1;
  
  if ((param_2 != 0xffffffff) && (param_2 != 0xfffffffe)) {
    stream_unget(param_1,param_2);
    bVar1 = strbuffer_pop(param_1 + 0x28);
    if (bVar1 != param_2) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("c == d","3rdparty/jansson-2.6/src/load.c",0x10c,"lex_unget_unsave");
    }
  }
  return;
}

