
/* WARNING: Unknown calling convention */

int lex_get_save(lex_t *lex,json_error_t *error)

{
  int c;
  int iVar1;
  
  iVar1 = (lex->stream).state;
  if (iVar1 == 0) {
    iVar1 = stream_get(&lex->stream,error);
  }
  if (1 < iVar1 + 2U) {
    strbuffer_append_byte(&lex->saved_text,(char)iVar1);
  }
  return iVar1;
}

