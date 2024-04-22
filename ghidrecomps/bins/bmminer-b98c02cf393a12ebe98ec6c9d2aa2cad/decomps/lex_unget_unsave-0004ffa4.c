
void lex_unget_unsave(int param_1,int param_2)

{
  int iVar1;
  
  if (1 < param_2 + 2U) {
    stream_unget();
    iVar1 = strbuffer_pop(param_1 + 0x28);
    if (param_2 != iVar1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("c == d","compat/jansson-2.9/src/load.c",0x11d,DAT_0004ffdc);
    }
  }
  return;
}

