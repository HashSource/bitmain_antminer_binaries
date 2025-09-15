
void lex_unget_unsave(lex_t *lex,int c)

{
  byte bVar1;
  int c_local;
  lex_t *lex_local;
  char d;
  
  if ((c != -1) && (c != -2)) {
    stream_unget(&lex->stream,c);
    bVar1 = strbuffer_pop(&lex->saved_text);
    if (c != (uint)bVar1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("c == d","compat/jansson-2.9/src/load.c",0x11d,"lex_unget_unsave");
    }
  }
  return;
}

