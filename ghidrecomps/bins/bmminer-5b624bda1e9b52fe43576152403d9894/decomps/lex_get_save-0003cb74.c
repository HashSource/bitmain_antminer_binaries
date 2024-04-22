
/* WARNING: Unknown calling convention */

int lex_get_save(lex_t *lex,json_error_t *error)

{
  int iVar1;
  int c;
  
  iVar1 = stream_get(&lex->stream,error);
  if (1 < iVar1 + 2U) {
    strbuffer_append_byte(&lex->saved_text,(char)iVar1);
  }
  return iVar1;
}

