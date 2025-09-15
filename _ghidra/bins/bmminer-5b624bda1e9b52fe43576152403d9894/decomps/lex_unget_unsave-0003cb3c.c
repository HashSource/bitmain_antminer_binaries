
/* WARNING: Unknown calling convention */

void lex_unget_unsave(lex_t *lex,int c)

{
  char cVar1;
  
  if (1 < c + 2U) {
    stream_unget(&lex->stream,c);
    cVar1 = strbuffer_pop(&lex->saved_text);
    if (cVar1 != c) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("c == d","compat/jansson-2.6/src/load.c",0x10c,"lex_unget_unsave");
    }
  }
  return;
}

