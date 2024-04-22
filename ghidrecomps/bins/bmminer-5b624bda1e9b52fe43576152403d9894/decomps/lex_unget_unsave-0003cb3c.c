
/* WARNING: Unknown calling convention */

void lex_unget_unsave(lex_t *lex,int c)

{
  char cVar1;
  char d;
  
  if (1 < c + 2U) {
    stream_unget(&lex->stream,c);
    cVar1 = strbuffer_pop(&lex->saved_text);
    if (cVar1 != c) {
                    /* WARNING: Subroutine does not return */
      __assert_fail(DAT_0003cb68,DAT_0003cb6c,0x10c,DAT_0003cb70);
    }
  }
  return;
}

