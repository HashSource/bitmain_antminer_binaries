
/* WARNING: Unknown calling convention */

void lex_close(lex_t *lex)

{
  if (lex->token == 0x100) {
    _jsonp_free(&(lex->value).string);
  }
  strbuffer_close(&lex->saved_text);
  return;
}

